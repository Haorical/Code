t=int(input())
for tt in range(t):
    s=str(input())
    print(s)
    s=s.strip()
    s=s.replace('?','!')
    l=s.split()
    s2='AI:'
    for i in range(len(l)):
        # print(i)
        if l[i]=='can' and l[i+1]=='you':
            s2+='I'
            l[i+1]='can'
        elif l[i]=='could' and l[i+1]=='you':
            s2+='I'
            l[i+1]='could'
        elif l[i]=='I':
            s2+=' '
            s2+='you'
        elif l[i]=='me':
            s2+=' '
            s2+='you'
        else:
            s2+=' '
            s2+=l[i]
    s2=s2.strip()
    if (s2[-1]=='?' or s2[-1]=='!') and s2[-2]==' ':
        tp = list(s2)
        tp[-2]=tp[-1]
        tp[-1]=''
        s2=''.join(tp)
    print(s2.strip())