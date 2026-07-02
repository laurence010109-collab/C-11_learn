/*
 * sstream 学习 demo
 * ================
 * <sstream> 包含三个类：
 *   istringstream  - 从字符串读（解析）
 *   ostringstream  - 往字符串写（格式化）
 *   stringstream   - 既能读又能写
 *
 * sstream 和 fstream 的 API 是统一的（都继承自 iostream），
 * 只是 fstream 背后是文件，sstream 背后是字符串。
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>  // for setprecision

using namespace std;

// ============================================================
// 1. istringstream — 字符串解析
// ============================================================
void demo_istringstream()
{
    cout << "===== istringstream: 字符串解析 =====\n";

    // --- 场景 1：解析 CSV 行 ---
    string line = "张三,25,85.5";
    istringstream iss(line);
    string name;
    int age;
    double score;
    char comma;  // 用来吃掉逗号

    // 用 getline 按分隔符提取（更稳）
    getline(iss, name, ',');
    iss >> age >> comma >> score;
    cout << "姓名: " << name << ", 年龄: " << age << ", 分数: " << score << "\n\n";

    // --- 场景 2：分割空格分隔的字符串 ---
    string data = "hello world c++ sstream";
    istringstream iss2(data);
    string word;
    vector<string> words;
    while (iss2 >> word)  // >> 默认按空格/换行分割
        words.push_back(word);

    cout << "空格分割结果: ";
    for (const auto& w : words)
        cout << w << " ";
    cout << "\n\n";
}

// ============================================================
// 2. ostringstream — 字符串格式化（拼字符串）
// ============================================================
void demo_ostringstream()
{
    cout << "===== ostringstream: 字符串格式化 =====\n";

    // --- 场景 1：拼接多种类型 ---
    ostringstream oss;
    string name = "张三";
    int age = 25;
    double salary = 12345.6789;

    oss << "员工信息\n";
    oss << "姓名: " << name << "\n";
    oss << "年龄: " << age << "\n";
    oss << "薪资: " << fixed << setprecision(2) << salary << " 元\n";

    string result = oss.str();  // .str() 提取最终字符串
    cout << result << "\n";

    // --- 场景 2：ostringstream 比 + 拼接高效 ---
    // 用 + 拼接字符串会产生很多临时对象，ostringstream 更高效
    ostringstream oss2;
    for (int i = 0; i < 5; ++i)
        oss2 << "item_" << i << (i < 4 ? ", " : "");

    cout << "拼接结果: " << oss2.str() << "\n\n";
}

// ============================================================
// 3. stringstream — 既读又写（配合 .seekp / .seekg）
// ============================================================
void demo_stringstream()
{
    cout << "===== stringstream: 读写双向 =====\n";

    stringstream ss;
    // 写入
    ss << "100 200 300";
    cout << "写入后: " << ss.str() << "\n";

    // 读取
    int a, b, c;
    ss >> a >> b >> c;
    cout << "读取: " << a << " " << b << " " << c << "\n";

    // 这时流位置已经在末尾了（因为读完了）
    // 清空状态 + 重置位置
    ss.clear();                // 清除 EOF 标志
    ss.str("");                // 清空内容
    ss << "新内容: " << 42;    // 复用
    cout << "复用后: " << ss.str() << "\n\n";
}

// ============================================================
// 4. 综合练习：解析日志文件（Day 6 的实战任务）
// ============================================================
void demo_log_parser()
{
    cout << "===== 综合：日志解析器 =====\n";

    // 模拟一个日志文件内容（实际中从 fstream 读入）
    string log_data = R"(
[INFO] 2024-01-15 10:30:00 用户登录 user_id=1001
[ERROR] 2024-01-15 10:31:05 数据库连接失败 errno=1040
[WARN] 2024-01-15 10:32:10 磁盘使用率 85%
[INFO] 2024-01-15 10:33:00 用户登出 user_id=1001
[ERROR] 2024-01-15 10:34:22 请求超时 timeout=5000ms
)";

    struct LogEntry {
        string level;   // INFO / WARN / ERROR
        string date;
        string time;
        string message;
    };

    vector<LogEntry> logs;
    istringstream log_stream(log_data);
    string line;

    while (getline(log_stream, line)) {
        if (line.empty()) continue;  // 跳过空行

        // 一行格式: [LEVEL] YYYY-MM-DD HH:MM:SS 消息
        istringstream line_ss(line);

        LogEntry entry;
        char bracket;  // 吃掉 '[' 和 ']'

        line_ss >> bracket;              // [
        getline(line_ss, entry.level, ']');  // 读到 ] 为止
        line_ss >> entry.date >> entry.time;
        getline(line_ss, entry.message);     // 剩下的都是消息

        logs.push_back(entry);
    }

    // 统计输出
    cout << "共解析 " << logs.size() << " 条日志:\n";
    for (const auto& log : logs) {
        cout << "  [" << log.level << "] "
             << log.date << " " << log.time
             << " -" << log.message << "\n";
    }

    // 过滤 ERROR 级别
    cout << "\nERROR 级别的日志:\n";
    for (const auto& log : logs) {
        if (log.level == "ERROR")
            cout << "  " << log.date << " " << log.time << " -" << log.message << "\n";
    }
    cout << "\n";
}

// ============================================================
// 5. 经典面试题：字符串与数字互转
// ============================================================
void demo_type_conversion()
{
    cout << "===== 类型转换（面试高频） =====\n";

    // --- 数字 -> 字符串 ---
    ostringstream oss;
    oss << 3.14159 << " 是圆周率, " << 42 << " 是答案";
    string s = oss.str();
    cout << "数字到字符串: " << s << "\n";

    // --- 字符串 -> 数字 ---
    string nums = "3.14 2.72 1.41";
    istringstream iss(nums);
    double pi, e, sqrt2;
    iss >> pi >> e >> sqrt2;
    cout << "字符串到数字: π=" << pi << " e=" << e << " √2=" << sqrt2 << "\n";

    // --- 注意事项：失败的情况 ---
    string bad = "abc123";
    istringstream iss2(bad);
    int val = -1;
    if (iss2 >> val) {
        cout << "转换成功: " << val << "\n";
    } else {
        cout << "转换失败! '" << bad << "' 不是有效数字\n";
    }
    // 注意: abc123 会失败，因为 abc 不是数字开头
    // 但 "123abc" 能成功读取 123（剩下 abc 在流里）
    string mixed = "123abc";
    istringstream iss3(mixed);
    int val2 = -1;
    string rest;
    iss3 >> val2;
    iss3 >> rest;
    cout << "混合字符串: 数字=" << val2 << ", 剩余='" << rest << "'\n\n";
}

// ============================================================
// 6. .str() / .tellp() / .tellg() / .seekp() / .seekg()
// ============================================================
void demo_stream_position()
{
    cout << "===== 流位置操作 =====\n";

    ostringstream oss;
    oss << "Hello";
    oss << " World";

    cout << "最终字符串: " << oss.str() << "\n";
    cout << "当前写入位置 (tellp): " << oss.tellp() << "\n";

    // 在中间插入（注意：不是覆盖，ostringstream 的 seekp 不一定在所有实现上都支持覆盖插入）
    // 这里主要展示 tellp / str 的用法
    string current = oss.str();
    cout << "字符串长度: " << current.size() << "\n\n";
}

int main()
{
    demo_istringstream();
    demo_ostringstream();
    demo_stringstream();
    demo_log_parser();
    demo_type_conversion();
    demo_stream_position();

    return 0;
}
