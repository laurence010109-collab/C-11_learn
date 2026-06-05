#include<iostream>
using namespace std;

void test(int& a)
{
    cout<<"左值引用"<<endl;
}

void test(int&& a)
{
    cout<<"右值引用"<<endl;
}

void forword(int&& a)
{
    test(a);
}

int main()
{   
    
    int a=10;
    test(a);
    test(10);
    forword(10);//int&& a=10; a是一个左值，所以调用test(int& a)函数
    return 0;

}