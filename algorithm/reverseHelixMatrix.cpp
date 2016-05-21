#include<iostream>
#include <iomanip>
#include<algorithm>
#include<vector>
#include <stdlib.h>
using namespace std;

vector<vector<int>> showHelixMatrix(int row,int col)  //打印由外向内的row*col矩阵
{
    if(col<1)col=1;
    if(row<1)row=1;
    int x,y,value;
    x = y = value = 0;
    vector<int> temp(col,0);
	vector<vector<int>> arr(row,temp);
    int minNum = col < row? col : row;
    int layer = minNum/2;
    for(int i = 0;i < layer;i++)
    {
        int colMaxIndex = col - 1 - i;
        int rowMaxIndex = row - 1 - i;
        for(int j=i;j<colMaxIndex;j++)arr[i][j] = ++value;
        for(int j=i;j<rowMaxIndex;j++)arr[j][colMaxIndex] = ++value;
        for(int j=colMaxIndex;j>i;j--)arr[rowMaxIndex][j] = ++value;
        for(int j=rowMaxIndex;j>i;j--)arr[j][i] = ++value;
    }
    
    if(minNum%2 == 1)
    {
        if(row <= col)for(int k = layer; k < col-layer;  k++)arr[layer][k] = ++value;
        else for(int k = layer; k < row-layer; k++)arr[k][layer] = ++value;
    }
    return arr;
}

int getValueByCoordinate(int row,int col,int x,int y) //根据x、y坐标返回row*col螺旋矩阵指定位置的值
{
    if(row < 1 || col < 1 || x < 0 || y < 0)return -1;
    int minNum = min(min(x,y),min(row-1-x,col-1-y));
    int distance = x + y - 2*minNum;
    int startValue = 2*minNum*(row+col-2*minNum)+1;//row*col - (row-2*minNum)*(col-2*minNum);
    if(x == minNum || y == col-1-minNum || (col < row && minNum*2+1 == col))
        return startValue + distance;
    else
        return startValue + (row + col - 4*minNum -2)*2 - distance;
}

vector<vector<int>> showHelixMatrix2(int row,int col)  //打印由内向外的矩阵，layer矩阵阶数
{
    if(col<1)col=1;
    if(row<1)row=1;
    int x,y;
    x = y = 0;
    vector<int> temp(col,0);
	vector<vector<int>> arr(row,temp);
    int minNum = col < row? col : row;
    int layer = minNum/2;
    for(int i = 0;i < layer;i++)
    {
        int colMaxIndex = col - 1 - i;
        int rowMaxIndex = row - 1 - i;
        for(int j=i;j<colMaxIndex;j++)arr[i][j] = getValueByCoordinate(row, col, i, j);
        for(int j=i;j<rowMaxIndex;j++)arr[j][colMaxIndex] = getValueByCoordinate(row, col, j, colMaxIndex);
        for(int j=colMaxIndex;j>i;j--)arr[rowMaxIndex][j] = getValueByCoordinate(row, col, rowMaxIndex, j);
        for(int j=rowMaxIndex;j>i;j--)arr[j][i] = getValueByCoordinate(row, col, j, i);
    }
    
    if(minNum%2 == 1)
    {
        if(row <= col)for(int k = layer; k < col-layer;  k++)arr[layer][k] = getValueByCoordinate(row, col, layer, k);
        else for(int k = layer; k < row-layer; k++)arr[k][layer] = getValueByCoordinate(row, col, k, layer);
    }
    return arr;
}

int main()
{
	vector<vector<int>> arr;
    arr=showHelixMatrix(7,5);
	for_each(arr.begin(),arr.end(),[](vector<int> arr2){
        for_each(arr2.begin(),arr2.end(),[](int num){
            cout<<setw(2)<<num<<" ";
        });
        cout<<endl;
    });
    
    cout<<endl;
    
    arr=showHelixMatrix2(7,5);
    for_each(arr.begin(),arr.end(),[](vector<int> arr2){
        for_each(arr2.begin(),arr2.end(),[](int num){
            cout<<setw(2)<<num<<" ";
        });
        cout<<endl;
    });
    
	return 0;
}
