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
int kFromLast(Node *head,int k){
	Node *ptr=head;
	Node *ptr1=head;
	for(int i=0;i<k;i++){
		ptr=ptr->next;
	}
	while(ptr!=NULL){
		ptr=ptr->next;
		ptr1=ptr1->next;
	}
	
	return ptr1->data;
}
int main(){
	int n,val;
	cin>>n;
	Node *head=NULL;
		for (int i = 0; i <n; i++) {
			cin>>val;
			head=insert(head,val);
		}
	int k;
	cin>>k;
	cout<<kFromLast(head,k)<<endl;		//k>0
	//Print(head);
	return 0;
}

