#include<iostream>
using namespace std;
#include<vector>

template<typename T>
void func(T&& arg)
{
    cout<<"func(T&& arg)被调用了"<<endl;
}
void func(int& arg)
{
    cout<<"func(int& arg)被调用了"<<endl;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    vector<int>&& v1 = move(v); // v1是一个右值引用，绑定到v上

    func(10);
    int a = 20;
    func(a);
    func(move(a)); // move(a)将a转换为右值，调用func(T&& arg)函数
    func(forward<int&>(a)); // forward<int&>(a)保持a的值类别，调用func(int& arg)函数


    return 0;
}