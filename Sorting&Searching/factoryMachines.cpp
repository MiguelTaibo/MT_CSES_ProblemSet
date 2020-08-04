#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mnx = 2e5;
ll t,n, k[mnx], values[mnx];
const int lpos = 10e6;
ll possibles[lpos];

void printArray(array<int,2> r[], int l) {
  for (int i = 0; i<l;i++) {
    cout << r[i][0] << " ";
  }
  cout << endl;
  for (int i = 0; i<l;i++) {
    cout << r[i][1] << " ";
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> t;
  double tasa=0;
  ll m;
  for (int i = 0; i<n;i++) {
    cin >> k[i];
    tasa+=(1.0/k[i]);
    m = max(m,k[i]);
  }
  ll min_time = ceil((double)t/tasa);
  ll max_time = min_time+m;
  ll pr = 0;
  for (int i=0;i<n;i++) {
    pr+=(min_time/k[i]);
  }
  //cout << "tas: " << tasa;
  //cout << " time: " << min_time << "  products: " << pr << endl;
  ll remaining = t-pr;

  if (remaining<=0) {
    cout << min_time << endl;
  } else {
    //cout << remaining << " " << n;


    int index = 0;

    for (int i = 0; i<n;i++) {
        for (int j=(min_time/k[i]+1);j<(min_time/k[i]+1+remaining);j++) {
          if (j*k[i]>max_time) {break;}
          possibles[index]=j*k[i];
          index++;
        }
    }
    //cout << remaining << " " << index << " " << max_time << endl;
    //for (int i = 0; i<index;i++) cout << possibles[i] << " ";
    //cout << endl;
    sort(possibles,possibles+index);
    cout << possibles[remaining-1] << endl;
  }
}
