#include <bits/stdc++.h>
     
using namespace std;
    
#ifdef ONLINE_JUDGE
#define debug(...) 42
#else
#include "algo/debug.h"
#endif

    
int main()
{
    long long int t = 0;
    cin >> t;
    while (t--)
    {
        long long int n = 0;
        cin >> n;
        priority_queue<long long int, vector<long long int>, greater<long long int>> pos;
        priority_queue<long long int, vector<long long int>, greater<long long int>> spares;
        priority_queue<long long int> zeros;
        priority_queue<long long int, vector<long long int>, greater<long long int>> neg;
            priority_queue<long long int, vector<long long int>, less<long long int>> negless;
        while (n--)
        {
            long long int input;
            cin >> input;
            if (input > 0)
            {
                
                pos.push(input);
            }
            else if(input <0)
            {
                    negless.push(input);
                neg.push(input);
            } else {
                zeros.push(input);
            }
        }

        if(pos.size()==0 && zeros.size()==0) {
            long long int ans = 1;
            int i = 5;
            while(i--){
                ans *= negless.top();
                negless.pop();
            }
            cout << ans << endl;
            continue;
        }
    
        while(pos.size() <5) {
            pos.push(0);
        }
    
        while(pos.size() > 5) {
            pos.pop();
        }
        //       while (!pos.empty()) {
        //     cout << pos.top() << ' ';
        //     pos.pop();
        // }
        
        while(neg.size() > 1 && pos.size()>1) {
            long long int n1 = neg.top();
            neg.pop();
            long long int n2 = neg.top();
            neg.pop();
    
            long long int p1 = pos.top();
            pos.pop();
            long long int p2 = pos.top();
            pos.pop();
            debug(n1, n2, p1, p2);
    
            if((n1*n2) >= (p1*p2)){
                // pos.push((n1*-1));
                // pos.push((n2*-1));
                spares.push(n1);
                spares.push(n2);
            } else {
                pos.push(p1);
                pos.push(p2);
                neg.push(n1);
                neg.push(n2);
                break;
            }
        }
        long long int ans =1;
        
        while(!spares.empty()){
            debug(spares.top());
            pos.push(spares.top());
            spares.pop();
        }
    
        if(!zeros.empty()) {
            
            while(!pos.empty()) {
                long long int top = pos.top();
                debug("zro", top);
                ans *= pos.top();
                pos.pop();
            }
        } else {
            while(!pos.empty()) {
                long long int top = pos.top();
                debug("noz", top);
                if(top == 0) {
                    top = neg.top();
                    neg.pop();
                }
                debug(top, ans);
                ans *= top;
                    debug(top, ans);
                pos.pop();
            }
        }
        debug(ans);
    
            cout << ans << endl;
    }
    return 0;
}
