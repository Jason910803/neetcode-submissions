class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagram_map = defaultdict(list)

        # for s in strs:
        #     sorted_s = "".join(sorted(s))
        #     anagram_map[sorted_s].append(s)
        #     # print(anagram_map.values())
        
        # return list(anagram_map.values())

        # Time: O(N * KlogK)
        # Space: O(N * K)

        for s in strs:
            count = [0] * 26

            for char in s:
                count[ord(char) - ord('a')] += 1
            
            anagram_map[tuple(count)].append(s)
        
        return list(anagram_map.values())