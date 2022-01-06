//
// Created by lang22 on 2021/1/13.
//

#ifndef LEETCODE_UFSET_H
#define LEETCODE_UFSET_H
#include <iostream>
#include <vector>
#define swap(x, y) x = (x)+(y); y = (x)-(y); x = (x)-(y);
using namespace std;

class UnionFindSet
{
private:
    /* data */
    vector<int> parent, rank;

public:
    int size; // 总点数
    int extra; // 多余边条数
    int cp; // 连通分量个数
    UnionFindSet(int n);
    ~UnionFindSet();
    int find(int x);
    void Union(int x, int y);
    void print();
    int getCP();
};

UnionFindSet::UnionFindSet(int n)
{
    extra = 0;
    cp = 0;
    size = n;
    rank.resize(n, 1);
    parent.resize(n);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
}

UnionFindSet::~UnionFindSet()
{
}

int UnionFindSet::find(int x) { //查询时路径压缩
    return parent[x] = parent[x] != x ? find(parent[x]) : parent[x];
}

void UnionFindSet::Union(int x, int y) { //按秩合并
    int fx = find(x);
    int fy = find(y);
    if (fx == fy) {
        extra ++;
        return;
    }
    if (rank[fx] < rank[fy]) {
        swap(fx, fy);
    }
    parent[fy] = fx;
    rank[fx] += rank[fy];
}

void UnionFindSet::print() {
    for (int i = 0; i < size; i++) {
//        printf("%d -> %d\n", i, parent[i]);
         std::cout<<i<<" -> "<<parent[i]<<endl;
    }
}

int UnionFindSet::getCP() {
    for (int i = 0; i < size; i++) {
        if(parent[i] == i){
            cp++;
        }
    }
    return  cp;
}
#endif //LEETCODE_UFSET_H
