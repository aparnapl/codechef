#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
	int info;
	struct node* left;
	struct node* right;
};
typedef struct node node;

node* create(int val)
{
	node* n= (node*)malloc(sizeof(node));
	n->info=val;
	n->left=NULL;
	n->right=NULL;
	return n;
}
void insert(node* r,int val)
{
	
		if(val > r->info)
		{
		     if(r->right == NULL)
		      {
		      	node* n = create(val);
		      	r->right=n;
		      }
		     else
		      {
		      	insert(r->right,val);
		      }
		}
		else
		{
			if(r->left == NULL)
		      {
		      	node* n = create(val);
		      	r->left=n;
		      }
		     else
		      {
		      	insert(r->left,val);
		      }
		}
	
}
void preorder(node*r)
{
	if(r==NULL)
	 return;
	cout<<r->info<<'\n';
	preorder(r->left);
	preorder(r->right);
}
void postorder(node* r)
{
	if(r==NULL)
	 return;
	
	postorder(r->left);
	postorder(r->right);
	cout<<r->info<<'\n';
}
void inorder(node* r)
{
	if(r==NULL)
	 return;
	
	inorder(r->left);
	cout<<r->info<<'\n';
	inorder(r->right);
	
}
int main()
{
    
	node*r = (node*)malloc(sizeof(node));
	r->info=10;
	r->right=NULL;
	r->left=NULL;
	insert(r,5);
	insert(r,12);
	insert(r,11);
	insert(r,15);
	insert(r,3);
	insert(r,8);
	preorder(r);
	cout<<"-----\n";
	inorder(r);
	cout<<"-----\n";
	postorder(r);
}
