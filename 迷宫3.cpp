#include<stdio.h>
#include<stdlib.h>
typedef struct Path{
	int x;
	int y;
	int dir;
}Path;
typedef struct STNode{
	Path path;
	struct STNode* next;
}STNode,*LinkStack;
void Push(LinkStack* S,Path path);
Path Pop(LinkStack* S);
void Initmaze(int maze[100][100],int m,int n);
void Print(LinkStack* S);
int main(){
	int m,n;//行，列
	int x1,y1,x2,y2;
	int maze[100][100]={0};
	int i,j,k;
	int x[4]={1,0,-1,0};
	int y[4]={0,1,0,-1};
	int dir[4]={1,2,3,4};
	LinkStack S=NULL;
	Path path;
	int flag=1;
	scanf("%d %d",&m,&n);//m行n列
	scanf("%d %d",&x1,&y1);
	scanf("%d %d",&x2,&y2);
	Initmaze(maze,m,n);
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&maze[i][j]);
		}
	}
	path={x1,y1,0};
	Push(&S,path);
	maze[S->path.x][S->path.y]=1;
	while(S!=NULL){
		if(S->path.x==x2&&S->path.y==y2){
			break;
		}
		for(int k=0;k<4;k++){
			if(maze[S->path.x+y[k]][S->path.y+x[k]]==0){
				S->path.dir=dir[k];
				maze[S->path.x+y[k]][S->path.y+x[k]]=1;
				path.x=S->path.x+y[k];
				path.y=S->path.y+x[k];
				path.dir=1;
				Push(&S,path);
				flag=0;
				break;
			}
		}
		if(flag==1){
			maze[S->path.x][S->path.y]=1;
			Pop(&S);
		}
		
		flag=1;
	}
	if(S==NULL){
		printf("no");
	}
	else
	Print(&S);
	return 0;
}
void Push(LinkStack* S,Path path){
	LinkStack q=(LinkStack)malloc(sizeof(STNode));
	q->path=path;
	q->next=(*S);
	(*S)=q;
}
Path Pop(LinkStack* S){
	LinkStack q=(*S);
	Path path=q->path;
	(*S)=(*S)->next;
	free(q);
	return path;
}
void Initmaze(int maze[100][100],int m,int n){
	int i,j=0;
	for(i=0;i<m+2;i++){
		for(j=0;j<n+2;j++){
			maze[i][j]=1;
		}
	}
}
void Print(LinkStack* S){
	LinkStack q=NULL;
	while((*S)!=NULL){
		Push(&q,Pop(S));
	}
	while(q!=NULL){
		Path a=Pop(&q);
		printf("(%d,%d,%d)",a.x,a.y,a.dir);
		if(q!=NULL){
			printf(",");
		}
	}
}




