for a in range(1,21):
    for b in range(a,21):
        for c in range(b,21):
            if (a*a+b*b==c*c):
                s = str(a) + ' ' + str(b) + ' ' + str(c)
                print(s)