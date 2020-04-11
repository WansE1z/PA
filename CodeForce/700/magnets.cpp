#include <bits/stdc++.h>
using namespace std;

int main (){
    int n;
    int v[100005];
    string str;
    int result = 1;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> str;
        if (str == "10"){
            v[i] = 1;
        } else {
            v[i] = 0;
        }
    }
    for (int i = 0; i < n-1; i++){
        if (v[i] != v[i+1]){
            result++;
        }
    }
    cout << result;

return 0;
}

