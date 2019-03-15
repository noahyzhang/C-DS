//#include<iostream>
//
//using namespace std;
//
//class BST {
//private:
//	struct Node
//	{
//		int val;
//		Node* left;
//		Node* right;
//
//		Node(int val)
//		{
//			this->val = val;
//			this->left = this->right = NULL;
//		}
//	};
//
//	Node* root;
//	int count;
//public:
//	BST()
//	{
//		root = NULL;
//		count = 0;
//	}
//	~BST()
//	{
//		
//	}
//
//	bool IsEmpty();
//	int Size();
//	void Insert(int num);
//	void PreOrder(Node* node);
//	void InOrder(Node* node);
//	void PostOrder(Node* node);
//	void PreOrder();
//	void InOrder();
//	void PostOrder();
//	Node* Search(int num);
//	void DeleteNode(int num);
//};
//
//bool BST::IsEmpty()
//{
//	return 0 == count;
//}
//
//int BST::Size()
//{
//	return count;
//}
//
//void BST::Insert(int num)
//{
//	Node* temp = this->root;
//	if (this->root == NULL)
//	{
//		this->root = new Node(num);
//		count++;
//	}
//	else
//	{
//		Node* node = new Node(num);
//		Node* PreTemp = NULL;
//		while (temp != NULL)
//		{
//			PreTemp = temp;
//			if (num < temp->val)
//			{
//				temp = temp->left;
//			}
//			else if (num > temp->val)
//			{
//				temp = temp->right;
//			}
//			else if (num == temp->val)
//				break;
//		}
//		if (temp == NULL && num < PreTemp->val)
//		{
//			PreTemp->left = node;
//		}
//		else if (temp == NULL && num > PreTemp->val)
//		{
//			PreTemp->right = node;
//		}
//	}
//}
//
//void BST::PreOrder(Node* node)
//{
//	if (node != NULL)
//	{
//		cout << node->val << " ";
//		PreOrder(node->left);
//		PreOrder(node->right);
//	}
//}
//
//void BST::InOrder(Node* node)
//{
//	if (node != NULL)
//	{
//		InOrder(node->left);
//		cout << node->val << " ";
//		InOrder(node->right);
//	}
//}
//
//void BST::PostOrder(Node* node)
//{
//	if (node != NULL)
//	{
//		PostOrder(node->left);
//		PostOrder(node->right);
//		cout << node->val << " ";
//	}
//}
//
//void BST::PreOrder()
//{
//	BST::PreOrder(this->root);
//	cout << endl;
//}
//
//void BST::InOrder()
//{
//	BST::InOrder(this->root);
//	cout << endl;
//}
//
//void BST::PostOrder()
//{
//	BST::PostOrder(this->root);
//	cout << endl;
//}
//
//BST::Node* BST::Search(int num)
//{
//	Node* temp = this->root;
//	while (temp != NULL)
//	{
//		if (num == temp->val)
//			return temp;
//		else if (num < temp->val)
//			temp = temp->left;
//		else if (num > temp->val)
//			temp = temp->right;
//	}
//	if (temp == NULL)
//		return NULL;
//}
//
//void BST::DeleteNode(int num)
//{
//	Node* temp = this->root;
//	Node* parentNode = this->root;
//	while (temp != NULL)
//	{
//		parentNode = temp;
//		if (num == temp->val)
//			break;
//		else if (num < temp->val)
//			temp = temp->left;
//		else if (num > temp->val)
//			temp = temp->right;
//	}
//	if (temp == NULL)
//		return;
//
//	//先删除只有左子树的结点
//	if (temp->right == NULL)
//	{
//		if (temp == root)
//			root = temp->left;
//		else
//		{
//			if (temp == parentNode->left)
//				parentNode->left = temp->left;
//			else
//				parentNode->right = temp->left;
//		}
//		delete temp;
//	}
//	else if(temp->left == NULL) //再删除只有右子树的结点
//	{
//		if (temp == root)
//			root = temp->right;
//		else
//		{
//			if (temp == parentNode->left)
//				parentNode->left = temp->right;
//			else
//				parentNode->right = temp->right;
//		}
//		delete temp;
//	}
//	else  //再删除左右子树都有的结点
//	{
//		//我们需要找到左子数最大值，或者右子树中最小值
//		//这个例子我们找左子树中最大值
//		Node* replace = temp->left;
//		Node* prereplace = temp;
//		while (replace->right != NULL)
//		{
//			prereplace = replace;
//			replace = replace->right;
//		}
//		temp->val = replace->val;
//		if (replace == prereplace->left)
//			prereplace->left = replace->right;
//		else
//			prereplace->right = replace->right;
//
//		delete replace;
//	}
//}
//
//
//int main()
//{
//	BST *bst = new BST();
//	bst->Insert(3);
//	bst->Insert(3);
//	bst->Insert(5);
//	bst->Insert(7);
//	bst->Insert(2);
//	bst->Insert(4);
//	
//	bst->PreOrder();
//	bst->InOrder();
//	bst->PostOrder();
//
//	bst->DeleteNode(3);
//
//	return 0;
//}