t = int(input())
data = input().split(" ")
pesos = []

def sortList(list):
    sorted = False
    while not sorted:
        sorted=True
        for i in range(len(list)-1):
            if list[i]>list[i+1]:
                temp = list[i]
                list[i]=list[i+1]
                list[i+1]=temp
                sorted=False
    return list

def evalSets(pesos, swapList):
    set = []
    for el in swapList:
        set.append(pesos[el])
    return sum(set)

def nextList(swapList):
    next = False
    for i in range(1,len(swapList)+1):
        if swapList[-i]!=t-i:
            next = True
            swapList[-i]+=1
            for j in range(1,i):
                swapList[-j]=swapList[-i]+i-j
            break
        else:
            continue
    return next

for d in data:
    pesos.append(int(d))

sortList(pesos)

#print(pesos)

suma = sum(pesos)
#print(suma)
best_scrore = suma
l=len(pesos)//2
if l>9:
    l=9
#print(l)

for i in range(1,l+1):
    next = True
    swapList = [j for j in range(i)]
    while next:
        #print(swapList)
        temp_score = abs(suma-2*evalSets(pesos,swapList))
        #print(swapList, temp_score)
        if temp_score<best_scrore:
            best_scrore=temp_score
        next = nextList(swapList)
print(best_scrore)
