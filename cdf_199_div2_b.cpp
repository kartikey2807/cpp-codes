// if you get a wrong answer but you are convinced
// that your logic is correct do :- 1) read the
// entire code and try to find if something needs
// to be added 2) start making test cases that you
// think can possibly give WA.
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
#define pb push_back
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n, m, s, f;
      cin >> n >> m >> s >> f;
      lld time[m], L[m], R[m];
      for(lld i = 0; i < m; i += 1){
      	cin >> time[i] >> L[i] >> R[i];
      }
      lld prev;
      if (s <= f){
      	prev = 0;
      	for(lld i = 0; i < m; i += 1){
      		if (time[i]-prev-1 >= f-s){
      			for(lld j = 1; j <= (f-s); j += 1)
      				cout << "R";
      			s = f;
      		}
      		else{
      			lld blind_steps = time[i]-prev-1;
      			s+= blind_steps;
      			for(lld j = 1; j <= blind_steps; j += 1)
      				cout << "R";
      			if (s >= L[i]-1 && s <= R[i])
      				cout << "X";
      			else
      				{s++; cout << "R";}
      		}
      		if (s == f)
      			break;
      		prev = time[i];
      	}
      	for(lld j = 1; j <= (f-s); j += 1)
      		cout << "R";
      }
      else{
      	prev = 0;
      	for(lld i = 0; i < m; i += 1){
      		if (time[i]-prev-1 >= s-f){
      			for(lld j = 1; j <= (s-f); j += 1)
      				cout << "L";
      			s = f;
      		}
      		else{
      			lld blind_steps = time[i]-prev-1;
      			s-= blind_steps;
      			for(lld j = 1; j <= blind_steps; j += 1)
      				cout << "L";
      			if (s >= L[i] && s <= R[i]+1)
      				cout << "X";
      			else
      				{s--; cout << "L";}
      		}
      		if (s == f)
      			break;
      		prev = time[i];
      	}
      	for(lld j = 1; j <= (s-f); j += 1)
      		cout << "L";
      }
      return 0;
}