#include <bits/stdc++.h>
using namespace std;
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define FOR(i,a,n) for(int i=a;i<n;i++)
 
typedef long long ll;
typedef pair<int, int> ii;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
 
ll query(vector<ll> &bit, int x) {
  ll res = 0;
  while(x) {
    res += bit[x];
    x -= (x & -x);
  }
  return res;
}
 
/******O(logn)******/
//add v to position x
void add(vector<ll> &bit, int x, int v) {
  while(x < bit.size()) {
    bit[x] += v;
    x += (x & -x);
  }
}
 
int main() { _
  int n, p; cin >> n >> p;
  vector<ll> v(n);
  FOR(i,0,n) {
    int a, b; cin >> a >> b; a--, b--;
    v[a]++;
    v[b]++;
  }
 
  //indices from 1 to n;
  vector<ll> bit(n+2, 0);
  FOR(i,0,n) add(bit, v[i]+1, 1);
 
  ll res = 0;
  FOR(i,0,n) {
    ll falta = p - v[i];
    res += query(bit, n+1);
    if(falta > 0) res -= query(bit, falta);
    if(v[i] >= falta) res--;
  }
 
  cout << (res/2) << endl;
  return 0;
}
