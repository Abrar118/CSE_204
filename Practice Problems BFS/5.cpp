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

map<int,vector<string>>m;
queue<string>q;
int cnt;

void bfs(int n)
{
    q.push("");

    while(!q.empty())
    {
        string s=q.front();
        q.pop();

        s.push_back('0'), q.push(s), m[s.size()].push_back(s);
        s.pop_back();
        s.push_back('1'), q.push(s), m[s.size()].push_back(s);
        cnt+=2;

        if(cnt==pow(2,n+1)-2) return;
    }
}

void print_comb()
{
    map<int,vector<string>>::iterator it;

    for(it=m.begin();it!=m.end();++it)
    {
        cout<<"Strings of length =>> "<<it->first<<" ";
        for(int k=0;k<it->second.size();++k) cout<<it->second[k]<<" ";
        cout<<endl;
    }
}


int main()
{
    int n; cin>>n;
    bfs(n);
    print_comb();
    return 0;
}