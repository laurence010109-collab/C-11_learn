#include <iostream>
#include <list>
using namespace std;

template<class T>
class printcontainer
{
public:
    void printcontain(T &container)
    {
        for(m_it=container.begin();m_it!=container.end();m_it++)
        {
            cout<<*m_it<<" ";
        }
        cout<<endl;
    }
    // auto m_it; auto必须初始化；不能作为类的非静态成员； static const auto v3 = 10;// ok
    decltype(T().begin()) m_it;
};



int main()
{
    list<int> l1={1,2,3,4,5};
    printcontainer<list<int>> p1;
    p1.printcontain(l1);
    return 0;
}