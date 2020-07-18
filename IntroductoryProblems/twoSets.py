n = int(input())

sum = n*(n+1)/2

if sum%2==1:
    print("NO")
elif sum%2==0:
    print("YES")
    media = sum/2
    set1 = []
    set2 = []
    for i in reversed(range(1,n+1)):
        if media>=i:
            set1.append(i)
            media=media-i
        elif media<i:
            set2.append(i)

    print(len(set1))
    text = ""
    for i in reversed(set1):
        text+=(str(i)+" ")
    print(text)
    print(len(set2))
    text = ""
    for i in reversed(set2):
        text+=(str(i)+" ")
    print(text)