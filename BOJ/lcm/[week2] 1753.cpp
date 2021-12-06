#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
// 다익스트라
void solution(int k, unordered_map<int, vector<pair<int, int>>> m, int v){
    int max = 0;
    
    vector<int> answer(v+1, INF);
    //min heap 그냥 사용시 max heap
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({0, k});
    answer[k] = 0;

    while(!q.empty()){
        int cost = q.top().first;
        int from = q.top().second;
        q.pop();

        for(int i=0; i<m[from].size(); i++){
            int to = m[from][i].first;
            int weight = m[from][i].second;
            
            if(answer[to] > weight + cost){ // 더 작은경우 갱신
                answer[to] = weight + cost;
                q.push({answer[to], to});
            }
        }
    }

    for(int i=1; i<=v; i++){
        if(answer[i] == INF) cout << "INF" << endl;
        else cout << answer[i] << endl;
    }
}

int main(int argc, char** argv){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int v, e;
    cin >> v >> e;

    int k;
    cin >> k; // 시작 정점 번호
    
    unordered_map<int, vector<pair<int, int>>> m; // u, v, w   u->v 일때 w가중치
    for(int i=0; i<e; i++){
        int u, otherEdge, w;
        cin >> u >> otherEdge >> w;
        
        m[u].push_back({otherEdge, w});
    }

    solution(k, m, v);

	  return 0;
}