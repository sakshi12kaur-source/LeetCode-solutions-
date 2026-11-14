class Solution:
    def subsets(self, nums: list[int]) -> list[list[int]]:
        result = []

        def solve(index=0, lst=[]):
            if index == len(nums):
                result.append(lst[:])
                return

            # Pick the current element
            lst.append(nums[index])
            solve(index + 1, lst)

            # Do not pick the current element
            lst.pop()
            solve(index + 1, lst)

        solve()
        return result