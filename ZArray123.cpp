#include <vector>
#include "pt4.h"
using namespace std;

void Solve()
{
    Task("ZArray123");
    int K, n;
    pt >> K >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        pt >> a[i];
    }
    
    vector<vector<int>> series_list;
    if (!a.empty()) {
        vector<int> current = {a[0]};
        for (int i = 1; i < a.size(); ++i) {
            if (a[i] == current.back()) {
                current.push_back(a[i]);
            } else {
                series_list.push_back(current);
                current.clear();
                current.push_back(a[i]);
            }
        }
        series_list.push_back(current);
    }
    
    if (series_list.size() >= K + 1) {
        swap(series_list[0], series_list[K]);
    }
    
    vector<int> new_a;
    for (const auto& s : series_list) {
        new_a.insert(new_a.end(), s.begin(), s.end());
    }
    
    Show(new_a.begin(), new_a.end());
    pt << new_a;
}
