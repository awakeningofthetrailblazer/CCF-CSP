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

const int maxn = 1024;
int N, K, T;
int XL, XR, YD, YU;

struct  node{
	int x, y;
}nd[maxn];

int main() {
	cin >> N >> K >> T;

	cin >> XL >> YD >> XR >> YU;

	int resPass = 0, resStay = 0;

	while (N--) {
		int x, y, cnt = 0,cnt_stay=0;
		bool isStay = false;
		for (int i = 0; i < T; i++) {
			cin >> x >> y;
			if (x >= XL && x <= XR && y >= YD && y <= YU) {
				cnt++;
				cnt_stay++;
			}
			else {
				if (cnt_stay >= K) isStay = true;
				cnt_stay = 0;
			}
		}

		if (cnt) resPass++;
		if (isStay || cnt_stay >= K) resStay++;
	}

	cout << resPass << endl << resStay << endl;

	return 0;
}
