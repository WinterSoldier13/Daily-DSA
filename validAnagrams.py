class Solution:
	def isAnagram(self, s: str, t: str):

		hashmap={}
		for ch in s:
			hashmap[ch] = 0
		for ch in s:
			hashmap[ch]+=1
		
		for ch in t:
			if not ch in hashmap.keys():
				return False
			if hashmap[ch]<=0:
				return False
			hashmap[ch]-=1
		
		for val in hashmap.values():
			if val!=0:
				return False
		return True


