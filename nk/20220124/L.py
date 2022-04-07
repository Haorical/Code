

def dis(x,y):
    return (x*x+y*y)**0.5
t=int(input())
for tt in range(t):
    n=int(input())
    s=input()
    x=0
    y=0
    mx=0
    for i in range(n):
        c = s[i]
        if c=='U':
            y+=1
        elif c=='D':
            y-=1
        elif c=='L':
            x-=1
        else: x+=1
        mx=max(float(mx),dis(x,y))
print(mx)

