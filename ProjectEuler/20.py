d=dict()
j=1
for i in range(ord('A'),ord('Z')+1):
    d[chr(i)]=j
    j+=1

def main():
    global d
    
    print(d)
    t=input()
    
    
    t=t.split(',')
    t.sort()  #THIS IS BUILT IN FN. SORT
    print(t[0:10])  #CHECKING IF EVERYTHING IS SORTED
    tot=0
    l=[]
    i=0
    for i in range(len(t)):  #THERE ARE 5000 NAMES
        
        for s in t[i]:
            if(s=='"'):
                #print(s)
                continue
            else:
                #print(s)
                tot+=d[s]

        p=(i+1)*tot
        l.append(p)
        
        if(t[i]=='"COLIN"'):
            print(t[i]," i= ",i)
            print("p= ",p," tot= ",tot)
            print(t[i],"  ",l[i])

        tot=p=0

    p=0
    print("len(l) = ",len(l))
    for i in range(len(l)):
        p+=l[i]    
    print("total score= ",p)
                
main()