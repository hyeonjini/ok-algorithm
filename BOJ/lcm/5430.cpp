#include <bits/stdc++.h>
using namespace std;

// 벡터 사용 -> 시간 초과
// 벡터는 insert, erase 의 경우 최악 O(n)의 시간복잡도 땡기거나 지워야해서 
// O(1)을 갖는 놈을 사용해야함 -> list O(1)

void solution(string p, list<string>& arr) {
    bool reverse = false; //reverse 시키면 계속 시간초과나서 안시키는 방향으로..
    for(int i=0; i<p.length(); i++){
      if(p[i] == 'R'){
          reverse = !reverse;
          //reverse(arr.begin(), arr.end()) 사용시 시간초과.. O(n)
      } else if(p[i] == 'D'){
          if(arr.empty()){
              cout << "error\n";
              return;
          } else{
              if(reverse)
                  arr.pop_back();
              else
                  arr.pop_front();
          }
      }
    }
    
    string res = "[";
    while(!arr.empty()){
        if(reverse){
            res += arr.back();
            arr.pop_back();
        } else {
            res += arr.front();
            arr.pop_front();
        }
        
        if(!arr.empty()) res += ",";
    }
    cout << res + "]\n";
}

int main(int argc, char** argv){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    
    for(int i=0; i<T; i++){
      string p, ar;
      int n;
      cin >> p >> n >> ar;

      list<string> arr;
      if(n > 0){
          ar = ar.substr(1, ar.length() -2);// [] 제거

          //, 제거하고 arr에 push
          int prev = 0, curr = 0;
          curr = ar.find(',');
          while(curr != string::npos){ // string find 못찾으면 string::npos 반환
            string sub = ar.substr(prev, curr-prev);
            arr.push_back(sub);
            prev = curr+1;
            curr = ar.find(',', prev);
          }
          arr.push_back(ar.substr(prev, curr-prev));
      }
      solution(p, arr);
    }
	  return 0;
}