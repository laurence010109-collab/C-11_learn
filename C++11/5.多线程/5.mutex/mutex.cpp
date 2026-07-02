#include<iostream>
#include<mutex>
#include<thread>
using namespace std;
mutex mtx;
timed_mutex tmtx;
class Base
{
public:

    void increment(int count)
    {
        for(int i=0;i<count;i++)
        {
            mtx.lock();//加锁，当前线程获得互斥锁，其他线程无法获得互斥锁
            number++;
            cout<<"number: "<<number<<endl;
            mtx.unlock();//解锁，当前线程释放互斥锁，其他线程可以获得互斥锁
            //休眠进入阻塞状态，当前线程不占用CPU时间片，其他线程可以获得CPU执行权
            this_thread::sleep_for(chrono::milliseconds(100));//当前线程休眠100毫秒，当前线程不占用CPU时间片，其他线程可以获得CPU执行权
        }
    }
    void decrement(int count)
    {
        for(int i=0;i<count;i++)
        {
            //mtx.lock();//加锁，当前线程获得互斥锁，其他线程无法获得互斥锁
            lock_guard<mutex> lock(mtx);
            number--;
            cout<<"number: "<<number<<endl;
            //mtx.unlock();//解锁，当前线程释放互斥锁，其他线程可以获得互斥锁
            //休眠进入阻塞状态，当前线程不占用CPU时间片，其他线程可以获得CPU执行权
            this_thread::sleep_for(chrono::milliseconds(100));//当前线程休眠100毫秒，当前线程不占用CPU时间片，其他线程可以获得CPU执行权
        }
    }

    void work()
    {
        while(true)
        {
            if(tmtx.try_lock_for(chrono::milliseconds(100)))//尝试获得互斥锁，如果在指定时间内获得互斥锁，则返回true，否则返回false
            {
                count++;
                cout<<"count: "<<count<<endl;
                cout<<"线程ID: "<<this_thread::get_id()<<endl;
                this_thread::sleep_for(chrono::milliseconds(100));//当前线程休眠100毫秒，当前线程不占用CPU时间片，其他线程可以获得CPU执行权
                tmtx.unlock();
                break;
            }
            else
            {
                cout<<"获取互斥锁失败"<<endl;
                cout<<"线程ID: "<<this_thread::get_id()<<endl;
            }
        }
    }

private:
    int number=999;
    int count=0;

};

int main()
{
    Base b;
    thread t1(&Base::work,&b);
    thread t2(&Base::work,&b);
    t1.join();
    t2.join();
 
    return 0;
}