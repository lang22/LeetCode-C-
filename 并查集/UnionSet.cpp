#include <iostream>
#include <vector>
#define swap(x, y) x = (x)+(y); y = (x)-(y); x = (x)-(y);
using namespace std;

class UnionSet
{
private:
	/* data */
	vector<int> parent, rank;
	int size;

public:
	UnionSet(int n);
	~UnionSet();
	int find(int x);
	void Union(int x, int y);
	void print();
};

UnionSet::UnionSet(int n)
{
	size = n;
	rank.resize(n, 1);
	parent.resize(n);
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}
}

UnionSet::~UnionSet()
{
}

int UnionSet::find(int x) { //查询时路径压缩
	return parent[x] != x ? find(parent[x]) : parent[x];
}

void UnionSet::Union(int x, int y) { //按秩合并
	int fx = find(x);
	int fy = find(y);
	if (fx == fy) {
		cout << "[" << x << "," << y << "]" << " is a redundant edge!" << endl;
		return;
	}
	if (rank[fx] < rank[fy]) {
		swap(fx, fy);
	}
	parent[fy] = fx;
	rank[fx] += rank[fy];
}

void UnionSet::print() {
	for (int i = 0; i < size; i++) {
//		printf("%d -> %d\n", i, parent[i]);
		 std::cout<<"i"<<" -> "<<"parent[i]"<<endl;
	}
}

int main() {
	UnionSet uset(6);
	vector<vector<int>> edges = { {1, 2},{2, 3},{3, 4},{1, 4},{1, 5} };
	for (auto edge : edges) {
		uset.Union(edge[0], edge[1]);
	}
	uset.print();
	return 0;
}