#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> bubbleSort(vector<int> arr)
{
	int size = arr.size();
	int tmp = 0;
	for(int i = 0; i < size; i++)
	{
		for(int j = size-1; j > i; j--)
		{
			if(arr[j-1] > arr[j])
			{
				tmp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = tmp;
			}
		}
	}
	return arr;
}

vector<int> bubbleSort2(vector<int> arr)
{
	int size = arr.size();
	int tmp = 0;
	int flag = 0;
	for(int i = 0; i < size && flag == 0; i++)
	{
		flag = 1;
		for(int j = size-1; j > i; j--)
		{
			if(arr[j-1] > arr[j])
			{
				flag = 0;
				tmp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = tmp;
			}
		}
	}
	return arr;
}

int main()
{
	int num[] = {8,3,1,5,9,4,2};
	vector<int> arr1(num,num+7);
	vector<int> arr2;
	arr2 = bubbleSort(arr1);
	for_each(arr2.begin(),arr2.end(),[](int a){cout<< a <<" ";});
	cout<<endl;
	
	arr2 = bubbleSort2(arr1);
	for_each(arr2.begin(),arr2.end(),[](int a){cout<< a <<" ";});
	cout<<endl;
	return 0;
}

