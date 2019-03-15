//#include<iostream>
//#include<algorithm>
//#include<queue>
//
//using namespace std;
//
//template<typename Key, typename Value>
//class BST
//{
//private:
//	struct Node {
//		Key key;
//		Value val;
//		Node* left;
//		Node* right;
//
//		Node(Key key, Value val)
//		{
//			this->key = key;
//			this->val = val;
//			this->left = this->right = NULL;
//		}
//	};
//	int count;
//	Node* root;
//
//	Node* Insert(Node* node, Key key, Value val)
//	{
//		if (node == NULL)
//		{
//			count++;
//			return new Node(key, val);
//		}
//
//		if (node->key == key)
//			node->val = val;
//		else if (key < node->key)
//			node->left = Insert(node->left, key, val);
//		else if (key > node->key)
//			node->right = Insert(node->right, key, val);
//
//		return node;
//	}
//
//	void destory(Node* node)
//	{
//		if (node != NULL)
//		{
//			destory(node->left);
//			destroy(node->right);
//
//			delete node;
//			count--;
//		}
//	}
//
//	bool Contain(Node* node, Key key)
//	{
//		if (node == NULL)
//			return false;
//		else if (node->key == key)
//			return true;
//		else if (key < node->key)
//			return Contain(node->key, key);
//		else
//			return Contain(node->right, key);
//	}
//
//	Value* search(Node* node, Key key)
//	{
//		if (node == NULL)
//			return NULL;
//		if (node->key == key)
//			return &(node->val);
//		else if (key < node->key)
//			return search(node->left, key);
//		else if (key > node->key)
//			return search(node->right, key);
//	}
//
//	void PreOrder(Node* node)
//	{
//		if (node != NULL)
//		{
//			cout << node->val << " ";
//			PreOrder(node->left);
//			PreOrder(node->right);
//		}
//	}
//
//	void InOrder(Node* node)
//	{
//		if (node != NULL)
//		{
//			InOrder(node->left);
//			cout << node->val << " ";
//			InOrder(node->right);
//		}
//	}
//
//	void PostOrder(Node* node)
//	{
//		if (node != NULL)
//		{
//			PostOrder(node->left);
//			PostOrder(node->right);
//			cout << node->val << " ";
//		}
//	}
//
//	Node* RemoveMin(Node* node)
//	{
//		if (node->left == NULL)
//		{
//			Node* tmp = node->right;
//			delete node;
//			count--;
//			return tmp;
//		}
//
//		node->left = RemoveMin(node->left);
//		return node;
//	}
//
//	Node* RemoveMax(Node* node)
//	{
//		if (node->right == NULL)
//		{
//			Node* tmp = node->left;
//			delete node;
//			count--;
//			return tmp;
//		}
//
//		node->right = RemoveMax(node->right);
//		return node;
//	}
//
//public:
//	BST()
//	{
//		root = NULL;
//		count = 0;
//	}
//	~BST()
//	{
//		destroy(this->root);
//	}
//
//	int GetSize()
//	{
//		return count;
//	}
//
//	bool IsEmpty()
//	{
//		return 0 == count;
//	}
//
//	void Insert(Key key, Value val)
//	{
//		root = Insert(root, key, val);
//	}
//
//	bool Contain(Key key)
//	{
//		return Contain(root, key);
//	}
//
//	Value* search(Key key)
//	{
//		return search(root, key);
//	}
//
//	void PreOrder()
//	{
//		PerOrder(node);
//	}
//
//	void InOrder()
//	{
//		InOrder(node);
//	}
//
//	void PostOrder()
//	{
//		PostOrder(node);
//	}
//
//	void LevelOrder()
//	{
//		queue<Node*> q;
//		q.push(root);
//		while (!q.empty())
//		{
//			Node* node = q.front();
//			q.pop();
//
//			cout << node->key << endl;
//
//			if (node->left != NULL)
//				q.push(node->left);
//			if (node->right != NULL)
//				q.push(node->right);
//		}
//	}
//
//	void RemoveMin()
//	{
//		if (root != NULL)
//		{
//			root = RemoveMin(root);
//		}
//	}
//
//	void RemoveMax()
//	{
//		if (root != NULL)
//		{
//			root = RemoveMax(root);
//		}
//	}
//};
//
//int main()
//{
//	BST<int,int> bst;
//	bst.Insert(1, 2);
//	bst.Insert(3, 4);
//	bst.Insert(5, 6);
//	return 0;
//}