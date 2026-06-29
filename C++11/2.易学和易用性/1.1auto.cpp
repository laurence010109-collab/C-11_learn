#include<map>
#include<iostream>
int main()
{
    std::map<int,std::string>person;
    std::map<int,std::string>::iterator it=person.begin();
    for(;it!=person.end();it++)
    {
        std::cout<<"hello"<<std::endl;
    }
    std::cout<<"hello"<<std::endl;
    return 0;
}

int main2()
{
    std::map<int,std::string>person;
    auto it=person.begin();
    for(;it!=person.end();it++)
    {
        std::cout<<it->first<<" "<<it->second<<std::endl;   
    }
    return 0;
}