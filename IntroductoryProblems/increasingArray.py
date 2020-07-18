n = int(input())
arr = input().split(" ")
array = [int(a) for a in arr]

steps = 0

for i in range(1,n):
    if array[i]<array[i-1]:
        steps=steps+array[i-1]-array[i]
        array[i]=array[i-1]
print(steps)
