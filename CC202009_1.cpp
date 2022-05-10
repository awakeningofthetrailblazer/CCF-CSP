#include<iostream>
#include<fstream>
#include<vector>
#include<iomanip>
#include<unordered_map>
#include<utility>
#include<algorithm>
#include<map>
#include<string>
#include<cmath>


#define cin fin//复制时删除

using  namespace std;

ifstream fin("csp_input.txt");//复制时删除

const int maxn = 210;

int N;

struct NODE{
	int id;
	int x, y;
	double d;
}nd[maxn];

bool cmp(NODE a,NODE b);

int main() {
	nd[0].id = 0;
	cin >> N >> nd[0].x >> nd[0].y;

	for (int i = 1; i <= N; i++) {
		cin >> nd[i].x >> nd[i].y;
		nd[i].id = i;
		nd[i].d = sqrt((nd[i].x - nd[0].x)*(nd[i].x - nd[0].x) + (nd[i].y - nd[0].y)*(nd[i].y - nd[0].y));
	}

	sort(nd + 1, nd + N + 1, cmp);

	for (int i = 1; i <= 3; i++) cout << nd[i].id << endl;

	return 0;
}

bool cmp(NODE a, NODE b) {
	if (a.d != b.d)return a.d < b.d;
	else return a.id < b.id;
}
