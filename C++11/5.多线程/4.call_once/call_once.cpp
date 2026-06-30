#include<iostream>
#include<thread>
#include<mutex>
using namespace std;
once_flag flag;
mutex mtx;
class Base
{
public:
    Base(const Base& obj)=delete;
    Base& operator=(const Base& obj)=delete;
    static Base* getInstance()
    {
        call_once(flag,[&](){
            obj=new Base();
            cout<<"Base对象创建成功"<<endl;
        });
        return obj;
    }
    void set_name(string name)
    {
        this->name=name;
    }
    string get_name()
    {
        return name;
    }
private:
    Base()=default;
    string name;
    static Base* obj;
};
Base* Base::obj=nullptr;

void func(string name)
{
    lock_guard<mutex> lock(mtx);
    Base::getInstance()->set_name(name);
    cout<<"name: "<<Base::getInstance()->get_name()<<endl;
}

int main()
{
    thread t1(func,"张三");
    thread t2(func,"李四");
    thread t3(func,"王五");
    t1.join();
    t2.join();
    t3.join();
    return 0;
}