#include<iostream>
#include<sstream>
using namespace std;
#include<string>
#include<vector>
void test_istream01()
{
    cout<<"=================test_istream===================="<<endl;
    string str="laurence 2,3,4,5";
    istringstream iss(str);//istringstream是输入字符串流，类似于从文件中读取数据
    string name;
    int a,b,c,d;
    getline(iss,name,',');//getline函数从输入流中读取一行数据，直到遇到指定的分隔符为止，这里指定的分隔符是逗号
    iss>>a>>b>>c>>d;//默认按空格分割字符串，依次读取到变量中
    cout<<"name: "<<name<<endl;
    cout<<"a: "<<a<<endl;
    cout<<"b: "<<b<<endl;
    cout<<"c: "<<c<<endl;
    cout<<"d: "<<d<<endl;
}

void test_istream02()
{
    string str="laurence 2,3,4,5";
    istringstream iss(str);
    string word;
    vector<string> words;
    while(iss>>word)//默认按空格分割字符串，依次读取到变量中
    {
        words.push_back(word);
    }
    for(const auto&w:words)
    {
        cout<<w<<endl;
    }
    cout<<"=================test_istream02===================="<<endl;
}

void test_ostream01()
{
    cout<<"====================test_ostream01===================="<<endl;
    ostringstream oss;
    string name="laurence";
    int age=25;
    double salare=1999.99;
    oss<<"员工信息"<<endl;
    oss<<"姓名: "<<name<<endl;
    oss<<"年龄: "<<age<<endl;
    oss<<"薪资: "<<salare<<endl;
    string result_oss=oss.str();//str()函数返回字符串流中的内容
    cout<<result_oss<<endl;
    cout<<"====================test_ostream01===================="<<endl;
}

void test_iostream01()
{
    cout<<"=======================test_iostream01===================="<<endl;
    stringstream ss;
    ss<<"laurence 2 3 4 5";
    cout<<"写入字符串流后的内容: "<<ss.str()<<endl;
    //读取
    string word;
    while(ss>>word)
    {
        cout<<word<<endl;
    }
    ss.clear();//清除流状态标志位，避免后续操作失败
    ss.str(" ");
    ss<<"新内容："<<42<<endl;
    cout<<"写入新内容后的字符串流内容: "<<ss.str()<<endl;
    cout<<"=======================test_iostream01===================="<<endl;
}

// ============================================================
// 4. 综合练习：解析日志文件（Day 6 的实战任务）
// ============================================================




int main()
{

    test_istream01();
    test_istream02();
    test_ostream01();
    test_iostream01();
    return 0;
}