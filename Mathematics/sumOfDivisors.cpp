#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mxn = 1e12;
const int sqmxn = 1e6;
const int mod = 1e9+7;
int n,x;
int prims[sqmxn], plen;

void calcSubset(int a[], set<int> &x, int n)
{
  for (int i=0; i<(1<<n); i++)
   {
       ll s = 1;
       for (int j=0; j<n; j++)
           if (i & (1<<j))
               s *= a[j];
       x.insert(s);
   }
}

ll solve(int x)
{
  int factors[sqmxn], flen = 0;
  int i = 0;
  int temp = x;
  while (prims[i]<=x/2) {
    if ((temp/prims[i])*prims[i]==temp) {
      factors[flen]=prims[i];
      temp/=prims[i];
      flen++;
    }
    else {
      i++;
    }
  }


  if (flen==0) {
    return (1+x);
  }
  else {
    set<int> s;
    ll res = 0;
    calcSubset(factors,s,flen);
    for (auto it = s.begin(); it!= s.end(); it++) {
      res+=(*it);
      cout << (*it) << " ";
    }
    return res;
  }
}




void findPrims(int m, int prims[], int &len)
{
  len = 0;
  bool found;
  for (int k = 2; k<m;k++) {
    const double sq = sqrt(k);
    found = false;
    for (int i = 0; i<len && prims[i]<sq;i++) {
      if ((k/prims[i])*prims[i]==k) {
        found = true;
        break;
      }
    }
    if (!found) {
      prims[len]=k;
      len++;
    }
  }
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> x;

  findPrims(sqmxn,prims,plen);
  //for (int i = 0; i<plen; i++)
  //  cout << prims[i] << " ";
  ll sol = 0;
  for (int i = 1; i<=x;i++) {
    sol+=solve(x);
    sol%=mod;
  }
  cout << sol << endl;


}
