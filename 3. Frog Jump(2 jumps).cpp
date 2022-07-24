// Problem Link:
// Codestudio:  https://bit.ly/3JPcoOx

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Memoization => TC(O(n)), SC(O(n) + O(n));
int totalJumps(int n, vector<int>& arr, vector<int>& memo){
    if(n == 0)
        return 0;
    if(memo[n] != -1) return memo[n];
    
    int left = abs(arr[n]-arr[n-1]) + totalJumps(n-1, arr, memo), right = INT_MAX;
    if(n>1) right = abs(arr[n]-arr[n-2]) + totalJumps(n-2, arr, memo);
    
    return memo[n] = min(left, right);
  
}
int frogJump(int n, vector<int>& arr){
    vector<int> memo(n+1, -1);
    return totalJumps(n-1, arr, memo);
}


// DP => TC(O(n)), SC(O(n));
int frogJump2(int n, vector<int>& arr){
    vector<int> dp(n, 0);
    
    for(int i = 1; i<n; i++){
        int one_jump = abs(arr[i]-arr[i-1]) + dp[i-1], double_jump = INT_MAX;
        if(i>1) double_jump = abs(arr[i]-arr[i-2]) + dp[i-2];
        
        dp[i] = min(one_jump, double_jump);
    }
    
    return dp[n-1];
    
}

// Optimized DP => TC(O(n)), SC(O(1));
int frogJump_optimized(int n, vector<int>& arr){
    int prev = 0, prev2;
    
    for(int i = 1; i<n; i++){
        int one_jump = abs(arr[i]-arr[i-1]) + prev, double_jump = INT_MAX;
        if(i>1) double_jump = abs(arr[i]-arr[i-2]) + prev2;
        
        int temp = min(one_jump, double_jump);
        prev2 = prev;
        prev = temp;
    }
    
    return prev;
}




int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);


    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    
    cout << frogJump(n, arr) << endl;
    cout << frogJump2(n, arr) << endl;
    cout << frogJump_optimized(n, arr) << endl;


    return 0;
}
