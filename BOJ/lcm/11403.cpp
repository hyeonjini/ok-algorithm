#include <bits/stdc++.h>
using namespace std;

void dfs(int i, vector<bool>& visited, unordered_map<int, vector<int>>& routes){
    for(int j = 0; j < routes[i].size(); j++){
        if(!visited[routes[i][j]]){
            visited[routes[i][j]] = true;
            dfs(routes[i][j], visited, routes);
        }
    }
}

int main(int argc, char** argv){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    
    unordered_map<int, vector<int>> routes;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int input;
            cin >> input;
            if(input == 1)
                routes[i].push_back(j); // i번째 정점에 j 정점 추가
        }
    }

    for(int i=0; i<n; i++){
        vector<bool> visited(n, false); // 0번 정점 부터 check

        dfs(i, visited, routes);

        for(int j=0; j<visited.size(); j++)
            cout << visited[j] << " ";
            
        cout << endl;
    }

	  return 0;
}