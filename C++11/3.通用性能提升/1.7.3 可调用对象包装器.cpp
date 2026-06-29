#include<iostream>
using namespace std;
#include<functional>

//function是一个函数对象包装器，可以包装普通函数、成员函数和仿函数对象
//function包装器可以将不同类型的函数包装成一个统一的函数对象，方便调用和传递
void callfunc(int x,const function<void(int)> &f)
{
    if(x%2==0)
    {
        f(x);
    }
}

void output(int x)
{
    cout<<"x="<<x<<endl;
}

void output_add(int x)
{
    cout<<"x+10="<<x+10<<endl;
}

int main()
{   
    // 1.使用bind函数将output函数绑定到一个新的函数对象f上
    // f是一个仿函数对象，可以像普通函数一样调用
    auto f=bind(output,placeholders::_1);
    for(auto i:{1,2,3,4,5,6,7,8,9,10})
    {
        callfunc(i,f); // 调用函数对象f，输出x的值
    }
    // 2.使用bind函数将output_add函数绑定到一个新的函数对象f1上
    auto f1=bind(output_add,placeholders::_1);
    for(auto i:{4,5,6})
    {
        callfunc(i,f1); // 调用函数对象f1，输出x+10的值
    }
    return 0;
}