class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {

        vector<int> foc(26, -1); // first occurrence
        vector<int> loc(26, -1); // last occurrence

        // 1. Find first and last occurrence
        for (int i = 0; i < s.size(); i++) {

            int idx = s[i] - 'a';

            if (foc[idx] == -1)
                foc[idx] = i;

            loc[idx] = i;
        }

        vector<vector<int>> ranges;

        // 2. Find all valid ranges
        for (int i = 0; i < 26; i++) {

            if (foc[i] == -1)
                continue;

            int f = foc[i];
            int l = loc[i];

            bool valid = true;

            // 3. Check and expand the range
            for (int j = f; j <= l; j++) {

                // If this character occurs before
                // our starting position, the range is invalid.
                if (foc[s[j] - 'a'] < f) {
                    valid = false;
                    break;
                }

                // Include all occurrences of this character.
                l = max(l, loc[s[j] - 'a']);
            }

            if (valid)
                ranges.push_back({f, l});
        }

        vector<string> ans;

        // 4. Keep only the smaller valid ranges
        for (auto &r1 : ranges) {

            bool keep = true;

            for (auto &r2 : ranges) {

                if (r1 == r2)
                    continue;

                // r2 is completely inside r1
                if (r2[0] >= r1[0] && r2[1] <= r1[1]) {
                    keep = false;
                    break;
                }
            }

            if (keep) {

                // 5. Convert range into substring
                ans.push_back(
                    s.substr(r1[0], r1[1] - r1[0] + 1)
                );
            }
        }

        return ans;
    }
};