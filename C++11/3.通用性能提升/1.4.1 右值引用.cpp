#include<iostream>
using namespace std;
#include<string>

class Person
{
public:
    Person():m_age(new int(100))
    {
        cout<<"this is 构造函数"<<endl;
    }
    Person(const Person&p):m_age(new int(*p.m_age))
    {
        cout<<"this is 拷贝构造函数"<<endl;
    }
    Person(Person && p):m_age(p.m_age)
    {
        p.m_age=nullptr;
        cout<<"this is 移动构造函数"<<endl;
    }
    int* m_age;
    ~Person()
    {
        delete m_age;
        cout<<"this is 析构函数"<<endl;
    }
};

Person func()
{
    Person p;
    cout<<"func()函数结束，return p"<<endl;
    return p;
}

int main()
{
    Person p1=func();
    cout<<"p1.m_age="<<*p1.m_age<<endl;
    return 0;

}