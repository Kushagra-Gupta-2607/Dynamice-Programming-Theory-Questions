// Problem Link:
// Codestudio: https://www.codingninjas.com/codestudio/problem-details/ninja-s-training_3621003

typedef long long ll;
using vi = vector<int>;
using vvi = vector<vi>;

// Memoization => TC(O(n*3)), SC(O(n) + O(n*3));
int check(vvi& v, vvi& dp, int n, int idx = 0, int last = -1){
    if(idx == n) return 0;
    if(last != -1 && dp[idx][last] != -1) return dp[idx][last];
    
    int maxi = -1e9;
    for(int i = 0; i<3; i++){
        if(i != last) maxi = max(maxi, check(v, dp, n, idx+1, i) + v[idx][i]);
    }
    if(last != -1) dp[idx][last] = maxi;
    return maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vvi dp(n, vi(3, -1));
    return check(points, dp, n);
}


// DP => TC(O(n*3*3)), SC(O(n*3));
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vvi dp(n+1, vi(3, 0));
    for(int i = 1; i<=n; i++){
        for(int last = 0; last<3; last++){
            int maxi = -1e9;
            for(int cnt = 0; cnt<3; cnt++){
                if(last != cnt) maxi = max(maxi, dp[i-1][cnt]);
            }
            dp[i][last] = maxi + points[i-1][last];
        }
    }
    return max({dp[n][0], dp[n][1], dp[n][2]});
}

// Space optimized DP => TC(O(n*3*3)), SC(O(1));
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vi prev(3, 0);
    for(int i = 1; i<=n; i++){
        vector<int> temp(3, 0);
        for(int last = 0; last<3; last++){
            int maxi = -1e9;
            for(int cnt = 0; cnt<3; cnt++){
                if(last != cnt) maxi = max(maxi, prev[cnt]);
            }
            temp[last] = maxi + points[i-1][last];
        }
        prev = temp;
    }
    return *max_element(prev.begin(), prev.end());
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);


    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(3));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<3; j++){
            cin >> arr[i][j];
        }
    }
    
    cout << ninjaTraining(arr) << endl;


    return 0;
}
