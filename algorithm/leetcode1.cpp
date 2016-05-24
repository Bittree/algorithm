/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) 
{
    int size = nums.size();
    vector<int> ret(2,0);
    for(int i=0; i<size-1; i++) {
        for(int j=i+1; j<size; j++){
            if(nums[i] + nums[j] == target)
            {
                ret[0] = i;
                ret[1] = j;
            }
        }
    }
    return ret;
}

int main()
{
    int num[] = {8,3,1,5,9,4,2};
    vector<int> arr1(num,num+7);
    vector<int> arr2;
    arr2 = twoSum(arr1,10);
    for_each(arr2.begin(),arr2.end(),[](int a){cout<< a <<" ";});
    cout<<endl;
    return 0;
}