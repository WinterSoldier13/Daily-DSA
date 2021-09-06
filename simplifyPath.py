class Solution:
    def simplifyPath(self, path: str):

        path = path.replace('//','/')
        path = path.replace('///','/')
        path = path.replace('////','/')
        path = path.replace('////','/')
        path = path.replace('/////','/')
        path = path.replace('//////','/')
        path = path.replace('///////','/')
        path = path.replace('//','/')
        path = path.replace('///','/')
        path = path.replace('////','/')
        path = path.replace('////','/')
        path = path.replace('/////','/')
        path = path.replace('//////','/')
        path = path.replace('///////','/')
        path = path.replace('//','/')
        path = path.replace('///','/')
        path = path.replace('////','/')
        path = path.replace('////','/')
        path = path.replace('/////','/')
        path = path.replace('//////','/')
        path = path.replace('///////','/')
        path = path.replace('//','/')
        path = path.replace('///','/')
        path = path.replace('////','/')
        path = path.replace('////','/')
        path = path.replace('/////','/')
        path = path.replace('//////','/')
        path = path.replace('///////','/')
        
        stack = []
        print(path)
        path = path.split('/')
        path = path[1:]
        # print(path)

        for i in path:
            if(i == '.'):
                continue
            if(i == '..'):
                if(len(stack)>0):
                    stack.pop()
            else:
                stack.append(i)
        # print(stack)
        s='/'
        for i in stack:
            if(i==''):
                continue
            s+=i
            s+='/'
        
        if(len(s)==1):
            return s
        s= s[::-1]
        s = s.replace('/','',1)
        s=s[::-1]
        
        return s