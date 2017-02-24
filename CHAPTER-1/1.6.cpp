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
	string str;
	cin>>str;
	int val=0;
	string newstr="",temp="";
	stringstream ss;
	for(int i=0; i< str.length()-1; i++){
		if(str[i]==str[i+1]){
			val++;
		}
		else{
			ss<<val+1;
			ss>>temp;
			ss.clear();
            newstr+=str[i]+temp;
            val=0;
		}
	}

		newstr+=(str[str.length()-1]);
		ss<<val+1;
		ss>>temp;
		ss.clear();
		newstr+=temp;
	cout<<newstr<<endl;
	return 0;
}