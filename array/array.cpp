#include<iostream>
using namespace std;

int main()
{
	int arr[3];
	cout<<"请输入数组中的元素:"<<endl;
	for(int i=0;i<3;i++){
		cin>>arr[i];
	}
	
	cout<<"数组中的元素是:"<<endl;
	for(int i=0;i<3;i++){
		cout<<arr[i]<<" ";
	}
}
