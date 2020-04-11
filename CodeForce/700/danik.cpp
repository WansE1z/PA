#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string str;
    cin >> n;
    cin >> str;
    int cD = 0, cA = 0;
    for (int i = 0; i < str.length();i++){
        if (str[i] == 'D'){
            cD++;
        }
        if (str[i] == 'A'){
            cA++;
        }
    }
    if (cD > cA){
        cout << "Danik";
    } else if (cD < cA){
        cout << "Anton";
    } else {
        cout << "Friendship";
    }
}