#include<iostream>
#include<fstream>
#include<vector>
#include<iomanip>
#include<unordered_map>
#include<utility>

#define cin fin//复制时删除

using  namespace std;

ifstream fin("csp_input.txt");//复制时删除

int init();

int main() {
	int res = init();

	cout << res << endl;

	return 0;
}

int init() {
	int N, w, score, res=0;
	cin >> N;
	while (N--) {
		cin >> w >> score;
		res += w * score;
	}

	if (res > 0) return res;
	else return 0;
}
