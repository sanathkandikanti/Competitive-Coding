#include <bits/stdc++.h>

using namespace std;

#ifdef ONLINE_JUDGE
#include "../CodeForces/practice/algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
    string record;
    int a = 0;
    int b = 0;
    cin >> record;
    for(int i = 0; i < record.length()-1; i+=2){
        if(record[i] == 'A') {
            a +=  record[i+1] - 48;
            
        } else {
            b += record[i+1] - 48;
        }
    }
    if(a>b){
        cout <<'A'<<endl;
    } else {
        cout << 'B' << endl;
    }
    return 0;
}