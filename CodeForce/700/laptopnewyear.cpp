#include <bits/stdc++.h>
using namespace std;
int main (){
    int a[100];
    int n;
    cin >> n;
    int x[n+10];
    for (int i = 0; i < n; i++){
        cin >> x[i];
        a[x[i]] = i+1;
    }
    for (int i = 1; i <= n; i++){
        cout << a[i] << " ";
    }
}