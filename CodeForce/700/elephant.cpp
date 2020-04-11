#include <bits/stdc++.h>
using namespace std;
int main() {
  int distance;
  cin >> distance;
  int nrOfMoves = 0;
  while (distance != 0) {
    if (distance > 5) {
      nrOfMoves++;
      distance -= 5;
    } else {
      distance = 0;
      nrOfMoves++;
    }
  }
  cout << nrOfMoves;
}