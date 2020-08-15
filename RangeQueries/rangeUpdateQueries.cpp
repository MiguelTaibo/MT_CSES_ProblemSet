#include <bits/stdc++.h>

using namespace std;

#define FOR(n) for (int i=0; i<n;i++)
#define FOR2(n) for (int j=0; j<n;j++)
#define arr(N) array<int, N>
#define SPACE << " " <<
#define F << endl

typedef long long ll;
const int mxn = 1e6;
long q,n,m[mxn], powV;
int inicio, len, ant, v;



int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> q;
  v = ceil(log2(n));
  powV = pow(2,v);
  for (int i = 0; i<n;i++) {
    cin >> m[i];
  }

  /*
  inicio = 0;
  for (int k = v; k>=0;k--) {
    for (int i = inicio; i<inicio+pow(2,k);i++) {
      cout << m[i] << " ";
    } cout F;
    inicio+=pow(2,k);
  }
  */

  int control, a, b, u, t;
  int offset;
  ll res, potencia;
  for (int k = 0; k<q;k++) {
    cin >> control;
    if (control==1) {
      cin >> a >> b >> u;
      a--;
      offset = 0;
      potencia = pow(2,v);
      while (a<b) {
        if (a%2==1) {
          //cout << " add " << offset+a;
          m[offset+a++]+=u;
        }
        if (b%2==1) {
          m[offset+--b]+=u;
          //cout << " add " << offset+b;
        }
        a/=2; b/=2;
        offset+=potencia;
        potencia/=2;
      }
    }
    else if (control==2) {
      cin >> t;
      t--;
      res = 0;
      offset = 0;
      potencia = pow(2,v);
      for (int i = 0; i<=v;i++) {
        res+=m[t+offset];
        t/=2;
        offset+=potencia;
        potencia/=2;
      }
      cout << res << endl;
    }
  }


}
