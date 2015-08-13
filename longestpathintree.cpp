#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>
#include <stdio.h>
#include<set>
#include<string.h>
#include<math.h>
#include<queue>
#define ll long long
#define INF 999999
using namespace std;
vector <int> v[10002];
int visited[10002],maxdis=-1;
int temp,dist[10002],pos;
void bfs(ll i)
{
	queue <ll> q;
	q.push(i);
	visited[i]=1;
    dist[i]=0;
	while(!q.empty())
	{
		ll k=q.front();
		q.pop();
		for(ll j=0;j<v[k].size();j++)
		{
			if(visited[v[k][j]]==0)
			{dist[v[k][j]]=dist[k]+1;

			 if(maxdis<dist[v[k][j]])
             {maxdis=dist[v[k][j]];
               pos=v[k][j];
             }

				q.push(v[k][j]);
				visited[v[k][j]]=1;


			}

		}
	}
}
int main()
{
    int n,s,f,c1,c2,i,j;
        cin>>n;

        for(i=0;i<n-1;++i)
        {
            cin>>c1>>c2;
            v[c1].push_back(c2);
            v[c2].push_back(c1);
        }
        memset(dist,0,sizeof(dist));
        bfs(1);

        memset(dist,0,sizeof(dist));
        memset(visited,0,sizeof(visited));

        bfs(pos);

        cout<<maxdis<<'\n';
}
