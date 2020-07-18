n=int(input())

i=1
res = 0

while 5**i<=n:
    res+=(n//(5**i))
    i+=1

print(res)