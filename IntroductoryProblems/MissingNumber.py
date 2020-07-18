n = int(input())
data = input().split(" ")

#print(data)

checks = [0 for i in range(len(data)+2)]
#print(checks)
for d in data:
    checks[int(d)]=1

for i in range(1,len(data)+2):
    if checks[i]==0:
        print(i)
