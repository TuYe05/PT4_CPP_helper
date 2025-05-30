#include "pt4.h"
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

void Solve() {
    Task("Text43");
    
    // 输入参数解析
    double intervalStart, intervalEnd;   // 区间起止点
    int segmentationCount;               // 区间分割数
    string outputFilename;               // 输出文件名
    pt >> intervalStart >> intervalEnd >> segmentationCount >> outputFilename;

    // 计算步长（避免除零错误，由题目保证segmentationCount > 0）
    const double stepSize = (intervalEnd - intervalStart) / segmentationCount;
    
    // 创建输出文件流并设置数值格式
    ofstream outputFile(outputFilename);
    outputFile << fixed                  // 固定小数格式
               << setprecision(8);       // 默认8位小数精度
    
    // 生成三角函数表
    for (int stepIndex = 0; stepIndex <= segmentationCount; ++stepIndex) {
        // 计算当前点的x坐标
        const double currentX = intervalStart + stepIndex * stepSize;
        
        // 格式化输出三列数据：
        outputFile << setw(8)  << setprecision(4)  << currentX    // X列：8字符宽，4位小数
                   << setw(12) << setprecision(8)  << sin(currentX)  // 正弦列：12字符宽
                   << setw(12) << setprecision(8)  << cos(currentX)  // 余弦列：12字符宽
                   << endl;
    }

    // 显式关闭文件流（非必要但推荐）
    outputFile.close();
}
