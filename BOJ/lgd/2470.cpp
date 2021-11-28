#include <bits/stdc++.h>

using namespace std;

/*
*/



int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	vector<int> number;
	int sum;

	int N;
	cin >> N;
	
	int input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		number.push_back(input);
	}

	sort(number.begin(), number.end());


	sum = 2100000000;

	int left, right;
	int target;
	int l_index = 0, r_index = N-1;


		left = 0;
		right = N - 1;
		

		while (left < right) {
			target = number[left] + number[right];
			if (target == 0) {
				sum = 0;
				l_index = left;
				r_index = right;
				break;
			}
			else if (target > 0) {
				int temp = sum;
				if (temp < 0) temp *= -1;
				if (target < temp) {
					l_index = left;
					r_index = right;
					sum = number[l_index] + number[r_index];
				}
				right--;
			}
			else {
				int temp = sum;
				if (temp < 0) temp *= -1;
				if (target * -1 < temp) {
					l_index = left;
					r_index = right;
					sum = number[l_index] + number[r_index];
				}
				left++;
			}

		}

		cout << number[l_index] << " " << number[r_index];

	return 0;
}