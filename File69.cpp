#include "pt4.h"
#include <fstream>
using namespace std;

bool isSummer(int month) {
    return month >= 6 && month <= 8;
}

void Solve() {
    Task("File69");
    
    string inputFile, outputFile;
    pt >> inputFile >> outputFile;

    ifstream fin(inputFile, ios::binary);
    ofstream fout(outputFile, ios::binary);

    fin.seekg(0, ios::end);
    int recordCount = fin.tellg() / 80;
    fin.seekg(0, ios::beg);

    bool hasSummerDates = false;
    char buffer[80];

    for (int i = 0; i < recordCount; ++i) {
        fin.read(buffer, 80);
        string dateStr(buffer);
        
        // 解析日期格式：dd/mm/yyyy
        int day = stoi(dateStr.substr(0, 2));
        int month = stoi(dateStr.substr(3, 2));
        int year = stoi(dateStr.substr(6, 4));

        if (isSummer(month)) {
            hasSummerDates = true;
            // 写入完整日期字符串
            fout.write(buffer, 80);
        }
    }

    // 关闭文件流
    fin.close();
    fout.close();

    // 如果没有夏季日期则清空文件
    if (!hasSummerDates) {
        ofstream clearFile(outputFile, ios::trunc);
        clearFile.close();
    }
}
