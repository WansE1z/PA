#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[6][6];
  int pozi = 0, pozj = 0;
  int mutari = 0;
  for (int i = 1; i <= 5; i++) {
    for (int j = 1; j <= 5; j++) {
      cin >> a[i][j];
      if (a[i][j] == 1) {
        pozi = i;
        pozj = j;
        break;
      }
    }
  }
  while (pozi != 3 || pozj != 3) {
    if (pozi < 3) {
      mutari++;
      pozi++;
    }
    if (pozi > 3) {
      mutari++;
      pozi--;
    }
    if (pozj < 3) {
      mutari++;
      pozj++;
    }
    if (pozj > 3) {
      mutari++;
      pozj--;
    }
  }
  cout << mutari;
  return 0;
}