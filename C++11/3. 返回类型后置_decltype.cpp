#include<iostream>
using namespace std;

template<typename U,typename R>
auto add(U&a,R&b)->decltype(a+b)
{
    return a+b;
}

int main()
{
    int i=10;
    double j=20.5;
    auto num=add<int,double>(i,j);
    cout<<num<<endl;
    return 0;
    
}
