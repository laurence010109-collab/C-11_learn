#include<iostream>
using namespace std;

class A
{

    public:
    virtual void show()
    {
        cout<<"A"<<endl;
    }
};

class B:public A
{
    public:
    virtual void show() override
    {
        cout<<"B"<<endl;
    }
};
class C:public B
{
    public:
     void show() override
    {
        cout<<"C"<<endl;
    }
};

int main()
{
    A *a;
    B b;
    a=&b;
    a->show();
    C c;
    a=&c;
    a->show();
    return 0;
}