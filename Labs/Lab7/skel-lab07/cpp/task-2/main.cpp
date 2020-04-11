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
	int contor = 0;
	vector<int> adj[kNmax];
	int grad[kNmax];
	queue<int> queue;

	void read_input() {
		ifstream fin("in");
		fin >> n >> m;
		for (int i = 1, x, y; i <= m; i++) {
			fin >> x >> y;
			adj[x].push_back(y);
		}
		fin.close();
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
		for (int i = 1; i <= n; i++){
			if (grad[i] == 0){
				queue.push(i);
			}
		}
		while (!queue.empty()){
			int x;
			x = queue.front();
			queue.pop();
			topsort[++contor] = x;
			for (int i = 1; i < adj[x].size();i++){
				grad[adj[x][i]]--;
				if (grad[adj[x][i]]== 0){
					queue.push(adj[x][i]);
				}
			}
		}
		return topsort;
	}

	void print_output(vector<int> result) {
		ofstream fout("out");
		for (int i = 0; i < int(result.size()); i++) {
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
