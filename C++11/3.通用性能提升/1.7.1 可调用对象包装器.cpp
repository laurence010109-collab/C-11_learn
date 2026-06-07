#include<iostream>
using namespace std;
#include<functional>

void test(int &&a,int&& b)
{
    cout<<"a="<<a<<" b="<<b<<" a+b="<<a+b<<endl;
}

class Test
{
public:
    static void sub(int &&a,int&& b)
    {
        cout<<"a="<<a<<" b="<<b<<" a-b="<<a-b<<endl;
    }
};

class Test1
{
public:
    void operator()(int &&a,int&& b)
    {
        cout<<"a="<<a<<" b="<<b<<" a*b="<<a*b<<endl;
    }
};

int main()
{
    // 1.put函数对象包装普通函数
    function<void(int&&,int&&)> func1=test;
    func1(10,20);
    // 2.put函数对象包装静态成员函数
    function<void(int&&,int&&)> func2=Test::sub;
    func2(30,40);
    // 3.put函数对象包装仿函数对象
    Test1 t;
    function<void(int&&,int&&)> func3=t;
    func3(50,60);

    return 0;   
}