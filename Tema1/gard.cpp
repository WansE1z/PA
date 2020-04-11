#include <algorithm>
#include <fstream>
#include <stack>
#include <vector>

using namespace std;
ifstream fin("gard.in");
ofstream fout("gard.out");
const int NMAX = 1000000;

struct interval {
  int stanga, dreapta;
  bool operator<(const interval &a) const {
    // overload operator
    if (stanga == a.stanga) return dreapta > a.dreapta;
    // am sortat la stanga
    return stanga < a.stanga;
  }
};
/*
  Sortarea este folosita in felul urmator:
  Avem initial spre exemplu
  0 6
  4 12
  5 10
  2 4
  9 14

  Sortez la stanga, de unde rezulta:
  0 6
  2 4
  4 12
  5 10
  9 14
*/
vector<interval> v;
stack<interval> st;

int main() {
  int n;
  interval aux;
  fin >> n;

  for (int i = 1; i <= n; i++) {
    fin >> aux.stanga >> aux.dreapta;
    v.push_back(aux);
  }
  sort(v.begin(), v.end());
  st.push(v[0]);
  // dam push pe stiva la primul interval (in exemplu 0 6)
  for (unsigned int i = 1; i < v.size(); i++) {
    aux = st.top();
    if (v[i].dreapta <= aux.dreapta) {
      continue;
    } else {
      st.push(v[i]);
    }
    // garduri care imi trebuie, si dau push
  }
  fout << n - st.size() << "\n";
  /* numarul de garduri inutile este egal cu numarul lor - cate am in stack
     in stack fiind de fapt garduri utile.
  */

  return 0;
}
