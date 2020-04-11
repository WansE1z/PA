#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    string t;
    cin >> t;
    cout << min(2*(int)count(t.begin(),t.end(),'a')-1,(int)t.size());
}