#include<iostream>
#include<cassert>

using namespace std;

template<typename Graph>
class Comment {

private:
	Graph &graph;
	bool* visited;
	int* id; // 检测两个结点之间是否连接
	int ccount;

	void dfs(int i)
	{
		visited[i] = true;
		id[i] = ccount;
		typename Graph::adjIterator adj(graph, i);
		for (int w = adj.begin(); !adj.end(); w = adj.next())
		{
			if (visited[w] == false)
				dfs(w);
		}
	}

public:
	Comment(Graph graph) :graph(graph) {
		visited = new bool[graph.NodeSize()];
		id = new int[graph.NodeSize()];
		ccount = 0;
		for (int i = 0; i < graph.NodeSize(); ++i)
		{
			visited[i] = false;
			id[i] = -1;
		}
		for (int i = 0; i < graph.NodeSize(); i++)
		{
			if (visited[i] == false)
			{
				dfs(i);
				ccount++;
			}
		}
	}

	~Comment()
	{
		delete[] visited;
	}

	int Count()
	{
		return ccount;
	}

	bool isConnection(int v, int m)
	{
		assert(v >= 0 && v < graph.NodeSize());
		assert(m >= 0 && m < graph.NodeSize());
		return id[v] == id[m];
	}
};