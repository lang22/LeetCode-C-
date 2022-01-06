#include <iostream>
#include "UFSet.h"

using namespace std;

int main() {
    vector<vector<int>> connections = { {0, 1},{0, 2},{1, 2} };
    int n = 4, cn = connections.size();
    UnionFindSet set(n);
    for(auto c:connections){
        set.Union(c[0], c[1]);
    }
    int need = set.getCP() - 1; // 需要补的边数=连通分量个数-1
    int extra = set.extra; // 冗余边
    cout<<extra<<" "<<need<<endl;
    return extra-need>=0?need:-1;
}
