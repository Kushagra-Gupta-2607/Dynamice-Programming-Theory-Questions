// Problem Link:
// Atcoder: https://atcoder.jp/contests/dp/tasks/dp_b

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Memoization => TC(O(n*k)), SC(O(n) + O(n));
int totalJumps(int n, int k, vector<int>& arr, vector<int>& memo){
    if(n == 0)
        return 0;
    if(memo[n] != -1) return memo[n];
    
    int minSteps = INT_MAX;
    for(int i = 1; i<=k; i++){
        if(n-i<0) break;
        minSteps = min(minSteps, abs(arr[n]-arr[n-i]) + totalJumps(n-i, k, arr, memo));
    }
    
    return memo[n] = minSteps;
  
}
int frogJump(int n, int k, vector<int>& arr){
    vector<int> memo(n, -1);
    return totalJumps(n-1, k, arr, memo);
}


// DP => TC(O(n*k)), SC(O(n));
int frogJump2(int n, int k, vector<int>& arr){
    vector<int> dp(n, 0);
    
    for(int i = 1; i<n; i++){
        int minSteps = INT_MAX;
        for(int j = 1; j<=k; j++){
            if(i-j<0) break;
            minSteps = min(minSteps, abs(arr[i]-arr[i-j]) + dp[i-j]);
        }
        
        dp[i] = minSteps;
    }
    
    return dp[n-1];
    
}




int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);


    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    
    cout << frogJump(n, k, arr) << endl;
    cout << frogJump2(n, k, arr) << endl;


    return 0;
}
