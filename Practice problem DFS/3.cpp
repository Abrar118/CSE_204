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

vector<int>tree[30001];
int p;
map<pair<int,int>,int>weight;
map<int,int>distanc;
map<int,bool>visited;

void dfs(int node)
{
    visited[node]=true;

    for(int i=0;i<tree[node].size();++i)
    {
        p=tree[node][i];

        if(!visited[p])
        {
            distanc[p]+=distanc[node]+weight[{node,p}]; //node is the parent, so update distance of p by addning the
                                                        //distnace between node and p to the distance of node
            dfs(p);
        }
    }
}

void reset();

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t,n,u,v,w,max_dis, farthest_leaf; cin>>t;
    for(int i=0;i<t;++i)
    {
        cin>>n;
        for(int k=0;k<n-1;++k) 
        {
            cin>>u>>v>>w;
            tree[u].push_back(v); //edge from u to v
            tree[v].push_back(u); //edge from v to u

            weight[{u,v}]=w;  //weight of edge uv
            weight[{v,u}]=w;  //weight of edge vu....same as uv
        }

        dfs(0); //dfs call 0 as root

        max_dis=0;

        map<int,int>::iterator it;

        for(it=distanc.begin();it!=distanc.end();++it)
        {
            if(max_dis<it->second) max_dis=it->second, farthest_leaf=it->first; //caltucating the fartest node from root
        }

        distanc.clear(), visited.clear();

        dfs(farthest_leaf); //dfs call, farthest node as root;

        max_dis=0;
        for(it=distanc.begin();it!=distanc.end();++it)
        {
            if(max_dis<it->second) max_dis=it->second; //calculating the fartest node from the previsous farthest node
                                                       //that way we get two node with farthest distance
        }


        cout<<"Case "<<i+1<<": "<<max_dis<<endl;
        
        reset();

    }
    return 0;
}

void reset()
{
    for(int i=0;i<30001;++i) tree[i].clear();
    weight.clear();
    distanc.clear();
    visited.clear();
}