#include<iostream>
#include<fstream>

#define cin fin//复制时删除

using  namespace std;

ifstream fin("csp_input.txt");//复制时删除

const int maxn = 500;
int N,M,L;

int G[maxn][maxn], LL[maxn] = {0};

int main() {
	cin >> M >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> G[i][j];
			LL[G[i][j]]++;
		}
	}

	for (int i = 0; i < L; i++) {
		cout << LL[i];
		if (i == L - 1) cout << endl;
		else cout << ' ';
	}

	return 0;
}
