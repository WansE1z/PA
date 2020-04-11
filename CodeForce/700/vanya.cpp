#include <bits/stdc++.h>
using namespace std;

int main (){
    int n,h,v[1005];
    int result = 0;
    cin >> n >> h;
    for (int i = 0; i < n; i++){
        cin >> v[i];
        if (v[i] > h){
            result += 2;
        } else {
            result++;
        }
    }
    cout << result;
return 0;
}

