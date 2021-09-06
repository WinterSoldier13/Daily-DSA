def isValid(s):
    arr = s.split('.')
    if(len(arr) != 4):
        return False
    
    for i in arr:
        if(i=='' or (i[0] =='0' and len(i)!=1) or not i.isdigit() or int(i)>255 or int(i)<0 ):
            return False
    return True