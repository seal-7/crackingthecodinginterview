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

int detect_loop(Node *head){
	if(head==NULL){
		return -1;
	}
	Node *slow=head;
	Node *fast=head;
	while(fast!=NULL and slow!=NULL and fast->next){
		fast=fast->next->next;
		slow=slow->next;
		if(fast==slow){
			break;
		}
	}
	if(fast==slow){
		int count=0;
		while(head!=fast){
			head=head->next;
			fast=fast->next;
			count++;
		}
		return count;
	}
	return -1;
}

int main(){
	Node *head=NULL;
	int n,val,loop_here;
	
	cin>>n>>loop_here;		//index where loop joints
	
	for(int i=0; i< n; i++){
		cin>>val;
		head=insert(head,val);
	}
	
	Node *temp1=head,*temp2=head;
	
	while(temp1->next!=NULL){
		temp1=temp1->next;
	}
	
	for(int i=0;i<loop_here;i++){
		temp2=temp2->next;
	}
	temp1->next=temp2;

	int pos=detect_loop(head);
	if(pos==-1){
		cout<<"No loop detected\n";
	}
	else{
		cout<<pos<<"\n";
	}
	return 0;
}