// if you get a wrong answer but you are convinced
// that your logic is correct do :- 1) read the
// entire code and try to find if something needs
// to be added 2) start making test cases that you
// think can possibly give WA. Double cannot be used
// for comparisons use div and mod instead. 
#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
using namespace std;
typedef double  dbl;
typedef long long int lld;
#define PI 3.14159265358979323
#define foi(i,n) for(lld i = 0; i < n; i+=1)
#define fod(i,n) for(lld i=n-1; i >=0; i-=1)
#define MAX std::numeric_limits<lld>::max()
#define MIN std::numeric_limits<lld>::min()
#define FastIO  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define auth set <lld> :: iterator
#define pb push_back
map <pair <lld, lld>, set <lld> > mac;
map <pair <lld, lld>, vector<lld> > v;
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n;
      cin >> n;
      lld A[n],B[n],C[n];
      for(lld i = 0; i < n; i += 1){
      	cin>>A[i]>>B[i]>>C[i];
      	mac[make_pair(A[i],B[i])].insert(i);mac[make_pair(B[i],A[i])].insert(i);
      	mac[make_pair(A[i],C[i])].insert(i);mac[make_pair(C[i],A[i])].insert(i);
      	mac[make_pair(B[i],C[i])].insert(i);mac[make_pair(C[i],B[i])].insert(i);
      }
      for(map <pair <lld, lld>, set <lld> > :: iterator itr = mac.begin(); itr != mac.end(); itr++){
      	set <lld> temp = itr->second;
      	vector <lld> ans;
      	for(auth pos = temp.begin(); pos != temp.end(); pos++){
      		if (A[*pos] != (itr->first).first && A[*pos] != (itr->first).second){
      			ans.pb(A[*pos]);
      		}
      		else{
      			if (B[*pos] != (itr->first).first && B[*pos] != (itr->first).second){
      				ans.pb(B[*pos]);
      			}
      			else{
      				ans.pb(C[*pos]);
      			}
      		}
      	}
      	v[itr->first] = ans;
      }
      lld ans = MIN;
      vector <pair <pair <lld, lld>, lld> > order;
      for(map <pair <lld , lld>, vector <lld> > :: iterator itr = v.begin(); itr != v.end(); itr++){
      	sort(v[itr->first].begin(),v[itr->first].end(),greater<lld>());
      	if (v[itr->first].size() > 1){
      		if (min(min((itr->first).first,(itr->first).second),v[itr->first][0]+v[itr->first][1]) > ans){
      			ans=min(min((itr->first).first,(itr->first).second),v[itr->first][0]+v[itr->first][1]);
      			order.clear();
      			order.pb(make_pair(itr->first,v[itr->first][0]));
      			order.pb(make_pair(itr->first,v[itr->first][1]));
      		}
      	}		
      	else{
      		if (min(min((itr->first).first,(itr->first).second),v[itr->first][0]) > ans){
      			ans=min(min((itr->first).first,(itr->first).second),v[itr->first][0]);
      			order.clear();
      			order.pb(make_pair(itr->first,v[itr->first][0]));
      		}
      	}
      }
      cout << order.size() << "\n";
      set <lld> vis;
      for(lld i = 0; i < order.size(); i += 1){
      	vector <lld> t1;
      	t1.pb((order[i].first).first);t1.pb((order[i].first).second);t1.pb(order[i].second);
      	sort(t1.begin(),t1.end());
		for(lld j = 0; j < n; j += 1){
			if (vis.count(j))
				continue;
			vector <lld> t2;
			t2.pb(A[j]);
			t2.pb(B[j]); 
			t2.pb(C[j]);
			sort(t2.begin(),t2.end());
			if (t2 == t1){
				cout << j+1 << " ";
				vis.insert(j);
				break;
			}
		}
      }
      return 0;
}