#include<iostream>
using namespace std;
#include<string>

class tets
{
public:
    template<typename T,typename U>
    decltype(auto)add(T t,U u)
        {
            return t+u;
        }
};

int main()
{
    tets t;
    cout<<t.add(2.1,5)<<endl;//double typename会自动推断出T为double，U为int，返回值类型为double
    cout<<t.add(2,3)<<endl;//int
    return 0;
}