#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> quickSort(vector<int> arr, int l ,int r)
{
	if(l < r)
	{
		int i = l;
		int j = r;
		int x = arr[l];
		while(i < j)
		{
			while(i < j && arr[j] >= x)j--;
			if(i < j)arr[i++] = arr[j];
			while(i < j && arr[i] <= x)i++;
			if(i < j)arr[j--] = arr[i]; 
		}
		arr[i] = x;
		arr = quickSort(arr,l,i-1);
		arr = quickSort(arr,i+1,r);
	}
	return arr;
}

int main()
{
	int num[] = {8,3,1,5,9,4,2,45,7,22,23,6,-1};
	int size = sizeof(num)/sizeof(num[0]);
	vector<int> arr1(num,num+size);
	vector<int> arr2;
	arr2 = quickSort(arr1,0,arr1.size()-1);
	for_each(arr2.begin(),arr2.end(),[](int a){cout<< a <<" ";});
	cout<<endl;
	return 0;
}

