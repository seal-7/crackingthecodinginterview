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
bool check(string str,string str1){
	if(str.length()==str1.length()+1){
		int i=0,j=0;
		while(i<str.length()){
			if(str1[j]==str[i]){
				i++;
				j++;
			}
			else{
				i++;
			}
		}
		if(j==str1.length()){
			return true;
		}
	}
	else if(str1.length()==str.length()+1){
		int i=0,j=0;
		while(i<str1.length()){
			if(str[j]==str1[i]){
				i++;
				j++;
			}
			else{
				i++;
			}
		}
		if(j==str.length()){
			return true;
		}
	}
	else{
		int i=0;
		bool flag=false;
		while(i<str.length()){
			if(flag and str[i]!=str1[i])
				return false;
			if(!flag and str[i]!=str1[i])
				flag=true;			
			i++;
		}
		if(i==str.length())
		return true;
	}
	return false;
}
int main(){
	string str,str1;
    cin>>str>>str1;
    if(check(str,str1)){
    	cout<<"true\n";
    }
    else{
    	cout<<"false\n";
    }
	return 0;
}