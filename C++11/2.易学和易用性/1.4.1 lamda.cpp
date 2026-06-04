#include<iostream>
using namespace std;

int main()
{
    int a=10;
    float b=3.14;
    auto p=[=](int x,int y) {return x*y+a*b;};

    cout<<p(2,3)<<endl;
    return 0;
}