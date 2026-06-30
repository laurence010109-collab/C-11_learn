#include<iostream>
#include<thread>
using namespace std;
void func()
{
    cout<<"我是线程ID:"<<this_thread::get_id()<<endl;
}
void func2(string name,int age)
{
    cout<<"我是线程ID:"<<this_thread::get_id()<<endl;
    cout<<"name:"<<name<<endl;
    cout<<"age:"<<age<<endl;
}
int main()
{
    cout<<"主线程ID:"<<this_thread::get_id()<<endl;
    thread t1(func);
    thread t2(func2,"张三",20);
    t1.join();
    cout<<"before t2 detach"<<t2.joinable()<<endl;
    t2.detach();
    cout<<" after t2 detach"<<t2.joinable()<<endl;
    cout<<"t2线程分离后,主线程ID:"<<this_thread::get_id()<<endl;
    // t2.join(); // 此行会导致程序崩溃，因为线程已经被分离
   thread t3;
   cout<<"t3线程是否可连接:"<<t3.joinable()<<endl; 
    
    return 0;

}