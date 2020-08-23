#include <bits/stdc++.h>

using namespace std;

#define FOR(n) for (int i=0; i<n;i++)
#define FOR2(n) for (int j=0; j<n;j++)
#define arr(N) array<int, N>
#define SPACE << " " <<
#define F << endl

typedef long long ll;
const int mxn = 1e6;
const int MXN = 4e5;
ll q,n, x, m[mxn], powV;
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
  for (int i=n;i<powV;i++) {
    m[i]=(ll)1e10;
  }

  inicio = 0;
  for (int k = v; k>=0; k--) {
    ant = pow(2,k);
    inicio+=pow(2,k);
    for (int i = 0; i<ant; i++) {
      m[inicio+i]=min(m[inicio+2*i-ant],m[inicio+2*i-ant+1]);
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

  int a,b, offset, control;
  ll res,potencia;
  for (int k = 0; k<q;k++) {
    cin >> control >> a >> b;
    a--;
    res =(ll)1e10;
    offset = 0;
    potencia = pow(2,v);
    if (control==2) {
      while (a<b) {
        if (a%2==1) {
          //cout << " add " << offset+a;
          res = min(res,m[offset+a++]);
        }
        if (b%2==1) {
          res = min(res,m[offset+--b]);
          //cout << " add " << offset+b;
        }
        a/=2; b/=2;
        offset+=potencia;
        potencia/=2;
      }
      cout << res F;
    }
    else if (control==1) {
      m[a]=b;
      offset+=potencia;
      for (int t =1; t<=v;t++) {
        a/=2; a*=2;
        m[offset+a/2]=min(m[offset+a-potencia],m[offset+a-potencia+1]);
        a/=2;
        potencia/=2;
        offset+=potencia;
      }
    }
  }


}
