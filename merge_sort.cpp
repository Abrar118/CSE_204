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

void merge(vector<int>&a, int l, int m, int r)
{
    int temp[r-l+1],id=0;

    int i,k;
    for(i=l, k=m+1; i<=m and k<=r;)
    {
        if(a[i]<a[k]) temp[id++]=a[i], ++i;
        else temp[id++]=a[k], ++k;
    }

    while(i<=m) temp[id++]=a[i++];
    while(k<=r) temp[id++]=a[k++];

    for(int i=l;i<=r;++i) a[i]=temp[i-l];
}

void merge_sort(vector<int>&a, int l, int r)
{
    if(l<r)
    {
        int m=l+(r-l)/2;
        merge_sort(a,l,m);
        merge_sort(a,m+1,r);
        merge(a,l,m,r);
    }
    else return;
}

int main()
{

    vector<int>a{5,4,2,6,8,1,8,1,5,2,3,2,7,9};
    merge_sort(a,0,a.size()-1);
    for(int i:a) cout<<i<<" ";
    return 0;
}