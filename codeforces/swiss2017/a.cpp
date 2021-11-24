#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimization ("unroll-loops")
#pragma GCC optimization ("O2")
#pragma GCC target ("avx2")

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
// #define endl '\n'
#define f first
#define s second
#define pb push_back
#define FOR(i,a,n) for(int i=a;i<n;i++)

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
ll testei = 0;

ll fexp(ll x, ll y, ll m) { // iterativo
  ll ret = 1;
  while (y) {
    if (y & 1) ret = ((__int128) ret * (__int128) x) % m;
    y >>= 1;
    x = ((__int128) x *  (__int128) x) % m;
    // cout << x << endl;
  }
  return ret;
}


bool teste(ll mod, multiset<ll> ms) {
  ll num = 1;
  while(ms.size()) {
    if(ms.find(num) == ms.end()) return false;
    ms.erase(ms.find(num));
    num = (num * 2) % mod;
  }

  return true;
}

int main() { _
  int n; cin >> n;
	multiset<ll> ms_og;

  FOR(i,0,n) {
    ll in; cin >> in;
    ms_og.insert(in);
  }

  multiset<ll> ms_novo = ms_og;
  ll pot = 1;
  while(ms_novo.size() and ms_novo.find(pot) != ms_novo.end()) {
    ms_novo.erase(ms_novo.find(pot));
    pot *= 2;
  }

  if(ms_novo.empty()) {
    cout << *(ms_og.rbegin()) + 1 << endl;
    return 0;
  }

  // for(auto i : ms_novo) cout << i << " ";
  // cout << endl;

  bool impar = false;
  int counter = 0;
  for(auto i : ms_og) {
    if(counter and i&1) impar = true;
    counter++;
  }

  ll res = LINF;
  while(ms_novo.size()) {
    ll num = *(ms_novo.begin());
    ll cand = pot - num;
    // if(cand == 2434872392342) cout << "AAAAAAAA" << endl;
    // cout << "cand: " << cand << " - " << endl;

    if(cand < res and 
       ms_og.find(fexp(2, n-1, cand)) != ms_og.end() and
       (!(cand&1) or (cand&1 and impar)) and
       cand > *(ms_og.rbegin()) and
       teste(cand, ms_og)
    ) {
      // if(cand == 2434872392342) cout << "AAAAAAAA" << endl;
      res = cand;
      testei++;
      // cout << cand << endl;
    }

    while(ms_novo.size() and ms_novo.find(num) != ms_novo.end()) {
      ms_novo.erase(ms_novo.find(num));
      num *= 2;
    }
  }

  // cout << "t: " << testei << endl;
  cout << (res == LINF ? (*(ms_og.rbegin()) + 1LL) : res) << endl;
  return 0;
}
