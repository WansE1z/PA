#include <bits/stdc++.h>
#define MAX 50000 + 5
#define INF 2e9
 
using namespace std;
 
vector<pair<int, int>>graph[MAX];
int dist[MAX], vf[MAX];
int main()
{
    ifstream fin("in");
    ofstream fout("out");
 
    ios::sync_with_stdio(false);
    fin.tie(0);
    fout.tie(0);
    srand(time(NULL));
 
    int n, m, source;
 
    fin >> n >> m >> source;
 
    for(int i = 1; i <= m; i++)
    {
        int a, b, cost;
 
        fin >> a >> b >> cost;
 
        graph[a].push_back({b, cost});
    }
 
    queue<int>Q;
    bitset<MAX>inQueue;
    bool eCiclu = false;
    source = 1;
    dist[source] = 0;
    for(int i = 2; i <= n; i++)dist[i] = INF;
 
    Q.push(source);
    inQueue[source] = true;
 
    while(!eCiclu && Q.size())
    {
        int nod = Q.front();
 
        Q.pop();
 
        inQueue[nod] = false;
        for(auto vecin : graph[nod])
        {
            if(dist[vecin.first] > dist[nod] + vecin.second)
            {
                dist[vecin.first] = dist[nod] + vecin.second;
 
                if(!inQueue[vecin.first])
                {
                    if(vf[vecin.first] > n)
                        eCiclu = true;
                    else
                    {
                        Q.push(vecin.first);
                        inQueue[vecin.first] = true;
                        vf[vecin.first]++;
                    }
                }
            }
        }
    }
 
    if(eCiclu) {
        fout << "Ciclu negativ!";
        return 0;
    }
    else
        fout << "0" << " ";
        for(int i = 2; i <= n; i++)fout << dist[i] << " ";
 
    fin.close();
    fout.close();
 
    return 0;
}
