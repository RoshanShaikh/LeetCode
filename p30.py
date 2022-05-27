import collections
from typing import List


# class Solution:
#     def findSubstring(self, s: str, words: List[str]) -> List[int]:
#         i = 0
#         word_length = len(words[0])
#         count = collections.Counter(words)
#         substr_length = word_length * words.__len__()
#         ans = []
#         while(i < (len(s) + 1 - substr_length)):
#             countcopy = count.copy()
#             word_used = 0
#             for j in range(i, i+substr_length):
#                 sub = s[j:j+substr_length]
#                 if (countcopy[sub] > 0):
#                     countcopy[sub] -= 1
#                     word_used += 1
#                 else:
#                     break
#             if(word_used == words.__len__()):
#                 ans.append(i)
#             i += 1
#         return ans

class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
                i = 0
                word_length = len(words[0])
                count = collections.Counter(words)
                substr_length = word_length * words.__len__()
                ans = []
                while(i < (len(s) + 1 - substr_length)):
                    countcopy = count.copy()
                    word_used = 0
                    for j in range(i, i+substr_length):
                        sub = s[j:j+substr_length]
                        if (countcopy[sub] > 0):
                            countcopy[sub] -= 1
                            word_used += 1
                        else:
                            break
                    if(word_used == words.__len__()):
                        ans.append(i)
                    i += 1
                return ans

def main():
    print(Solution().findSubstring("barfoothefoobarman",
                                   ["foo", "bar"]))


if __name__ == "__main__":
    main()
