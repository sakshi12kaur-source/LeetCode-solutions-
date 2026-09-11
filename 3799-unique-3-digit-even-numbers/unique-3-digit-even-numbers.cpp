class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);

        for (int d : digits)
            freq[d]++;

        int ans = 0;

        for (int num = 100; num <= 999; num++) {
            if (num % 2 != 0)
                continue;

            vector<int> need(10, 0);
            int x = num;

            need[x % 10]++;
            x /= 10;

            need[x % 10]++;
            x /= 10;

            need[x]++;

            bool possible = true;

            for (int d = 0; d <= 9; d++) {
                if (need[d] > freq[d]) {
                    possible = false;
                    break;
                }
            }

            if (possible)
                ans++;
        }

        return ans;
    }
};