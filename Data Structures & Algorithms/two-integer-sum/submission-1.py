class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        index = {} # {"num": index}

        for i, num in enumerate(nums):
            remain = target - num
            if remain in index:
                return [index[remain], i]
            
            index[num] = i
        
        