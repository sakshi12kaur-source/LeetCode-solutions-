class Solution {
public:
    void computeLPS(vector<int>& pattern, vector<int>& lps) {
        int m = pattern.size();
        int len = 0;
        lps[0] = 0;

        int i = 1;
        while (i < m) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    bool KMP(vector<int>& pat, vector<int>& txt) {
        if (pat.empty()) return true;

        int n = txt.size();
        int m = pat.size();

        vector<int> lps(m, 0);
        computeLPS(pat, lps);

        int i = 0;
        int j = 0;

        while (i < n) {
            if (pat[j] == txt[i]) {
                i++;
                j++;
            }

            if (j == m) {
                return true;
            } else if (i < n && pat[j] != txt[i]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }

        return false;
    }

    bool rotationPossible(vector<int>& block, vector<int>& target) {
        vector<int> doubled = target;
        doubled.insert(doubled.end(), target.begin(), target.end());
        return KMP(block, doubled);
    }

    int sortableIntegers(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        int n = nums.size();
        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            bool valid = true;

            for (int start = 0; start < n; start += k) {
                vector<int> block(nums.begin() + start,
                                  nums.begin() + start + k);
                vector<int> target(sorted.begin() + start,
                                   sorted.begin() + start + k);

                if (!rotationPossible(block, target)) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                ans += k;
            }
        }

        return ans;
    }
};