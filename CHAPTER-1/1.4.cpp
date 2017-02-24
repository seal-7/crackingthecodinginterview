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
bool isPermutation(string str,string str1){
vector<int> vec(130,0);
vector<int> vec1(130,0);
	for(int i=0; i< str.size(); i++){
		vec[str[i]]++;
	}
	for(int i=0; i< str1.length(); i++){
		vec1[str1[i]]++;
	}
	
	for(int i=0; i< 128; i++){
		if(vec[i]!=vec1[i])
			return false;
	}
	return true;
}
int main(){
	string str;
	string str1;
	getline(cin,str);
	getline(cin,str1);
	if(isPermutation(str,str1)){
		cout<<"TRUE\n";
	}
	else{
		cout<<"FALSE\n";
	}
	return 0;
}