#include<iostream>
#include<set>
using namespace std;
int main()
{std::set<int>::iterator it;
    int N,M,size,j,i;
    cin>>N;
int f[N];
set<int>s;
 for( i=0;i<N;++i)
 {
     cin>>f[i];
     cin>>M;
     int ff[M];
     for(j=0;j<M;++j)
     {cin>>ff[j];
      s.insert(ff[j]);
     }

 }
 size=s.size();
 for(i=0;i<N;++i)
 {
    {
        for(it=s.begin();it!=s.end();++it)
           {if(f[i]==*it)
            size--;}
     }
 }
cout<<size;
}
