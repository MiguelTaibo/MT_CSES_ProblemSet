t = int(input())
for _ in range(t):
    [a,b] = [int(temp) for temp in input().split(" ")]
    sum = a+b
    if sum%3!=0:
        print("NO")
    elif a<sum/3 or b<sum/3:
        print("NO")
    else:
        print("YES")
