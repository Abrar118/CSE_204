#include<bits/stdc++.h>
//#include "utility.h"
#define endl "\n"
#define tab "\t"
#define pq priority_queue
#define in long long
#define dub double
#define dubb long double
const in modv=998244353;
using namespace std;

char board[202][202];
int visited[202][202];
int n=1;

void dfs(int i,int k, char sym)
{
    visited[i][k]=true;
    
    //upper left cell
    if(!visited[i-1][k-1] and (i-1<n and k-1<n) and board[i-1][k-1]==sym) dfs(i-1,k-1,sym);

    //upper cell
    if(!visited[i-1][k] and (i-1<n and k<n) and board[i-1][k]==sym) dfs(i-1,k,sym);

    //left cell
    if(!visited[i][k-1] and (i<n and k-1<n) and board[i][k-1]==sym) dfs(i,k-1,sym);

    //rigght cell
    if(!visited[i][k+1] and (i<n and k+1<n) and board[i][k+1]==sym) dfs(i,k+1,sym);

    //down cell
    if(!visited[i+1][k] and (i+1<n and k<n) and board[i+1][k]==sym) dfs(i+1,k,sym);

    //down right cell
    if(!visited[i+1][k+1] and (i+1<n and k+1<n) and board[i+1][k+1]==sym) dfs(i+1,k+1,sym);
}

void reset()
{
    for(int i=0;i<202;++i)
    {
        for(int k=0;k<202;++k) board[i][k]='\0';
    }

    for(int i=0;i<202;++i)
    {
        for(int k=0;k<202;++k) visited[i][k]=false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    bool white, black;
    int tc=0; //test case

    for(int i=0;i<202;++i)
    {
        for(int k=0;k<202;++k) board[i][k]='\0'; ///set every cell to NULL
    }

    while(true)
    {
        cin>>n;
        if(!n) break;

        for(int i=0;i<n;++i)
        {
            for(int k=0;k<n;++k) cin>>board[i][k];
        }

        white=black=false; //initially nobody wins

        for(int i=0;i<n;++i)
        {
            if(board[i][0]=='w' and !visited[i][0]) dfs(i,0,'w'); //white starts from the first column (index 0)
        }

        //white wins if it reaches the last column
        //so we have to check if any of the cells in the last column is visited or not

        for(int i=0;i<n;++i)
        {
            if(visited[i][n-1] and board[i][n-1]=='w')
            {
                white=true; break;
            }
        }

        ///black starts from the first row (index 0)

        if(!white)
        {
            for(int i=0;i<n;++i)
            {
                if(board[0][i]=='b' and !visited[0][i]) dfs(0,i,'b');
            }
        }

        //black wins if it reaches the last row
        //so we have to check if any of the cells of the last row is visited or not

        for(int i=0;i<n;++i)
        {
            if(visited[n-1][i] and board[n-1][i]=='b')
            {
                black=true; break;
            }
        }

        cout<<++tc<<" ";

        if(white) cout<<'W'<<endl;
        else cout<<'B'<<endl;

        reset();
    }
    return 0;
}