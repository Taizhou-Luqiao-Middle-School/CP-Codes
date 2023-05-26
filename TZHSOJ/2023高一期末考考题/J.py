from datetime import datetime
a=input().strip()
d=datetime.strptime(a,'%Y-%m-%d')
ans=d.timetuple().tm_yday
print(ans)
