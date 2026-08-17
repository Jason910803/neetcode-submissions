class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        n = len(cardPoints)

        prefix = [0] * (n + 1)
        for i in range(n):
            prefix[i + 1] = prefix[i] + cardPoints[i]

        suffix = [0] * (n + 1)
        for i in range(n - 1, -1, -1):
            suffix[i] = suffix[i + 1] + cardPoints[i]

        res = 0
        for left in range(k + 1):
            right = k - left
            res = max(res, prefix[left] + suffix[n - right])

        return res