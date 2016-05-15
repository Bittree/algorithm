#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class MaxHeap
{
public:
    MaxHeap(vector<int>);
    void insert(int);
    void remove(void);
    void makeHeap(void);
    void nodeDown(int index,int length);
    vector<int> heapSort();
    vector<int> heapArray(void);
private:
    vector<int> data; 
};

MaxHeap::MaxHeap(vector<int> arr)
{
    data = arr;
}

void MaxHeap::insert(int val)
{
    data.push_back(val);
    int child = data.size() - 1;
    int parent = (child - 1)/2;
    while(parent >= 0 && child != 0)
    {
        if(data[parent] >= val)break;
        
        data[child] = data[parent];
        child = parent;
        parent = (child - 1)/2;
    }
    data[child] = val;
    
}

void MaxHeap::remove(void)
{
    int temp = data[0];
    int size = data.size();
    data[0]=data[size-1];
    data.pop_back();
    nodeDown(0,size-1);
}

void MaxHeap::makeHeap(void)
{
    int size = data.size();
    for(int i= (size-2)/2; i >= 0;i--)nodeDown(i, size);
}

void MaxHeap::nodeDown(int index,int length)
{
    int temp = data[index];
    int parent = index;
    int left_child = parent * 2 + 1;
    temp = data[parent];
    while(left_child < length)
    {
        if(left_child + 1 < length && data[left_child] < data[left_child + 1])left_child++;
        
        if(data[left_child] < temp)break;
        
        data[parent] = data[left_child];
        parent = left_child;
        left_child = parent * 2 + 1;
    }
    data[parent] = temp;
}

vector<int> MaxHeap::heapArray(void)
{
    return data;
}

vector<int> MaxHeap::heapSort()
{
    int size = data.size();
    makeHeap();
    for(int i = size-1; i > 0;i--)
    {
        int temp = data[i];
        data[i] = data[0];
        data[0] = temp;
        
        nodeDown(0, i);    
    }
    return data;
}

int main()
{
	int num[] = {8,3,1,5,9,4,2,45,7,22,23,6,-1};
	int size = sizeof(num)/sizeof(num[0]);
	vector<int> arr1(num,num+size);
	vector<int> arr2;
    
    MaxHeap *heap = new MaxHeap(arr1);
    if(!heap)return 0;
    
	arr2 = heap->heapSort();
	for_each(arr2.begin(),arr2.end(),[](int a){cout<< a <<" ";});
	cout<<endl;
    delete heap;
	return 0;
}
