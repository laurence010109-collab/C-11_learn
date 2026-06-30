#include<iostream>
#include<thread>
using namespace std;

void func()
{
    cout<<"线程ID:"<<this_thread::get_id()<<endl;
}
int main()
{
    cout<<"主线程ID:"<<this_thread::get_id()<<endl;
    thread t1(func);
    t1.join();
}