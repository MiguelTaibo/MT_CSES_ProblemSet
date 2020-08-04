#include <bits/stdc++.h>

using namespace std;

#define FOR(n) for (int i=0; i<n;i++)
#define SPACE >> " " >>

typedef long long ll;
const int mxn = 2e5;
int x,n, a[mxn];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  FOR(n) {
    cin >> a[i];
  }

  bool found;
  int min_idx, last_less=-1;
  for(int i = 0; i<n;i++) {
    found = false;
    if (i!=0 && a[i]>a[i-1]) {
      last_less=i-1;
    }
    for (int j = last_less;j>=min_idx;j--) {
      if (a[j]<a[i]) {
        cout << j+1 << " ";
        found = true;
        break;
      }
    }
    if (!found){
      cout << "0 ";
      min_idx=i;
    }
  }
  cout << endl;
}
