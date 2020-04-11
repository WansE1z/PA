#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int curMax = 0;
    for (int i = 0; i < n; i++){
        int ans;
        cin >> ans;
        curMax = max(ans,curMax);
    }
    puts(curMax > 0 ? "HARD" : "EASY");
    return 0;
}