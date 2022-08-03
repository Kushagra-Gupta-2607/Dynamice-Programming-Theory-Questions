// Problem Link:
// Leetcode 1143. Longest Common Subsequence: https://leetcode.com/problems/longest-common-subsequence/


// Recursion + Memoization DP
class Solution {
public:
    using vi = vector<int>;
    using vvi = vector<vi>;
    
    int lcs(string& text1, string& text2, vvi& dp, int idx1, int idx2){
        if(idx1<0 || idx2<0) return 0;
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        
        int z;
        if(text1[idx1] == text2[idx2]) z = 1 + lcs(text1, text2, dp, idx1-1, idx2-1);
        else z = max(lcs(text1, text2, dp, idx1-1, idx2), lcs(text1, text2, dp, idx1, idx2-1));
        return dp[idx1][idx2] = z;
    }
        
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vvi dp(n, vi(m, -1));
        return lcs(text1, text2, dp, n-1, m-1);
    }
};


// Tabulation DP
class Solution {
public:
    using vi = vector<int>;
    using vvi = vector<vi>;
    
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vvi dp(n+1, vi(m+1, 0));
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(text1[i-1] == text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};


// Space Optimized Tabulation DP
class Solution {
public:
    using vi = vector<int>;
    
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vi prev(m+1, 0), curr(m+1, 0);
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(text1[i-1] == text2[j-1]) curr[j] = 1 + prev[j-1];
                else curr[j] = max(prev[j], curr[j-1]);
            }
            prev = curr;
        }
        return prev[m];
    }
};
