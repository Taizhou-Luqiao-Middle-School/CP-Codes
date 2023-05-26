l=input()
c=int(len(l))
if(l[0:int(c/2)]==l[-1:int(-c/2-1):-1]):
    # l[0:int(c/2)] 的含义是截取l列表的前一半
    # l[-1:int(-c/2-1):1] 的含义是截取l列表的后一半
    # 本句是在比较 l 的前一半和后一半是否相等
    # https://www.runoob.com/python3/python3-list.html
    print("Yes")
else :
    print("No")


