text = input()

c_ant = ""
repetition = 0
res = 0
for c in text:
    if c_ant==c:
        repetition+=1
    else:
        repetition=0
        c_ant = c
    if repetition>res:
        res=repetition
print(res+1)
