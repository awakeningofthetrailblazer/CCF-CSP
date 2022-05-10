#include<iostream>
#include<fstream>
#include<vector>
#include<iomanip>
#include<unordered_map>
#include<utility>
#include<map>

#define cin fin//复制时删除

using  namespace std;

ifstream fin("csp_input.txt");//复制时删除

int N, K, x, y, cnt;

unordered_map<int, int> sig;

int main() {
	cin >> N >> K;

	cnt = 0;

	sig[0] = 1;

	while (K--)  {
		cin >> x >> y;
		if (!sig[y]) cnt++;
		sig[x] = 1;
	}

	cout << cnt << endl;

	return 0;
}
