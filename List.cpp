//#include<iostream>
//#include<ctime>
//#include<algorithm>
//#include<assert.h>
//#include<string>
//#include"Student.h"
//
//using namespace std;
//
//namespace SortTestHelp {
//	int* SortTestHelp(int n, int arrL, int arrR)
//	{
//
//		srand(time(NULL));
//		int *arr = new int[n];
//		for (int i = 0; i < n; i++)
//			arr[i] = rand() % (arrR - arrL + 1) + arrL;
//		return arr;
//	}
//
//	template<typename T>
//	void PrintArray(T arr[], int n)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			cout << arr[i] << " ";
//		}
//		cout << endl;
//	}
//
//	template<typename T>
//	void SelectionArray(T arr[], int n)
//	{
//		int i, j;
//		for (i = 0; i < n; i++)
//		{
//			int MinIndex = i;
//			for (j = i + 1; j < n; j++)
//			{
//				if (arr[j] < arr[MinIndex])
//					MinIndex = j;
//			}
//			swap(arr[i], arr[MinIndex]);
//		}
//	}
//
//	template<typename T>
//	void CalculationTime(string sortName, void(*sort)(T[], int), T arr[], int n)
//	{
//		clock_t startTime = clock();
//		sort(arr, n);
//		clock_t endTime = clock();
//
//		cout << sortName << ":" << double(endTime - startTime) / CLOCKS_PER_SEC << "s";
//	}
//
//	template<typename T>
//	void InsertSort(T arr[], int n)
//	{
//		for (int i = 1; i < n; i++)
//		{
//			for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--)
//			{
//				swap(arr[j], arr[j - 1]);
//			}
//		}
//	}
//
//	template<typename T>
//	void InsertSort2(T arr[], int n)
//	{
//		for (int i = 1; i < n; i++)
//		{
//			int j;
//			T e = arr[i];
//			for (j = i; j > 0 && arr[j-1] > e; j--)
//			{
//				arr[j] = arr[j-1];
//			}
//			arr[j] = e;
//		}
//	}
//
//	template<typename T>
//	void ShellSort(T arr[], int n)
//	{
//		int gap = n;
//		while (1)
//		{
//			gap = gap / 3 + 1;
//			for (int i = 1; i < n; ++i)
//			{
//				int j;
//				T e = arr[i];
//				for (j = i - gap; j >= 0 && arr[j] > e; j = j-gap)
//				{
//					arr[j+gap] = arr[j];
//				}
//				arr[j+gap] = e;
//			}	
//			if (gap == 1)
//				break;
//		}
//	}
//}
//
//int main()
//{
//	/*int n = 10000;
//	int* arr = nullptr;
//	arr = SortTestHelp::SortTestHelp(n, 0, n);
//	SortTestHelp::PrintArray(arr, n);*/
//
//	//int arr[] = { 10,9,8,7,6,5,4,3,2,1 };
//	/*string arr[] = { "D","C","B","A" };
//	int n = sizeof(arr) / sizeof(arr[0]);
//	SortTestHelp::SelectionArray(arr, n);
//	SortTestHelp::PrintArray(arr, n);*/
//
//	/*Student st[3] = { {"zhangyi",100},{"haha",99} };
//	SortTestHelp::SelectionArray(st, 2);
//	for (int i = 0; i < 2; i++)
//	{
//		cout << st[i] << endl;
//	}*/
//
//	int n = 10;
//	int* arr = SortTestHelp::SortTestHelp(n, 0, n);
//	SortTestHelp::ShellSort(arr, n);
//	SortTestHelp::PrintArray(arr, n);
//	//SortTestHelp::CalculationTime("selection sort ", SortTestHelp::SelectionArray, arr, n);
//	//SortTestHelp::PrintArray(arr, n);
//	//int arr[] = { 10,9,8,7,6,5,4,3,2,1 };
//	//SortTestHelp::InsertSort(arr, n);
//	//SortTestHelp::PrintArray(arr, n);
//	//SortTestHelp::CalculationTime("Insert sort", SortTestHelp::InsertSort, arr, n);
//	//SortTestHelp::InsertSort2(arr, n);  //插入排序算法对于有序的数组比较快
//	//SortTestHelp::PrintArray(arr, n);
//	return 0;
//}
//
