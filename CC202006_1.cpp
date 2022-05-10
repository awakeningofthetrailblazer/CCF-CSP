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

struct node {
	int x, y;
	char type;
};

vector<node> nd;

int main() {
	int N, M, xx, yy;
	char type;

	cin >> N >> M;

	while (N--) {
		cin >> xx >> yy >> type;
		nd.push_back({ xx,yy,type });
	}

	int A, B, C, vv;
	char pos_type = 'N', neg_type = 'N';

	while (M--) {
		bool fitAwell = true, fitBwell = true;
		int tempA = -1, tempB = -1;
		cin >> A >> B >> C;
		for (node temp : nd) {
			vv = A + B * temp.x + C * temp.y;
			if ((temp.type == 'A' && vv < 0) || (temp.type == 'B' && vv > 0)) fitAwell = false;
			if ((temp.type == 'A' && vv > 0) || (temp.type == 'B' && vv < 0)) fitBwell = false;
		}

		if (fitAwell || fitBwell ) cout << "Yes" << endl;
		else cout << "No" << endl;
	}

	return 0;
}
