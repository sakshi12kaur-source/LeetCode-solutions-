class Solution:
    def numOfSubarrays(self, arr: list[int]) -> int:
        MOD = 10**9 + 7
        prefix_sum = 0
        odd_count = 0 
        for i in arr:
            prefix_sum += i
            odd_count += prefix_sum % 2
        odd_count += (len(arr) - odd_count) * odd_count
        return odd_count % MOD