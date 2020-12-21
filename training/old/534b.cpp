#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main ()
{
    string s;
    ll counter = 0;
    stack<char> st;
    cin >> s;
    for (int i = 0; i < s.length(); i++){
        if (!st.empty() && s[i] == st.top()){
            st.pop();
            counter++;
        }
        else{
            st.push(s[i]);
        }
    }
    if (counter % 2 == 0)
        cout << "No";
    else
        cout << "Yes";
    return 0;
}