#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> shellSort(vector<int> arr)
{
	int size = arr.size();
    for(int gap = size/2; gap > 0;gap/=2)
    {
        for(int i = 0; i < gap; i++)
        {
            for(int j = i + gap; j < size;j += gap)
            {
                if(arr[j-gap] > arr[j])
                {
                    int temp = arr[j];
                    int k = j - gap;
                    while(k >= 0 && arr[k] > temp)
                    {
                        arr[k + gap] = arr[k];
                        k -= gap;
                    }
                    arr[k + gap] = temp;
                }
            }
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
	arr2 = shellSort(arr1);
	for_each(arr2.begin(),arr2.end(),[](int a){cout<< a <<" ";});
	cout<<endl;
	return 0;
}

