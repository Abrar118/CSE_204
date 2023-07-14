#include<bits/stdc++.h>
using namespace std;

vector<int>a[100];
bool state[100];
int path[100],prog,p;
queue<int>tier;

void bfs(int node)
{
    cout<<"Explored "<<node<<endl;
    state[node]=true;
    path[node]=0;
    tier.push(node);
    while(!tier.empty())
    {
        prog=tier.front();
        tier.pop();
        for(int i=0;i<a[prog].size();++i)
        {
            p=a[prog][i];
            if(!state[p]) state[p]=true, path[p]=path[prog]+1, tier.push(p), cout<<"Explored "<<p<<endl;
        }
    }

    cout<<"bfs done"<<endl;
}

void dfs(int node)
{
    state[node]=true;
    for(int i=0;i<a[node].size();++i)
    {
        p=a[node][i];
        if(!state[p]) dfs(p);
    }
}

int main()
{
    int n,e,x,y; cin>>n>>e;
    set<int>nodes;
    for(int i=0;i<e;++i)
    {
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
        nodes.insert(x), nodes.insert(y);
    }

    for(set<int>::iterator it=nodes.begin();it!=nodes.end();++it) cout<<*it<<" ";
    cout<<endl;

    for(set<int>::iterator it=nodes.begin();it!=nodes.end();++it)
    {
        if(!state[*it]) bfs(*it);
    }

    for(set<int>::iterator it=nodes.begin();it!=nodes.end();++it)
    {
        if(state[*it]) cout<<"VISITED node "<<*it<<endl;
        else cout<<"Has not visited "<<*it<<endl;
    }
    return 0;
}

/*
9 11
1 2
2 6
6 3
3 5
5 8
8 4
4 7
7 1
1 0
2 0
0 5
*/