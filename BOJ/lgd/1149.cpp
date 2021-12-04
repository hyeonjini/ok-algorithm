#include <bits/stdc++.h>

using namespace std;

/*
*/

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
		
	int distance[1000][3] = { -1 };
	int input[1000][3];
	int N;
	int result = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> input[i][j];
		}
	}
	for (int i = 0; i < 3; i++) {
		distance[0][i] = input[0][i];
	}

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			if (j == 0) {
				distance[i][j] =input[i][j] + min(distance[i-1][1], distance[i-1][2]);
			}
			else if (j == 1) {
				distance[i][j] = input[i][j] + min(distance[i - 1][0], distance[i - 1][2]);
			}
			else {
				distance[i][j] = input[i][j] + min(distance[i - 1][0], distance[i - 1][1]);
			}
		}
	}

	result = distance[N - 1][0];

	for (int i = 1; i < 3; i++) {
		if (result > distance[N - 1][i]) {
			result = distance[N - 1][i];
		}
	}

	cout << result;

	return 0;
}