#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    int normal = 0;
    int square = 0;
    int curly = 0;
    cin >> str;
    for(int i = 0 ; i < str.length ; i++) {
        if(str[i] == '(') {
            normal++;
        }
        if(str[i] == '[') {
            square++;
        }
        if(str[i] == '{') {
            curly++;
        }
        if(str[i] == ')') {
            normal--;
        }
        if(str[i] == ']') {
            square--;
        }
        if(str[i] == '}') {
            curly--;
        }
        if(normal < 0 || curly < 0 || square < 0) {
             cout << 'false';
        }
    }
    if(square == 0 && normal == 0 && curly == 0 ) {
        cout << 'true';
    } else {
        cout << 'false';
    }
    cout << out << endl;
}