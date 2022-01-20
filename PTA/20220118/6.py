i = 51# int(input())
m = '1'
for j in range(2,100):
    m+='1'
    x = int(m)
    if x%i==0:
        print("{0} {1}".format(int(x/i),j))
        break