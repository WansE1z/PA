#include <bits/stdc++.h>
using namespace std;

int main (){
int n;
cin >> n;
double x;
double suma = 0.0;
double medie;
for (int i = 0; i < n; i++){
    cin >> x;
    suma += x;
}
medie = suma / n;
cout << medie;
return 0;
}

