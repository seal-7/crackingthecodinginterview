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
int add_recur(Node *s1,Node *s2,Node *sum){
	if(s1->next==NULL and s2->next==NULL){
		int ans=s1->data+s2->data;
		if(ans/10==1){
			sum->data=ans%10;
			return 1;
		}
		else{
			sum->data=ans;
			return 0;
		}
	}
	int carry=add_recur(s1->next,s2->next,sum->next);
	sum->data=(carry + s1->data + s2->data);
	if(sum->data/10==1){
		sum->data=(sum->data)%10;
		return 1;
	}
	return 0;
}
Node *add(Node *s1,Node *s2,Node *sum){
	if(s1==NULL){
		return s2;
	}
	if(s2==NULL){
		return s1;
	}
	int carry=add_recur(s1,s2,sum);
	if(carry==1){
		Node *extra=new Node;
		extra->data=1;
		extra->next=sum;
		return extra;
	}
	return sum;
}

int main(){
	Node *s1=NULL;
	Node *s2=NULL;
	Node *sum=NULL;
	int n,val;
	cin>>n;
	for(int i=0; i< n; i++){
		cin>>val;
		s1=insert(s1,val);
	}
	for(int i=0; i< n; i++){
		cin>>val;
		s2=insert(s2,val);
		sum=insert(sum,0);
	}
	sum=add(s1,s2,sum);
	Print(sum);
	return 0;
}