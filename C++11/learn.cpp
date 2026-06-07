/**
 * ============================================================
 *  C++ 函数指针（Function Pointer）— 知识点 + 案例
 *  C++11 using 别名方式：using ptr = void(*)(int);
 * ============================================================
 *  编译: g++ -std=c++11 -o learn learn.cpp && ./learn
 * ============================================================
 */

#include <iostream>
#include <vector>
#include <functional>  // std::function

using namespace std;

// =============================================================
//  一、函数指针基础
//  using 别名声明 （C++11 推荐方式）
// =============================================================

/**
 * 传统方式（C 风格）：
 *   typedef void (*FuncPtr)(int);
 *
 * C++11 using 别名（更清晰，推荐）：
 *   using FuncPtr = void(*)(int);
 *
 * 解读 using ptr = void(*)(int)：
 *  ┌─────────────────────────────────────────────┐
 *  │ using ptr = void(*)(int);                   │
 *  │         ↑     ↑    ↑  ↑                     │
 *  │       别名  返回类型 参数列表                 │
 *  │               (*) 表示"这是一个指针"         │
 *  └─────────────────────────────────────────────┘
 *  含义：ptr 是一个类型别名，代表"指向返回 void、
 *        接受一个 int 参数的函数"的指针。
 */

// 用 using 声明函数指针类型 —— 核心语法
using Callback = void(*)(int);        // 指向 void(int) 的函数指针
using IntOp    = int(*)(int, int);     // 指向 int(int,int) 的函数指针
using StrFunc  = string(*)(const string&); // 指向 string(const string&) 的函数指针

// ---------- 示例函数 ----------
void hello(int n) {
    cout << "Hello! number = " << n << endl;
}

int add(int a, int b) { return a + b; }
int mul(int a, int b) { return a * b; }

string toUpper(const string& s) {
    string result;
    for (char c : s) result += toupper(c);
    return result;
}

// =============================================================
//  二、基本使用 —— 声明、赋值、调用
// =============================================================

void demo_basic() {
    cout << "\n========== 1. 函数指针基础 ==========\n";

    // 1) 声明函数指针变量
    Callback p;             // p 是一个函数指针

    // 2) 赋值（两种写法等价）
    p = hello;              // 函数名隐式转为指针（推荐）
    // p = &hello;          // 显式取地址（等价）

    // 3) 调用（两种写法等价）
    p(42);                  // 隐式解引用（推荐，更简洁）
    (*p)(42);               // 显式解引用（传统写法）

    // 4) 空指针检查
    Callback q = nullptr;
    if (q == nullptr) {
        cout << "q 是空函数指针，不要调用它！" << endl;
    }

    // 5) int(*)(int,int) 示例
    IntOp op = add;
    cout << "add(10, 20) = " << op(10, 20) << endl;

    op = mul;
    cout << "mul(10, 20) = " << op(10, 20) << endl;

    // 6) string(*)(const string&) 示例
    StrFunc sf = toUpper;
    cout << "toUpper(\"hello\") = " << sf("hello") << endl;
}

// =============================================================
//  三、函数指针作为参数（回调函数）
// =============================================================

/**
 * 函数指针最经典的用法就是做回调（Callback）。
 * 调用者提供一个函数，由被调用者在特定时机执行。
 */

// 遍历数组，对每个元素应用回调
void forEach(int* arr, size_t n, Callback fn) {
    for (size_t i = 0; i < n; ++i) {
        fn(arr[i]);  // 回调
    }
}

void printSquare(int x) {
    cout << x * x << " ";
}

void demo_callback() {
    cout << "\n========== 2. 函数指针作为回调 ==========\n";

    int arr[] = {1, 2, 3, 4, 5};

    cout << "平方值: ";
    forEach(arr, 5, printSquare);
    cout << endl;

    // 💡 也可以传入 lambda（但必须是非捕获的 lambda 才能转为函数指针）
    cout << "立方值: ";
    forEach(arr, 5, [](int x) { cout << x * x * x << " "; });
    cout << endl;
}

