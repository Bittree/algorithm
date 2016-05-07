#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> insertSort(vector<int> arr)
{
        int size = arr.size();
        for(int i = 1; i < size;i++)
        {
                int target = arr[i];
                int j = 0;
                for(j = i; j > 0 && arr[j-1] >target; j--)
                {
                        arr[j] = arr[j-1];
                }
                arr[j] = target;
        }
        return arr;
}

int main()
{
        int num[] = {8,3,1,5,9,4,2};
        vector<int> arr1(num,num+7);
        vector<int> arr2;
        arr2 = insertSort(arr1);
        for_each(arr2.begin(),arr2.end(),[](int a){cout<< a <<" ";});
        cout<<endl;
        return 0;
}

