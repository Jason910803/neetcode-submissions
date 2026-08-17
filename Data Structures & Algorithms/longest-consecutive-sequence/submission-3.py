class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        # if not nums: 
        #     return 0
        
        # nums.sort()
        # longest_streak, current_streak = 1, 1

        # for i in range(1, len(nums)):
        #     if nums[i] == nums[i - 1] + 1:
        #         current_streak += 1
        #         longest_streak = max(longest_streak, current_streak)
        #     elif nums[i] == nums[i - 1]:
        #         continue
        #     else:
        #         current_streak = 1
        
        # return longest_streak

        # Time: O(NlogN), Space: O(1)

        num_set = set(nums)
        longest_streak = 0

        for num in num_set:
            if num - 1 not in num_set:
                current_streak = 1
                current_num = num

                while current_num + 1 in num_set:
                    current_streak += 1
                    current_num += 1
                
                longest_streak = max(longest_streak, current_streak)
        
        return longest_streak

        # Time: O(N), Space: O(N)