class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        map_strs = defaultdict(list)

        for i in strs:
            sorted_str = "".join(sorted(i))
            map_strs[sorted_str].append(i)
              
        return list(map_strs.values())    
