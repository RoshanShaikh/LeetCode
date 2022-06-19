from typing import List


class WordFilter:
    dictWords = []

    def __init__(self, words: List[str]):
        self.dictWords = words

    def f(self, prefix: str, suffix: str) -> int:
        for i, str in reversed(list(enumerate(self.dictWords))):
            if(str.startswith(prefix) and str.endswith(suffix)):
                return i
        return -1


# Your WordFilter object will be instantiated and called as such:
# obj = WordFilter(words)
# param_1 = obj.f(prefix,suffix)
