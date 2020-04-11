#include <bits/stdc++.h>
#include <string_view>
#include <string>
using namespace std;
bool endsWith(const std::string &mainStr, const std::string &toMatch)
{
	if(mainStr.size() >= toMatch.size() &&
			mainStr.compare(mainStr.size() - toMatch.size(), toMatch.size(), toMatch) == 0)
			return true;
		else
			return false;
}

int main(){
    int n;
    string str;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> str;
        if (endsWith(str,"po")){
            cout << "FILIPINO" << endl;
        } else if (endsWith(str,"mnida")){
            cout << "KOREAN" << endl;
        } else {
            cout << "JAPANESE" << endl;
        }
    }
}