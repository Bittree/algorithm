#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> mergeArray(vector<int> arr, int first,int mid,int last)
{
        int l = first;
        int r = last;
        int ml = mid;
        int mr = mid+1;
        int k = l;
        vector<int> temp = arr;
        while(l <= ml && mr <= r)
        {
            if(arr[l] > arr[mr])temp[k++] = arr[mr++];
            else temp[k++] = arr[l++];
        }
        while(l <= ml)temp[k++] = arr[l++];
        while(mr <= r)temp[k++] = arr[mr++];
        return temp;
}

vector<int> mergeSort(vector<int> arr,int first,int last)
{
    if(first < last)
    {
        int mid = (first + last)/2;
        arr = mergeSort(arr,first,mid);
        arr = mergeSort(arr,mid+1,last);
        arr = mergeArray(arr, first, mid, last);
    }
    return arr;
}

int main()
{
	int num[] = {8,3,1,5,9,4,2,45,7,22,23,6,-1};
	int size = sizeof(num)/sizeof(num[0]);
	vector<int> arr1(num,num+size);
	vector<int> arr2;
	arr2 = mergeSort(arr1,0,arr1.size()-1);
	for_each(arr2.begin(),arr2.end(),[](int a){cout<< a <<" ";});
	cout<<endl;
	return 0;
}
