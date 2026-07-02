#include<iostream>
#include<fstream>
using namespace std;
// 写入文件内容
void test01()
{
    ofstream ofs;
    ofs.open("test.txt",ios::out);
    ofs<<"姓名:张三"<<endl;
    ofs<<"性别:男"<<endl;
    ofs<<"年龄:20"<<endl;
    ofs.close();
}
// 读取文件内容
void test02()
{
    fstream ifs;
    ifs.open("test.txt",ios::in);
    if(!ifs.is_open())
    {
        cout<<"文件打开失败"<<endl;
        return;
    }

    // char c;
    // while((c=ifs.get())!=EOF)
    // {
    //     cout<<c;
    // }
    // ifs.close();
    char buf[1024]={0};
    while(ifs>>buf)
    {
        cout<<buf<<endl;
    }
    ifs.close();
}

class Person{
public:
    char name[64];
    int age;

};
// 写入二进制文件
void test03()
{
    Person p={"laurence",25};
    ofstream ofs("Person.txt",ios::out | ios::binary);
    ofs.write((const char*)&p,sizeof(p));
    ofs.close();
}

void tets04()
{
    Person p;
    ifstream ifs("Person.txt",ios::in | ios::binary);
    ifs.read((char*)&p,sizeof(p));
    cout<<"姓名:"<<p.name<<",年龄:"<<p.age<<endl;
    ifs.close();

}
int main()
{
    test01();
    test02();
    test03();
    tets04();
    return 0;
}