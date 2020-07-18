
def str2numList(string):
    return  [int(el) for el in string.split(" ")]

def sort(arr):
    quickSort(arr, 0, len(arr)-1)

def quickSort(arr,l,r):
    if l<r:
        pivot = arr[r]
        i = l-1
        for j in range(l,r):
            if arr[j]<pivot:
                i+=1
                arr[i],arr[j]=arr[j],arr[i]
        arr[i+1],arr[r]=arr[r],arr[i+1]

        quickSort(arr,l,i)
        quickSort(arr,i+2,r)

[n,x] = str2numList(input())
p = str2numList(input())

sort(p)

res = 0
i = 0
j = len(p)-1
min = p[0]
while i<j:
    if p[i]+p[j]<=x and p[i]+p[j]>x-min:
        p.remove(p[j])
        p.remove(p[i])
        if i==0 and j>1:
            min = p[0]
        res+=1
        j-=2
    elif p[i]+p[j]>x:
        j-=1
    elif p[i]+p[j]<=x-min:
        i+=1

for l in p:
    res+=1

print(res)


