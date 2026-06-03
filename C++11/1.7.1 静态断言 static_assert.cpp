#include<iostream>

int main()
{
    static_assert(sizeof(long)==8,"long类型的大小不为4");
    std::cout<<"64bit系统中long类型: "<<sizeof(long)<<std::endl;
    return 0;


}
