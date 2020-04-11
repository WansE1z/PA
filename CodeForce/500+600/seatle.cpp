#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string str;
    cin >> n;
    cin >> str;
    if (str[0] == 'S' && str[n-1] == 'F'){
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}