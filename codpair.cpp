#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#define b  first
#define l second
using namespace std;
int main()
{
int t;
cin>>t;
long long n,i,m,tot,res;


while(t--)
{tot=0;
res=0;
    cin>>n;
vector < pair<long long,long long> >p(n);
     for(i=0;i<n;++i)
     {
         cin>>p[i].b;
         cin>>p[i].l;

     }
     sort(p.begin(),p.end());

vector< long long >song;
     for(i=0;i<n;++i)
     {
         if(i==0||(p[i-1].b<p[i].b))
            song.push_back(p[i].l);
         else
            tot=tot+p[i].l;
     }
     m=song.size();
     sort(song.begin(), song.end());
    res=m*tot;
    for(i=0;i<song.size();++i)
    {res=res+(i+1)*song[i];
    }
    cout<<res<<endl;
}
}
