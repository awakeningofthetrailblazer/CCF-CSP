#include<iostream>
#include<fstream>
#include<vector>
#include<unordered_map>

#define cin fin//复制时删除

using  namespace std;

ifstream fin("csp_input.txt");//复制时删除

long long n, N, r;
unordered_map<long long, int> Amap,Aerror;

vector<long long> A;

void init();

void calculate();

long long Fr(long long x);

int main() {
	init();

	calculate();

	return 0;
}

void init() {
	cin >> n >> N;
	long long x;
	Amap[0] = 0;
	A.push_back(0);
	for (int i = 1; i <= n; i++) {
		cin >> x;
		A.push_back(x);
		Amap[x] = i;
	}

	r = N / (n + 1);

}

void calculate() {
	//cout << r << endl;
	//for (int i = 0; i < N; i++) cout <<"Fr"<< i << ' ' << Fr(i) << endl;
	long long err = 0;
	long long x, y, r1, r2;
	for (int i = 0; i <= n; i++)  {
		x = A[i], r1 = x / r;
		if (i != n) {
			y = A[i + 1];
		}
		else {
			y = N;
		}
		
		r2 = (y - 1) / r;

		int t = Amap[x];
		long long temp = t * (y - x);
		
		if (r1 >= t && r2 >= t) {
			err += Fr(y - 1) - Fr(x - 1) - temp;
		}
		else if (r1 <= t && r2 <= t) {
			err -= Fr(y - 1) - Fr(x - 1) - temp;
		}
		else if (r1 <= t && r2 >= t) {
			err += Fr(y - 1) - Fr(r*(t + 1) - 1) - t * (y - r * (t + 1)) - Fr(r*t - 1) + Fr(x - 1) + t * (r*t - x);
		}
		else {
			err -= Fr(y - 1) - Fr(r*(t + 1) - 1) - t * (y - r * (t + 1)) - Fr(r*t - 1) + Fr(x - 1) + t * (r*t - x);
		}

		cout <<t<<' '<<A[i]<<' '<< err << endl;
	}
	


	cout << err << endl;
}

long long Fr(long long x) {
	x = x+1;
	long long res = (x%r)*(x / r) + r*(x / r - 1)*(x / r) / 2;
	return res;
}
