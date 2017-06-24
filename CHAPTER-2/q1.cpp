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
typedef vector<int> vi; 
typedef pair<int,int> ii; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define modulo(a, b) (a%b<0 ? a%b+b : a%b)
/*_______________________________________________*/
struct Node{
	int data;
	Node *next;
};
/*_______________________________________________*/

/*
Node * insert(int val,Node *head){
	Node *temp=new Node();
	temp->data=val;
	temp->next=NULL;
	if(head==NULL){
		head=temp;
		return head;
	}
	Node *ptr=head;
	while(ptr->next!=NULL){
		ptr=ptr->next;
	}
	ptr->next=temp;
	return head;
}
*/


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
Node *remove_duplicates(Node *head){
	Node *i=head;
	while(i!=NULL){
		Node *j=head;
		Node *temp=head;
		while(j!=NULL){			
			if(j->data==i->data and i!=j){
				temp->next=j->next;
				free(j);
				j=temp;
			}
			temp=j;
			j=j->next;
		}
		i=i->next;
	}
	return head;
}
int main(){
	Node *head=NULL;
	int n,val;
	cin>>n;
	for(int i=0; i< n; i++){
		cin>>val;
		head=insert(head,val);
	}
	head=remove_duplicates(head);
	//remove_all(head,head);
	Print(head);
}