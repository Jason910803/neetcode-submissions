class Solution:
    def isPalindrome(self, s: str) -> bool:
        # first filter the string
        # filtered_chars = [char.lower() for char in s if char.isalnum()]
        # print(filtered_chars)
        # # then turn back to string
        # filtered_str = "".join(filtered_chars)

        # return filtered_str == filtered_str[::-1]

        # Time: O(N), Space: O(N)

        left, right = 0, len(s) - 1

        while left < right:
            while left < right and not s[left].isalnum():
                left += 1
            
            while left < right and not s[right].isalnum():
                right -= 1
            
            if s[left].lower() != s[right].lower():
                return False
            
            left += 1
            right -= 1

        return True