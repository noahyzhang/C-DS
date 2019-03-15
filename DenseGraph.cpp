#include<iostream>
#include<vector>
#include<cassert>
#include<ctime>
#include<cstdlib>

using namespace std;


//�����ڽӾ���ʵ�ֳ���ͼ
class DenseGraph
{
private:
	int node, side; //node��ͼ�Ľ��  side��ͼ�ϵı�
	bool directed; //true��������ͼ��false��������ͼ
	vector<vector<bool>> g;

public:
	DenseGraph(int node, bool directed)
	{
		this->node = node;
		this->side = 0;
		this->directed = directed;
		for (int i = 0; i < node; i++)
		{
			g.push_back(vector<bool>(node, false));
		}
	}

	~DenseGraph()
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
		return g[v][m];
	}

	void AddSide(int v,int m)
	{
		assert(v >= 0 && v < node);
		assert(m >= 0 && m < node);

		if (HasSide(v, m) == true)
			return;

		g[v][m] = true;
		if (this->directed == false) // ���Ϊ����ͼ
			g[m][v] = true;
		this->side += 1; //�ߵ�������1
	}

	class adjIterator
	{
	private:
		DenseGraph &graph;
		int v; // ���
		int index; //��ǰѭ�����Ǹ����
	public:
		adjIterator(DenseGraph& g, int v) :graph(g) 
		{
			this->v = v;
			this->index = -1;
		}
		int begin()
		{
			index = -1;
			return next();
		}

		int next()
		{
			for (index += 1; index < graph.NodeSize(); index++)
				if (graph.g[v][index] == true)
					return index;
			return -1;
		}

		bool end()
		{
			return index >= graph.NodeSize();
		}
	};
};

//
//int main()
//{
//	srand(time(NULL));
//	DenseGraph g1 = DenseGraph(10, false);
//	for (int i = 0; i < 10; i++)
//	{
//		int v = rand() % 10;
//		int m = rand() % 10;
//		g1.AddSide(v, m);
//	}
//
//	for (int i = 0; i < 10; i++)
//	{
//		cout << i << ":";
//		DenseGraph::adjIterator adj(g1, i);
//		for (int w = adj.begin(); !adj.end(); w = adj.next())
//			cout << w << " ";
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}