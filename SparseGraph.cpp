#include<iostream>
#include<cassert>
#include<vector>
#include<ctime>
#include<cstdlib>
#include"GraphComment.h"
#include"Path.h"
#include"ShortPath.h"

using namespace std;

//使用临接表实现稀疏图
class SparseGraph {

private:
	int node, side; //node表示结点，side表示边
	bool directed;  //true为有向图，false为无向图
	vector<vector<int>> g;

public:
	SparseGraph(int node, bool directed)
	{
		this->node = node;
		this->side = 0;
		this->directed = directed;
		for (int i = 0; i < node; i++)
		{
			g.push_back(vector<int>());
		}
	}
	~SparseGraph()
	{

	}

	int NodeSize()
	{
		return this->node;
	}

	int SideSize()
	{
		return this->side;
	}

	bool HasSide(int v, int m)
	{
		assert(v >= 0 && v < node);
		assert(m >= 0 && m < node);

		for (int i = 0; i < g[v].size(); i++)
		{
			if (g[v][i] == m)
				return true;
		}
		return false;
	}

	void AddSide(int v, int m)
	{
		assert(v >= 0 && v < node);
		assert(m >= 0 && m < node);

		if (HasSide(v, m) == true)
			return;

		g[v].push_back(m);
		if (v != m && this->directed == false)
			g[m].push_back(v);
		this->side += 1;
	}

	class adjIterator {
	private:
		SparseGraph &graph;
		int v;  //结点
		int index; //循环到哪一个结点
	public:
		adjIterator(SparseGraph &graph,int v) :graph(graph)
		{
			this->v = v;
			this->index = 0;
		}

		int begin()
		{
			index = 0;
			if (graph.g[v].size() != 0)
				return graph.g[v][index];
			return -1;
		}

		int next()
		{
			index++;
			if (index < graph.g[v].size())
				return graph.g[v][index];
		}
		bool end()
		{
			if (index >= graph.g[v].size())
				return true;
			else
				return false;
		}
	};
};

int main()
{
	SparseGraph g2(10, false);
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		int v = rand() % 10;
		int m = rand() % 10;
		g2.AddSide(v, m);
	}
	for (int i = 0; i < 10; i++)
	{
		cout << i << ":";
		SparseGraph::adjIterator adj(g2,i);
		for (int w = adj.begin(); !adj.end(); w = adj.next())
			cout << w << " ";
		cout << endl;
	}

	Comment<SparseGraph> co(g2);
	cout << "comment count:" << co.Count() << endl;
	cout << co.isConnection(2, 0) << endl;

	Path<SparseGraph> dfs(g2, 0);
	cout << "DFS : ";
	dfs.showPath(6);

	ShortPath<SparseGraph> spa(g2,0);
	cout << "BFS : ";
	spa.showPath(6);

	system("pause");
	return 0;
}

