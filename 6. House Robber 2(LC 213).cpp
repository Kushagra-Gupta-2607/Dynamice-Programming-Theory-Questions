// Problem Link:
// Leetcode 213. House Robber II: https://leetcode.com/problems/house-robber-ii/

typedef long long ll;

// Memoization => TC(O(2*n)), SC(O(2*n) + O(2*n));
    int maxRob(vector<int>& nums, vector<int>& memo, int n, int idx = 0){
        if(idx>=n) return 0;
        if(memo[idx] != -1) return memo[idx];
        
        int pick = maxRob(nums, memo, n, idx+2) + nums[idx];
        int not_pick = maxRob(nums, memo, n, idx+1);
        
        return memo[idx] = max(pick, not_pick);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> memo1(n, -1), memo2(n, -1);
        int ans1 = maxRob(nums, memo1, n, 1);
        int ans2 = maxRob(nums, memo2, n-1, 0);
        return max(ans1, ans2);
    }


// DP => TC(O(2*n)), SC(O(2*n));
    int maxRob(vector<int>& nums, vector<int>& dp, int n, int start){
        dp[start] = nums[start];
        for(int i = start+1; i<n; i++){
            int pick = nums[i] + (i == start+1 ? 0 : dp[i-2]);
            int not_pick = dp[i-1];
            
            dp[i] = max(pick, not_pick);
        }
        return dp[n-1];
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp1(n+1, 0), dp2(n+1, 0);
        int ans1 = maxRob(nums, dp1, n, 1);
        int ans2 = maxRob(nums, dp2, n-1, 0);
        return max(ans1, ans2);
    }

// Space optimized DP => TC(O(2*n)), SC(O(1));
    int maxRob(vector<int>& nums, int n, int start){
        int prev2 = 0, prev = nums[start];
        for(int i = start+1; i<n; i++){
            int pick = nums[i] + prev2;
            int not_pick = prev;
            
            int curr = max(pick, not_pick);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int ans1 = maxRob(nums, n, 1);
        int ans2 = maxRob(nums, n-1, 0);
        return max(ans1, ans2);
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
    
    cout << rob(arr) << endl;


    return 0;
}
