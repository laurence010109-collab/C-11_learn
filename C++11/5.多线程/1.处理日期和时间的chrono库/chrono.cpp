#include<iostream>
#include<chrono>
using namespace chrono;
using namespace std;
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
    return 0;
}