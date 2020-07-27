#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

  int n;
  cin >> n;

  ll x[n], min=1e9, max=-1e9;
  for (int i = 0; i<n;i++) {
    cin >> x[i];
    if (x[i]>max) {
      max = x[i];
    }
    if (x[i]<min) {
      min = x[i];
    }
  }

  ll sol;
  if (max<=0) {
    sol = max;
  }
  else if (min>=0) {
    sol = 0;
    for (int i = 0; i<n;i++) {
      sol+=x[i];
    }

  }
  else {
    ll current= 0;
    sol = 0;


    for (int i = 0; i<n;i++) {
      if (current+x[i]>0) {
        current+=x[i];
        if (current>sol) {
          sol = current;
        }
      } else {
        current = 0;
      }
    }

  }
  cout << sol << endl;

}
