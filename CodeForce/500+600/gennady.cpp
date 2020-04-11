#include <bits/stdc++.h>
using namespace std;
int main (){
    string card,cards;
    cin >> card;
    string suit,rank;
    string suits,ranks;
    string result;
    int flag = 0;
    suit = card.at(1);
    rank = card.at(0);
    for (int i = 0; i < 5; i++){
        cin >> cards;
        suits = cards.at(1);
        ranks = cards.at(0);
        if (suits == suit || ranks == rank){
            flag = 1;
        }
    }
    if (flag == 0){
        cout << "NO";
    } else {
        cout << "YES";
    }
}
