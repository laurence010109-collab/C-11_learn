#include<iostream>
#include<string>
int main()
{
    std::string str1="hello"+std::to_string(100);
    std::cout<<str1<<std::endl;
    std::string str2="world"+std::to_string(3.14+1.232);
    std::cout<<str2<<std::endl;


    std::string str3="345";
    std::string strr4="1.3242dchsdl/cls";
    // std::string str5="ashdka";
    int myint=std::stoi(str3);
    std::cout<<"i1: "<<myint<<std::endl;
    double mydouble=std::stod(str3);
    std::cout<<"str3: "<<mydouble<<std::endl;
    double d1=std::stod(strr4);
    std::cout<<"d1: "<<d1<<std::endl;

    
    return 0;
}