n = int(input())
a = list(map(int, input().split()))
s = int(input())

for i in range(n-1):
    myMax = a[i]
    temp = 0

    if s == 0:
        break

    for j in range(i+1, n):
        myIdx = j - i
        
        if a[j] > myMax:
            myMax = a[j]
            temp = myIdx
        
        if myIdx >= s:
            break
    
    if temp:
        s = s - temp
        a.remove(myMax)
        a.insert(i, myMax)

for i in a:
    print(i, end=' ')