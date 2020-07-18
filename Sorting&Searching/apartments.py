[n,m,k]=input().split(" ")
n,m,k=int(n), int(m), int(k)


a = input().split(" ")
a = [int(t) for t in a]

b = input().split(" ")
b = [int(t) for t in b]

a = sorted(a)
b = sorted(b)

i = 0
j = 0
res = 0
while i<len(a) and j<len(b):
    if abs(a[i]-b[j])<=k:
        i+=1
        j+=1
        res+=1
    elif a[i]>b[j]:
        j+=1
    elif a[i]<b[j]:
        i+=1
print(res)
