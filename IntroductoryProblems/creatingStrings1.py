string = input()

letras = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']

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

def toNumbres(string):
    numbers = []
    for c in string:
        numbers.append(letras.index(c))
    return numbers

def toString(numbers):
    string=""
    for n in numbers:
        string+=letras[n]
    return string

def permutes(strings, n, l):
    if n==l-1:
        res = strings
    else:
        res = []
        for str in strings:

            res.append(str)
            for i in range(n+1,l):
                if str[i]==str[n]:
                    continue
                else:
                    t = list(str)
                    value = t[i]
                    del t[i]
                    t.insert(n, value)
                    new_str = ''.join(t)
                    if new_str!=res[-1]:
                        res.append(new_str)
        res = permutes(res,n+1,l)
    return res

sort_str = toString(sortList(toNumbres(string)))

result = (permutes([sort_str],0,len(sort_str)))

print(len(result))
for str in result:
    print(str)