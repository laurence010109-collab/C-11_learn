#include<iostream>
#include<vector>

template <typename T>
class tets
{
public:
    void traveral(T &a)
    {
        auto it=a.begin();
        for(;it!=a.end();it++)
        {
            std::cout<<*it<<" ";
        }
        std::cout<<std::endl;
    }
};

int main()
{
    std::vector<int>v{1,2,3,4,5};
    tets<std::vector<int>> t;
    t.traveral(v);
    return 0;
}

