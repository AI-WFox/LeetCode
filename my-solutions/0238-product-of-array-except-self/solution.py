class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        si = len(nums)

        suffix = [1] * (si + 1)
        prefix = [1] * (si + 1)

        for i in range(len(suffix)-2, -1, -1):
            suffix[i] = nums[i] * suffix[i+1]

        for i in range(1, len(prefix)):
            prefix[i] = nums[i-1] * prefix[i-1]

        for i in range(len(nums)):
            nums[i] = prefix[i] * suffix[i+1]
        
        return nums



