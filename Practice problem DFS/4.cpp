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

int m=1,n;
char oil_mine[102][102];
bool visited[102][102];

void dfs(int i,int k)
{
    visited[i][k]=true;

    //upper cell
    if(!visited[i-1][k] and (i-1<m and k<n) and oil_mine[i-1][k]=='@') dfs(i-1,k); //check if out of range or already visited
                                                                                   // or there is a oil mine at the cell then
    //left cell
    if(!visited[i][k-1] and (i<m and k-1<n) and oil_mine[i][k-1]=='@') dfs(i,k-1);
    //right cell
    if(!visited[i][k+1] and (i<m and k+1<n) and oil_mine[i][k+1]=='@') dfs(i,k+1);
    //down cell
    if(!visited[i+1][k] and (i+1<m and k<n) and oil_mine[i+1][k]=='@') dfs(i+1,k);

    //upper left corner
    if(!visited[i-1][k-1] and (i-1<m and k-1<n) and oil_mine[i-1][k-1]=='@') dfs(i-1,k-1);
    //upper right corner
    if(!visited[i-1][k+1] and (i-1<m and k+1<n) and oil_mine[i-1][k+1]=='@') dfs(i-1,k+1);
    //down left corner
    if(!visited[i+1][k-1] and (i+1<m and k-1<n) and oil_mine[i+1][k-1]=='@') dfs(i+1,k-1);
    //down right corner
    if(!visited[i+1][k+1] and (i+1<m and k+1<n) and oil_mine[i+1][k+1]=='@') dfs(i+1,k+1);

}

void reset()
{
    for(int i=0;i<102;++i)
    {
        for(int k=0;k<102;++k) oil_mine[i][k]='*'; //absence of oil initially before input
    }

    for(int i=0;i<102;++i)
    {
        for(int k=0;k<102;++k) visited[i][k]=false;//every cell is unvisited before input
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


    for(int i=0;i<102;++i)
    {
        for(int k=0;k<102;++k) oil_mine[i][k]='*'; //absence of oil
    }
    
    int ans;

    while(true)
    {
        cin>>m>>n;
        if(!m) break;

        for(int i=0;i<m;++i)
        {
            for(int k=0;k<n;++k) cin>>oil_mine[i][k];
        }

        ans=0;
        

        //One connected component indicates one oil pocket
        //the number of connected components are the total number of oil pockets
        //each dfs call denotes one connected component
        //so after each dfs call, increase the count by 1
        //output count as final asnwer (here count is measured with the variable ans)

        for(int i=0;i<m;++i)
        {
            for(int k=0;k<n;++k)
            {
                if(!visited[i][k] and oil_mine[i][k]=='@') dfs(i,k), ++ans;
            }
        }

        cout<<ans<<endl;
        reset();
    }
    return 0;
}