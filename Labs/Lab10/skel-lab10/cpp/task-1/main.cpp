#include <bits/stdc++.h>
using namespace std;
struct edge
{
    int x,y,cost;
};
edge v[400005];
bool cmp(edge a,edge b)
{
    if(a.cost==b.cost)
        return a.x<b.x;
    return a.cost<b.cost;
}
int t[200005],h[200005];
void unionset(int x,int y)
{
    if(h[x]>h[y])t[y]=x;
    if(h[x]<h[y])t[x]=y;
    if(h[x]==h[y])
    {
        h[x]++;
        t[y]=x;
    }
}
int findset(int x)
{
    while(x!=t[x])x=t[x];
    return x;
}
int fr[400005];
int main()
{
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    int n,m,i;
    cin >> n >> m;
    for(i=1;i<=m;i++)
        cin >> v[i].x >> v[i].y >> v[i].cost;
    sort(v+1,v+m+1,cmp);
    for(i=1;i<=n;i++)t[i]=i,h[i]=1;
    int sum=0;
    for(i=1;i<=m;i++)
    {
        int x1=v[i].x,y1=v[i].y;
        int x2=findset(x1),y2=findset(y1);
        if(x2==y2)continue;
        unionset(x2,y2);
        fr[i]=1;
        sum+=v[i].cost;
    }
    cout << sum;
}