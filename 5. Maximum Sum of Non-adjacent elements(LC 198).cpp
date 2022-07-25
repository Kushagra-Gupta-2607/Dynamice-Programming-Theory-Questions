// Problem Link:
// Leetcode 198. House Robber: https://leetcode.com/problems/house-robber/

typedef long long ll;

// Memoization => TC(O(n)), SC(O(n) + O(n));
    int maxRob(vector<int>& nums, vector<int>& memo, int n){
        if(n<0) return 0;
        if(memo[n] != -1) return memo[n];
        
        int pick = maxRob(nums, memo, n-2) + nums[n];
        int not_pick = maxRob(nums, memo, n-1);
        
        return memo[n] = max(pick, not_pick);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(n, -1);
        return maxRob(nums, memo, n-1);
    }


// DP => TC(O(n)), SC(O(n));
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        
        for(int i = 1; i<n; i++){
            int pick = (i == 1 ? 0 : dp[i-2]) + nums[i];
            int not_pick = dp[i-1];
            
            dp[i] = max(pick, not_pick);
        }
        
        return dp[n-1];
    }

// Space optimized DP => TC(O(n)), SC(O(1));
    int rob(vector<int>& nums) {
        int prev2 = 0, prev = nums[0];
        
        for(int i = 1; i<nums.size(); i++){
            int pick = (i == 1 ? 0 : prev2) + nums[i];
            int not_pick = prev;
            
            int curr = max(pick, not_pick);
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
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    
    cout << rob(arr) << endl;


    return 0;
}
