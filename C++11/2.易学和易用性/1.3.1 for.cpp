#include<iostream>
using namespace std;
#include<vector>

int main()
{
    vector<int> v{1,2,3,4,4,4};//初始化列表,进行赋值
    for(auto i:v)
    cout<<i<<" ";
    cout<<endl;

    cout<<"######修改元素######"<<endl;
    for(auto&i:v)//只运行一次，i是v中元素的引用，修改i就是修改v中元素的值
    {
        if(i==4)
        i=0;
    }
    for(auto i:v)
    cout<<i<<" ";
    cout<<endl;

    return 0;
}