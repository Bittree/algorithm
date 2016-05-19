#include<iostream>
#include <iomanip>
#include<algorithm>
#include<vector>
using namespace std;

vector<vector<int>> showHelixMatrix(int layer)  //layer矩阵阶数
{
    int x,y;
    x = y = (layer - 1)/2;
    vector<int> temp(layer,0);
	vector<vector<int>> arr(layer,temp);
    for(int value = 1;value <= layer * layer;value++)
    {
        if(x>=y && x>layer-y-1)
        {
            arr[x][y]=value;
            y--;
        }
        else if(x>y && x<=layer-y-1)
        {
            arr[x][y]=value;
            x--;
        }
        else if(x<y && x>layer-y-1)
        {
            arr[x][y]=value;
            x++;
        }
        else if(x<=y && x<=layer-y-1)
        {
            arr[x][y]=value;
            y++;
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
