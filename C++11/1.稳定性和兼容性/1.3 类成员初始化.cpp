
//C++初始化98 初始化方法:
#include<iostream>
class test
{
    public:
    int a=10;
    int b=20;
    static int c;//静态成员变量
    void print()
    {
        std::cout<<"a: "<<a<<" b: "<<b<<" c: "<<c<<std::endl;
    }
};
int test::c=30;//静态成员变量初始化
int main()
{
    test t1;
    t1.print();
    return 0;   
}