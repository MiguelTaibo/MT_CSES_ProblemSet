#include <bits/stdc++.h>

using namespace std;


struct P {
  int x, y;
  bool operator<(const P &p) {
    if (x != p.x) return x < p.x;
    else return y < p.y;
  }
};

typedef long long ll;
const int mxn = 1e5;

int x,n,temp;

void printset(set<pair<int,int>> t) {
  for (auto it=t.begin(); it!=t.end();it++) {
    cout << (*it).first << " " << (*it).second << endl;
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> x >> n;
  set<pair<int,int>> s;
  s.insert({1,x});

  //auto it = s.begin();
  //cout << (*it).first << " " << (*it).second;
  int m,first,second;
  //printset(s);
  for (int i = 0; i<n;i++) {
    cin >> temp;
    m = 0;
    for (auto it=s.begin();it!=s.end();it++) {
      if ((*it).first<temp && temp<(*it).second) {
        first = (*it).first;
        second = (*it).second;
        s.erase(*it);
        s.insert({first,temp});
        s.insert({temp+1,second});
        break;
      }
      else if ((*it).first==temp) {
        if ((*it).first==(*it).second) s.erase(*it);
        else {
          first = (*it).first;
          second = (*it).second;
          s.erase(*it);
          s.insert({first+1,second});
        }
        break;
      }
      else if ((*it).second==temp) {
        if ((*it).first==(*it).second) s.erase(*it);
        else {
          first = (*it).first;
          second = (*it).second;
          s.erase(*it);
          s.insert({first,second-1});
        }
        break;
      }

    }
    //printset(s);
    m=0;
    for (auto it=s.begin();it!=s.end();it++) {
      m = max(m,(*it).second-(*it).first);
    }
    cout << m+1 << " ";
  }
  cout << endl;

}
