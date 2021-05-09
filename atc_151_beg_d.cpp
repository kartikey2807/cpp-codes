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
#define foi(i,n) for(i = 0; i < n; i+=1)
#define fod(i,n) for(i=n-1; i >=0; i-=1)
#define MAX std::numeric_limits<lld>::max()
#define MIN std::numeric_limits<lld>::min()
#define FastIO  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define LEN 2000
lld level [LEN];
set <lld> BFS_ (vector <lld> V[], lld s)
{
	cerr << s << "\n";
	set <lld> visit;
	queue< lld> que;
	lld y;
	que.push(s);
	level[s]= 0;
	visit.insert(s);
	while (!que.empty())
	{
		y=que.front();
		que.pop();
		for(lld i = 0; i<V[y].size(); i+=1)
		{
			if (!visit.count(V[y][i])==1)
			{
			level[V[y][i]] = level[y]+1;
				visit.insert(V[y][i]);
				que.push(V[y][i]);
			}
		}
	}
	return visit;
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",   stdin);
      freopen("outputf.in", "w",  stdout);
      #endif
      FastIO
      lld h, w;
      cin >> h;
      cin >> w;
      vector <lld>V[LEN];
      lld A[LEN] , k = 0;
      char dda[h+1][w+1];
      for(lld i = 1; i <= h; i+= 1)
      {
      	for(lld j = 1;j<=w;j++)
      	{
      		cin >> dda[i][j];
      		if (dda[i][j] == '.')
      		{
      			if (i > 1 && dda[i-1][j] == '.')
      			{
      				V[(((i+j)*(i+j+1))/2)+j].push_back(((((i-1)+j)*((i-1)+j+1))/2)+(j-0));
      				V[((((i-1)+j)*((i-1)+j+1))/2)+(j-0)].push_back((((i+j)*(i+j+1))/2)+j);
      			}
      			if (i < h && dda[i+1][j] == '.')
      			{
      				V[(((i+j)*(i+j+1))/2)+j].push_back(((((i+1)+j)*((i+1)+j+1))/2)+(j-0));
      				V[((((i+1)+j)*((i+1)+j+1))/2)+(j-0)].push_back((((i+j)*(i+j+1))/2)+j);
      			}
      			if (j > 1 && dda[i][j-1] == '.')
      			{
      				V[(((i+j)*(i+j+1))/2)+j].push_back((((i+(j-1))*(i+(j-1)+1))/2)+(j-1));
      				V[(((i+(j-1))*(i+(j-1)+1))/2)+(j-1)].push_back((((i+j)*(i+j+1))/2)+j);
      			}
      			if (j < w && dda[i][j+1] == '.')
      			{
      				V[(((i+j)*(i+j+1))/2)+j].push_back((((i+(j+1))*(i+(j+1)+1))/2)+(j+1));
      				V[(((i+(j+1))*(i+(j+1)+1))/2)+(j+1)].push_back((((i+j)*(i+j+1))/2)+j);
      			}
      			A[k] = (((i+j)*(i+j+1))/2)+j;
      			k++;
      		}
      	}
      }
      set <lld> vis;
      lld max   = 0;
      lld i, j;
      foi(i, k)
      {
      	foi(j, LEN)
      	{
      		level[j] = -1;
      	}
      	vis = BFS_(V, A[i]);
      	foi(j, k)
      	{
      		if (level[A[j]] != -1)
      		{
      			if (level[A[j]] > max)
      			{
      				max=level[A[j]];
      			}
      		}
      	}
      }
      cout << max <<"\n";
      return 0;
}