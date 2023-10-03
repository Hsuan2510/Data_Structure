#include<bits/stdc++.h> 

using namespace std;

void visit(int arr[],int now,int idx){
	if(now<idx){
		visit(arr,2*now,idx);
		cout<<arr[now]<<" ";
		visit(arr,2*now+1,idx);
	}
};
int main(){
	int index=1;
	int arr[10005];
	int a;
	while(cin>>a){
    	arr[index]=a;
    	index++;
    	char ch = getchar(); 
    	if(ch == '\n')
    		break;
    }
	visit(arr,1,index);
	return 0;
}
