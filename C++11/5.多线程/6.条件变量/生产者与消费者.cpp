#include<iostream>
#include<mutex>
#include<condition_variable>
#include<queue>
#include<thread>
using namespace std;


class MyQueue
{
public:
    //生产者
    void put(const int& value)
    {
        unique_lock<mutex> my_lock(mtx);
        while(my_queue.empty())
        {
            cout<<"队列为空,生产者可以生产数据"<<endl;
            //unique_lock是一个互斥锁的包装类，它可以在构造函数中加锁，在析构函数中解锁，保证在作用域结束时自动释放互斥锁，避免死锁。
            notfull.wait(my_lock);//wait()函数会阻塞当前线程，直到条件变量被通知，或者超时，或者被中断。wait()函数会自动释放互斥锁，并在等待期间阻塞当前线程。当条件变量被通知时，wait()函数会重新获取互斥锁，并继续执行。
        }
        
        my_queue.push(value);
        cout<<"生产者生产了一个数据:"<<value<<endl;
        notempty.notify_one();
    }
    //消费者
    void get()
    {   
        unique_lock<mutex> my_lock(mtx); 
        while(my_queue.size()==maxSize)
        {
            cout<<"队列已满,消费者可以消费数据"<<endl;
            
            notempty.wait(my_lock);
            //wait()函数会阻塞当前线程，直到条件变量被通知，或者超时，或者被中断。wait()函数会自动释放互斥锁，并在等待期间阻塞当前线程。当条件变量被通知时，wait()函数会重新获取互斥锁，并继续执行。
        }

        my_queue.front();
        cout<<"消费者消费了一个数据:"<<my_queue.front()<<endl;
        my_queue.pop();
        notfull.notify_one();
    }
    bool empty()
    {
        lock_guard<mutex> my_lock(mtx);
        cout<<"队列是否为空:"<<my_queue.empty()<<endl;
        return my_queue.empty();

    }
    void size()
    {
        lock_guard<mutex> my_lock(mtx);
        my_queue.size();
        cout<<"队列的大小为:"<<my_queue.size()<<endl;
    }
    bool full()
    {
        lock_guard<mutex> my_lock(mtx);
        cout<<"队列是否已满:"<<(my_queue.size()==maxSize)<<endl;
        return my_queue.size()==maxSize;
    } 
private:
    int maxSize=100;
    std::queue<int> my_queue;
    mutex mtx;
    condition_variable notfull;
    condition_variable notempty;

};

int main()
{
    MyQueue my_queue;
    thread t1[5];
    thread t2[5];
    for(int i=0;i<5;i++)
    {
        t1[i]=thread(&MyQueue::put,&my_queue,i+100);
        t2[i]=thread(&MyQueue::get,&my_queue);
    }
    for(int i=0;i<5;i++)
    {
        t1[i].join();
        t2[i].join();
    }

}