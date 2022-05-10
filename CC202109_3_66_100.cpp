#include<iostream>
#include<fstream>
#include<vector>
#include<iomanip>
#include<unordered_map>
#include<utility>

#define cin fin//复制时删除

using  namespace std;

ifstream fin("csp_input.txt");//复制时删除

int N, S, P, T;//神经元数目、突触数目、脉冲源、输出时刻
double delta_t;//时间间隔
double v_min, v_max;
int spiking_num_min, spiking_num_max;

unordered_map<int, int> cnt_r;

struct RN {
	double v, u, a, b, c, d;
	unordered_map<int, double> IIt;
};

struct NN {
	double w;
	int D;
};

vector<RN> Rn;//神经元 0~N-1
unordered_map<int, int> spiking_r;//脉冲 N~N+P-1
unordered_map<int, unordered_map<int, NN>> neural;//突触


void init();

void display();

void IterationPart();

void refreshRN(int t, int rk);

void dfs(int x, int t);

static unsigned long next1 = 1;

/* RAND_MAX assumed to be 32767 */
int myrand(void) {
	next1 = next1 * 1103515245 + 12345;
	return((unsigned)(next1 / 65536) % 32768);
}

int main() {
	init();

	IterationPart();

	display();

	return 0;
}

void init() {
	cin >> N >> S >> P >> T;
	cin >> delta_t;
	int tempN = N, x, s, t, D, cnt = N;
	double vv, uu, aa, bb, cc, dd, w;
	while (tempN) {
		//scanf("%d %lf %lf %lf %lf %lf %lf", &x, &vv, &uu, &aa, &bb, &cc, &dd);
		cin >> x >> vv >> uu >> aa >> bb >> cc >> dd;
		RN temp = { vv,uu,aa,bb,cc,dd };
		tempN -= x;
		while (x--) Rn.push_back(temp);
	}
	tempN = P;
	while (tempN--) {
		//scanf_s("%d", &x);//
		cin >> x;
		spiking_r[cnt++] = x;
	}
	tempN = S;
	while (tempN--) {
		//scanf_s("%d %d %f %d", &s, &t, &w, &D);//
		cin >> s >> t >> w >> D;
		neural[s][t] = { w,D };
	}

	for (t = 1; t <= T; t++) {
		for (int i = N; i < N + P; i++) {
			if (spiking_r[i] > myrand()) {
				dfs(i, t);
			}
		}
	}
}

void display() {
	cout << fixed << setprecision(3) << v_min << ' ';
	cout << fixed << setprecision(3) << v_max << endl;
	cout << spiking_num_min << ' ' << spiking_num_max << endl;
}

void IterationPart() {
	for (int t = 1; t <= T; t++) {

		for (int i = 0; i < N; i++) {
			refreshRN(t, i);
		}
	}

	for (int i = 0; i < N; i++) {
		if (i == 0 || Rn[i].v > v_max) v_max = Rn[i].v;
		if (i == 0 || Rn[i].v < v_min) v_min = Rn[i].v;
		if (i == 0 || cnt_r[i] > spiking_num_max) spiking_num_max = cnt_r[i];
		if (i == 0 || cnt_r[i] < spiking_num_min) spiking_num_min = cnt_r[i];
	}

}

void refreshRN(int t, int rk) {
	double bfv = Rn[rk].v, bfu = Rn[rk].u;
	Rn[rk].v = bfv + delta_t * (0.04*bfv*bfv + 5.0 * bfv + 140.0 - bfu) + Rn[rk].IIt[t];
	Rn[rk].u = bfu + delta_t * Rn[rk].a*(Rn[rk].b*bfv - bfu);
	if (Rn[rk].v >= 30.0) {
		dfs(rk, t);
		cnt_r[rk]++;
		Rn[rk].v = Rn[rk].c;
		Rn[rk].u += Rn[rk].d;
	}

	//cout << t << ' ' << Rn[rk].IIt[t] << endl;
	//cout << t << '\t' << Rn[rk].v << endl;
}

void dfs(int x, int t) {

	for (unordered_map<int, NN>::iterator it = neural[x].begin(); it != neural[x].end(); it++) {
		if (it->first < N) {
			Rn[it->first].IIt[t + (it->second).D] += (it->second).w;
			//cout << it->first << ' ' << t + (it->second).D << ' ' << Rn[it->first].IIt[t + (it->second).D] << endl;
		}
		else dfs(it->first, t + (it->second).D);
	}
}
