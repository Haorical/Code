/*
#include<bits/stdc++.h>
using namespace std;
int mmp[105][105];
int t,n,k,x,y,x1,y1,maxx,maxy,sum=0;
int main(){
    cin>>t;
    while(t--){
        memset(mmp,0,sizeof(mmp));
        maxx=0;
        maxy=0;
        sum=0;
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            cin>>x>>y>>x1>>y1;
            if(x>maxx) maxx=x; //墙最大行列
            if(x1>maxx) maxx=x1;
            if(y>maxy) maxy=y;
            if(x<x1){
                for(int j=x;j<=x1;j++) mmp[j][y]=1;//转换一下地图
            }else{
                for(int j=x1;j<=x;j++) mmp[j][y]=1;
            }
        }
        //从左到右逐行扫描
        for(int i=0;i<=maxx;i++){
            int tmp=0;//第i列格子数
            for(int j=0;j<=maxy;j++){
                if(mmp[i][j]>0) tmp++;
            }
            int offset=tmp-k;//需要去除的墙数
            if(offset>0){
                sum+=offset;
                while(offset--){ //一个一个拆，不是排序之后全拆的
                    int maxs=0,yy;
                    for(int k=0;k<=maxy;k++){
                        if(mmp[i][k]){
                            int tmp=0;
                            for(int z=i+1;z<=maxx;z++){
                                if(mmp[z][k]){
                                    tmp++;
                                }else break;
                            }
                            if(maxs<tmp){
                                maxs=tmp;
                                yy=k;
                            }
                        }
                    }
                    for(int p=i;p<=i+maxs;p++){
                        mmp[p][yy]=0;
                    }
                }
            }
        }
        cout<<sum<<endl;
    }
    system("pause");
    return 0;
}
*/

#include<bits/stdc++.h>
using namespace std;
int main(){int mmp[105][105];int t,n,k,x,y,x1,y1,maxx,maxy,sum=0;cin>>t;while(t--){memset(mmp,0,sizeof(mmp));maxx=0;maxy=0;sum=0;cin>>n>>k;for(int i=1;i<=n;i++){cin>>x>>y>>x1>>y1;if(x>maxx)maxx=x;if(x1>maxx)maxx=x1;if(y>maxy)maxy=y;if(x<x1)for(int j=x;j<=x1;j++)mmp[j][y]=1;else for(int j=x1;j<=x;j++)mmp[j][y]=1;}for(int i=0;i<=maxx;i++){int tmp=0;for(int j=0;j<=maxy;j++){if(mmp[i][j]>0) tmp++;}int offset=tmp-k;if(offset>0){sum+=offset;while(offset--){int maxs=0,yy;for(int k=0;k<=maxy;k++){if(mmp[i][k]){int tmp=0;for(int z=i+1;z<=maxx;z++){if(mmp[z][k])tmp++;else break;}if(maxs<tmp){maxs=tmp;yy=k;}}}for(int p=i;p<=i+maxs;p++){mmp[p][yy]=0;}}}}cout<<sum<<endl;}}