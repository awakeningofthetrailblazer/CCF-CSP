#include<iostream>
#include<fstream>

#define cin fin//复制时删除

using  namespace std;

ifstream fin("csp_input.txt");//复制时删除

const int maxn = 601;
int N,L,R,T;

int G[maxn][maxn], sum[maxn][maxn] = {0};

void avgCal();

double avg(int x, int y);

int main() {
	cin >> N >> L >> R >> T;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> G[i][j];
			
			sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + G[i][j];
		}
	}

	avgCal();

	return 0;
}

void avgCal() {
	int res = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (avg(i, j) <= T) res++;
		}
	}

	cout << res << endl;
}

double avg(int x, int y) {
	double res=0,cnt=0;
	int u = y - R > 0 ? y - R - 1 : 0;
	int d = y + R <= N ? y + R : N;
	int l = x - R > 0 ? x - R - 1 : 0;
	int r = x + R <= N ? x + R : N;

	cnt = (r - l)*(d - u);

	//cout << x << ':' << l << ' ' << r << endl;
	//cout << y << ':' << u << ' ' << d << endl;

	res = sum[r][d] + sum[l][u] - sum[r][u] - sum[l][d];

	//cout << res << ' ' << cnt << ' ' << res / cnt << endl;

	return res/cnt;
}
