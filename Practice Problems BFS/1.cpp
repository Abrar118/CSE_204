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

map<string,string>parent;

void print_path(string s)
{
    vector<string>path;
    string cur=s;
    while(cur!="C:")
    {
        path.push_back(cur);
        cur=parent[cur];
    }
    path.push_back("C:");
    
    for(int i=path.size()-1;i>-1;--i)
    {
        cout<<path[i]<<((i)? "\\\\":"");
    }

    cout<<endl<<2*(path.size()-1)<<endl;
}

int main()
{
    string s,ss;
    int e; cin>>e;
    for(int i=0;i<e;++i)
    {
        cin>>s>>ss;
        parent[ss]=s;
    }

    int q; cin>>q;
    while(q--)
    {
        cin>>s;

        if(parent.find(s)!=parent.end()) print_path(s);
        else cout<<-1<<endl;
    }

    return 0;
}