# 用python很简单，但是最后一个样例超时了，我也不会优化，换成c++
a=input().split()
n=int(a[0])
del(a[0])
sum=0
k=int(input())
l1=[]
d1={}
for i in range(k):
    t1,t2=input().split()
    l1.append(t1)
    d1[t1]=int(t2)
    sum+=int(t2)
sum=sum/k
l2=[]
for i in l1:
    if i not in a and d1[i]>sum:
        l2.append(i)
l2.sort()
for i in l2:
    print(i,end=' ')
