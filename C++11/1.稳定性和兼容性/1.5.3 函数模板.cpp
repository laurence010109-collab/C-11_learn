#include<iostream>

template<typename T=int>
void fun(T a)
{
    std::cout<<"a: "<<a<<std::endl;
    std::cout<<"sizeof(T): "<<sizeof(T)<<std::endl;
}
int main()
{
    fun(100);
    fun(3.14);
    return 0;
}