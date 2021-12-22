/*

#include<bits/stdc++.h>
using namespace std;
double ans(int x){
    double sum=0.0;
    for(int i=1;i<=x;i++){
        sum+=log(double(i));
    }
    return sum;
}
int main(){
    int n;
    while(cin>>n){
        if(!n) break;
        int t = (n-1960)/10+2;
        //cout<<t<<endl;
        t = 1<<t;
        //cout<<t<<endl;
        //t = (1<<t)-1;
        //cout<<t<<endl;
        t = t * log(double(2));
        
        for(int i=1;i<9999999;i++){
            if(ans(i)>=t){
                cout<<i-1<<endl;
                break;
            }
        }
        
        //cout<<ans(t)<<endl;
    }
    system("pause");
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
    int y,Y,i,j,m;
    double f,w;
    while(1==scanf("%d",&y)&&y){
        w=log(4);
        for(Y=1960;y<=Y;y+=10){
            w *= 2;
        }
        i = 1;
        f = 0;
        while(f<w){
            f+=log(double(++i));
        }
        printf("%d\n",i-1);
    }
    return 0;
}

*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int y;
    while(cin>>y){
        if(y==0) break;
        double w=log(4.0);
        for(int i=1960;i<=y;i+=10){
            w*=2;
        }
        double f=0;
        int i=1;
        while(f<w){
            f+=log(double(++i));
        }
        cout<<i-1<<endl;
    }
    system("pause");
    return 0;
}
// double i-1 都是<