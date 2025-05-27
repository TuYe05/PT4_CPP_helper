#include "pt4.h"
#include <string>
using namespace std;

// 递归解析表达式
int parse_expression(const string& s, int& pos) {
    if (isdigit(s[pos])) { // 处理数字
        int val = s[pos++] - '0';
        return val;
    }
    
    // 处理函数调用
    char func = s[pos];
    pos += 2; // 跳过 "M(" 或 "m("
    
    // 解析第一个参数
    int arg1 = parse_expression(s, pos);
    pos++; // 跳过逗号
    
    // 解析第二个参数
    int arg2 = parse_expression(s, pos);
    pos++; // 跳过 ")"
    
    // 返回计算结果
    return func == 'M' ? max(arg1, arg2) : min(arg1, arg2);
}

void Solve() 
{
    Task("Recur20");
    string s;
    pt >> s;
    int pos = 0;
    pt << parse_expression(s, pos);
}
