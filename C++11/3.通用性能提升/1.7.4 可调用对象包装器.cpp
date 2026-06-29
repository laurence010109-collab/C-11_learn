#include<iostream>
using namespace std;
#include<functional>

class Test
{
public:
    void output(int x,int y)
    {
        cout<<"x="<<x<<" y="<<y<<" x+y="<<x+y<<endl;
    }
    int m_number=100;
};

int main()
{
    //bind绑定成员函数
    Test t;
    function<void(int,int)> f=bind(&Test::output,&t,placeholders::_1,placeholders::_2); // 绑定成员函数output，传入对象t和占位符，调用时传入参数10和20
    f(10,20);
    auto f1=bind(&Test::output,&t,520,placeholders::_1); // 绑定成员函数output，传入对象t和占位符，调用时传入参数10和20
    f1(1314);
    //bind绑定类成员变量
    function<int&()> f6=bind(&Test::m_number,&t); // 绑定成员变量
    cout<<"t.m_number="<<f6()<<endl; // 输出成员变量的值
    auto f2=bind(&Test::m_number,&t); // 绑定成员变量
    cout<<"t.m_number="<<f2()<<endl; // 输出成员变量的值
    f2()=520; // 修改成员变量的值
    cout<<"t.m_number="<<f2()<<endl; // 输出修改后的成员变量
    return 0;   
}