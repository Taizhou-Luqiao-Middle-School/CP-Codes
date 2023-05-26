a=input()
a=a.replace(',',' ')

a=list(map(float,a.split()))
c=0.0
a.sort()
for i in a:
   c+=i

print("%.2f %.2f"%(c/len(a),a[0]))


