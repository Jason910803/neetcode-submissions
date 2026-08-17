class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        res = []
        n = len(numbers)
        l = 0
        r = n - 1

        while l < r:
            two_sum = numbers[l] + numbers[r]

            if two_sum == target:
                return [l + 1, r + 1]
            elif two_sum > target:
                r -= 1
            else:
                l += 1
        
        