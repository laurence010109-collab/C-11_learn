#include<iostream>
using namespace std;
#include<string>

class Person
{
public:
    Person(int&max)
    {
        this->m_max=max>0?max:100;
    }
    Person(int&max,int&mid):Person(max)
    {
        this->m_mid=mid>0&&mid<max?mid:50;
    }
    Person(int&max,int&mid,int&min):Person(max,mid)
    {
        this->m_min=min>0&&min<mid?min:10;
    }
    int m_max,m_mid,m_min;
};


int main()
{
    int max=90,mid=40,min=5;
    Person p(max,mid,min);
    cout<<p.m_max<<" "<<p.m_mid<<" "<<p.m_min<<endl;
    return 0;   

}