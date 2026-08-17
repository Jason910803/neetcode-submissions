class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagram_map = defaultdict(list)

        for s in strs:
            sorted_s = "".join(sorted(s))
            anagram_map[sorted_s].append(s)
            # print(anagram_map.values())
        
        return list(anagram_map.values())