#include<iostream>
using namespace std;
#include<string>

class Person
{
public:
    Person(int max)
    {
        this->m_max=max>0?max:100;
    }
    Person(int max,int mid):Person(max)
    {
        this->m_mid=mid>0&&mid<max?mid:50;
    }
    Person(int max,int mid,int min):Person(max,mid)
    {
        this->m_min=min>0&&min<mid?min:10;
    }
    int m_max,m_mid,m_min;

    void func(const int a)
    {
        cout<<"this is Person class func()"<<endl;
    }
    void func(const double a)
    {
        cout<<"this is Person class func(double)"<<endl;
    }
};

class Son:public Person
{
public:
    using Person::Person;
    using Person::func;//不加会隐藏父类的func函数，导致无法调用父类的func函数
    void func()
    {
        cout<<"this is Son class func()"<<endl;
    }
};

int main()
{
    Son s(90,40,5);
    s.func();
    s.func(10);
    s.func(10.0);
    return 0;

}