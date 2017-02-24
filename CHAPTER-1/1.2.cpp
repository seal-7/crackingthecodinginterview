/*
                               ____    _____      _      _               _____ 
                              / ___|  | ____|    / \    | |             |___  |
                              \___ \  |  _|     / _ \   | |      _____     / / 
                               ___) | | |___   / ___ \  | |___  |_____|   / /  
                              |____/  |_____| /_/   \_\ |_____|          /_/   
                                                                               */
#include<bits/stdc++.h>
using namespace std;
bool arr[256];
bool checkSame(string str1,string str2){
for(int i=0;i<str1.length();i++){
	arr[str1[i]]=true;
}
for(int i=0;i<str2.length();i++){
	if(!arr[str2[i]]){
		return false;
	}
}
return true;
}
	int main(){
		string str1,str2;
		cin>>str1;
		cin>>str2;
		if(str1.length()==str2.length()){
			if(checkSame(str1,str2)){
				cout<<"YES\n";
			}
			else{
				cout<<"NO\n";			
			}
		}
		else{
			cout<<"NO\n";			
		}
	}