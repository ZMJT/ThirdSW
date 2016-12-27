#include <iostream>
#include <list>
#include "Obr.h"
using namespace std;
int main(){
	//Observer start; 
	//2016.11.28
	Observer *obr1 = new Observer;
	Observer *obr2 = new Observer;
	Subject *sub1 = new Subject;
	sub1->Add(obr1);
	sub1->Add(obr2);
	sub1->SetState(6);
	sub1->Notify();
	delete sub1;
	system("pause");
	return 1;
}