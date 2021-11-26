#include <bits/stdc++.h>

using namespace std;

/*
*/

struct alpha {
	char a;
	int value;
	int level;
};

bool sort_alpha(const alpha& s1, const alpha& s2) {
	return s1.level > s2.level;
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int N;

	cin >> N;
	string input[10];
	vector<alpha> alphas;

	int result = 0;
	int start = 9;

	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}
	
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < input[i].length(); j++) {
			char temp = input[i][j];
			bool togle = true;
			int level = 1;
			for (int l = 0; l < input[i].length() - j - 1; l++) {
				level = level * 10;
			}
			for (int k = 0; k < alphas.size(); k++) {
				if (alphas[k].a == temp) {
					togle = false;		
					alphas[k].level += level;
					break;
				}
			}
			if (togle) {
				alpha t;
				t.a = temp;
				t.value = -1;
				t.level = level;
				alphas.push_back(t);
			}
		}
	}

	sort(alphas.begin(), alphas.end(), sort_alpha);


	for (int i = 0; i < alphas.size(); i++) {
		alphas[i].value = start--;
		result += alphas[i].value * alphas[i].level;
	}

	cout << result;

	return 0;
}