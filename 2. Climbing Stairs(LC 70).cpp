// Problem Link:
// LC 70. Climbing Stairs: https://leetcode.com/problems/climbing-stairs/
// Almost Similar as fibonacci

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Memoization => TC(O(n)), SC(O(n) + O(n));
int totalStairs(int n, vector<int>& memo){
    if(n<=1)
        return 1;
  
  if(memo[n] != -1)
    return memo[n];
  
  return memo[n] = totalStairs(n-1, memo) + totalStairs(n-2, memo);
  
}
int climbingStairs(int n){
  vector<int> memo(n+1, -1);
  return totalStairs(n, memo);
}


// DP => TC(O(n)), SC(O(n));
int climbingStairs2(int n){
    if(n<2) return 1;
    
    vector<int> dp(n+1);
    dp[0] = 1;
    dp[1] = 1;
    
    for(int i = 2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
    
}

// Optimized DP => TC(O(n)), SC(O(1));
int climbingStairs_optimized(int n){
    if(n<2) return 1;
    
    int prev2 = 1, prev = 1;
    for(int i = 2; i<=n; i++){
        int curr = prev+prev2;
        prev2 = prev;
        prev = curr;
    }
    return prev;
}




int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);


    int n;
    cin >> n;
    cout << climbingStairs(n) << endl;
    cout << climbingStairs2(n) << endl;
    cout << climbingStairs_optimized(n) << endl;


    return 0;
}
