n = int(input())

if n==1:
    print(1)
elif n==2 or n==3:
    print("NO SOLUTION")
elif n==4:
    print("2 4 1 3")
elif n%2==0:
    dif = int(n/2)
    res = ""
    for i in range(1,dif+1):
        res += str(i)+" "+ str(i+dif)+" "
    print(res)
elif n % 2 == 1:
    dif = int((n+1) / 2)
    res = ""
    for i in range(1, dif):
        res += str(i) + " " + str(i + dif) + " "
    res+=str(dif)
    print(res)

