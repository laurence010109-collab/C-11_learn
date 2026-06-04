#include<iostream>
using namespace std;
#include<string>

struct Person
{
    const char* name;
    int age;
};

template<typename T>
constexpr T display(T t)
{
    return t;   
}

int main()
{
    constexpr struct Person p{"张三",20};
    constexpr struct Person p1=display(p);
    cout<<p1.name<<" "<<p1.age<<endl;
    
    return 0;

}