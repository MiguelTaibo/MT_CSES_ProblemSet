n = int(input())

temp = n
text = ""
while temp!=1:
    text += str(int(temp))
    if temp%2==0:
        temp = temp/2
    elif temp%2==1:
        temp = 3*temp+1
    text += " "
print(text+"1")
