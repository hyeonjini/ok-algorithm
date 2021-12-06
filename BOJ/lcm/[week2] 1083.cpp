#include <bits/stdc++.h>
using namespace std;

void solution(int n, vector<int>& arr, int s){
    for(int i=0; i<n-1; i++){
        int max = arr[i];
        int maxIdx = i;
        for(int j=i+1; j <= i + s && j < n; j++){
            if(max < arr[j]) {
                max = arr[j];
                maxIdx = j;
            }
        }

        for(int j=maxIdx; j>i && s > 0; j--, s--)
            swap(arr[j], arr[j-1]);
        
        if(s == 0) break;
    }

    for(auto& i : arr) cout << i << " ";
    cout << endl;
}

int main(int argc, char** argv){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> arr;
    int s;
    
    for(int i=0; i<n; i++){
        int input;
        cin >> input;
        arr.push_back(input);
    }
    cin >> s;
    
    solution(n, arr, s);

	  return 0;
}