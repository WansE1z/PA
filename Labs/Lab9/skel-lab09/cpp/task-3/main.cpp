#include <stdio.h>
#include <algorithm>
 
using namespace std;
 
long i, j, k, n, edge[110][110];
 
int main() {
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	
	scanf("%ld", &n);
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= n; ++j) {
			scanf("%ld", &edge[i][j]);
			if (i != j && edge[i][j] == 0) edge[i][j] = 1000000000;
		}
	}
	for (k = 1; k <= n; ++k) {
		for (i = 1; i <= n; ++i) {
			for (j = 1; j <= n; ++j) {
				edge[i][j] = min(edge[i][j], edge[i][k] + edge[k][j]);
			}
		}
	}
	
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= n; ++j) {
			if (edge[i][j] == 1000000000) printf("0 ");
			else printf("%ld ", edge[i][j]);
		}
		printf("\n");
	}
	return 0;
}