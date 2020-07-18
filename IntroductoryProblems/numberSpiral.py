t = int(input())

for _ in range(t):
    text = input().split(" ")
    y = int(text[0])
    x = int(text[1])
    square = max(x,y)-1
    if square%2==0:
        if y<x:
            print(square**2+2*x-y)
        elif x<y:
            print(square**2+x)
        elif x==y:
            print(square**2+x)
    elif square%2==1:
        if x<y:
            print(square**2+2*y-x)
        elif y<x:
            print(square**2+y)
        elif x==y:
            print(square**2+x)