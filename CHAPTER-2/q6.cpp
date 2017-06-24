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
struct Capsule
{
	bool value;
	Node *node;
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

Capsule *checkPalindrome(Node *head,Node *tail){
	if(head==NULL){
		Capsule *temp=new Capsule;
		temp->value=false;
		temp->node=NULL;
		return temp;
	}
	if(tail->next==NULL){	
		if(head->data==tail->data){
			Capsule *cap=new Capsule;
			cap->value=true;
			cap->node=head->next;
			return cap;
		}
		else{
			Capsule *cap=new Capsule;
			cap->value=false;
			cap->node=NULL;
			return cap;	
		}
	}
	Capsule *returned_cap=checkPalindrome(head,tail->next);
	Capsule *temp=new Capsule;
	if(returned_cap->value){		
		if(returned_cap->node->data==tail->data){			
			temp->value=true;
			temp->node=returned_cap->node->next;
			return temp;
		}
	}
	temp->value=false;
	temp->node=NULL;
	return temp;
}
int main(){
	Node *head=NULL;
	int n,val;
	cin>>n;
	for(int i=0; i< n; i++){
		cin>>val;
		head=insert(head,val);
	}
	cout<<checkPalindrome(head,head)->value;
	return 0;
}