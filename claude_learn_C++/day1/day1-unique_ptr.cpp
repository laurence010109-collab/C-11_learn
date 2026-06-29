#include<iostream>
#include<string>
#include<memory>

class My_class
{
public:
    void hello()
    {
        std::cout<<"hello this is hello"<<std::endl;
    }
    ~My_class() {std::cout<<"this is 析构函数"<<std::endl;}

};

void demo_unique()
{
    std::unique_ptr p=std::make_unique<My_class>();
    p->hello();
    //auto p2=p;
    std::unique_ptr p1=std::move(p);
    p1->hello();
}

void demo_shared()
{
    std::shared_ptr S=std::make_shared<My_class>();
    auto S1=S;
    auto S2=S1;
    S2->hello();
    S1->hello();
}
int main()
{
    demo_unique();
    return 0;
}