#include<iostream>
#include<fstream>
#include<vector>
#include<iomanip>
#include<unordered_map>
#include<utility>
#include<map>

#define cin fin//复制时删除

using  namespace std;

ifstream fin("csp_input.txt");//复制时删除

map<int, unordered_map<bool, int>> record;
unordered_map<int, int> theta;

void init();

int main() {
	init();

	int max = -1, max_theta = -1;
	for (unordered_map<int, int>::iterator it = theta.begin(); it != theta.end(); it++) {
		if (it->second > max ) {
			max = it->second;
			max_theta = it->first;
		}
		else if (it->second == max && it->first > max_theta) {
			max_theta = it->first;
		}
	}

	cout << max_theta << endl;

	return 0;
}

void init() {
	int M, y, res, sum_crc=0,sum_err=0;
	
	cin >> M;
	while (M--) {
		cin >> y >> res;
		record[y][res]++;
		if (res) sum_crc++;
	}
	for (map<int, unordered_map<bool,int>>::iterator it = record.begin(); it != record.end(); it++) {
		
		
		//cout << it->first << ' ' << sum_crc << ' ' << sum_err << endl;

		theta[it->first] = sum_err + sum_crc;

		sum_err += (it->second)[false];
		sum_crc -= (it->second)[true];
	}
}
