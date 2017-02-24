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

int main(){	
	int n,val;
	cin>>n;
	vector< int > vec[n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>val;
			vec[i].push_back(val);
		}
	}
	int first,last,temp;
	for(int layer=0; layer< n/2; layer++){
		first=layer;
		last=n-1-layer;
		for(int i=first; i< last; i++){
			int offset=i-first;
			temp=vec[first][i];
			vec[first][i]=vec[last-offset][first];
			vec[last-offset][first]=vec[last][last-offset];
			vec[last][last-offset]=vec[i][last];
			vec[i][last]=temp;
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<vec[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// 4
// 1 2 3 4
// 5 6 7 8
// 9 10 11 12
// 13 14 15 16