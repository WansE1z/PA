#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int s1,s2,s3,sum;
    cin >> s1 >> s2 >> s3 >> sum;
    int arr[4] = {s1,s2,s3,sum};
    std::vector<int> vect (arr,arr+4);
    sort(vect.begin(),vect.end());
    //cout << sum - s1 << sum - s2 << sum - s3;
    cout << vect[3] - vect[0] << " "; 
    cout << vect[3] - vect[1] << " ";
    cout << vect[3] - vect[2] << " ";


}