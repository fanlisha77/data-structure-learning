#include<iostream>
using namespace std;

const int MAXSIZE=100;
//创建顺序表 
struct SeqList{
	int data[MAXSIZE];//存数据 
	int length;//当前长度 
};

//顺序表初始化
void Init(SeqList &L){
	L.length=0;
} 

//顺序表插入
bool insert(SeqList &L,int i,int x){
	if(i<0 || i>L.length){//判断位置是否合法 
		return false;
	}
	
	if(L.length>=MAXSIZE){//判断空间是否已满 
		return false;
	}
	
	for(int j=L.length;j>i;j--){
		L.data[j]=L.data[j-1];//往后挪位置 
	}
	
	L.data[i]=x;
	L.length++;
} 

//顺序表删除
bool remove(SeqList &L,int i){
	if(i<0 || i>=L.length){
		return false;
	}
	
	for(int j=i;j<L.length-1;j++){
		L.data[j]=L.data[j+1];
	}
	
	L.length--;
} 

//顺序表查找
int find(SeqList L,int x){
	for(int i=0;i<L.length;i++){
		if(L.data[i]==x){
			return i;
		}
	}
	return -1;
} 

//顺序表遍历
void print(SeqList L){
	for(int i=0;i<L.length;i++){
		cout<<L.data[i]<<" ";
	}
	cout<<endl;
} 

int main()
{
	SeqList L;
	Init(L);
	
	insert(L,0,10);
	insert(L,1,20);
	insert(L,2,30);
	insert(L,3,40);
	
	cout<<"原数组为："<<endl;
	print(L);
	
	insert(L,3,99);
	cout<<"插入操作后数组变为:"<<endl;
	print(L);
	
	remove(L,2);
	cout<<"删除操作后数组变为:"<<endl;
	print(L);
	
	cout<<"要查找的数的下标是:"<<find(L,20)<<endl;
	
	return 0;
}
