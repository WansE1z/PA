#include <iostream>
using namespace std;
int main(){
    int n,i = 0;
    cin >> n;
    while (n >= 100){
        n -= 100;
        i++;
    }
    while (n >= 20){
        n -= 20;
        i++;
    }
    while (n >= 10){
        n -= 10;
        i++;
    }
    while (n >= 5){
        n -= 5;
        i++;
    }
    while (n >= 1){
        n -=1;
        i++;
    }
    cout << i;

}