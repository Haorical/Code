#include<bits/stdc++.h>
using namespace std;
struct Mouse{
    double J,F;
    double a;
};
int m,n;
vector<Mouse> v;
vector<Mouse>::iterator it;
bool cmp(const Mouse m1, const Mouse m2){
    if(m1.a!=m2.a) return m1.a>m2.a;
    else return m1.F<m2.F;
}
int main(){
    while(~scanf("%d %d",&m,&n)){
        v.clear();
        Mouse mouse;
        if(m==-1&&n==-1) break;
        for(int i=0;i<n;i++){
            scanf("%lf %lf",&mouse.J,&mouse.F);
            mouse.a=mouse.J/mouse.F;
            v.push_back(mouse);
        }
        sort(v.begin(),v.end(),cmp);
        double sum=0;
        for(int i=0;i<v.size();i++){
            if(v[i].F<=m){
                sum+=v[i].J;
                m-=v[i].F;
            }else{
                sum+=m*v[i].a;
                break;
            }
        }
        printf("%.3lf\n",sum);
    }
    system("pause");
    return 0;
}