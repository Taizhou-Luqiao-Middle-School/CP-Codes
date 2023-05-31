# 所以说什么时候能装一下库啊，二维数组都不能用！



# import numpy as np
# na=np.zeros((60,60),dtype=int)

# a=int(input())

# def num(i,j):
#     if na[i][j]:
#         return na[i][j]
#     if (j!=1 and j!=i):
#         m=num(i-1,j)+num(i-1,j-1)
#         return m
    
#     elif (j==1 or j==i):
#         return 1
    
# for i in range(1,a+1):
#     for j in range(1,i+1):
#         print(num(i,j),end=" ")
    
#     print("")



a=int(input())

def num(i,j):
    if (j!=1 and j!=i):
        m=num(i-1,j)+num(i-1,j-1)
        return m
    
    elif (j==1 or j==i):
        return 1
    
for i in range(1,a+1):
    for j in range(1,i+1):
        print(num(i,j),end=" ")
    
    print("")
