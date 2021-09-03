# You need to write code for push() and pop()

class MyStack:
    arr = []
    def __init__(self):
        self.arr=[]
    
    #Adds element to the Stack
    def push(self,data):
        #add code here
        self.arr.append(data)
    
    #Removes element from the stack
    def pop(self):
        #add code here
        if(len(self.arr)>0):
            e=  self.arr[-1]
            self.arr.pop()
            return e
        return -1
        
        

