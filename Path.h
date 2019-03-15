#include<iostream>
#include<stack>
#include<vector>
#include<cassert>

using namespace std;

template<typename Graph>
class Path {
private:
	Graph &graph;
	int s;  //某一个点
	bool* visited;
	int* from;  //他是从那个点来的

	void dfs(int v)
	{
		visited[v] = true;

		typename Graph::adjIterator adj(graph, v);
		for(int i = adj.begin();!adj.end();i = adj.next())
			if (!visited[i])
			{
				from[i] = v;
				dfs(i);
			}
	}

public:
	Path(Graph &graph, int s) :graph(graph) {

		assert(s >= 0 && s < graph.NodeSize());

		visited = new bool[graph.NodeSize()];
		from = new int[graph.NodeSize()];
		for (int i = 0; i < graph.NodeSize(); ++i)
		{
			visited[i] = false;
			from[i] = -1;
		}
		this->s = s;

		//寻找路由
		dfs(s);
	}

	~Path()
	{
		delete[] visited;
		delete[] from;
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
				cout << "→";
		}
	}
};