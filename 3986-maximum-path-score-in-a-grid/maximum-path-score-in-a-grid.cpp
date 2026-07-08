class Solution {
public:
    // int dp[201][201][1001];
    int solve(int i, int j, vector<vector<int>>& grid, int k, int c, auto& dp){
        int m = grid.size(), n = grid[0].size();
        if(i == m || j == n)return INT_MIN;

        if(dp[i][j][c] != -1)return dp[i][j][c];
        int addScore = 0, addCost = 0;
        if(grid[i][j] == 1){
            addScore += 1;
            addCost += 1;
        }else if(grid[i][j] == 2){
            addScore += 2;
            addCost += 1;
        }
        if(c+addCost > k)return dp[i][j][c] = INT_MIN;
        if(i == m-1 && j == n-1) return dp[i][j][c] = addScore;
        int right = solve(i,j+1,grid,k,c+addCost,dp);
        int down = solve(i+1,j,grid,k,c+addCost,dp);
        int best = max(right,down);
        if(best == INT_MIN)return dp[i][j][c] = INT_MIN;
        return dp[i][j][c] = addScore+best;
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        // memset(dp,-1,sizeof(dp));
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>> (n+1, vector<int> (k+1,-1)));
        int ans = solve(0,0,grid,k,0,dp);
        return ans == INT_MIN? -1 : ans;
    }
};