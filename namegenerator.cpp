#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cstring>
#include <string>
using namespace std;
char letterin(string letters){
	int n = rand() % letters.size();
	return letters.at(n);
};
char nextletter(char prev){
	if(prev == 'a'){
	return letterin("bcdfgjklmnpqrstvxz");
	}	
	else if(prev == 'b'){
	return letterin("aeiloru");
	}	
	else if(prev == 'c'){
	return letterin("ahikloru");
	}	
	else if(prev == 'd'){
	return letterin("aeioru");
	}	
	else if(prev == 'e'){
	return letterin("abcdefglmnpqrvx");
	}	
	else if(prev == 'f'){
	return letterin("aeiloru");
	}	
	else if(prev == 'g'){
	return letterin("aeiloru");
	}	
	else if(prev == 'h'){
	return letterin("aeiou");
	}	
	else if(prev == 'i'){
	return letterin("abcdfglmnrt");
	}
	else if(prev == 'j'){
	return letterin("aeiouy");
	}	
	else if(prev == 'k'){
	return letterin("aeioruwy");
	}	
	else if(prev == 'l'){
	return letterin("aeiouy");
	}	
	else if(prev == 'm'){
	return letterin("aeiouy");
	}	
	else if(prev == 'n'){
	return letterin("aeiou");
	}	
	else if(prev == 'o'){
	return letterin("abcdfgiklmnoprstuvwxy");
	}	
	else if(prev == 'p'){
	return letterin("aeiloruy");
	}	
	else if(prev == 'q'){
	return letterin("u");
	}	
	else if(prev == 'r'){
	return letterin("aeiouy");
	}	
	else if(prev == 's'){
	return letterin("acehiklmnopqstuw");
	}	
	else if(prev == 't'){
	return letterin("aehioruwy");
	}	
	else if(prev == 'u'){
	return letterin("bcdgklmnprstvx");
	}	
	else if(prev == 'v'){
	return letterin("aeiouy");
	}	
	else if(prev == 'w'){
	return letterin("aehioruy");
	}	
	else if(prev == 'x'){
	return letterin("aceioxy");
	}	
	else if(prev == 'y'){
	return letterin("aeiou");
	}	
	else if(prev == 'z'){
	return letterin("aeiou");
	}
	else return 'a';	
};
/*
int endname(int length){
	double r = (double)rand() / RAND_MAX;
	if(length==1) return 0;
	else if(length==2) return 0;
	else if(length==3) return 0;
	else if(length==4) return r <0.3;
	else if(length==5) return r <0.35;
	else if(length==6) return r <0.4;
	else if(length==7) return r <0.45;
	else if(length==8) return r <0.5;
	else if(length==9) return r <0.6;
	else if(length==10) return r <0.7;
	else return 1;
};
*/
string randname(){
	int n = rand() % 6 + 4;	
	char name[n];
	name[0] = letterin("abcdefghijklmnopqrstuvwxyz");
	for(int i = 1; i<n; i++){
		name[i] = nextletter(name[i-1]);
	};
	name[n] = '\0';
	return name;
};
string randlast(){
	int n = rand() % 6 + 6;	
	char name[n];
	name[0] = letterin("abcdefghijklmnopqrstuvwxyz");
	for(int i = 1; i<n; i++){
		name[i] = nextletter(name[i-1]);
	};
	name[n] = '\0';
	return name;
};
string givenfirst(){
	char first;
	cin >> first;
	int n = rand() % 6 + 4;	
	char name[n];
	name[0] = first;
	for(int i = 1; i<n; i++){
		name[i] = nextletter(name[i-1]);
	};
	name[n] = '\0';
	return name;
};
int generatenames(){
	srand (time(NULL));
	cout << "how many names do you want? ";
	int num;
	cin >> num;
	cout << endl;
	for(int i = 0; i < num; i++){
	cout << randname() << endl;
	}
	return 0;
}
