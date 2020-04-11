#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,q;
    cin >> q;
    for (int i = 0; i < q; i++){
        cin >> n;
        if (n == 2){
            cout << 2 << endl;
        } else if (n % 2 == 1){
            cout << 1 << endl;
        } else if (n >= 2){
            cout << 0 << endl;
        } else {
            continue;
        }
    }
}