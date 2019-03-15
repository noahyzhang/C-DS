//#include<iostream>
//
//using namespace std;
//
//int GetNum(int arr[], int n)
//{
//	int num = 0;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = i + 1; j < n; j++)
//		{
//			if (arr[i] > arr[j])
//				num++;
//		}
//	}
//	return num;
//}
//
//static int num = 0;
//
//void __Merge(int arr[], int l, int mid, int r)  
//{
//	int* aux = new int[r+1];
//	for (int i = l; i <= r; ++i)
//	{
//		aux[i - l] = arr[i];
//	}
//	
//	int i = l, j = mid + 1;
//	for (int k = l; k <= r; ++k)
//	{
//		if (i > mid)
//		{
//			arr[k] = aux[j-l];
//			j++;
//		}
//		else if (j > r)
//		{
//			arr[k] = aux[i-l];
//			i++;
//		}
//		else if (aux[i-l] <= aux[j-l])
//		{
//			arr[k] = aux[i-l];
//			i++;
//		}
//		else if (aux[i-l] > aux[j-l])
//		{
//			arr[k] = aux[j-l];
//			j++;
//			num += (mid-i+1);
//		}
//	}
//	delete [] aux;
//}
//
//void __MergeSort(int arr[],int l, int r)
//{
//	if (l >= r)
//		return;
//	int mid = ((r - l) >> 1) + l;
//	__MergeSort(arr, l, mid);
//	__MergeSort(arr, mid + 1, r);
//	__Merge(arr, l, mid, r);
//}
//
//void GetNum2(int arr[], int n)
//{
//	__MergeSort(arr, 0,n-1);
//}
//
//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6,7,8,9 ,10};
//	int arr2[] = { 10,9,8,7,6,5,4,3,2,1 };
//	int testarr[] = { 3,2,1 };
//	//int num = GetNum(testarr,3);
//	GetNum2(arr2,10);
//	cout << num << endl;
//	return 0;
//}
