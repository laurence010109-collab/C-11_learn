// C++中增加了final关键字来限制某个类不能被继承，
// 或者某个虚函数不能被重写，
// 和Java的final关键字的功能是类似的。如果使用final修饰函数，只能修饰虚函数
// ，并且要把final关键字放到类或者函数的后面。

#include<iostream>
class Base 
{
    public:
    int a=10;
    int b=20;
    virtual void peint()
    {
        std::cout<<"Base:a:"<<a<<"b: "<<b<<a+b<<std::endl;
    }
};
class Derived final:public Base
{
    public:
    int c=30;
    void peint() final
    {
        std::cout<<"Derived:a: "<<a<<" b: "<<b<<" c: "<<c<<" a+b+c: "<<a+b+c<<std::endl;
    }
};
// class Derived2:public Derived
// {
//     public:
//     int d=40;
// };
int main()
{
    Derived d;
    d.peint();
    return 0;
}