#include<iostream>
#include<memory>
#include<vector>

class Weight
{
public:
    Weight(int id):ID(id)
    {
        std::cout<<"weight"<<ID<<"开始构造"<<std::endl;
    }
    ~Weight() {std::cout<<"weight"<<ID<<"开始析构"<<std::endl;}
    void show() const
    {
        std::cout<<"weight"<<ID<<std::endl;
    }

private:
    int ID;
};
void demo_unique()
{
    std::unique_ptr U1=std::make_unique<Weight>(1);
    U1->show();
    auto U2=std::move(U1);
    U2->show();
}

void demo_shared()
{
    std::shared_ptr S1=std::make_shared<Weight>(2);
    auto S2=S1;
    S2->show();
    std::cout<<"引用计数"<<S1.use_count()<<std::endl;
    auto S3=S2;
    std::cout<<"引用计数"<<S1.use_count()<<std::endl;
}

void demo_vector()
{
    std::vector<std::unique_ptr<Weight>> v1;
    v1.push_back(std::make_unique<Weight>(1));
    v1.push_back(std::make_unique<Weight>(2));
    for(auto &i:v1)
    {
        i->show();
    }
}
int main()
{
    demo_unique();
    demo_shared();
    demo_vector();
    std::cout<<"程序结束"<<std::endl;
    return 0;
}