#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;

//268pg 이코테 참고

int find(vector<int>& parent, int x){
    if(parent[x] != x){
        return find(parent, parent[x]);
    }

    return x;
}

void union_parent(vector<int>& parent, int a, int b){
    int x = find(parent, a);
    int y = find(parent, b);    

    if(x < y)
        parent[y] = x;
    else
        parent[x] = y;
}

void solution(int n, int m, vector<int>& knowing, vector<vector<int>>& party){
    int answer = 0;

    vector<int> parent(n+1); // root 
    for(int i=0; i<n+1; i++) parent[i] = i; // root 노드 자기 자신으로 초기화

    // 진실을 아는 사람 0 초기화
    for(auto& i : knowing)
        parent[i] = 0;
    
    for(auto& p: party){
        for(int j=0; j<p.size(); j++){
            for(int k=0; k<p.size(); k++){
                union_parent(parent, p[j], p[k]);
            }
        }
    }

    for(int i=0; i<party.size(); i++){
        if(party[i].size() == 0) answer++;
        bool check = true;
        for(int j=0; j<party[i].size(); j++){
            if(find(parent, party[i][j]) == 0){
                check = false;
                break;
            } 
        }
        if(check) answer++;
    }

    cout << answer << endl;
}

int main(int argc, char** argv){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    
    int cnt;
    cin >> cnt;
    vector<int> knowing(cnt); // 아는 사람들
    vector<vector<int>> party(m);

    for(int i=0; i<cnt; i++){
        int input;
        cin >> input;
        knowing.push_back(input);
    }

    for(int i=0; i<m; i++){
        int partySize;
        cin >> partySize;
        for(int j=0; j<partySize; j++){
            int input;
            cin >> input;
            party[i].push_back(input);
        }
    }

    solution(n, m, knowing, party);

	  return 0;
}