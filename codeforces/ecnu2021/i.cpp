//JP - Not in Kansas Anymore
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll,ll> iill;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 150;

string a, b;
ll dp[MAX][MAX];
 


int main(){ _
	cin >> a >> b;


	/******O(n*m)******/
	// Calculates |lcs| of strings 'a' and 'b' and stores it in dp[a.size()][b.size()]
	for(int i = 0; i <= a.size(); i++) {
 	   for(int j = 0; j <= b.size(); j++) {
    	    if(!i or !j) dp[i][j] = 0;
     	   else {
         	   if(a[i-1] == b[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
       	     else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
   		}
	}
	
	if(dp[a.size()][b.size()] == b.size()) cout << "Yes" << endl;
	else cout << "No" << endl;

	exit(0);
}
