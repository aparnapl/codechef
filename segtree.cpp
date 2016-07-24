#include<stdio.h>
#include<iostream>
using namespace std;
void init(int a[],int tree[],int i,int j,int k)
{
	if(i>j)
		return ;
	if(i==j)
		tree[k]=a[i];
    else
    {
    	init(a,tree,i,(i+j)/2,2*k+1);
    	init(a,tree,(i+j)/2+1,j,2*k+2);
    	cout<<i<<" "<<2*k+1<<" "<<2*k+2<<'\n';
    	tree[k]=tree[2*k+1]+tree[2*k+2];
    }
}
int getsum(int a[],int tree[],int i,int j,int k,int l,int h)
{

	if(i>j)
	  return 0;
	//cout<<i<<" "<<j<<" "<<k<<'\n';
	if(j<l or i>h)
      	   return 0;
	else if(i==j)
	  {
	  	cout<<k<<" "<<tree[k]<<'\n';
	  	return tree[k];
	  } 
    else 
      {
      	if(i>=l && h<=j)
      	   {
      	   	cout<<tree[k]<<'\n';
      	   	return tree[k]; 
      	   }        	
        else 
		   return getsum(a,tree,(i+j)/2+1,j,2*k+2,l,h) + getsum(a,tree,i,(i+j)/2,2*k+1,l,h); 
      }
}
void pointupdate(int tree[],int ind,int val,int i,int j,int k)
{
	cout<<i<<" "<<j<<" "<<k<<'\n';
	if(i>j)
	   return;
	if(ind<i or ind>j)
	   return;
	if(i==j)
	   tree[k]+=val;
	else
	{
	tree[k]+=val;
	pointupdate(tree,ind,val,i,(i+j)/2,2*k+1);
	pointupdate(tree,ind,val,(i+j)/2+1,j,2*k+2);
	}
}
int main()
{
	int n=5,i;
	int a[]={2,1,5,4,6};
	int tree[2*n];
	for(i=0;i<2*n;i++)
		tree[i]=0;
	init(a,tree,0,n-1,0);
	for(i=0;i<=2*n-2;i++)
	  cout<<tree[i]<<" ";
	  cout<<'\n';
	  cout<<getsum(a,tree,0,4,0,2,2)<<'\n';
	  
	  pointupdate(tree,3,4,0,4,0);
	  
	for(i=0;i<=2*n-2;i++)
	  cout<<tree[i]<<" ";
}
