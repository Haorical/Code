/*
#include<bits/stdc++.h>
using namespace std;
#define MAXN 256
char br[MAXN];
int dp[MAXN][MAXN], pos[MAXN][MAXN];
int len;
void print_br(int i, int j){
    if(i>j) return;
    if(i==j){
        if(br[i]=='('||br[j]==')')printf("()");
        else printf("[]");
    }
    else if(pos[i][j] == -1){printf("%c", br[i]);print_br(i+1, j-1);printf("%c", br[j]);}
    else{print_br(i, pos[i][j]);print_br(pos[i][j]+1, j);}
}

bool match(int i, int j){
    if(br[i]=='('&&br[j]==')')return true;
    if(br[i]=='['&& br[j] ==']')return true;
    return false;
}

int main(){
    int i, j, k, mid, t;
    while(gets(br)!=NULL){
        memset(dp,0,sizeof(dp));
        len=strlen(br);
        for(i=0;i<len;i++){
            dp[i][i]=1;
        }
        for(k=1;k<len;k++){
            for(i=0;i+k<len;i++){
                j=i+k;
                dp[i][j]=0x7fffffff;
                if(match(i,j)){
                    dp[i][j]=dp[i+1][j-1];
                    pos[i][j]=-1;
                }
                for(mid=i;mid<j;mid++){
                    if(dp[i][j]>(t=dp[i][mid]+dp[mid+1][j])){ //bug 0x01
                        dp[i][j]=t;
                        pos[i][j]=mid;
                    }
                }
            }
        }
        print_br(0, len-1);
        printf("\n");
    }
    system("pause");
    return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
const int MAXN=256;char br[MAXN];int dp[MAXN][MAXN],pos[MAXN][MAXN];int len;void print_br(int i,int j){if(i>j)return;if(i==j){if(br[i]=='('||br[j]==')')printf("()");else printf("[]");}else if(pos[i][j]==-1){printf("%c", br[i]);print_br(i+1, j-1);printf("%c",br[j]);}else{print_br(i,pos[i][j]);print_br(pos[i][j]+1,j);}}bool match(int i, int j){ if(br[i]=='('&&br[j]==')')return true;if(br[i]=='['&& br[j] ==']')return true;return false;}int main(){int i,j,k,mid,t;while(gets(br)!=NULL){memset(dp,0,sizeof(dp));len=strlen(br);for(i=0;i<len;i++){dp[i][i]=1;}for(k=1;k<len;k++){for(i=0;i+k<len;i++){j=i+k;dp[i][j]=0x7fffffff;if(match(i,j)){dp[i][j]=dp[i+1][j-1];pos[i][j]=-1;}for(mid=i;mid<j;mid++){if(dp[i][j]>(t=dp[i][mid]+dp[mid+1][j])){dp[i][j]=t;pos[i][j]=mid;}}}}print_br(0,len-1);printf("\n");}}