// =============================================================
//  四、函数指针数组（策略模式 / 菜单分发）
// =============================================================

void menu_add()    { cout << "执行加法操作" << endl; }
void menu_sub()    { cout << "执行减法操作" << endl; }
void menu_mul()    { cout << "执行乘法操作" << endl; }
void menu_div()    { cout << "执行除法操作" << endl; }
void menu_quit()   { cout << "退出程序" << endl; }

void demo_array() {
    cout << "\n========== 3. 函数指针数组（策略模式） ==========\n";

    // 函数指针数组 —— 比 switch-case 更灵活
    using MenuHandler = void(*)();
    MenuHandler menu[] = {
        menu_add,   // 索引 0
        menu_sub,   // 索引 1
        menu_mul,   // 索引 2
        menu_div,   // 索引 3
        menu_quit   // 索引 4
    };

    cout << "选择操作 (0-4):\n";
    for (int i = 0; i < 5; ++i) {
        cout << "  " << i << " → ";
        menu[i]();  // 通过索引调用不同的函数
    }

    // 也可以动态选择
    cout << "\n动态选择索引 3: ";
    int choice = 3;
    menu[choice]();
}

// =============================================================
//  五、函数指针作为类成员
// =============================================================

class Processor {
public:
    // 构造函数：接收一个函数指针
    Processor(IntOp op) : op_(op) {}

    int execute(int a, int b) {
        return op_(a, b);  // 通过函数指针调用
    }

    // 运行时更换策略
    void setOperation(IntOp op) {
        op_ = op;
    }

private:
    IntOp op_;  // 函数指针作为成员变量
};

void demo_class_member() {
    cout << "\n========== 4. 函数指针作为类成员 ==========\n";

    Processor proc(add);
    cout << "proc.execute(6, 7) = " << proc.execute(6, 7) << endl;  // 13

    proc.setOperation(mul);
    cout << "切换为乘法: " << proc.execute(6, 7) << endl;           // 42
}

// =============================================================
//  六、函数指针作为返回值
// =============================================================

/**
 * 根据操作符返回对应的函数指针
 * 返回类型 IntOp = int(*)(int, int)
 */
IntOp getOperation(char op) {
    switch (op) {
        case '+': return add;
        case '*': return mul;
        default:  return nullptr;  // 返回空指针表示不支持
    }
}

void demo_return() {
    cout << "\n========== 5. 函数指针作为返回值 ==========\n";

    IntOp op = getOperation('+');
    if (op) {
        cout << "操作符 '+' 的结果: " << op(10, 5) << endl;
    }

    op = getOperation('*');
    if (op) {
        cout << "操作符 '*' 的结果: " << op(10, 5) << endl;
    }
}

// =============================================================
//  七、函数指针与 std::function 对比（C++11）
// =============================================================

void demo_vs_function() {
    cout << "\n========== 6. 函数指针 vs std::function ==========\n";

    // ----- 函数指针 -----
    using FP = int(*)(int, int);
    FP fp = add;
    cout << "函数指针: fp(3, 4) = " << fp(3, 4) << endl;

    // ✅ 可以指向非捕获 lambda
    fp = [](int a, int b) { return a - b; };
    cout << "函数指针指向lambda: (3-4) = " << fp(3, 4) << endl;

    // ❌ 不可以指向捕获 lambda
    // int factor = 2;
    // fp = [factor](int a, int b) { return (a + b) * factor; };  // 编译错误！

    // ----- std::function（类型擦除，更灵活）-----
    using StdFunc = function<int(int, int)>;
    StdFunc sf = add;
    cout << "std::function: sf(3, 4) = " << sf(3, 4) << endl;

    int factor = 2;
    sf = [factor](int a, int b) { return (a + b) * factor; };  // ✅ 可以捕获
    cout << "std::function捕获lambda: (3+4)*2 = " << sf(3, 4) << endl;

    // 💡 对比总结
    cout << "\n--- 对比 ---\n";
    cout << "函数指针     : 轻量（8字节），不可捕获，C兼容\n";
    cout << "std::function: 较重（32~48字节），可捕获任何可调用对象\n";
}

