#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mxn = 1e6;
const int mod = 1e9 +7;

int x,c[mxn],n;
ll value[mxn];
bool ready[mxn];

ll solve(int x)
{
  if (x<0) return 0;
  else if (x==0) return 1;
  else if (ready[x]) return value[x];
  else {
    ll res = 0;
    for (int i = 0; i<n;i++) {
      res+=solve(x-c[i]);
    }
    res%=mod;
    value[x]=res;
    ready[x]=true;
    return res;
  }
}


int main() {

  cin >> n >> x;
  for (int i = 0; i<n;i++)
    cin >> c[i];

  ll sol = solve(x);
  cout << sol <<endl;

}
