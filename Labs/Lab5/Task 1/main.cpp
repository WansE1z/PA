#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n, k, bk[100], v[100];

void bkt(int poz) {
	if (poz == k + 1) {
		for (int i = 1; i <= k; i++) {
			cout << bk[i] << " ";
		}
		cout << endl;
		return;
	}
	for (int i = 1; i <= n; ++i) {
		if (v[i] == 0) {
			bk[poz] = i;
			v[i] = 1;
			bkt(poz + 1);
			v[i] = 0;
		}
	}
}
int main() {
	cin >> n >> k;
	int a = 1, b = 1;
	for (int i = 1; i <= n; i++) {
		if (i <= n - k) {
			b *= i;
		}
		a *= i;
	}
	int result = a / b;
	cout << result << endl;
	bkt(1);
	return 0;
}