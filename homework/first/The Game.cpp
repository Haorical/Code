#include<bits/stdc++.h>
using namespace std;
int winner=0;
int cnt;
int ma[20][20];
int d[5][3];
bool v[20][20][5];
void findme(int x,int y,int team,int num,int direct)
{
    int i,j,k;
    v[x][y][direct]=1;
    if(ma[x+d[direct][1]][y+d[direct][2]]==team)
        cnt++,findme(x+d[direct][1],y+d[direct][2],team,num++,direct);

}
int main()
{
    int t,k,i,j,q,a,b;
    scanf("%d",&t);
    d[1][1]=1;d[1][2]=0;
    d[2][1]=1;d[2][2]=1;
    d[3][1]=0;d[3][2]=1;
    d[4][1]=-1;d[4][2]=1;
    for(k=1;k<=t;k++)
        {
            winner=0;
            memset(ma,0,sizeof(ma));
            memset(v,0,sizeof(v));

            for(i=1;i<=19;i++)
                for(j=1;j<=19;j++)
                    scanf("%d",&ma[i][j]);
            for(i=1;i<=19;i++)
                for(j=1;j<=19;j++)
                    if(ma[i][j]!=0)
                        for(q=1;q<=4;q++)
                        if(v[i][j][q]==0)
                        {
                            v[i][j][q]=1;
                            if(ma[i+d[q][1]][j+d[q][2]]==ma[i][j])
                                {
                                    cnt=2,findme(i+d[q][1],j+d[q][2],ma[i][j],2,q);
                                    if(cnt==5 && ma[i-d[q][1]][j-d[q][2]]!=ma[i][j])
                                    {
                                        winner=ma[i][j];
                                        a=i,b=j;
                                    }
                                }
                        }
            if(winner!=0)
                printf("%d\n%d %d\n",winner,a,b);
            else printf("0\n");
    }
    system("pause");
    return 0;
}