#include <bits/stdc++.h>

using namespace std;

/*
*/

struct point {
	int r;
	int c;
};

int result = 9999999;
vector<point> chickens;
vector<point> home;


void combi(vector<point> pick ,int r, int index, int depth) {
	if (r == 0) {
		int r_temp = 0;
		for (int i = 0; i < home.size(); i++) {
			int temp = 100000;
			for (int j = 0; j < pick.size(); j++) {
				int x = home[i].r - pick[j].r;
				int y = home[i].c - pick[j].c;
				if (x < 0) x *= -1;
				if (y < 0) y *= -1;
				if (temp > x + y) temp = x + y;
			}
			r_temp += temp;
		}
		if (result > r_temp) result = r_temp;
	}
	else if (depth == chickens.size()) {
		return;
	}
	else {
		pick[index] = chickens[depth];
		combi(pick, r - 1, index + 1, depth + 1);

		combi(pick, r, index, depth + 1);
	}
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N, M;

	int input[50][50] = { 0 };

	cin >> N >> M;
	vector<point> pick(M);


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> input[i][j];
			if (input[i][j] == 2) {
				point temp;
				temp.r = i;
				temp.c = j;
				chickens.push_back(temp);
			}
			if (input[i][j] == 1) {
				point temp;
				temp.r = i;
				temp.c = j;
				home.push_back(temp);
			}
		}
	}
	
	combi(pick, M, 0, 0);
	

	cout << result;


	return 0;
}