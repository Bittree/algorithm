#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> selectSort(vector<int> arr)
{
        int size = arr.size();
        int temp = 0;
        for(int i = 0;i < size;i++)
        {
            int k = i;
            for(int j = i + 1; j < size; j++)
            {
                if(arr[j] < arr[k])
                {
                    k = j;
                }
            }
            if(i != k)
            {
                temp = arr[i];
                arr[i] = arr[k];
                arr[k] = temp;
            }
        }
        return arr;
}

int main()
{
	int num[] = {8,3,1,5,9,4,2,45,7,22,23,6,-1};
	int size = sizeof(num)/sizeof(num[0]);
	vector<int> arr1(num,num+size);
	vector<int> arr2;
	arr2 = selectSort(arr1);
	for_each(arr2.begin(),arr2.end(),[](int a){cout<< a <<" ";});
	cout<<endl;
	return 0;
}
