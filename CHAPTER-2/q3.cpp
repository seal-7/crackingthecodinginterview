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
Node *deleteMiddle(Node *head){
	if(head->next==NULL){ 
		return head;
	}
	Node *slow=head;
	Node *temp=head;
	Node *fast=head;
	if(fast->next->next==NULL){
		slow->next=NULL;
		free(fast->next);
		return head;
	}
	while(fast!=NULL){
		if(fast->next==NULL){
			break;
		}
		temp=slow;
		slow=slow->next;
		fast=fast->next->next;
	}
	temp->next=slow->next;
	return head;
}
int main(){
	int n,val;
	Node *head=NULL;
	cin>>n;
	for(int i=0; i< n; i++){
		cin>>val;
		head=insert(head,val);
	}
	head=deleteMiddle(head);
	Print(head);
	return 0;
}