#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <iterator>
#include <list>
using namespace std;

const int kNmax = 100005;

class Task {
 public:
	void solve() {
		read_input();
		print_output(get_result());
	}

 private:
	int n;
	int m;
	vector<int> adj[kNmax];
	int visited[kNmax];

	void read_input() {
		ifstream fin("in");
		fin >> n >> m;
		for (int i = 1, x, y; i <= m; i++) {
			fin >> x >> y;
			adj[x].push_back(y);
		}
		fin.close();
	}

	void topsorthelper(int node, vector<int> &topsort){
		visited[node] = 1;
		for (int x : adj[node]){
			if (visited[x] == 0){
				topsorthelper(x,topsort);
			}
		}
		topsort.push_back(node);
	}

	vector<int> get_result() {
		/*
		TODO: Faceti sortarea topologica a grafului stocat cu liste de
		adiacenta in adj.
		*******
		ATENTIE: nodurile sunt indexate de la 1 la n.
		*******
		*/
		vector<int> topsort;
		for (int i = 1 ; i <= n; i++){
			if (visited[i] == 0){
				topsorthelper(i,topsort);
			}
		}
		return topsort;
	}

	void print_output(vector<int> result) {
		ofstream fout("out");
		for (int i = int(result.size())-1; i >= 0; i--) {
			fout << result[i] << ' ';
		}
		fout << '\n';
		fout.close();
	}
};

int main() {
	Task *task = new Task();
	task->solve();
	delete task;
	return 0;
}
