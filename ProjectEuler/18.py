# Coded By: Armaan Nougai
# Project Euler 18 and 67


with open('__ed_input.txt','r') as FILE:
    Data = FILE.readlines()
    arr = [list(map(int,(j.split()))) for j in Data]
    
    result_arr = [0]*(len(arr[-1])+1)
    for row in arr[::-1]:
        
        result_arr = list([value + max(result_arr[x],result_arr[x+1]) for x,value in enumerate(row)])
        
    print(result_arr[0])