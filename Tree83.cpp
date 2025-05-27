#include "pt4.h"
using namespace std;

// 词法分析器：将输入字符串转换为标记队列
vector<string> tokenize(const string& s) {
    vector<string> tokens;
    for (int i = 0; i < s.size();) {
        if (isalpha(s[i])) { // 处理函数名M/m
            tokens.push_back(s.substr(i, 1));
            i++;
        } else if (isdigit(s[i])) { // 处理数字
            int j = i;
            while (j < s.size() && isdigit(s[j])) j++;
            tokens.push_back(s.substr(i, j - i));
            i = j;
        } else { // 处理符号
            tokens.push_back(string(1, s[i]));
            i++;
        }
    }
    return tokens;
}

// 递归解析表达式构建语法树
PNode parse_expression(vector<string>& tokens, int& pos) {
    if (pos >= tokens.size()) return nullptr;
    
    string tok = tokens[pos];
    
    // 处理函数节点
    if (tok == "M" || tok == "m") {
        PNode node = new Node;
        node->Data = (tok == "M") ? -1 : -2;
        
        pos += 2; // 跳过 "M(" 或 "m("
        node->Left = parse_expression(tokens, pos);
        pos++;    // 跳过 ","
        node->Right = parse_expression(tokens, pos);
        pos++;     // 跳过 ")"
        
        return node;
    }
    // 处理数字节点
    else if (isdigit(tok[0])) {
        PNode node = new Node;
        node->Data = stoi(tok);
        node->Left = node->Right = nullptr;
        pos++;
        return node;
    }
    
    return nullptr;
}

void Solve() {
    Task("Tree83");
    string s;
    pt >> s; // 读取输入表达式
    
    vector<string> tokens = tokenize(s);
    int pos = 0;
    PNode root = parse_expression(tokens, pos);
    
    pt << root;
}
