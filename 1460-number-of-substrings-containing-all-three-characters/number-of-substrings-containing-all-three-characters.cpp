class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> lastSeenAt = {{'a', -1}, {'b', -1}, {'c', -1}};
        int count = 0;

        for (int right = 0; right < s.length(); ++right) {
            // Update the last seen index of the current character
            lastSeenAt[s[right]] = right;

            // Ensure all three characters are seen at least once
            if (lastSeenAt['a'] > -1 && lastSeenAt['b'] > -1 && lastSeenAt['c'] > -1) {
                int lastseen = min({lastSeenAt['a'], lastSeenAt['b'], lastSeenAt['c']});
                count += lastseen + 1;
            }
        }

        return count;
    }
};