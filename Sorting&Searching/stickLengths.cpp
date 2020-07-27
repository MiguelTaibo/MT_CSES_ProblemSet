#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

  int n;
  cin >> n;

  ll x[n], suma=0;
  for (int i = 0; i<n;i++) {
    cin >> x[i];
    suma+=x[i];
  }

  sort(x,x+n);

  ll sol = 0;
  int midlen = n/2;
  ll mediana = x[midlen];

  for (int i = 0; i<midlen;i++) {
    sol+=(mediana-x[i]);
  }
  for (int i = midlen+1; i<n;i++) {
    sol+=(x[i]-mediana);
  }
  //cout << midlen << mediana <<endl;
  cout << sol << endl;

}
