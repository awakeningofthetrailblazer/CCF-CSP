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
#include<unordered_set>


#define cin fin//复制时删除

using  namespace std;

ifstream fin("csp_input.txt");//复制时删除

int main() {
	int N, A, B, id, vlu;
	long long res = 0;
	cin >> N >> A >> B;

	unordered_map<int, int> U;

	while (A--) {
		cin >> id >> vlu;
		U[id] = vlu;
	}
	while (B--) {
		cin >> id >> vlu;
		res += vlu * U[id];
	}

	cout << res << endl;

	return 0;
}
