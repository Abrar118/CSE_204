#include<bits/stdc++.h>

using namespace std;

char adj_mat[21][21];
map<pair<int,int>,bool>visited;
pair<int,int> cell;
int w,h;

void dfs(int i,int k)
{
    visited[{i,k}]=true;

    cell={i-1,k}; //upper cell
    if(!visited[cell] and (i-1<h and k<w) and adj_mat[i-1][k]=='.') dfs(i-1,k);  //check if out of bound and if already visited

    cell={i,k-1}; // left cell
    if(!visited[cell] and (i<h and k-1<w) and adj_mat[i][k-1]=='.') dfs(i,k-1);

    cell={i,k+1}; //right cell
    if(!visited[cell] and (i<h and k+1<w) and adj_mat[i][k+1]=='.') dfs(i,k+1);

    cell={i+1,k}; //bottom cell
    if(!visited[cell] and (i+1<h and k<w) and adj_mat[i+1][k]=='.') dfs(i+1,k);
}

void reset()
{
    visited.clear();

    for(int i=0;i<21;++i)
    {
        for(int k=0;k<21;++k) adj_mat[i][k]='#'; //setting every cell to water as in '#' so that we don't visit that cell
    }
}


int main()
{
    int t, initial_pos_i,initial_pos_k, ans; cin>>t;
    for(int tc=0;tc<t;++tc)
    {
        cin>>w>>h;
        for(int i=0;i<h;++i)
        {
            for(int k=0;k<w;++k)
            {
                cin>>adj_mat[i][k];
                if(adj_mat[i][k]=='@') initial_pos_i=i, initial_pos_k=k;
            }
        }

        dfs(initial_pos_i, initial_pos_k);
        
        ans=0;
        map<pair<int,int>,bool>::iterator it;

        for(it=visited.begin();it!=visited.end();++it)
        {
            if(it->second==true) ++ans;
            //cout<<it->first.first<<" "<<it->first.second<<" "<<it->second<<endl;
        }

        cout<<"Case "<<tc+1<<": "<<ans<<endl;
        reset();
    }
    return 0;
}