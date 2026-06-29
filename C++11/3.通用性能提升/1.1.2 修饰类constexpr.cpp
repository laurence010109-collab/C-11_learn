#include<iostream>
using namespace std;
#include<string>

class Person
{
public:
    constexpr Person(const char* name,int age):name(name),age(age){}
    const char* name;
    int age;
};


int main()
{
    constexpr Person p{"张三",20};
    cout<<p.name<<" "<<p.age<<endl;
    return 0;

}