import random
class RandomizedSet:
    hashset = {}

    def __init__(self):
        self.hashset = {}


    def insert(self, val: int) -> bool:
        if(val in self.hashset.keys()):
            return False
        self.hashset[val] = 1
        return True


    def remove(self, val: int) -> bool:
        try:
            self.hashset.pop(val)
            return True
        except:
            return False

    def getRandom(self) -> int:
        l = len(self.hashset)
        return list(self.hashset.keys())[random.randint(0,l-1)]