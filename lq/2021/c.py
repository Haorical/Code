a = 2021041820210418
l = []
l.append(1)
l.append(a)
for i in range(2,707400007074):
    if a%i==0:
        if i>a/i:
            break
        l.append(i)
        l.append(int(a/i))
        print(l)
sum=0
for i in l:
    for j in l:
        for k in l:
            if i*j*k==a:
                print(i,j,k)
                sum+=1
print(sum)