#pragma once
#include<iostream>
#include<queue>
#include<stack>
#include<cassert>
using namespace std;

template<typename Graph>
class ShortPath {
private:
	Graph &graph;
	int s;
	bool* visited;
	int* from;
	int* ord;  
public:
	ShortPath(Graph &graph, int s) :graph(graph) {
		assert(s >= 0 && s < graph.NodeSize());

		visited = new bool[graph.NodeSize()];
		from = new int[graph.NodeSize()];
		ord = new int[graph.NodeSize()];
		for (int i = 0; i < graph.NodeSize(); ++i)
		{
			visited[i] = false;
			from[i] = -1;
			ord[i] = -1;
		}
		this->s = s;

		queue<int> q;
		q.push(s);
		visited[s] = true;
		ord[s] = 0;
		while (!q.empty())
		{
			int w = q.front();
			q.pop();

			typename Graph::adjIterator adj(graph, w);
			for (int i = adj.begin(); !adj.end(); i = adj.next())
			{
				if (!visited[i])
				{
					q.push(i);
					visited[i] = true;
					from[i] = w;
					ord[i] = ord[w] + 1;
				}
			}
		}
	}


	~ShortPath()
	{
		delete[] visited;
		delete[] from;
		delete[] ord;
	}

	bool hasPath(int w)
	{
		assert(w >= 0 && w < graph.NodeSize());
		return visited[w];
	}

	void path(int w, vector<int> &vec)
	{
		stack<int> s;

		int p = w;
		while (p != -1)
		{
			s.push(p);
			p = from[p];
		}
		vec.clear();
		while (!s.empty())
		{
			vec.push_back(s.top());
			s.pop();
		}
	}

	void showPath(int w)
	{
		vector<int> vec;
		path(w, vec);
		for (int i = 0; i < vec.size(); ++i)
		{
			cout << vec[i];
			if (i == vec.size() - 1)
				cout << endl;
			else
				cout << "¡ú";
		}
	}

	int length(int w)
	{
		assert(w >= 0 && w < graph.NodeSize());
		return ord[w];
	}
};