l=[]
a=input()
for i in a:
    l.insert(0,i)#如何使用insert() : https://www.runoob.com/python3/python3-att-list-insert.html
    #含义是把i添加到列表的第一位

l.sort(reverse=True) # python 自带的排序函数
for i in l:
print(i,end='')
