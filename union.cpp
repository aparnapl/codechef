#include<bits/stdc++.h>
using namespace std;
int find(int x,int parent[])
{
	if(parent[x]==x)
		return x;
	parent[x]=find(parent[x],parent);
	return parent[x];
	
}
void union1(int a,int b,int parent[],int rank[])
{
	int x=find(a,parent);
	int y=find(b,parent);
	cout<<a<<" "<<b<<" "<<x<<" "<<y<<'\n';
	if(x != y)
	{
		if(rank[x] > rank[y])
			parent[y]=x;
		else if(rank[x] < rank[y])
			parent[x]=y;
		else 
			{
				parent[x]=y;
				rank[y]++;
			}
	}
	else 
	 printf("Cycle exists !\n");
}

int main()
{
	int i;
	int parent[] = {0,1,2,3,4,5,6,7,8};
	int rank[] = {0,0,0,0,0,0,0,0,0};
	union1(0,1,parent,rank);
	for(i=0;i<=8;i++)
		cout<<parent[i]<<" ";
	cout<<'\n';
	union1(2,3,parent,rank);
	for(i=0;i<=8;i++)
		cout<<parent[i]<<" ";
	cout<<'\n';
	
	union1(0,2,parent,rank);
	for(i=0;i<=8;i++)
		cout<<parent[i]<<" ";
	cout<<'\n';
	union1(1,3,parent,rank);
	for(i=0;i<=8;i++)
		cout<<parent[i]<<" ";
	cout<<'\n';
	union1(4,5,parent,rank);
	for(i=0;i<=8;i++)
		cout<<parent[i]<<" ";
	cout<<'\n';
	union1(4,6,parent,rank);
	for(i=0;i<=8;i++)
		cout<<parent[i]<<" ";
	cout<<'\n';
	union1(5,7,parent,rank);
	for(i=0;i<=8;i++)
		cout<<parent[i]<<" ";
	cout<<'\n';
	union1(5,8,parent,rank);
	for(i=0;i<=8;i++)
		cout<<parent[i]<<" ";
	cout<<'\n';
	
}
