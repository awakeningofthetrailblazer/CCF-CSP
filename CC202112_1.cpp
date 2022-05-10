#include<iostream>
#include<fstream>
#include<vector>
#include<unordered_map>

#define cin fin//复制时删除

using  namespace std;

ifstream fin("csp_input.txt");//复制时删除

const int maxN = 1e7+1;

int n, N;
vector<int> A;
unordered_map<int, int> Amap,Acnt;

void init();

void calculate();

int main() {
	init();

	calculate();

	return 0;
}

void init() {
	cin >> n >> N;
	int x;
	A.push_back(0);
	Amap[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		A.push_back(x);
		Amap[x] = i;
	}


}

void calculate() {
	int sum = 0;
	for (int i = 1; i < n; i++) {
		sum += i*(A[i+1]-A[i]);
	}
	sum += n * (N - A[n]);
	cout << sum << endl;
}
