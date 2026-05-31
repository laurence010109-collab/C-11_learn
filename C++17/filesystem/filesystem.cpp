#include<iostream>
#include<filesystem>

namespace fs=std::filesystem;//初始化命名空间
//2.1 path 初始化
int main1()
{
    fs::path p1;//初始化为空路径
    fs::path p2="test.txt";
    fs::path p3="/home/user/test.txt";
    fs::path p4=p3;
    fs::path p5=std::move(p3);
    std::cout<<"p1: "<<p1<<std::endl;
    std::cout<<"p2: "<<p2<<std::endl;
    std::cout<<"p3: "<<p3<<std::endl;
    std::cout<<"p4: "<<p4<<std::endl;
    std::cout<<"p5: "<<p5<<std::endl;
    return 0;
}

//2.2 path 路径拼接操作
//path += 和 / 操作

int main2()
{
    fs::path p1="/home/user";
    fs::path p2="/tets.txt";
    p1+=p2;//路径拼接
    std::cout<<"p1: "<<p1<<std::endl;

    p2=p2/"helo.txt";//路径拼接
    std::cout<<"p2: "<<p2<<std::endl;
    return 0;               
}

// 对路径文件名进行操作修改
int main3()
{
    fs::path p1="/home/user/test1.txt";
    if(p1.has_filename())//判断路径是否有文件名
    std::cout<<"p1.filename(): "<<p1.filename()<<std::endl;
    p1.replace_filename("hello.txt");//替换路径文件名
    std::cout<<"p1.filename: "<<p1.filename()<<std::endl;
    p1.remove_filename();//移除路径文件名
    std::cout<<"p1: "<<p1<<std::endl;
    return 0;
}

// 2.4 对文件拓展名修改
int main4()
{
    fs::path p="/home/user/test1.txt";
    fs::path p1="/home/uers";
    std::cout<<p.has_extension()//判断路径是否有拓展名
    <<" "<<p1.has_extension()<<std::endl;

    std::cout<<"p.extrnsion  "<<p.extension()<<std::endl;
    p.replace_extension("png");//替换路径拓展名
    std::cout<<"p.extension: "<<p.extension()<<std::endl;

    p.replace_extension();//移除路径拓展名
    std::cout<<"p.extension: "<<p.extension()<<std::endl;
    return 0;
}
#include<fstream>//文件操作
#include<cstdio>//文件操作
// 2.5 path 判断路径是否存在

int main()
{
    const fs::path sandbox="sandbox";
    fs::create_directory(sandbox);//创建目录
    std::ofstream(sandbox/"file");//创建文件
    std::cout<<fs::exists(sandbox)<<" "<<fs::exists(sandbox/"file")<<" "<<fs::exists(sandbox/"nonexistent")<<std::endl;
    fs::remove_all(sandbox);//删除目录及其内容
    return 0;
}