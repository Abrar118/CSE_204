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

map<in,in>parent,step;
map<in,bool>state;
queue<in>q;
int p;

void bfs(in ini,in fn)
{
    parent[ini]=-1;
    state[ini]=true;
    q.push(ini);
    step[ini]=0;

    while(!q.empty())
    {
        p=q.front();
        q.pop();

        //cout<<p<<endl<<p*2<<" "<<p-1<<endl;
        if(!state[p*2]) q.push(p*2), step[p*2]=step[p]+1, parent[p*2]=p, state[p*2]=true;
        if(!state[p-1]) q.push(p-1), step[p-1]=step[p]+1, parent[p-1]=p, state[p-1]=true;
        if(p*2==fn or p-1==fn) return;
    }
    cout<<"bfs done"<<endl;
}

void print_path(in ini,in fn,in l)
{
    if(fn==ini)
    {
        cout<<fn<<"->";
        return;
    }
    else print_path(ini,parent[fn],l);
    cout<<fn<<((fn==l)? "":"->");
}


int main()
{
    in n,m; cin>>n>>m;
    
    bfs(n,m);
    cout<<step[m]<<endl;
    
    // map<in,in>::iterator it;
    // for(it=parent.begin();it!=parent.end();++it)
    // {
    //     cout<<"Parent "<<it->first<<" child "<<it->second<<endl;
    // }

    print_path(n,m,m);
    return 0;
}