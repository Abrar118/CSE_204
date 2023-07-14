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

vector<int>a[100];
bool state[100];
int p, prog, color[100];
queue<int>tier;

bool bipartite_check(int node)
{
    state[node]=true;
    color[node]=0;
    tier.push(node);
    while(!tier.empty())
    {
        prog=tier.front();
        tier.pop();
        for(int i=0;i<a[prog].size();++i)
        {
            p=a[prog][i];
            if(!state[p] and color[p]!=color[prog]) state[p]=true, color[p]=(color[prog]+1)%2, tier.push(p);
            else if(color[p]==color[prog]) return false;
        }
    }
    return true;
}


int main()
{
    int n,e,x,y; cin>>n>>e;
    bool ans=true;
    set<int>nodes;
    for(int i=0;i<e;++i)
    {
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
        nodes.insert(x), nodes.insert(y);
    }

    for(int i=0;i<n+1;++i) color[i]=-1;
   
    for(set<int>::iterator it=nodes.begin();it!=nodes.end();++it)
    {
        if(!state[*it]) ans=bipartite_check(*it);
        if(!ans) break;
    }
    
    cout<<((ans)? "YES":"NO");
    return 0;
}