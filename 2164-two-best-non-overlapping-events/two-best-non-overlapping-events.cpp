class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {

        sort(events.begin(), events.end());

        int n = events.size();

        // best[i] = maximum value from i to n-1
        vector<int> best(n);

        best[n - 1] = events[n - 1][2];

        for (int i = n - 2; i >= 0; i--) {
            best[i] = max(best[i + 1], events[i][2]);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {

            int endTime = events[i][1];
            int value = events[i][2];

            // binary search for first event
            // whose start > endTime

            int low = i + 1;
            int high = n - 1;

            int nextIndex = n;

            while (low <= high) {

                int mid = low + (high - low) / 2;

                if (events[mid][0] > endTime) {
                    nextIndex = mid;
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }

            int total = value;

            if (nextIndex < n) {
                total += best[nextIndex];
            }

            ans = max(ans, total);
        }

        return ans;
    }
};