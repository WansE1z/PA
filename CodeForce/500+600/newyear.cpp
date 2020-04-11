#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    string s[22],t[22];
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> s[i];
    }
    for (int i = 0; i < m; i++){
        cin >> t[i];
    }
    int q;
    cin >> q;
    while (q--){
        int x;
        cin >> x;
        x--;
        cout << s[x % n] + t[x % m] << endl;
    }
}