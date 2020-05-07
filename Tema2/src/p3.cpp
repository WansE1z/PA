#include <bits/stdc++.h>

#include <iomanip>
using namespace std;

ifstream fin("p3.in");
ofstream fout("p3.out");
const int kNmax = 100005;
int n, m, node, target, enrg;
double energy, newValue;
vector<vector<pair<int, double>>> adj;  // matricea de adiacenta
list<int> routes;
queue<int> que;
bitset<kNmax> checked;

void modifiedDijkstra(int energy) {
    vector<pair<double, int>> dist(n + 1, {0.0, 0});
    /*
        in vectorul de distanta tin o pereche (energie, nod precedent)
    */

    que.push(1);
    dist[1].first = energy;
    // adaug in queue nodul sursa, si actualizez energia

    while (que.size()) {
        node = que.front();
        checked[node] = true;  // nodul este vizitat
        que.pop();

        for (auto& nextNode : adj[node]) {
            // in matricea de adiacenta, nextNode.first este nodul final, si
            // nextNode.second este energia
            target = nextNode.first;
            enrg = nextNode.second;

            // valoarea energiei calculata pe baza formulei din enunt
            newValue = dist[node].first * (1.0 - (enrg / 100.0));

            /*
                daca nodul nu a fost vizitat si valoarea noua este mai mare
               decat energia din nodul final atunci actualizez atat valoarea cat
               si nodul, pentru a face ruta, si dau push la nod in coada
            */
            if (newValue > dist[target].first || checked[target] == false) {
                dist[target].first = newValue;
                dist[target].second = node;
                que.push(target);
            }
        }
    }
    // se cere o precizie, asa ca folosesc functia fixed si setprecision.
    fout << fixed << setprecision(8) << dist[n].first << "\n";

    // actualizez variabila node cu nodul final, pentru a produce ruta
    node = n;

    // atata timp cat nu a ajuns la inceput
    while (node != 1) {
        // adaug nodul in ruta, si actualizez nodul
        routes.push_back(node);
        node = dist[node].second;
    }

    // adaug si nodul sursa in lista
    routes.push_back(1);

    // inversez lista pentru a o putea
    routes.reverse();
    for (auto& elem : routes) {
        fout << elem << " ";
    }
    fout.close();
}

int main() {
    fin >> n >> m >> energy;
    adj = vector<vector<pair<int, double>>>(n + 1);
    double p = 0.0;
    for (int k = 1, i, j; k <= m; k++) {
        fin >> i >> j >> p;
        /* i - orasul i (initial) ; j - orasul j (final); p - p% din
         energie(procent)
        */

        adj[i].push_back(make_pair(j, p));
        // matricea de adiacenta
    }
    fin.close();
    modifiedDijkstra(energy);
}
