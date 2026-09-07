class Solution:
    def distinctSubseqII(self, s: str) -> int:
        mod = 1_000_000_007
        ending = [0] * 26
        total = 0

        for char in s:
            index = ord(char) - ord('a')
            new_total = (2 * total + 1 - ending[index]) % mod
            ending[index] = total + 1
            total = new_total

        return total