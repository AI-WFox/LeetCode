class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        res = [1] * (n)

        prefix = 1
        for idx in range(n):
            res[idx] = prefix
            prefix *= nums[idx]
        
        postfix = 1
        for idx in range(n - 1, -1, -1):
            res[idx] *= postfix
            postfix *= nums[idx]
        
        return res
