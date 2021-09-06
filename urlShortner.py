from random import randint
class Codec:
    
    hashmap={}

    def encode(self, longUrl: str) -> str:
        """Encodes a URL to a shortened URL.
        """
        generated = randint(5,9999999)
        flag = False
        if(generated in self.hashmap.keys()):
            flag = True
        else:
            self.hashmap[generated] = longUrl
            return generated
        while(flag):
            generated = randint(5,99999)
            if(generated in self.hashmap.keys()):
                continue
            else:
                self.hashmap[generated] = longUrl
                break
        return generated
            
        

    def decode(self, shortUrl: str) -> str:
        return self.hashmap[shortUrl]
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(url))
