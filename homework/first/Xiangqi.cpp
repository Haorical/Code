#include<bits/stdc++.h>
 
using namespace std;
 
const int drow[] = {1, 1, -1, -1,   1, 0, -1, 0,   1, 1, -1, -1, 2, 2, -2, -2,   1, 1, -1, -1, 1, 1, -1, -1};
const int dcol[] = {1, -1, 1, -1,   0, 1, 0, -1,   2, -2, 2, -2, 1, -1, 1, -1,   1, -1, 1, -1, 1, -1, 1, -1};
 
const int N = 10;
const int M = 9;
char board[N + 1][M + 1];
 
int grow, gcol;
bool flag;

bool general( int row, int col, int start, int end )
{
    for ( int i = start ; i <= end ; i++ ) {
        int nextrow = row+drow[i];
        int nextcol = col+dcol[i];
        while(nextrow >= 1 && nextrow <= N && nextcol >= 1 && nextcol <= M) {
            if(board[nextrow][nextcol] == 'G')
                return true;
            if(board[nextrow][nextcol] != ' ')
                break;
            nextrow += drow[i];
            nextcol += dcol[i];
        }
    }
    return false;
}
 

bool chariot( int row, int col, int start, int end )
{
    for ( int i = start ; i <= end ; i++ ) {
        int nextrow = row+drow[i];
        int nextcol = col+dcol[i];
        while(nextrow >= 1 && nextrow <= N && nextcol >= 1 && nextcol <= M) {
            if(board[nextrow][nextcol] == 'R' || board[nextrow][nextcol] == 'G')
                return true;
            if(board[nextrow][nextcol] != ' ')
                break;
            nextrow += drow[i];
            nextcol += dcol[i];
        }
    }
    return false;
}
 

bool cannon( int row, int col, int start, int end )
{
    for ( int i = start ; i <= end ; i++ ) {
        int nextrow = row+drow[i];
        int nextcol = col+dcol[i];
 

        while(nextrow >= 1 && nextrow <= N && nextcol >= 1 && nextcol <= M) {
            if(board[nextrow][nextcol] != ' ')
                break;
            nextrow += drow[i];
            nextcol += dcol[i];
        }
 

        nextrow += drow[i];
        nextcol += dcol[i];
        while(nextrow >= 1 && nextrow <= N && nextcol >= 1 && nextcol <= M) {
            if(board[nextrow][nextcol] == 'C')
                return true;
            if(board[nextrow][nextcol] != ' ')
                break;
            nextrow += drow[i];
            nextcol += dcol[i];
        }
    }
 
    return false;
}
 

bool horse(int row, int col, int start, int end)
{
    for(int i = start; i <= end; i++) {
        int nextrow = row + drow[i];
        int nextcol = col + dcol[i];
        if(nextrow >= 1 && nextrow <= N && nextcol >= 1 && nextcol <= M)
            if(board[nextrow][nextcol] == 'H' && board[row +drow[i + 8]][col + dcol[i + 8]] == ' ')
                return true;
    }
    return false;
}
 
void deal()
{
    for(int i = 4; i <= 7; i++) {
        int nextrow = grow + drow[i];
        int nextcol = gcol + dcol[i];
        if(nextrow < 1 || nextrow > 3 || nextcol < 4 || nextcol > 6)
            continue;
 
        
        flag = chariot(nextrow, nextcol, 4, 7);
        if(flag)
            continue;
 
        
        flag = cannon(nextrow, nextcol, 4, 7);
        if(flag)
            continue;
 
        
        flag = horse(nextrow, nextcol, 8, 15);
        if(flag)
            continue;
 
        flag = false;
        return;
    }
 
    flag = true;
}
 
inline char mygetchar()
{
    char ret;
    while ((ret = getchar()) == ' ' || ret == '\t' || ret == '\n');
    return ret;
}
 
int main()
{
    int n;
    while(scanf("%d%d%d", &n, &grow, &gcol) == 3 && (n || grow || gcol)) {
        memset(board, ' ', sizeof(board));
 
        char piece;
        int row, col;
        while(n--) {
            piece = mygetchar();
            scanf("%d%d", &row, &col);
            board[row][col] = piece;
        }
 
        flag = false;
        if(!general(grow, gcol, 4, 4)) {
            flag = false;
            deal();
        }
 
        printf("%s\n", flag ? "YES" : "NO");
    }
    system("pause");
    return 0;
}