#include<bits/stdc++.h> 

using namespace std;

struct node{
	int num;
	node *left;
	node *right;
	node *parent;
};
bool havepath_or_not(node* root,int sum){
	if(root==NULL) return false;
	if(root->left==NULL && root->right==NULL && sum-root->num==0) return true;
	return havepath_or_not(root->left,sum-root->num) || havepath_or_not(root->right,sum-root->num);
}
int main(){
	int sum;
	int n;
	cin>>n;
	node *root;
	root=(node*)malloc(sizeof(node));
	root->left=NULL;
	root->right=NULL; 
	cin>>root->num;
	node *now;
	now=root;
	for(int i=0;i<n-1;i++){
		node *newnode;
		newnode=(node*)malloc(sizeof(node));
		newnode->left=NULL;
		newnode->right=NULL;
		cin>>newnode->num;
		
		node *ptr=root;
		node *y;
		while(ptr!=NULL){
			y=ptr;
			if(newnode->num>ptr->num){
				ptr=ptr->right;
			//	cout<<"right"<<endl;
			}	
			else if(newnode->num<ptr->num){
				ptr=ptr->left;
			//	cout<<"left"<<endl;
			}	
		}
		newnode->parent=y;
		if(y==NULL)
			y=newnode;
		else if(newnode->num<y->num)
			y->left=newnode;
		else
			y->right=newnode;
			
	} 
	cin>>sum;
	
	//cout<<root->left->num;
	//cout<<root->left->right->num;
	//cout<<havepath_or_not(root,sum);
	if(havepath_or_not(root,sum)==1){
		cout<<"There exit at least one path in binary search tree."<<endl; 
	}
	else cout<<"There have no path in binary search tree."<<endl;  
}
