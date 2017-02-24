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
	int n;
	cin>>n;
	string str;
	cin>>ws;
	getline(cin,str);
	int space=0;
	for(int i=0; i< n-1; i++){
		if(str[i]==' ')
			space++;
	}
	int i=str.length()-2,j=str.length()-1;
	while(str[i]==' '){
		i--;
	}
	while(i>=0){
		if(str[i]==' '){
			str[j]='0';
			str[j-1]='2';
			str[j-2]='%';
			j-=3;
			i--;
		}
		else{
			str[j]=str[i];
			j--;
			i--;
		}
	}
	cout<<str<<endl;
	return 0;
}