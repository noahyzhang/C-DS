#include<iostream>
#include<algorithm>
#include<cassert>
#include<ctime>

using namespace std;

template<typename Item>
class MaxHeap {
private:
	Item* data;
	int count;
	int capacity;
	void ShiftUp(int k)
	{
		while (k > 0 &&data[k] > data[(k - 1) / 2])
		{
			swap(data[k], data[(k - 1) / 2]);
			k = (k - 1) / 2;
		}
	}

	void ShiftDown(int k)
	{
		while (k * 2 + 1 < count)
		{
			int  j = k * 2 + 1;
			if (k * 2 + 2 <= count && data[k * 2 + 2] > data[k * 2 + 1])
				j += 1;
			if (data[k] >= data[j])
				break;
			swap(data[k], data[j]);
			k = j;
		}
	}

	void AddCapacity()
	{
		int NewCapacity = this->capacity * 2 + 5;
		Item* newdata = new Item[NewCapacity];
		for (int i = 0; i <= this->capacity; ++i)
		{
			newdata[i] = data[i];
		}
		delete[] data;
		this->data = newdata;
		this->capacity = NewCapacity;
	}
	
public:
	MaxHeap()
	{
		data = new Item[10];
		count = 0;
		this->capacity = 10;
	}

	MaxHeap(Item arr[], int n)
	{
		this->data = new Item[n+1];
		this->capacity = n + 1;
		for (int i = 0; i < n; i++)
		{
			data[i] = arr[i];
		}
		count = n;
		for (int i = (count - 1) / 2; i >= 0; i--)
		{
			ShiftDown(i);
		}
	}

	~MaxHeap()
	{
		delete[] data;
	}

	int SizeHeap()
	{
		return count;
	}
	bool EmptyHeap()
	{
		return count == 0;
	}
	void InsertHeap(Item num)
	{
		if (count + 1 >= capacity)
		{
			AddCapacity();
		}
		data[count] = num;
		ShiftUp(count);
		count++;
	}
	Item GetMax()
	{
		int ret = data[0];
		data[0] = data[--count];
		ShiftDown(0);
		return ret;
	}
	void PrintHeap()
	{
		for(int i = 0;i<count; ++i)
			cout << data[i] << " ";	
		cout << endl;
	}
};

//int main()
//{
//	srand(time(NULL));
//	//MaxHeap<int> heap;
//
//	//for (int i = 0; i < 20; i++)
//	//{
//	//	heap.InsertHeap(rand() % 100);
//	//}
//	//heap.PrintHeap();
//	//for (int i = 0; i < 20; i++)
//	//	cout << heap.GetMax() << endl;
//	//heap.PrintHeap();
//
//	int* arr = new int[20];
//	for (int i = 0; i < 20; i++)
//	{
//		arr[i] = rand() % 100;
//	}
//
//	MaxHeap<int> heap = MaxHeap<int>(arr, 20);
//	for (int i = 0; i < 20; ++i)
//	{
//		arr[i] = heap.GetMax();
//	}
//	for (int i = 19; i >= 0; i--)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//	return 0;
//}

//template<typename T>
//void __ShiftDown(T arr[], int n, int k)
//{
//	while (k * 2 + 1 < n)
//	{
//		int j = k * 2 + 1;
//		if (k * 2 + 2 < n && arr[k * 2 + 2] > arr[k * 2 + 1])
//			j += 1;
//		if (arr[k] > arr[j]) break;
//		swap(arr[k], arr[j]);
//		k = j;
//	}
//}
//
//
//template<typename T>
//void HeapSort(T arr[], int n)
//{
//	for (int i = (n - 1) / 2; i >= 0; i--)
//		__ShiftDown(arr, n, i);
//
//	for (int i = n - 1; i > 0; i--)
//	{
//		swap(arr[0], arr[i]);
//		__ShiftDown(arr, i, 0);
//	}
//}
//
//int main()
//{
//	int arr[] = { 1,3,5,7,9,2,4,6,8,10 };
//	HeapSort(arr, 10);
//	for (int i = 0; i < 10; i++)
//		cout << arr[i] << " ";
//	cout << endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//class D {
//	int d;
//public:
//	D(int x = 1) :d(x) {}
//	~D() { cout << "D"; }
//};
//int main() {
//	D d[] = { 3,3,3};
//	D* p = new D[2];
//	delete[]p;
//	return 0;
//}

//#include<vector>
//#include<queue>
// class Solution
// { public: 
//	 vector<int> maxSlidingWindow(vector<int>& nums, int k) 
//	 { 
//		 vector<int>array;
//		 priority_queue<pair<int, int> >q;
//		 for (int i = 0; i < k - 1; i++)
//			 q.push(make_pair(nums[i], i)); 
//
//		 for (int i = k - 1; i < nums.size(); i++) 
//		 { 
//			 q.push(make_pair(nums[i], i));
//			 while (q.top().second < (i - k + 1))
//				 q.pop(); 
//			array.push_back(q.top().first);
//		 } 
//	 return array;
//	 } 
// };