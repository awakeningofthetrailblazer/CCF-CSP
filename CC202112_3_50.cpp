#include<iostream>
#include<fstream>
#include<vector>
#include<unordered_map>
#include<string>

#define cin fin//复制时删除

using  namespace std;

ifstream fin("csp_input.txt");//复制时删除

const int mod_cell = 929;

int W, S;
string str;
vector<int> codes;


void init();

void Coding();

void display();

int numMod(int x);

vector<int> polyG(int k);

vector<int> polyMulti(vector<int> a,vector<int> b);

vector<int> polyMod(vector<int> a, vector<int> b);

int main() {

	init();

	Coding();

	display();

	return 0;
}

void init() {
	cin >> W >> S;
	cin >> str;
}

void Coding() {
	vector<int> que;
	bool is_small = false;
	bool is_large = true;
	bool is_num = false;
	for (int i = 0; i < str.length(); i++) {

		if (str[i] >= 'A' && str[i] <= 'Z') {
			if (!is_large) {
				if(is_small) que.push_back(28);
				que.push_back(28);
				is_large = true;
				is_small = false;
				is_num = false;
			}
			que.push_back(str[i] - 'A');
		}
		else if (str[i] >= 'a' && str[i] <= 'z') {
			
			if (!is_small) {
				que.push_back(27);
				is_small = true;
				is_large = false;
				is_num = false;
			}
			
			
			que.push_back(str[i] - 'a');
		}
		else if(str[i] >= '0' && str[i] <= '9'){
			
			if (!is_num) {
				que.push_back(28);
				is_num = true;
				is_small = false;
				is_large = false;
			}
			
			que.push_back(str[i] - '0');
		}
	}

	if (que.size() % 2) que.push_back(29);

	int cd, lencode;

	codes.push_back(0);

	for (int i = 0; 2 * i < que.size(); i++) {
		cd = 30 * que[2 * i] + que[2 * i + 1];
		codes.push_back(cd);
	}

	int k = 1 << (S + 1);
	if (S == -1) k = 0;

	int temp = (k + codes.size()) % W;

	if (temp) {
		for (int i = 0; i < W - temp; i++) codes.push_back(900);
	}

	lencode = codes.size();

	int len = codes.size();

	codes[0] = lencode;

	if (S != -1) {
		for (int i = 0; i < k; i++) codes.push_back(0);

		vector<int> poly_g = polyG(k);

		vector<int> poly_r = polyMod(codes, poly_g);

		for (int i = 0; i < k; i++) {
			codes[len + i] = numMod(poly_r[i]);
		}
	}
}

void display() {
	for (int a : codes) cout << a << endl;
	//cout << "size" << codes.size() << endl;
}

vector<int> polyG(int k) {
	vector<int> res = { 1 }, temp = { 1,-3 };
	int three = 3;
	for (int i = 0; i < k; i++) {
		res = polyMulti(res, temp);
		temp[1] *= three;
		temp[1] = numMod(temp[1]);
	}

	int t = 0;
	//for (int a : res) cout <<t++<<"=="<< a << endl;

	return res;
}

vector<int> polyMulti(vector<int> a, vector<int> b) {
	vector<int> res;
	int len = a.size() + b.size() - 1;
	int ak = a.size(), bk = b.size();
	for (int i = 0; i < len; i++) {
		int tt = len - i - 1;
		long long temp = 0;

		for (int j = 0; j <= tt; j++) {
			int aid = j, bid = tt - aid;

			int ai = ak - aid - 1, bi = bk - bid - 1;

			if (ai < 0 || ai > ak - 1 || bi < 0 || bi > bk - 1) continue;

			temp += a[ai] * b[bi];
			temp = numMod(temp);
		}

		res.push_back(temp);
	}

	return res;
}

vector<int> polyMod(vector<int> a, vector<int> b) {
	vector<int> poly_mod;

	int alen = a.size(), blen = b.size();

	for (int i = 0; i < alen - blen + 1; i++) {

		int res = a[i];

		for (int j = 0; j < blen; j++) {
			a[i + j] -= res * b[j];
			//cout <<  ' ' << a[i + j];
		}
		//cout << endl;

	}

	for (int i = 0; i < blen - 1; i++) {
		poly_mod.push_back(-a[alen - blen + i + 1]);
		//cout <<' '<< poly_mod[i] << endl;
	}


	return poly_mod;
}

int numMod(int x) {
	if (x<mod_cell && x>-mod_cell) return x;

	if (x >= 0) return x % mod_cell;
	else return mod_cell + x % mod_cell;
}
