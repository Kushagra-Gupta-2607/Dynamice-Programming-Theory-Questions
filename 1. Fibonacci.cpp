#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i > (a); --i)

#define forn(i,n) for(int i = 0; i < (int)n; ++i)
#define mins(x,y) x = min(x,y)
#define maxs(x,y) x = max(x,y)
#define sortva(v) sort(v.begin(), v.end())
#define sortvd(v) sort(v.begin(), v.end(), greater<int>())

#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define ct(x) cout << (x) << endl
#define mod 998244353

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;
typedef vector<pii> vpi;
typedef vector<vector<ll>> vvi;
typedef unordered_set<int> ui;
typedef unordered_map<int, int> uii;
const long long INF = 1e18;


// Memoization => TC(O(n)), SC(O(n) + O(n));
int findFibonacci(int n, vector<int>& memo){
  if(n<=1)
    return n;
  
  if(memo[n] != -1)
    return memo[n];
  
  return memo[n] = findFibonacci(n-1, memo) + findFibonacci(n-2, memo);
  
}
int fib(int n){
  vector<int> memo(n+1, -1);
  return findFibonacci(n, memo);
}


// DP => TC(O(n)), SC(O(n));
int fib2(int n){
    if(n<2) return n;
    
    vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = 1;
    
    for(int i = 2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
    
}

// Optimized DP => TC(O(n)), SC(O(1));
int fib_optimized(int n){
    if(n<2) return n;
    
    int prev2 = 0, prev = 1;
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
    cout << fib(n) << endl;
    cout << fib2(n) << endl;
    cout << fib_optimized(n) << endl;


    return 0;
}
