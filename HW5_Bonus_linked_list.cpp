#include<bits/stdc++.h> 

using namespace std;

struct linklist{
	int num;
	linklist *link;
};

int main(){
	linklist *first;
	first=(linklist*)malloc(sizeof(linklist));
	first->link=NULL;
	string input;
	int size=0;   //�̭����X�ӵ��I 
	while(cin>>input){
		int idx;
		int number;
		if(input=="exit"){
			if(first->link==NULL){
				cout<<"null";
				break;
			}
			linklist *current=first;
			while(current->link!=NULL){
				current=current->link;
				cout<<current->num<<"-->";
			}
			cout<<"null";
			break;
		}
		else if(input=="addBack"){
			cin>>number;
			linklist *newnode;
			newnode=(linklist*)malloc(sizeof(linklist));
			newnode->num=number;
			newnode->link=NULL;
			if(first->link==NULL){   //�Y�O�Ū� �����[�bfirst�᭱ 
				first->link=newnode;
			}
			else{
				linklist *current=first->link;   //first->current->..... 
				while(current->link!=NULL){
					current=current->link;
				}								//��current�ܨ�̫�@�� current->newnode->NULL 
				current->link=newnode;
				
			}
			size++;
			
		}
		else if(input=="addFront"){
			cin>>number;
			linklist *newnode;
			newnode=(linklist*)malloc(sizeof(linklist));
			newnode->num=number;
			newnode->link=first->link;
			first->link=newnode;
			size++;
		}
		else if(input=="addIndex"){
			cin>>idx;
			cin>>number;
			int i=0;
			linklist *current=first;
			linklist *newnode;
			newnode=(linklist*)malloc(sizeof(linklist));
			newnode->num=number;
			if(idx==0){   //�۷��addfront  
				newnode->link=first->link;
				first->link=newnode;
				size++;
			} 
			else{
				while(current->link!=NULL){
					current=current->link;
					if(i==idx-1){  //�Y�n��bidx ��i=idx-1�� current �b�ؼЯ��ޭȪ��e�� 
						newnode->link=current->link;
						current->link=newnode;
						size++;
						cout<<size<<" ";
						break;
					}
					i++;
				}
				
				if(current->link==NULL && idx<size){ //�Yidx����̫�@�� addBack 
					
					newnode->link=NULL;
					current->link=newnode;
					size++;
				}
			} 
		/*	for(int i=0;i<=size;i++){
				if(i==idx && i!=size){
					newnode->link=current->link;
					current->link=newnode;
					break;
				}
				if(i==size){
					current->link=newnode;
					newnode->link=NULL;
					break;
				}
				current=current->link;
			}
			size++;*/ 
		/*	if(idx+1==size){
				current->link=newnode;
				newnode->link=NULL;
			}*/
			
			/*while(current->link!=NULL){
				
				if(idx==0){
					newnode->link=first->link;
					first->link=newnode;
					break;
				}
				if(i==idx){
					newnode->link=current->link;
					current->link=newnode;
					break;
				}
				current=current->link;
				i++;
			}
			if(i==idx){
				current->link=newnode;
				newnode->link=NULL;
			}*/
		
		}
		else if(input=="deleteIndex"){
			cin>>idx;
			linklist *current=first;
			linklist *now=current->link;
			int i=0;
			while(current->link!=NULL){
				if(i==idx){
					current->link=now->link;
					delete now;
					size--;
					break;
				}
				current=current->link;
				now=current->link;
				i++;
			}
		}
		else{
			continue;
		}
	}
	return 0;
}
