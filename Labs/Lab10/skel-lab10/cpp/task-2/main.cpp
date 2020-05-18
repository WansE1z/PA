#include <bits/stdc++.h>
using namespace std;

const int kNmax = 200005;
typedef struct {
  int x, y, cost;
} muchie;

int viz[kNmax], n, m, sum;
vector<muchie> v(kNmax);

void sortare() {
  int flag = 0;
  while (flag == 0) {
    flag = 1;
    for (int i = 1; i <= m - 1; i++) {
      if (v[i].cost > v[i + 1].cost) {
        swap(v[i], v[i + 1]);
        flag = 0;
      }
    }
  }
}

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> v[i].x >> v[i].y >> v[i].cost;
  }
  sortare();
  int i = 1;
  for (int k = 1; k <= n - 1; k++) {
    while (viz[v[i].x] == viz[v[i].y] && viz[v[i].x] != 0) i++;
    sum += v[i].cost;

    if (viz[v[i].x] + viz[v[i].y] == 0) {
      viz[v[i].x] = viz[v[i].y] = v[i].x;
    } else {
      if (viz[v[i].x] * viz[v[i].y] == 0) {
        viz[v[i].x] = viz[v[i].y] = viz[v[i].x] + viz[v[i].y];
      } else {
        for (int j = 1; j <= n; j++) {
          if (viz[j] == viz[v[i].x] && j != v[i].x) {
            viz[j] = viz[v[i].y];
          }
        }
        viz[v[i].x] = viz[v[i].y];
      }
      i++;
    }
  }
  cout << sum;
}