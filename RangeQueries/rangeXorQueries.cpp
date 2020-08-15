#include <bits/stdc++.h>

using namespace std;

#define FOR(n) for (int i=0; i<n;i++)
#define FOR2(n) for (int j=0; j<n;j++)
#define arr(N) array<int, N>
#define SPACE << " " <<
#define F << endl

typedef long long ll;
const int mxn = 1e7;
const int MXN = 4e5;
ll q,n, x, m[mxn], powV;
int ant, v, inicio;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> q;
  v = ceil(log2(n));
  powV = pow(2,v);
  for (int i = 0; i<n;i++) {
    cin >> m[i];
  }

  inicio = 0;
  //cout F;
  //cout << v << " " << pow(2,v) F;
  for (int k = v; k>=0; k--) {
    ant = pow(2,k);
    inicio+=pow(2,k);
    for (int i = 0; i<ant; i++) {
      m[inicio+i]=m[inicio+2*i-ant] ^ m[inicio+2*i-ant+1];
    }
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

  int a,b, offset;
  ll res,potencia;
  set<int> s;
  for (int k = 0; k<q;k++) {
    cin >> a >> b;
    a--;
    b;
    offset = 0;
    res =0;
    potencia = pow(2,v);
    while (a<b) {
      if (a%2==1) {
        //cout << " add " << offset+a;
        res ^= m[offset+a++];
      }
      if (b%2==1) {
        res ^= m[offset+--b];
        //cout << " add " << offset+b;
      }
      a/=2; b/=2;
      offset+=potencia;
      potencia/=2;
    }
    cout << res F;
  }





}
