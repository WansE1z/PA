#include <bits/stdc++.h>
using namespace std;
int main (){
    int n;
    string str;
    int count1 = 0, count0 = 0;
    cin >> n >> str;
    for (int i = 0; i < n; i++){
        if (str[i] == 'n'){
            count1++;
        } 
        if (str[i] == 'r'){
            count0++;
        }
    }
    while (count1 != 0){
        cout << "1 ";
        count1--;
    }
    while (count0 != 0){
        cout << "0 ";
        count0--;
    }
    return 0;
}