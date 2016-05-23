#include<iostream>
#include <iomanip>
#include<algorithm>
#include<vector>
#include <stdlib.h>
using namespace std;

vector<vector<int>> showHelixMatrix(int layer)  //打印由内向外的矩阵，layer矩阵阶数
{
    if(layer<1)layer=1;
    layer = layer / 2 * 2 + 1;
    int num = (layer - 1)/2;
    vector<int> temp(layer,0);
	vector<vector<int>> arr(layer,temp);
    for(int i=1; i <= num+1; i++)
    {
        int leftUpCorner = i*i + (i-1)*(i-1);
        int current_layer = i*2-1;
        for(int j=0;j<current_layer;j++)
        {
            arr[i-1-j+num][i-1+num] = leftUpCorner-j;
            arr[1-i+j+num][1-i+num] = leftUpCorner-j;
        }
        for(int k=0;k<current_layer-2;k++)
        {
            arr[1-i+num][i-2-k+num] = leftUpCorner-current_layer-k;
            arr[i-1+num][2-i+k+num] = leftUpCorner-current_layer-k;
        }
    }
    return arr;
}

int main()
{
	vector<vector<int>> arr;
    arr=showHelixMatrix(5);
	for_each(arr.begin(),arr.end(),[](vector<int> arr2){
        for_each(arr2.begin(),arr2.end(),[](int num){
            cout<<setw(2)<<num<<" ";
        });
        cout<<endl;
    });
    
	return 0;
}
