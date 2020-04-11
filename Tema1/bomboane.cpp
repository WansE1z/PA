#include <fstream>

using namespace std;
ifstream fin("bomboane.in");
ofstream fout("bomboane.out");
const int NMAX = 2000;
const long long MOD = 1000000007;
long long sums[NMAX + 5];
long long dp[55][NMAX + 5];
int m, n;

int main() {
  int left, right, i, j;
  fin >> n >> m;
  dp[0][0] = 1;  // combinari de 0 luate cate 0 = 1
  for (j = 1; j <= n; j++) {
    /* dp[i][j] = in cate moduri pot obtine suma j daca am dat
    bomboane la primii i copii */

    fin >> left >> right;
    for (i = m; i >= 0; i--) {
      /* j = copilul
      la pasul n, nu te mai intereseaza decat pozitia m */

      for (int k = i - left; k >= i - right; k--) {
        // daca ai 7 bomboane, si intervalul [2 4], conteaza k = [3 4 5]
        if (k < 0) {
          break;
        }
        // dp[j][7] = dp[j-1][3] + dp[j-1][4] + dp[j-1][5]
        dp[j][i] = (dp[j - 1][k] + dp[j][i]) % MOD;
      }
      if (i == m && j == n) {
        // nu mai are rost sa calculezi cum a fost format cel anterior
        // suma m, n copii
        fout << dp[n][m] << "\n";
        return 0;
      }
    }
  }

  return 0;
}
