for i in range(1, 61, 1):
    for j in range(i, 61, 1):
        for k in range(1, 61, 1):
            if 1 / (i * i) + 1 / (j * j) == 1 / (k * k) :
                print(i, j, k)
