/*
 ____    _____      _      _               _____ 
/ ___|  | ____|    / \    | |             |___  |
\___ \  |  _|     / _ \   | |      _____     / / 
 ___) | | |___   / ___ \  | |___  |_____|   / /  
|____/  |_____| /_/   \_\ |_____|          /_/   

*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi; 
typedef pair<int,int> ii; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define modulo(a, b) (a%b<0 ? a%b+b : a%b)
#define PI 3.1415926535897
#define ceil(a,b) ((a+b-1)/b)
#define MOD 1000000007
#define INF 1e18+7
/*_______________________________________________*/
struct Node{
	int data;
	Node *next;
};
/*_______________________________________________*/
Node* insert(Node *head,int data){	
	if(head==NULL){
		Node *temp=new Node;
		temp->data=data;
		return temp;
	}
	head->next=insert(head->next,data);
	return head;
}
void Print(Node *head){
	if(head==NULL){
		return;
	}
	cout<<head->data<<" ";
	Print(head->next);
}
int find_merge_index(Node *list1,Node *list2){
	int count=0;
	while(list1!=NULL and list2!=NULL){
		if(list1==list2){
			return count;
		}
		count++;
		list1=list1->next;
		list2=list2->next;
	}
	return -1;
}
int check_intersection(Node *list1,Node *list2){
	if(list1==NULL or list2==NULL){
		return -1;
	}
	int length_1=0,length_2=0;
	Node *temp1=list1,*temp2=list2;
	while(temp1!=NULL or temp2!=NULL){
		if(temp1==NULL){
			length_2++;
			temp2=temp2->next;
		}
		else if(temp2==NULL){
			length_1++;
			temp1=temp1->next;
		}
		else{
			length_1++;
			length_2++;
			temp1=temp1->next;
			temp2=temp2->next;	
		}
	}
	if(length_2>length_1){
		for(int i=0;i<(length_2-length_1);i++){
			list2=list2->next;
		}
	}
	else if(length_1>length_2){
		for(int i=0;i<(length_1-length_2);i++){
			list1=list1->next;
		}
	}
	return find_merge_index(list1,list2);
}
int main(){
	Node *list1=NULL,*list2=NULL;
	int n,k,merge_point,val;
	
	cin>>n>>k;			 			//size of list1 and list2
	
	for(int i=0; i< n; i++){
		cin>>val;
		list1=insert(list1,val);
	}
	for(int i=0; i< k; i++){
		cin>>val;
		list2=insert(list2,val);
	}
	
	cin>>merge_point; 				//Where list 2 will merge list1
	
	Node *temp1=list1,*temp2=list2;
	for(int i=0;i<merge_point;i++){
		temp1=temp1->next;
	}
	while(temp2->next!=NULL){
		temp2=temp2->next;
	}
	temp2->next=temp1;

	int pos=check_intersection(list1,list2);
	if(pos==-1){
		cout<<"No Intersection \n";
	}
	else{
		cout<<pos<<endl;
	}
	Print(list1);
	cout<<"\n";
	Print(list2);
	return 0;
}