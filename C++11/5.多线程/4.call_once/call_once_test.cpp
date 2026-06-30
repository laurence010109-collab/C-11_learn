#include<iostream>
#include<thread>
using namespace std;
#include<mutex>

once_flag flag;
void do_once(string name,int age)
{
    cout<<"name: "<<name<<", age: "<<age<<endl;
}

void do_something(string name,int age)
{
    static int count=0;
    call_once(flag,do_once,"laurence",25);
    cout<<"do_something count: "<<++count<<endl;
    cout<<"do_something name: "<<name<<", age: "<<age<<endl;
}

int main()
{
    thread t1(do_something,"张三",20);
    thread t2(do_something,"李四",30);
    thread t3(do_something,"王五",40);
    t1.join();
    t2.join();
    t3.join();
}