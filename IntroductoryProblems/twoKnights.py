n = int(input())

def factorial(n):
    res = 1
    for i in range(1,n+1):
        res = res*i
    return res

for i in range(1,n+1):
    len = i**2
    comb = len*(len-1)/2
    #perdidas = 0
    perdidas = 2+(i-3)*6+(i-2)*6+4*(i-3)**2
    print(int(comb-perdidas))