#include <bits/stdc++.h>
using namespace std;

void solution(int a, int b){
    int answer = 1;
    while(a < b){
        if(b % 2 == 0){ // 2로 나눔
            b /= 2;
            answer++;
        } else{
            if(b % 10 == 1){ // 1의 자리 숫자 1
                b /= 10;
                answer++;
            } else{
                break;
            }
        }

        if(a == b){
            cout << answer << endl;
            return;
        } 
    }

    cout << -1 << endl;
}

int main(int argc, char** argv){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;

    solution(a, b);

	  return 0;
}