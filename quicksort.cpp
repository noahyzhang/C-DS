//#include<iostream>
//#include<algorithm>
//#include<ctime>
//
//using namespace std;
//
//void InsertSort(int arr[], int n)
//{
//	for (int i = 1; i < n; ++i)
//	{
//		int e = arr[i];
//		int j;
//		for (j = i; j > 0 && arr[j - 1] > e; --j)
//		{
//			arr[j] = arr[j-1];
//		}
//		arr[j] = e;
//	}
//}
//
//int __Partion(int arr[], int l, int r)
//{
//
//	swap(arr[l], arr[rand() % (r - l + 1) + l]);
//	int m = arr[l];
//	int j = l;  
//	for (int i = l+1;i <= r; ++i)
//	{
//		if (arr[i] < m)
//			swap(arr[++j], arr[i]);
//	}
//	swap(arr[l], arr[j]);
//	return j;
//}
//
//
//void __QuickSort(int arr[], int l, int r)
//{
//	if (l >= r)
//		return;
//	int p = __Partion(arr, l, r);
//	__QuickSort(arr, l, p - 1);
//	__QuickSort(arr, p + 1, r);
//}
//
//void QuickSort(int arr[], int n)  //一般快排
//{
//	srand(time(NULL));
//	if (n <= 15)
//		InsertSort(arr, n);
//	__QuickSort(arr, 0, n-1);
//}
//
//int __Partion2(int arr[], int l, int r)
//{
//	swap(arr[l], arr[rand() % (r - l + 1) + l]);
//	int e = arr[l];
//	int i = l + 1, j = r;
//	while (true)
//	{
//		while (i <= r && arr[i] <= e) i++;
//		while (j >= l+1 && arr[j] >= e) j--;
//		if (i > j) break;
//		swap(arr[i], arr[j]);
//		i++;
//		j--;
//	}
//	swap(arr[l], arr[j]);
//	return j;
//}
//
//void __QuickSort2(int arr[], int l, int r)
//{
//	if (l >= r)
//		return;
//	int  p = __Partion2(arr, l, r);
//	__QuickSort2(arr, l, p - 1);
//	__QuickSort2(arr, p + 1, r);
//}
//
//void QuickSort2(int arr[],int n)  //对于重复元素的防止方法
//{	
//	srand(time(NULL));
//	__QuickSort2(arr, 0, n - 1);
//}
//
//void __QuickSort3Way(int arr[], int l, int r)
//{
//	if (l >= r)
//		return;
//
//	swap(arr[l], arr[rand() % (r - l + 1) + l]);
//	int e = arr[l];
//	//[l+1,lt] [lt+1,i] [gt,r}
//	int lt = l;
//	int gt = r + 1;
//	int i = l + 1;
//	while (i < gt)
//	{
//		if (arr[i] < e)
//		{
//			swap(arr[i], arr[lt + 1]);
//			i++;
//			lt++;
//		}
//		else if (arr[i] > e)
//		{
//			swap(arr[i], arr[gt - 1]);
//			gt--;
//		}
//		else
//			i++;
//	}
//	swap(arr[l], arr[lt]);
//
//	__QuickSort3Way(arr, l, lt - 1);
//	__QuickSort3Way(arr, gt, r);
//}
//
//void QuickSort3Way(int arr[], int n)  //增添三个分组（< = >）
//{
//	srand(time(NULL));
//	__QuickSort3Way(arr, 0,n - 1);
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
//	int arr[21] = { 1,3,5,7,9,2,4,6,8,10,1,2,3,4,5,6,7,8,9,10 };
//	//QuickSort(arr, 10);
//	//QuickSort2(arr, 20);
//	QuickSort3Way(arr, 20);
//	PrintArr(arr, 20);
//	return 0;
//}