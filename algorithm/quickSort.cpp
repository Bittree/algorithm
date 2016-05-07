#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> quickSort(vector<int> arr, int l ,int r)
{
	
}

int main()
{
	int num[] = {8,3,1,5,9,4,2};
	vector<int> arr1(num,num+7);
	vector<int> arr2;
	arr2 = quickSort(arr1);
	for_each(arr2.begin(),arr2.end(),[](int a){cout<< a <<" ";});
	cout<<endl;
	return 0;
}

