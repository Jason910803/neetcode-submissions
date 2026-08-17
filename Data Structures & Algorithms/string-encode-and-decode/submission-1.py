class Solution:
    def encode(self, strs: List[str]) -> str:
        res = []
        for s in strs:
            res.append(f"{len(s)}#{s}")
        return "".join(res)

    def decode(self, s: str) -> List[str]:
        res = []

        i = 0
        while i < len(s):
            # find the index of next "#"
            j = i
            while s[j] != "#":
                j += 1

            length = int(s[i:j])
            res.append(s[j + 1 : j + 1 + length])
            # i always points to the first digit of number
            i = j + 1 + length

        return res
