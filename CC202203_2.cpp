#include<iostream>
#include<fstream>
#include<vector>
#include<iomanip>
#include<unordered_map>
#include<utility>
#include<algorithm>
#include<map>

#define cin fin//复制时删除

using  namespace std;

ifstream fin("csp_input.txt");//复制时删除

int N, M, K;

unordered_map<int, int> clc;

int main() {

	cin >> N >> M >> K;

	int t, c, q, len=0;
	for (int i = 0; i < N; i++) {
		cin >> t >> c;
		clc[t+1]--;
		clc[max(1, t - c + 1)]++;
		len = max(len, t + 1);

		//cout << max(1, t - c + 1) << " " << t + 1 << " " << clc[max(1, t - c + 1)] << ' ' << clc[t + 1] << endl;
	}

	for (int i = 1; i <= len; i++) {
		clc[i] += clc[i - 1];
		//cout << i << ' ' << clc[i] << endl;
	}

	while (M--) {
		cin >> q;

		if (len < q + K) {
			for (int i = len; i < q + K ; i++) clc[i] += clc[i - 1];
			len = q + K;
		}

		cout << clc[q + K] << endl;
	}

	return 0;
}
