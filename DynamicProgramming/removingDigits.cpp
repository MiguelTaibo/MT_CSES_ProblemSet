#include <bits/stdc++.h>

using namespace std;

int n, temp, t, m, sol;

int main() {

  cin >> n;

  while (n>0) {
    m = 0;
    temp = n;
    while (temp>0) {
      t = temp%10;
      m = max(m,t);
      temp /=10;
    }
    n -= m;
    sol++;
  }
  cout << sol <<endl;
}
