#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mnx = 2e5;
int n,k[mnx];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 0;i<n;i++) {
    cin >> k[i];
  }

  multiset<int> s;
  for (int i = 0; i<n;i++) {
    auto it = s.lower_bound(k[i]+1);
    if (it!=s.end())
      s.erase(s.find(*it));
    s.insert(k[i]);
  }

  cout << s.size() << endl;

}
