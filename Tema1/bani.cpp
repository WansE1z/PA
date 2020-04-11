#include <fstream>

using namespace std;
ifstream fin("bani.in");
ofstream fout("bani.out");
const int NMAX = 10;
const long long MOD = 1000000007;
long long dp[5][NMAX];
/// 1 - 10 lei
/// 2 - 50 lei
/// 3 - 100 lei
/// 4 - 200 lei
/// 5 - 500 lei

/*
  Pentru a avea O(log n), trebuie sa facem o functie care ridica
  la putere in timp logaritmic (fast lgpower)
  Exemplu:
  3^5
  5 = 101
  exp | base | result
  -------------------
  101 | 3    | 1
  10  | 9    | 3
  1   | 81   | 3
  0   | 81^2 | 243
  3^5 = 3^1 * 9^0 * 81^1
*/
long long lg_putere(long long baza, long long exponent) {
  long long rezultat = 1;
  while (exponent > 0) {
    if (exponent & 1) {
      rezultat = (rezultat * (baza % MOD)) % MOD;
    }
    baza = ((baza % MOD) * (baza % MOD)) % MOD;
    exponent = exponent >> 1;
  }
  return rezultat % MOD;
}
int main() {
  long long n, t, i;
  long long sol = 0;
  fin >> t >> n;
  if (t == 1) {
    sol = (5 * lg_putere(2, n - 1)) % MOD;
    fout << sol << "\n";
  } else {
    for (i = 1; i <= 5; i++) {
      dp[1][i] = 1;
      // de cate ori pot obtine o bancnota la pasul 1? => 1
    }
    for (i = 2; i <= n; i++) {
      // dp[i][j] cate combinatii am la pasul i, facute de bancnota j
      dp[i % 2][1] = ((dp[(i - 1) % 2][2] + dp[(i - 1) % 2][3]) % MOD +
                      dp[(i - 1) % 2][5]) %
                     MOD;
      dp[i % 2][2] = (dp[(i - 1) % 2][1] + dp[(i - 1) % 2][4]) % MOD;
      dp[i % 2][3] = ((dp[(i - 1) % 2][1] + dp[(i - 1) % 2][3]) % MOD +
                      dp[(i - 1) % 2][4]) %
                     MOD;
      dp[i % 2][4] = (dp[(i - 1) % 2][2] + dp[(i - 1) % 2][5]) % MOD;
      dp[i % 2][5] = dp[(i - 1) % 2][4];
    }
    /*
    i % 2 este o optimizare folosita pentru ca pe mine ma intereseaza
    mereu doar valoarea anterioara, deci nu are sens sa folosesc toti
    valorile i disponibile, sa aloc memorie aiureaa.
    */

    for (i = 1; i <= 5; i++) {
      sol = (sol + dp[n % 2][i]) % MOD;
    }
    // adun toate combinarile de la toate bancnotele la pasul n
    fout << sol << "\n";
  }
  return 0;
}
