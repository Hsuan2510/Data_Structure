#include<bits/stdc++.h> 

using namespace std;
typedef struct Thing{  //每一個非零元素 
	string thing;
	int weight;
};
void delete_heap(Thing heap[],int *n){
	int parent,child;
	Thing temp;
	temp=heap[(*n)--];
	parent=1;
	child=2;
	while(child<*n){
		if(child<*n && heap[child].weight<heap[child+1].weight)
			child++;
		if(temp.weight>=heap[child].weight) break;
		heap[parent]=heap[child];
		parent=child;
		child*=2; 
	}
	heap[parent]=temp;
}
void compare(int k,int n,Thing heap[]){
		int left=2*k;
		int right=2*k+1;
		int max;
		if(heap[left].weight>heap[right].weight){
			if(heap[left].weight>heap[k].weight){
				max=left;
			}
			else{
				max=k;
			}
		}
		else{
			if(heap[right].weight>heap[k].weight){
				max=right;
			}
			else{
				max=k;
			}
		}	
		if(max!=k){
			Thing tmp;
			tmp=heap[k];
			heap[k]=heap[max];
			heap[max]=tmp;
		}
}
int main(){
	int num;
	cin>>num;
	Thing *heap=new Thing[num+1];
	for(int i=1;i<=num;i++){
		cin>>heap[i].thing;
		cin>>heap[i].weight;
	}
	//建立max heap 
	for(int i=num/2;i>=1;i--){
		compare(i,num,heap);
	}
/*	for(int i=1;i<=num;i++){
			cout<<heap[i].weight<<" ";
		}*/
	cout<<"First three things to do:"<<endl;
	for(int i=0;i<3;i++){
		cout<<heap[1].thing<<endl;
		delete_heap(heap,&num);
		for(int i=num/2;i>=1;i--){
			compare(i,num,heap);
		}
	}
}
