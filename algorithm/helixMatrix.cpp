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

int getValueByCoordinate(int x,int y) //根据x、y坐标返回n阶螺旋矩阵指定位置的值
{
    int layer= max(abs(x),abs(y));
    int rightDownCornerValue = 4*layer*layer - 2*layer + 1;
    int ret = 0;
    if(y == -layer)
    {
        ret = rightDownCornerValue + 4*layer + x + layer;
    }
    else if(x == layer)
    {
        ret = rightDownCornerValue - (layer - y );
    }
    else if(x == -layer)
    {
        ret = rightDownCornerValue + 3 * layer - y;
    }
    else if(y == layer)
    {
        ret = rightDownCornerValue + layer - x;
    }
    
    return ret;
}

vector<vector<int>> showHelixMatrix2(int layer)  //打印由内向外的矩阵，layer矩阵阶数
{
    if (layer < 1)layer = 1;
	layer = layer / 2 * 2 + 1;
	int x, y;
	x = y = (layer - 1) / 2;
	vector<int> temp(layer, 0);
	vector<vector<int>> arr(layer, temp);
	int offset = (layer - 1) / 2;
	for (int value = 1;value <= layer * layer;value++)
	{
		if (x >= y && x > layer - y - 1)
		{
			arr[x][y] = getValueByCoordinate(y - offset, x - offset);
			y--;
		}
		else if (x > y && x <= layer - y - 1)
		{
			arr[x][y] = getValueByCoordinate(y - offset, x - offset);
			x--;
		}
		else if (x<y && x>layer - y - 1)
		{
			arr[x][y] = getValueByCoordinate(y - offset, x - offset);
			x++;
		}
		else if (x <= y && x <= layer - y - 1)
		{
			arr[x][y] = getValueByCoordinate(y - offset, x - offset);
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
    
    cout<<endl;
    
    arr=showHelixMatrix2(5);
    for_each(arr.begin(),arr.end(),[](vector<int> arr2){
        for_each(arr2.begin(),arr2.end(),[](int num){
            cout<<setw(2)<<num<<" ";
        });
        cout<<endl;
    });
    
	return 0;
}
