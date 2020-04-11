#include <iostream>
using namespace std;
int main (){
    int a,b,i = 1;
    cin >> a >> b;
    while (a < b){
        a *= 3;
        b *= 2;
        if (a <= b){
            i++;
        }
    }
    cout << i;
}