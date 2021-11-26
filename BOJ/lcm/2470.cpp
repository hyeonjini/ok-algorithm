#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> nums;

    for(int i=0; i<n; i++){
        int input;
        cin >> input;
        nums.push_back(input);
    }

    sort(nums.begin(), nums.end());

    int min = 2000000000;
    int left = 0;
    int right = n-1;
    int small, big;
    while(left < right){
        if(abs(nums[left] + nums[right]) < min){
            small = nums[left];
            big = nums[right];
            min = abs(small + big);

            if(min == 0) break;
        }
        
        //left 한칸 땡긴게 오른쪽 땡긴거 보다 클 경우 left 이동 아니면 right 이동
        if(abs(nums[left+1]+nums[right]) < abs(nums[left]+nums[right-1])){
            left++;
        } else
            right--;
    } 

    cout << small << " " << big << endl;

	  return 0;
}