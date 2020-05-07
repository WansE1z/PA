#include <bits/stdc++.h>

#include <fstream>
using namespace std;
ifstream fin("p2.in");
ofstream fout("p2.out");
queue<int> que;
const int MAX = 100001, INF = 2E5;
int n, m, src, dst, cnt = 1, i, p, fst, snd, node, effort;
int graph[MAX];
int nextOcc[INF];
int pos[INF];
int eff[INF];
int dist[MAX];
bitset<MAX> inqueue;

void bellmanFord(int& fst, int& snd, int& effort, int& pointer) {
    // atata timp cat exista elemente in queue
    while (que.size()) {
        fst = que.front();
        inqueue[fst] = false;
        // nu este in queue
        que.pop();

        for (pointer = graph[fst]; pointer != 0; pointer = nextOcc[p]) {
            // parcurg vectorul pana cand nu mai este 0 pointer-ul
            snd = pos[p];
            effort = eff[p];

            // retin in variabile costul si nodul destinatie
            /*
                pentru un graf unidirectional, fst, snd, effort reprezinta
                i,j,e din enunt, dar le-am numit asa sa imi fie mai usor
                am folosit mai multi vectori pentru a retine aceste date
            */
            if (dist[fst] + effort < dist[snd] && dist[fst] != INF) {
                /*
                 daca distanta din nodul initial + cost-ul ei este mai mic decat
                 distanta din nodul final actualizeaza distanta nodului
                */

                dist[snd] = dist[fst] + effort;
                if (!inqueue[snd]) {
                    // daca nu se afla in queue, adauga in queue nodul, si
                    // actualizez starea
                    que.push(snd);
                    inqueue[snd] = true;
                }
            }
        }
    }
}

int main() {
    fin >> n >> m;
    // n noduri, m muchii
    fin >> src >> dst;
    // nodul sursa/destinatie
    for (i = 0; i < m; ++i) {
        fin >> fst >> snd >> effort;
        // orasul i (fst), orasul j(snd), costul (effort).
        pos[cnt] = snd;
        // actualizez vectorul position

        eff[cnt] = effort;
        // actualizez costul

        nextOcc[cnt] = graph[fst];
        // nextOcc (nextOccurence) -> va fi urmatoarea aparitie

        graph[fst] = cnt;
        // actualizez vectorul cu contorul

        cnt++;
    }
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
    }
    dist[src] = 0;
    // nodul de pornire este 0

    que.push(src);
    // adaug in queue nodul

    inqueue[src] = true;
    // actualizez vectorul inqueue

    bellmanFord(fst, snd, effort, p);
    fout << dist[dst];
    // afisez distanta din nodul destination

    return 0;
}
