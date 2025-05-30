#include "pt4.h"
#include <fstream>
#include <vector>
using namespace std;

void Solve() {
    Task("File52");

    string archiveName;
    int fileCount;
    pt >> archiveName >> fileCount;

    vector<string> srcFiles(fileCount);
    for (int i = 0; i < fileCount; ++i) {
        pt >> srcFiles[i];
    }

    ofstream fout(archiveName, ios::binary);
    if (!fout) {
        pt << "Cannot create archive file";
        return;
    }

    vector<ifstream> fileStreams;
    vector<int> allCounts;
    vector<vector<int>> allData;

    // 第一阶段：收集元数据和内容
    for (auto& filename : srcFiles) {
        ifstream fin(filename, ios::binary);
        if (!fin) {
            pt << "Cannot open source file: " << filename;
            return;
        }

        fin.seekg(0, ios::end);
        streamsize fileSize = fin.tellg();
        fin.seekg(0, ios::beg);

        if (fileSize % sizeof(int) != 0) {
            pt << "Invalid file format";
            return;
        }

        int count = static_cast<int>(fileSize / sizeof(int));
        allCounts.push_back(count);

        vector<int> buffer(count);
        fin.read(reinterpret_cast<char*>(buffer.data()), fileSize);
        allData.push_back(move(buffer));

        fileStreams.push_back(move(fin));
    }

    // 第二阶段：写入文件数量
    fout.write(reinterpret_cast<const char*>(&fileCount), sizeof(int));

    // 第三阶段：写入所有组件数量
    for (int cnt : allCounts) {
        fout.write(reinterpret_cast<const char*>(&cnt), sizeof(int));
    }

    // 第四阶段：写入所有文件内容
    for (const auto& data : allData) {
        fout.write(reinterpret_cast<const char*>(data.data()), 
                  data.size() * sizeof(int));
    }
}
