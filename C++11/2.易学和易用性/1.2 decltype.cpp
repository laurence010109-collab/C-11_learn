#include<iostream>
using namespace std;
#include<string>

class test
{
public:
    string test;
    static const int value=110;//静态常量成员必须在类内初始化，且必须是const类型的整型或枚举类型
};

int main()
{
    int x=9;
    const int& y=x;
    decltype(x)a=x;//int
    decltype(auto)b=x;//const int&
    decltype(test::value)c=0;//const int

    test t;
    decltype(t.test)d="hello";//string
    return 0;

}