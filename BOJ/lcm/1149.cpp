#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    
    unordered_map<int, vector<int>> m; // i 번째 집의 색칠 dp

    int r, g, b;
    cin >> r >> g>> b;
    m[0].push_back(r);
    m[0].push_back(g);
    m[0].push_back(b);

    for(int i=1; i<n; i++){
        cin >> r >> g >> b;
        
        m[i].push_back(min(m[i-1][1] + r, m[i-1][2] + r)); // r
        m[i].push_back(min(m[i-1][0] + g, m[i-1][2] + g)); // g
        m[i].push_back(min(m[i-1][0] + b, m[i-1][1] + b)); // b
    }

    vector<int> v = m[n-1];
    sort(v.begin(), v.end());

    cout << v[0] << endl;
    
    return 0;
}