/*
                               ____    _____      _      _               _____ 
                              / ___|  | ____|    / \    | |             |___  |
                              \___ \  |  _|     / _ \   | |      _____     / / 
                               ___) | | |___   / ___ \  | |___  |_____|   / /  
                              |____/  |_____| /_/   \_\ |_____|          /_/   
                                                                               */
#include<bits/stdc++.h>
using namespace std;
bool isUnique(string str){
	int checker=0;
	for(int i=0;i<str.length();i++){
		int val=str[i]-'a';
		if((checker&(1<<val))>0){
			return false;
		}
		checker|=(1<<val);
	}
	return true;
}
	int main(){
		string str;
		cin>>str;
		if(isUnique(str)){
			cout<<"UNIQUE\n";
		}
		else{
			cout<<"NOT UNIQUE\n";
		}
	}