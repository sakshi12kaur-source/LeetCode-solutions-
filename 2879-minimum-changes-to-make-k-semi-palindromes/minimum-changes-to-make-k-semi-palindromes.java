
class Solution {
    int[][] cost;
    int[][] memo;
    int n;
    int INF = 1000000;

    public int minimumChanges(String s, int k) {
        n = s.length();
        cost = new int[n][n];
        memo = new int[n][k + 1];

        // Precompute substring costs
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                cost[i][j] = getCost(s, i, j);
            }
        }

        for (int[] row : memo) {
            Arrays.fill(row, -1);
        }

        return dfs(0, k);
    }

    int dfs(int start, int k) {
        if (k == 0) {
            return start == n ? 0 : INF;
        }

        if (n - start < 2 * k) {
            return INF;
        }

        if (memo[start][k] != -1) {
            return memo[start][k];
        }

        int ans = INF;

        for (int end = start + 2; end <= n - 2 * (k - 1); end++) {
            int currentCost = cost[start][end - 1];

            ans = Math.min(
                ans,
                currentCost + dfs(end, k - 1)
            );
        }

        return memo[start][k] = ans;
    }

    int getCost(String s, int l, int r) {
        int len = r - l + 1;
        int best = INF;

        for (int d = 1; d < len; d++) {
            if (len % d != 0) {
                continue;
            }

            int changes = 0;

            for (int offset = 0; offset < d; offset++) {
                int left = l + offset;
                int right = r - d + 1 + offset;

                while (left < right) {
                    if (s.charAt(left) != s.charAt(right)) {
                        changes++;
                    }

                    left += d;
                    right -= d;
                }
            }

            best = Math.min(best, changes);
        }

        return best;
    }
}