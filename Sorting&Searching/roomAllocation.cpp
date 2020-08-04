#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mxn = 2e5;
int x,n;
array<int,4> a[mxn];
array<int,2> rooms[mxn];

void printArray(array<int,2> r[], int l) {
  for (int i = 0; i<l;i++) {
    cout << r[i][0] << " ";
  }
  cout << endl;
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 0; i<n;i++){
    cin >> a[i][0] >> a[i][1];
    a[i][2]=i;
  }
  sort(a,a+n);

  int l = 0;
  bool found;
  int temp = 0;
  for (int k = 0; k<n;k++) {

    found = false;
    for (int p = 0; p<=l;p++) {
      int i;
      if (p+temp==0) i = 0;
      else i =(p+temp)%(l+1);


      if (i==l) {
        sort(rooms,rooms+l);
        if (rooms[0][0]>=a[k][0]) {
          temp = 0;
          break;
        }
        continue;
      }

      if (rooms[i][0]<a[k][0]) {
        rooms[i][0]=a[k][1];
        a[k][3]=rooms[i][1];
        found = true;
        temp = i+1;
        break;
      }

    }
    if (!found) {
      rooms[l][0]=a[k][1];
      rooms[l][1]=l+1;
      a[k][3]=++l;
      temp=0;
    }
    /*
    auto it = lower_bound(rooms, rooms+l,a[k][0]);
    //cout << it-rooms << " " <<(*it) << endl;
    //it--;
    if (it!=rooms) {
      it--;
      (*it)=a[k][1];
      a[k][3]=(it-rooms)+1;
      sort(it, rooms+l);
    }
    else {
      rooms[l]=a[k][1];
      a[k][3]=++l;
    }*/
  }

  array<int,2> b[n];
  for (int i = 0; i<n;i++) {
    b[i][0] = a[i][2];
    b[i][1] = a[i][3];
  }
  sort (b,b+n);

  cout << l << endl;
  for (int i = 0; i<n;i++) {
    cout << b[i][1] << " ";
  }
  cout << endl;

}
