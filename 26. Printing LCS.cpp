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
        int i = n, j = m, index = dp[n][m]-1;
        string s(index+1, '$');
        while(i && j){
            if(text1[i-1] == text2[j-1])
                s[index--] = text1[i-1], i--, j--;
            else if(dp[i][j-1]>dp[i-1][j])
                j--;
            else
                i--;
        }
        cout << s << endl;
        
        return dp[n][m];
    }
};
