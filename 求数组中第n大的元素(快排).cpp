//#include<iostream>
//#include<ctime>
//using namespace std;
//
//static int res = 0;
//void __QuickSort(int arr[], int l,int r,int num)
//{
//	if (l >= r)
//		return;
//	swap(arr[l], arr[rand() % (r - l + 1) + l]);
//	int e = arr[l];
//	//[l + 1, lt] [lt + 1, i] [gt, r]
//	int i = l + 1;
//	int lt = l;
//	int gt = r + 1;
//	while (i < gt)
//	{
//		if (arr[i] < e)
//		{
//			swap(arr[i], arr[lt+1]);
//			lt++;
//			i++;
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
//	if ( num >= lt + 1 && num <= gt)
//	{
//		res = arr[lt];
//		return;
//	}
//	if (num < lt)
//	{
//		__QuickSort(arr, l, lt - 1, num);
//	}
//	if (num > lt)
//		__QuickSort(arr, gt, r, num);
//
//}
//
//void QuickSort(int arr[], int n, int num) 
//{
//	srand(time(NULL));
//	__QuickSort(arr,0, n - 1, num);
//}
//
//int main()
//{
//	int arr[] = { 7,3,5,7,9,2,4,6,8,10 };
//	int testarr[] = { 5,6,7 };
//	QuickSort(arr, 10, 7);
//	cout << res << endl;
//	return 0;
//}