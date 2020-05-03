
#include <algorithm>
#include <fstream>
#include <queue>
#include <set>
#include <utility>
#include <vector>
using namespace std;

const int kNmax = 50005;
class Task {
 public:
  void solve() {
    read_input();
    print_output(get_result());
  }

 private:
  int n;
  int m;
  int source;
  vector<pair<int, int> > adj[kNmax];

  void read_input() {
    ifstream fin("in");
    fin >> n >> m >> source;
    for (int i = 1, x, y, w; i <= m; i++) {
      fin >> x >> y >> w;
      adj[x].push_back(make_pair(y, w));
    }
    fin.close();
  }

  struct compare {
    bool operator()(const int& l, const int& r) { return ((l) > ( r)); }
  };

  vector<int> get_result() {
    /*
    TODO: Gasiti distantele minime de la nodul source la celelalte noduri
    folosind Dijkstra pe graful orientat cu n noduri, m arce stocat in adj.
            d[node] = costul minim / lungimea minima a unui drum de la source la
    nodul node; d[source] = 0; d[node] = -1, daca nu se poate ajunge de la
    source la node. Atentie: O muchie este tinuta ca o pereche (nod adiacent,
    cost muchie): adj[x][i].first = nodul adiacent lui x, adj[x][i].second =
    costul.
    */

    vector<bool> checked(n + 1, false);
    vector<int> d(n + 1, -1);
    priority_queue<int, vector<int>, compare> queue;
    queue.emplace(source);
    d[source] = 0;
    int node;

    while (!queue.empty()) {
      node = queue.top();
      checked[node] = true;

      for (auto& nextNode : adj[node]) {
        if (checked[nextNode.first] == false ||
            d[nextNode.first] > nextNode.second + d[node] ||
            d[nextNode.first] == -1) {
          d[nextNode.first] = nextNode.second + d[node];
          queue.emplace(nextNode.first);
        }
      }
      queue.pop();
    }
    return d;
  }

  void print_output(vector<int> result) {
    ofstream fout("out");
    for (int i = 1; i <= n; i++) {
      fout << result[i] << " ";
    }
    fout << "\n";
    fout.close();
  }
};

int main() {
  Task* task = new Task();
  task->solve();
  delete task;
  return 0;
}