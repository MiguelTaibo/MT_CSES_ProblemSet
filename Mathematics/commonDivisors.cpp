#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mxn = 2e5;
int x,n,m=1;
set<int> s;

bool check(int t) {
  if (s.find(t)!=s.end()) {
    m = max(m,t);
    return true;
  }
  else {
    s.insert(t);
    return false;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int k = 0; k<n;k++) {
    cin >> x;
    if (x>m && !check(x)) {
      const double sq = sqrt(x);
      for (int i =2; i<sq;i++) {
        if ((x/i)*i==x) {
          if (i>m) check(i);
          if (x/i>m) check(x/i);
        }
      }
      if (((int)(x/sq))*sq==x && sq>m) check(sq);
    }
  }
  cout << m << endl;



}
