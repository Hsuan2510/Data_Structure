#include<bits/stdc++.h> 

using namespace std;

typedef struct point{
	int row;
	int col;
	int dir;
};


int mover(int dir){
	if(dir==0) return -1;
	else if(dir==1) return 0;
	else if(dir==2) return 1;
	else if(dir==3) return 0;
}
int movec(int dir){
	if(dir==0) return 0;
	else if(dir==1) return 1;
	else if(dir==2) return 0;
	else if(dir==3) return -1;
}

int main(){
	point stack[10005];
	int m,n;
	cin>>m>>n;
	int mark[m+2][n+2];
	int maze[m+2][n+2];
	//清空清1 
	for(int i=0;i<m+2;i++){
		for(int j=0;j<n+2;j++){
			maze[i][j]=1;
			mark[i][j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>maze[i][j];
		}
	}
	//檢查輸入 
	/*for(int i=0;i<m+2;i++){
		for(int j=0;j<n+2;j++){
			cout<<maze[i][j]<<" ";
		}
		cout<<endl;
	}*/
	
	point now;
	point next;
	int top=0;
	bool found=false;
	mark[1][1]=1;
	stack[0].row=1;
	stack[0].col=1;
	stack[0].dir=1;
	while(top>-1 && !found){
		now = stack[top];
		top--;
		while(now.dir<4&&!found){
			next.row=now.row+mover(now.dir);
			next.col=now.col+movec(now.dir);
			if(next.row==m&&next.col==n) {
				found=true;
			}
			else if(maze[next.row][next.col]==0&&mark[next.row][next.col]==0){
			 	mark[next.row][next.col]=1;
				stack[++top]=now;
				now.row=next.row;
				now.col=next.col;
				now.dir=0; 
			}
			else now.dir++;
		}
	} 
	if(found){
		for(int i=0;i<=top;i++){
			cout<<"("<<stack[i].row-1<<","<<stack[i].col-1<<")"<<" ";
		}
		cout<<"("<<now.row-1<<","<<now.col-1<<")"<<" ";
		cout<<"("<<m-1<<","<<n-1<<")";
	}
	else{
		cout<<"Can't reach the exit!"<<endl;
	}
	return 0;
}
