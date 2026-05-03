#include<iostream>
using namespace std;

//创建节点 
struct Node{
	int data;
	Node *next;
	
	Node(int val){
		data=val;
		next=nullptr;
	}
}; 

//插入（尾插法）
void append(Node*& head,int val){
	Node *newnode=new Node(val);//创建一个新节点
	
	if(head==nullptr){
		head=newnode;//空链表
		return; 
	} 
	
	Node *temp=head;//找最后一个节点
	while(temp->next!=nullptr){
		temp=temp->next;
	} 
	
	temp->next=newnode;//接上 
} 

//插入（头插法）
void PushFront(Node*& head,int val){
	Node *newnode=new Node(val);//创建新节点
	newnode->next=head;
	head=newnode;
} 

//遍历链表
void print(Node *head){
	Node *temp=head;
	while(temp!=nullptr){
		cout<<temp->data<<" -> ";
		temp=temp->next;
	}
	cout<<"NULL"<<endl;
} 

//查找
int find(Node *head,int val){
	Node *temp=head;
	int index=0;//index是下标 
	
	while(temp!=nullptr){
		if(temp->data==val){
			return index;
		}
		temp=temp->next;
		index++;
	}
	return -1;
} 

//删除（按值删除）
void Delete1(Node *&head,int val){
	if(head==nullptr){
		return;
	}
	
	if(head->data==val){
		Node *temp=head;
		head=head->next;
		delete temp;
		return;
	}
	
	Node *cur=head;
	while(cur->next!=nullptr&&cur->next->data!=val){
		cur=cur->next;
	}
	if(cur->next!=nullptr){
		Node *temp=cur->next;
		cur->next=temp->next;
		delete temp;
	}
} 

//删除（按位删除）
void Delete2(Node *&head,int k){
	if(head==nullptr||k<0){
		return;
	}
	
	if(k==0){
		Node *temp=head;
		head=head->next;
		delete temp;
	}
	
	Node *cur=head;
	for(int i=0;i<k-1&&cur!=nullptr;i++){
		cur=cur->next;
	}
	if(cur!=nullptr&&cur->next!=nullptr){
		Node *temp=cur->next;
		cur->next=temp->next;
		delete temp;
	}
	else{
		cout<<"位置非法"<<endl;
	}
} 

int main()
{
	Node* head1=nullptr;
	
	cout<<"尾插法组成的链表:"<<endl;
	append(head1,1);
	append(head1,2);
	append(head1,3);
	append(head1,4);
	print(head1);
	cout<<"尾插法插入数据后:"<<endl;
	append(head1,99);
	print(head1);
	cout<<"查找值为99的数据: "<<find(head1,99)<<endl;
	cout<<"删除值为99的数据:"<<endl;
	Delete1(head1,99);
	print(head1);
	cout<<"删除位置2上的元素:"<<endl;
	Delete2(head1,2);
	print(head1); 
	
	cout<<"----------------------------------"<<endl;
	
	Node *head2=nullptr;
	cout<<"头插法组成的链表:"<<endl;
	PushFront(head2,1);
	PushFront(head2,2);
	PushFront(head2,3);
	PushFront(head2,4);
	print(head2);
	cout<<"头插法插入数据后:"<<endl;
	PushFront(head2,99);
	print(head2);
	cout<<"查找值为99的数据: "<<find(head2,99)<<endl;
	cout<<"删除值为99的数据:"<<endl;
	Delete1(head2,99);
	print(head2);
	cout<<"删除位置2上的元素:"<<endl;
	Delete2(head2,2);
	print(head2); 
	
	return 0;
}
































