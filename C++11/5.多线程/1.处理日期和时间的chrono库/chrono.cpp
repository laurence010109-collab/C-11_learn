#include<iostream>
#include<chrono>
using namespace std::chrono;
using namespace std;

void clockTest()
{
    cout<<"=================clockTest===================="<<endl;
    system_clock::time_point tp1=system_clock::now();
    cout<<"现在的时间是:"<<tp1.time_since_epoch().count()<<endl;
    time_t tt=system_clock::to_time_t(tp1);//将时间点转换为time_t类型,tt是一个整数，表示从1970年1月1日0时0分0秒到现在的秒数,是一个时间戳
    cout<<"现在的时间是:"<<tt<<endl;
    cout<<"现在的时间是:"<<ctime(&tt)<<endl;
    chrono::hours h(10*24);
    system_clock::time_point tp2=tp1+h;
    cout<<"10天后的时间是:"<<tp2.time_since_epoch().count()<<endl;
    time_t tt2=system_clock::to_time_t(tp2);
    cout<<"10天后的时间是:"<<ctime(&tt2)<<endl;
    //时间点是可以进行加减运算的，时间段
}

void steadyClockTest()
{
    auto p1=steady_clock::now();
    for(int i=0;i<1000;i++)
    {
        cout<<i<<endl;
    }
    cout<<endl;
    auto p2=steady_clock::now();
    auto d=p2-p1;
    cout<<"程序运行时间为:"<<d.count()<<"纳秒"<<endl;

}

void durationCastTest()
{
    cout<<"=================durationCastTest===================="<<endl;
    chrono::seconds s(10);
    chrono::minutes m=chrono::duration_cast<chrono::minutes>(s);
    cout<<"10秒转换为分钟:"<<m.count()<<endl;
    chrono::milliseconds ms=chrono::duration_cast<chrono::milliseconds>(s);
    cout<<"10秒转换为毫秒:"<<ms.count()<<endl;
}
int main()
{
    //hour
    duration<int,ratio<3600>> hour(1);
    chrono::hours h(1);
    //minute
    duration<int,ratio<60>> minute(1);
    chrono::minutes m(1);
    //second
    duration<int> second(1);
    chrono::seconds s(1);
    chrono::seconds s1(2);
   //chrono::seconds s2(1.3);
    //millisecond
    duration<int,ratio<1,1000>> millisecond(1);
    chrono::milliseconds ms(1);
    cout<<"count:"<<s.count()<<endl;
    cout<<"count:"<<s1.count()<<endl;

    cout<<"================================="<<endl;
    chrono::minutes m1(1);
    chrono::seconds s2(30);
    chrono::seconds s3=m1+s2;
    cout<<"count:"<<s3.count()<<endl;
    clockTest();
    steadyClockTest();
    durationCastTest();
    return 0;
}