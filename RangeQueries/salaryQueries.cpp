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
int n, q, v;
ll powV, potencia, offset, inicio;
ll a[mxn], b[mxn];
ll k,x;

void getIfTrue(int idx,ll pot, ll off, ll &respuesta) {
  cout << off+idx << " ";
  if (b[off+idx]<k || x<a[off+idx]) return;
  else if (k<=a[off+idx] && b[off+idx]<=x) respuesta+=(powV/pot);
  else {
    getIfTrue(2*idx,pot*2,off-2*pot, respuesta);
    getIfTrue(2*idx+1,pot*2,off-2*pot, respuesta);
  }


}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> q;
  for (int i = 0; i<n;i++) {
    cin >> a[i];
    b[i] = a[i];
  };

  v = ceil(log2(n));
  powV = pow(2,v);
  for (int i=n;i<powV;i++) {
    a[i]=(ll)1e10;
  }

  inicio = 0;
  for (int k = v; k>=0; k--) {
    potencia = pow(2,k);
    inicio+=pow(2,k);
    for (int i = 0; i<potencia; i++) {
      a[inicio+i]=min(a[inicio+2*i-potencia],a[inicio+2*i-potencia+1]);
      b[inicio+i]=max(b[inicio+2*i-potencia],b[inicio+2*i-potencia+1]);
    }
  }

  char control;
  for (int temp = 0; temp<q; temp++) {
    cin >> control >> k >> x;
    if (control =='?') {
      ll res = 0;
      cout << inicio F;
      getIfTrue(0,1,inicio-1,res);
      cout F;
      cout << res << " " ;
    }
    else if (control=='!') {
      k--;
      offset = 0;
      potencia = pow(2,v);
      b[k]=x;
      a[k]=x;
      offset+=potencia;
      for (int t =1; t<=v;t++) {
        k/=2; k*=2;
        a[offset+k/2]=min(a[offset+k-potencia],a[offset+k-potencia+1]);
        b[offset+k/2]=max(b[offset+k-potencia],b[offset+k-potencia+1]);
        k/=2;
        potencia/=2;
        offset+=potencia;
      }
    }

  }
  cout F;
  //printA(); printB();


}
