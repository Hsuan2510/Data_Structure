#include<bits/stdc++.h> 

using namespace std;

struct student{
	int ID;
	int score;
	int num;
};

int main(){
	int n,idx=0;  //idx記錄第幾個開始不一樣 
	cin>>n;
	student arr[n];
	for(int i=0;i<n;i++){
		student stu;
		cin>>stu.ID;
		cin>>stu.score;
		stu.num=i;
		arr[i]=stu;
	}
	for(int i=0;i<n;i++){
		int max=i;
		for(int k=i+1;k<n;k++){
			if(arr[max].score<arr[k].score){
				student tmp;
				tmp=arr[max];
				arr[max]=arr[k];
				arr[k]=tmp;
			}
		}
	}
	for(int i=0;i<n;i++){
		if(arr[i].score!=arr[i+1].score){
			for(int k=idx;k<=i;k++){
				int min=k;
				for(int j=k+1;j<=i;j++){
					if(arr[min].num>arr[j].num){
						student tmp;
						tmp=arr[min];
						arr[min]=arr[j];
						arr[j]=tmp;
					}
				}		
			}
			idx=i+1;
		}
	}
	for(int i=0;i<n;i++){
		cout<<arr[i].ID<<endl;
	}
	return 0;
} 
