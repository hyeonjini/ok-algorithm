#include <bits/stdc++.h>

using namespace std;

/*
*/

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		string input, command, result;
		int c_len, i_len;

		cin >> command;
		cin >> i_len;
		c_len = command.length();
		cin >> input;
		int left = 0 , right = 0;
		vector<int> number;

		for (int j = 0; j < i_len; j++) {
			left = right + 1;
			right = input.find(",", left + 1);
			if (right == -1) {
				right = input.length() -1;
			}
			int temp = stoi(input.substr(left, right - left));
			number.push_back(temp);
		}
		
		bool togle = true;
		
		left = 0; right = i_len -1;

		for (int j = 0; j < c_len; j++) {
			if (command[j] == 'R') {
				togle = !togle;
			}
			else {
				i_len--;
				if (i_len >= 0) {
					if (togle) {
						left++;
					}
					else {
						right--;
					}
					
				}
				else {
					result = "error";
					break;
				}
				
			}
		}
		if (i_len >= 0) {
			cout << "[";
			if (togle) {
				for (int j = left; j <= right; j++) {
					cout << number[j];
					if (j != right) {
						cout << ",";
					}
				}
			}
			else {
				for (int j = right; j >= left; j--) {
					cout << number[j];
					if (j != left ) {
						cout << ",";
					}
				}
			}
			
			cout << "]"<< endl;
		}
		else {
			cout << result << endl;
		}
		
	}
	return 0;
}