from typing import List

class Solution:
    def countPrefixSuffixPairs(self, words: List[str]) -> int:
        # Helper function to check if one string is both a prefix and suffix of another
        def isPrefixAndSuffix(str1: str, str2: str) -> bool:
            return str2.startswith(str1) and str2.endswith(str1)

        # Count the valid pairs (i, j) where i < j
        count = 0
        for i in range(len(words)):
            for j in range(i + 1, len(words)):
                if isPrefixAndSuffix(words[i], words[j]):
                    count += 1

        return count
