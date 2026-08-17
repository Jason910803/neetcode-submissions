class Solution:
    def jump(self, nums: List[int]) -> int:
        n = len(nums)
        jumps = 0
        curr_end = 0
        next_end = 0

        for i in range(n):
            next_end = max(next_end, i + nums[i])

            if curr_end == i:
                if curr_end == n - 1:
                    break
                # this should not happen
                if curr_end == next_end:
                    return -1

                jumps += 1
                curr_end = next_end
        
        return jumps