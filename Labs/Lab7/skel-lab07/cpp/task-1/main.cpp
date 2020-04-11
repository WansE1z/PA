#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stdio.h>
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
	int source;
	vector<int> adj[kNmax];

	void read_input() {
		ifstream fin("in");
		fin >> n >> m >> source;
		for (int i = 1, x, y; i <= m; i++) {
			fin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		fin.close();
	}

	vector<int> get_result() {
		vector<int> distance(n + 1);
		vector<int> color(n + 1);

		for (int i = 0; i < n; i++){
			distance[i] = -1;
			color[i] = 0; // white
		}

		distance[source] = 0;
		color[source] = 1; // gray
		queue<int> queue;
		queue.push(source);
		while (!queue.empty()){
			int x = queue.front();
			for (int k = 0; k < adj[x].size();k++){
				int u = adj[x][k];
				if (color[u] == 0){
					// if it is white
					distance[u] = distance[x] + 1;
					color[u] = 1;
					queue.push(u);
				}
			}
			color[x] = 2; // black
			queue.pop();
		}
		return distance;
	}

	void print_output(vector<int> result) {
		ofstream fout("out");
		for (int i = 1; i <= n; i++) {
			fout << result[i] << (i == n ? '\n' : ' ');
		}
		fout.close();
	}
};

int main() {
	Task *task = new Task();
	task->solve();
	delete task;
	return 0;
}
