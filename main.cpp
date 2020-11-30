#include <iostream>
#include "namegenerator.cpp"
#include "Student.h"
#include <cmath>
using namespace std;
// I have a file called namegenerator.cpp which has functions randname() and randlast() which generate a first and last name (char array) in slightly different ways.
//prototypes:
int hashfunction(int);
void add(Student*);
void del(int);
void print();
//init hash table
int size = 100;
Student* hashtable[100];
// You can hash just using ID % size, but this seems like cheating...
int hashfunction(int ID){
	return ID % size;
};
// Add: takes in student, gets hash, goes to that spot in the table, goes down the linked list and puts the new student at the end.
void add(Student * stud){
	int spot = hashfunction(stud->ID);
	Student * current = hashtable[spot];
	if(current == NULL){
		hashtable[spot] = stud;
		hashtable[spot]->next = NULL;
	} 
	else{
	while(current->next != NULL){
		current = current->next;
	}
	current->next = stud;
	current->next->next = NULL;
	}
};
// Delete: basically does the same thing as add, except when it gets to stud it makes the chain go around it and then removes it. It removes every student with that ID.
void del(int ID){
	int spot = hashfunction(ID);
	Student * current = hashtable[spot];
	if(current == NULL){
		cout <<"No such student!" << endl;
	}
	else if(current->next == NULL){
		if(current->ID == ID){
			hashtable[spot] = NULL;
		}
	}
	else{
	while(current->next != NULL){
		if(current->next->ID == ID){
			if(current->next->next != NULL){
				current->next = current->next->next;
			}
			else current->next = NULL;
		};
		current = current->next;
	}
	}
};
void print(){
	for(int i = 0; i < size; i++){
		Student * current = hashtable[i];
		while(current != NULL){
			cout << current->first << " " << current->last << ", " << current->ID << ", " << current->GPA << endl;
			current = current->next;
		};
	};
};
int main(){
	//enter loop
	bool quit = false;
	while(quit == false){
	cout << "What would you like to do? Add (A), Delete (D), Print (P), or generate Random students (R). Or Quit (Q)." << endl;
	char response;
	cin >> response;
	if(response == 'A'){
		cout << "First name: ";
		string f;
		cin >> f;
		cout << "Last name: ";
		string l;
		cin >> l;
		cout << "ID: ";
		int ID;
		cin >> ID;
		cout << "GPA: ";
		double GPA;
		cin >> GPA;
		Student * newstud = new Student();
		newstud->first = f;
		newstud->last = l;
		newstud->ID = ID;
		newstud->GPA = GPA;
		add(newstud);
	}
	else if(response == 'D'){
		cout << "ID: ";
		int ID;
		cin >> ID;
		del(ID);
	}
	else if(response == 'P'){
		print();
	}
	else if(response == 'R'){
		cout << "How many students should I generate? ";
		int studnum;
		cin >> studnum;
		for(int i = 0; i < studnum; i++){
			string first = randname();
			string last = randlast();
			int ID = i+1;
			double GPA = 4 * (rand() / RAND_MAX);
			Student * newstud = new Student();
			newstud->first = first;
			newstud->last = last;
			newstud->ID = ID;
			newstud->GPA = GPA;
			add(newstud);
		};
	}
	else quit = true;
	};
	return 0;
}
