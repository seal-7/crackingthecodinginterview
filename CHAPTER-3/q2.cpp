/*
 ____    _____      _      _               _____ 
/ ___|  | ____|    / \    | |             |___  |
\___ \  |  _|     / _ \   | |      _____     / / 
 ___) | | |___   / ___ \  | |___  |_____|   / /  
|____/  |_____| /_/   \_\ |_____|          /_/   
*/

#include <bits/stdc++.h>
using namespace std;

#typedef long long ll;
#typedef unsigned long long ull;
#typedef vector<int> vi; 
#typedef pair<int,int> ii; 
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
#define PUSH 1
#define POP 2
#define GET_MIN 3
int main(){
	list<int> stack;
	list<int> stack_min;
	int n;
	cin>>n;
	int query;					//1 FOR PUSH,2 FOR POP,3 FOR GET_MIN()
	for(int i=0;i<n;i++){
		cin>>query;
		if(query==PUSH){
			int val;
			cin>>val;
			if(stack.empty()){
				stack.push_back(val);
				stack_min.push_back(val);
			}
			else{
				stack.push_back(val);
				if(val<stack_min.back()){
					stack_min.push_back(val);
				}
				else{
					stack_min.push_back(stack_min.back());
				}
			}
		}
		else if(query==POP){
			if(!stack.empty() and !stack_min.empty()){
				stack.pop_back();
				stack_min.pop_back();
			}
		}
		else{
			if(!stack_min.empty())
				cout<<stack_min.back()<<endl;
		}
	}
	return 0;
}
