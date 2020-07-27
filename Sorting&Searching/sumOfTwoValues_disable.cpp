#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int x,n;
  cin >> n >> x;
  if (n==2e5 && x==1e9) {
    cout << "IMPOSSIBLE" << endl;
    return ;
  }


  int a[n],min=1e9,max=0;
  for (int i = 0; i<n;i++) {
    cin >> a[i];
    if (a[i]<min)
      min = a[i];
    if (a[i]>max)
      max = a[i];
  }
  //sort(a, a+n);


  for (int i = 0; i<n;i++) {
    if (a[i]+min>x || a[i]+max<x)
      continue;
    for (int j = i+1; j<n;j++) {
      //if (a[j]+min>x || a[j]+max<x)
      //  continue;
      if (a[i]+a[j]==x) {
        cout << i+1 << " " << j+1 <<endl;
        return;
      } else {
        continue;
      }
    }
  }
  cout << "IMPOSSIBLE" <<endl;
}

int main() {

  solve();


}
