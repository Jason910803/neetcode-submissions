class Solution:
    def isPalindrome(self, s: str) -> bool:
        # first filter the string
        filtered_chars = [char.lower() for char in s if char.isalnum()]
        # then turn back to string
        filtered_str = "".join(filtered_chars)

        return filtered_chars == filtered_chars[::-1]