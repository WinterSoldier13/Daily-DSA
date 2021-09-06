class Solution:
    def wordPattern(self, pattern: str, str: str) -> bool:
        map_char = {}
        map_word = {}
        
        words = str.split(' ')
        if len(words) != len(pattern):
            return False
        
        for c, w in zip(pattern, words):
            if c not in map_char:
                if w in map_word:
                    return False
                else:
                    map_char[c] = w
                    map_word[w] = c
            else:
                if map_char[c] != w:
                    return False
        return True