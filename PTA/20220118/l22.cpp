#include<bits/stdc++.h>
using namespace std;
struct Node{
    int d,a,n;
}node[100002];
int main(){
    int p,n;
    cin>>p>>n;
    while(n--){
        int a1,a2,a3;
        cin>>a1>>a2>>a3;
        node[a1].a=a1;
        node[a1].d=a2;
        node[a1].n=a3;
    }
    int i=0;
    int a[100002],rt[100002];
    while(p!=-1){
        a[i++]=p;
        p=node[p].n;
    }
    int l=0,r=i-1;
    int j=0;
    while(l<=r){
        if(l==r) rt[j++]=a[l++];
        else{
            rt[j++]=a[r--];
            rt[j++]=a[l++];
        }
    }
        for(i=0;i<j-1;i++)
    {
        printf("%05d %d %05d\n",rt[i],a[aa[i]].data,aa[i+1]);
    }
     printf("%05d %d %d\n",aa[x-1],a[aa[x-1]].data,-1);
    system("pause");
    return 0;
}