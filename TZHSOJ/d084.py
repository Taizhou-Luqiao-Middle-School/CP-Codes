a=int(input())
def num(i):
    if(i>3):
        x=num(i-1)+num(i-2)
        return x
    else :
        return i
    
print(num(a))