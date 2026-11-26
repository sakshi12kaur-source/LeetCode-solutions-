class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        counts = {'a' : 0 , 'b': 0 , 'c' : 0}
        ans = 0
        left = 0
        for right in range(len(s)):
            counts[s[right]] += 1
            while counts['a'] > 0 and counts['b'] > 0 and counts['c'] > 0:
                counts[s[left]] -= 1
                left += 1
            ans += left
        return ans