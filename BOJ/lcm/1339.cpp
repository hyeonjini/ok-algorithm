#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    unordered_map<char, int> m;

    for(int i=0; i<n; i++){
        string input;
        cin >> input;
        int pos = 1;
        
        for(int j = input.size()-1; j >= 0; j--){ // 자리(idx) 더하기
            m[input[j]] += pos;
            pos *= 10;
        }
    }

    vector<int> max;
    
    for(auto& i : m)
        max.push_back(i.second);
    
    sort(max.begin(), max.end(), greater<int>()); // 내림차순 정렬

    int cnt = 9;
    int sum = 0;
    for(int i=0; i<max.size(); i++){
        sum += max[i] * cnt--;
    }

    cout << sum << endl;
    return 0;
}