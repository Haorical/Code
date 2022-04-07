#include<bits/stdc++.h>
using namespace std;
int main(){
    int t0=1;
    int t1=1;
    int t2=0;
    int t3=0;
    for(;t3<=4;t3++){
        t2=t0+t1;
        t0=t1;
        t1=t2;
        cout<<t2<<endl;
    }
    system("pause");
}

/*
lui $t0,1
lui $t1,1
lui $t2,0
lui $t3,0
lui $t4,n
loop:
addu $t2,$t0,$t1
addu $t0,$t1,$zero
addu $t1,$t2,$zero
addiu $t3,$t3,1
beq $t3,$t4,ending
j loop
ending:
addu $t5,$zero,$t2
*/