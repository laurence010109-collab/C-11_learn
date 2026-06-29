#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
//   现在开始：手写学生管理系统

//   要求：用 vector、map、string 实现一个学生管理系统，支持：

//   1. 添加学生（学号 + 姓名 + 成绩）
//   2. 显示所有学生
//   3. 按学号查找
//   4. 按学号删除
//   5. 按成绩排名
//   6. 退出

struct Student
{
    std::string id;
    std::string name;
    int score;
};


int main()
{
std::vector<Student> students;
std::map<std::string,Student> student_map;

int chioce;
do{
    std::cout << "\n=== 学生管理系统 ===\n";
    std::cout << "1. 添加学生\n";
    std::cout << "2. 显示所有学生\n";
    std::cout << "3. 按学号查找\n";
    std::cout << "4. 按学号删除\n";
    std::cout << "5. 按成绩排名\n";
    std::cout << "6. 退出\n";
    std::cout << "请选择: ";
    std::cin >> choice;
}while(chioce!=6)
{
    switch (chioce)
    {
        case 1:
            {
                Student s;
                std::cout << "请输入学号: ";
                std::cin >>s.id;
                std::cout << "请输入姓名: ";    
                std::cin >> s.name;
                std::cout << "请输入成绩: ";
                std::cin>>s.score;
                students.push_back(s);
                student_map[s.id] = s;
    
            }
            continue;
        case 2:
            {
                std::cout<<"学号\t姓名\t成绩\n";
                for(auto &s::students)
                {
                    std::cout<<s.id<<"\t"<<s.name<<"\t"<<s.score<<"\n";
                }
            }
            continue;
        case 3:
            {
                std::string id:
                std::cout<<"请输入学号: ";
                std::cin>>id;
                auto it = student_map.find(id);
                if(it != student_map.end())
                {
                    std::cout<<"学号: "<<it->second.id<<"\t姓名: "<<it->second.name<<"\t成绩: "<<it->second.score<<"\n";
                }
                else
                {
                    std::cout<<"未找到该学生\n";
                }
            }
            continue;
        case 4:
            {
                std::string id;
                std::cout<<"请输入学号： ";
                std::cin>>id;
                auto it =student_map.find(id);
                if(it!=student_map.end())
                {
                    student_map.erase(it);
                    students.erase(std::remove_if(students.begin(),students.end(),[&id](const Student &s){return s.id==id;}),students.end());
                    std::cout<<"删除成功\n";
                }
            }
            continue;
        case 5:
            {
                std::sort(students.begin(),students.end(),[](const Student &a,const Student &b){return a.score>b.score;});
                std::cout<<"学号\t姓名\t成绩\n";
                for(auto &s:students)
                {
                    std::cout<<s.id<<"\t"<<s.name<<"\t"<<s.score<<"\n";
                }
            }
            continue;
    }
}
std::cout << "退出系统\n";
return 0;
}