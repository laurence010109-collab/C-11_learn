#include<iostream>

template<typename T=int,T t=520>
class test
{
    public:
    void print()
    {
        std::cout<<"t: "<<t<<std::endl;
    }
};

int main()
{
    test<> t;
    t.print();

    test<int, 200> t2;
    t2.print();

    return 0;
}