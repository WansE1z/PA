#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,result=0;
    cin >> n;
    for (int i = 1; i <= n /2 ; i++){
        if (n % i == 0){
            result++;
        }
    }
    cout << result;
    return 0;
}