t=int(input())
for i in range(t):
    s=str(input())
    l=s.strip('.').split()
    sz=len(l)
#     # print(sz)
#     if sz==14:
#         # print(l[6][-4:-1],l[13][-4:])
#         if l[6][-4:-1]=='ong' and l[13][-3:]=='ong':
#             for j in range(sz-3):
#                 print(l[j],end=' ')
#             print('qiao ben zhong.')
#         else:
#             print('Skipped')
#     elif sz==10:
#         if l[4][-4:-1]=='ong' and l[9][-3:]=='ong':
#             for j in range(sz-3):
#                 print(l[j],end=' ')
#             print('qiao ben zhong.')
#         else:
#             print('Skipped')
#     else:
    flag=0
    for j in l:
#         if l[-1][-3:]=='ong':
        if 'ong,' in j:
            flag=1
            break
    if flag==1 and l[-1][-3:]=='ong':
        for j in range(sz-3):
            print(l[j],end=' ')
        print('qiao ben zhong.')
    else:
        print('Skipped')
        
            