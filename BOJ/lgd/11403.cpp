#include <bits/stdc++.h>

using namespace std;

/*
*/
vector<vector<int>> graph(100, vector<int>(0, 0));

void dfs(vector<int> &check, int n1, int n2) {

	for(int i = 0; i< graph[n1].size(); i++){
		int next = graph[n1][i];
		if (check[next] == 0) {
				check[next] = 1;
				dfs(check, next, n2);
		}
	}
}
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	


	int input;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> input;
			if (input == 1) {
				graph[i].push_back(j);
			}
		}
	}
	vector<int> check(100, 0);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j <N; j++) {
			dfs(check,i, j);
			cout << check[j] << " ";
			for (int k = 0; k < N; k++) {
				check[k] = 0;
			}
		}
		cout << endl;
	}

	return 0;
}