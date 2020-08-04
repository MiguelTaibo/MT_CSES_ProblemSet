#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mxn = 2e5;
int x,n;
array <int,2> a[mxn];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 0; i<n;i++) {
    cin >> a[i][0] >> a[i][1];
  }
  sort(a,a+n);
  ll time = 0;
  ll punt = 0;
  for (int i = 0; i<n;i++) {
    time+=a[i][0];
    punt+=(a[i][1]-time);
  }
  cout << punt << endl;

}
