#include<bits/stdc++.h>
using namespace std;
struct Node{
    double t;
    double v;
    double a;
}node[21];

int cmp(Node x,Node y){
    return x.a>y.a;
}

int main(){
    int m,n;
    while(cin>>m>>n){
        if(m==0&&n==0){
            break;
        }
        for(int i=0;i<m;i++){
            cin>>node[i].t>>node[i].v;
            node[i].a=node[i].v/node[i].t;
        }
        sort(node,node+m,cmp);
        //cout<<node[0].t<<" "<<node[0].v;
        int k=0;
        double sum=0;
        while(n){
            if(n<=node[k].t){
                //cout<<node[k].a;
                sum+=n*node[k].a;
                break;
            }
            sum+=node[k].v;
            n-=node[k].t;
            k++;
        }
        //cout<<sum;
        printf("%.2f\n",sum);
    }
    system("pause");
    return 0;
}