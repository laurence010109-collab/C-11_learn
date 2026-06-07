#include<iostream>
using namespace std;
#include<functional>

class Test
{
public:
    Test(function<void(int&&,int&&)> f):callback(f)
    {

    }
   function<void(int&&,int&&)> callback;
   void run()
    {
         callback(10,20);
    }

};

class Test1
{
public:
    void operator()(int &&a,int&& b)
    {
        cout<<"a="<<a<<" b="<<b<<" a*b="<<a*b<<endl;
    }
};

int main()
{
    Test1 t1;
    Test t(t1);
    t.run();
    return 0;
}