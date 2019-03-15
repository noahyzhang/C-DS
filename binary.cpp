//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//
//int res = -2;
//
//template<typename T>
//void __BinarySeach(T arr[], int l, int r, int target)
//{
//	if (l >= r)
//	{
//		if(res == -2)
//			res = -1;
//		return;
//	}
//	int mid = l + ((r - l) >> 1);
//	if (arr[mid] == target)
//	{
//		res = mid;
//		return;
//	}
//	__BinarySeach(arr, l, mid - 1, target);
//	__BinarySeach(arr, mid + 1, r,target);
//}
//
//template<typename T>
//void BinarySeach(T arr[], int n, int target)
//{
//	__BinarySeach(arr, 0, n-1,target);
//}
//
//int main()
//{
//	int arr[] = { 2,3,4,5,6,7,8,9,10 };
//	BinarySeach(arr, 9, 4);
//	cout << res << endl;
//	return 0;
//}
