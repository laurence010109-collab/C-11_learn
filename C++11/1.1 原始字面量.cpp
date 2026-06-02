// 使用原始字面量R “xxx(raw string)xxx”，
// （）两边的字符串在解析的时候是会被忽略的，
// 因此一般不用指定。如果在（）前后指定了字符串，
// 那么前后的字符串必须相同，否则会出现语法错误。


#include<iostream>
#include<string>
int main()
{
     std::string str="1D:\hello\world\test.txt";
     std::cout<<str<<std::endl;
    std::string str2="2D:\\hello\\world\\test.txt";
    std::cout<<str2<<std::endl;
    std::string str3=R"aaa(3D:\
    hello\
    world\
    test.txt)aaa";
    std::cout<<str3<<std::endl;
    return 0;

}