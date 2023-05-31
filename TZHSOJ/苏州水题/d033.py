a=b=c=0
for i in range(1,11):
    result = ""
    for j in range(1,51):
        if ( 3*(50-(5*i+j)) == (100-i-j) ):
            result = str(i) + ' ' + str(j) + ' ' + str(100-i-j)
            print(result)