// =============================================================
//  八、成员函数指针（特殊语法）
// =============================================================

struct Calculator {
    int offset;

    Calculator(int off) : offset(off) {}

    int addWithOffset(int x) {
        return x + offset;
    }

    int subWithOffset(int x) {
        return x - offset;
    }
};

void demo_member_ptr() {
    cout << "\n========== 7. 成员函数指针 ==========\n";

    // 声明成员函数指针：返回 int，接受 int，属于 Calculator 类
    using MemberFunc = int(Calculator::*)(int);

    // 赋值
    MemberFunc mf = &Calculator::addWithOffset;

    // 调用（必须通过对象）
    Calculator calc(10);
    Calculator* pcalc = &calc;

    cout << "calc.addWithOffset(5) = " << (calc.*mf)(5) << endl;   // 15
    cout << "pcalc->addWithOffset(5) = " << (pcalc->*mf)(5) << endl; // 15

    // 切换成员函数
    mf = &Calculator::subWithOffset;
    cout << "切换后: calc.subWithOffset(5) = " << (calc.*mf)(5) << endl; // 5
}

// =============================================================
//  九、实用技巧与注意事项
// =============================================================

void demo_tips() {
    cout << "\n========== 8. 实用技巧与注意事项 ==========\n";

    // 1) 用 auto 简化声明（C++11）
    auto fp = hello;        // 自动推导为 void(*)(int)
    fp(100);

    // 2) 检查函数指针是否为 nullptr
    Callback p = nullptr;
    // if (p) p(42);        // 安全：跳过空指针
    // 如果调用空函数指针 → 段错误！

    // 3) 函数指针的大小
    cout << "函数指针大小: " << sizeof(Callback) << " 字节\n";
    cout << "std::function大小: " << sizeof(function<void(int)>) << " 字节\n";

    // 4) 重载函数的函数指针需要转型
    // void foo(int);
    // void foo(double);
    // auto p = foo;                    // ❌ 二义性
    // auto p = static_cast<void(*)(int)>(foo);  // ✅ 指定版本

    // 5) 函数指针作为模板参数（零开销）
    // template<void(*F)(int)>
    // void wrapper(int x) { F(x); }
    // wrapper<hello>(42);
}

// =============================================================
//  十、综合案例 —— 实现简单的计算器
// =============================================================

// 用函数指针表实现一个简单的四则计算器

void demo_calculator() {
    cout << "\n========== 综合案例：函数指针计算器 ==========\n";

    // 定义运算函数
    auto calc_add = [](int a, int b) { return a + b; };
    auto calc_sub = [](int a, int b) { return a - b; };
    auto calc_mul = [](int a, int b) { return a * b; };
    auto calc_div = [](int a, int b) -> int {
        if (b == 0) {
            cerr << "错误：除数不能为0！\n";
            return 0;
        }
        return a / b;
    };

    // 用函数指针数组实现运算映射
    struct OpEntry {
        char symbol;
        IntOp func;
    };

    OpEntry ops[] = {
        {'+', calc_add},
        {'-', calc_sub},
        {'*', calc_mul},
        {'/', calc_div}
    };

    // 计算
    int x = 20, y = 5;
    cout << "计算: x = " << x << ", y = " << y << "\n\n";

    for (auto& entry : ops) {
        if (entry.func) {
            cout << "  " << x << " " << entry.symbol << " " << y
                 << " = " << entry.func(x, y) << endl;
        }
    }
}

// =============================================================
//  main —— 总入口
// =============================================================

int main() {
    cout << "========================================\n";
    cout << "  C++ 函数指针 完整教程\n";
    cout << "  using ptr = void(*)(int)\n";
    cout << "========================================\n";

    demo_basic();
    demo_callback();
    demo_array();
    demo_class_member();
    demo_return();
    demo_vs_function();
    demo_member_ptr();
    demo_tips();
    demo_calculator();

    cout << "\n========================================\n";
    cout << "  教程结束\n";
    cout << "========================================\n";
    return 0;
}
