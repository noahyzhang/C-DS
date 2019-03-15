//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//
//void InsertSort(int arr[], int l, int r)
//{
//	for (int i = l+1; i <= r; ++i)
//	{
//		int e = arr[i];
//		int j = i;
//		for (j = i; j > l && arr[j-1] > e; --j)
//		{
//			arr[j] = arr[j - 1];
//		}
//		arr[j] = e;
//	}
//}
//
//void __Merge(int arr[], int l, int mid, int r)
//{
//	int aux[100];
//	for (int i = l; i <= r; ++i)
//	{
//		aux[i-l] = arr[i];
//	}
//	int i = l, j = mid + 1;
//	for (int k = l; k <= r; ++k)
//	{
//		if (i > mid)
//		{
//			arr[k] = aux[j - l];
//			j++;
//		}
//		else if (j > r)
//		{
//			arr[k] = aux[i - l];
//			i++;
//		}
//		else if (aux[i - l] > aux[j - l])
//		{
//			arr[k] = aux[j - l];
//			j++;
//		}
//		else if (aux[i - l] < aux[j - l])
//		{
//			arr[k] = aux[i - l];
//			i++;
//		}
//	}
//}
//
//void __MergeSort(int arr[], int l, int r)
//{
//	//if (l >= r)
//	//	return;  //�ڶ����Ż�
//	if (r - l <= 15)
//	{
//		InsertSort(arr, l, r);
//		return;
//	}
//
//	int mid = l + ((r - l) >> 1);   //���һ��Ҫע�⣺l + r >> 1 �Ǵ�ġ�  l + (r-l)>>1 Ҳ�Ǵ�ģ����ȼ�������
//	__MergeSort(arr, l, mid);
//	__MergeSort(arr, mid + 1, r);
//	if(arr[mid] > arr[mid+1])   //��һ���Ż�
//		__Merge(arr, l, mid, r);
//}
//
//void MergeSort(int arr[], int n)  //�Զ����µĹ鲢����
//{
//	__MergeSort(arr, 0, n - 1);
//}
//
//void MergeSort2(int arr[], int n)  //�Ե����ϵĹ鲢���� û��ʹ��������±����������������
//{
//	for (int sz = 1; sz < n; sz *= 2)
//	{
//		for (int i = 0; i+sz < n; i += 2 * sz)
//		{
//			__Merge(arr, i, i + sz - 1, min(n-1,i + 2 * sz - 1));	
//		}
//	}
//}
//
//void PrintArr(int arr[], int n)
//{
//	for (int i = 0; i < n; ++i)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//}
//
//int main()
//{
//	int arr[11] = { 1,3,5,7,9,2,4,6,8,10 };
//	//MergeSort(arr, 10);
//	//InsertSort(arr, 0, 9);
//	MergeSort2(arr, 10);
//	PrintArr(arr, 10);
//	return 0;
//}