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

int main(){
	int m,n;
	cin>>m>>n;
	int b[m][n],a[m][n];
	for(int i=0; i< m; i++){
		for(int j=0; j< n; j++){
			a[i][j]=1;
		}
	}	
	for(int i=0; i< m; i++){
		for(int j=0; j< n; j++){
			cin>>b[i][j];
		}
	}
	for(int i=0; i< m; i++){
		for(int j=0; j< n; j++){
			if(b[i][j]==0){
				for(int k=0; k< m; k++){
					a[k][j]=0;
				}
				for(int k=0; k< n; k++){
					a[i][k]=0;
				}
			}
		}
	}
	for(int i=0; i< m; i++){
		for(int j=0; j< n; j++){
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}