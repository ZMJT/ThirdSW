#include "Family.h"
#include <iostream>
using namespace std;
Family::Family(){}
//Member�ĺ���ʵ��
Member::Member(){}

Member::~Member(){}

void Member::Operation(){
	cout << "������"<< Age << endl;
	if (ifSingle)
		cout << "����" << endl;
	else cout << "������" << endl;
	return;
};

Member::Member(int age, int ifsng){
	Age = age;
	ifSingle = ifsng;
}
//Married�ĺ���ʵ��
Married::Married(){}

void Married::Operation(){
	cout << "������һ����ͥ" << endl;
	list<Family*>::iterator iter1;
	for (iter1 = listFamily.begin(); iter1 != listFamily.end();iter1++){
		(*iter1)->Operation();
	}
};

void Married::Add(Family* fam){
	if (fam != NULL){
		cout << "����һ���³�Ա" << endl;
		listFamily.push_back(fam);
	}
	else return;
	return;
};
/*
void Married::Remove(Family* fam){
	cout << "ʧȥһ����Ա" << endl;
	list<Family *>::iterator iter;
	iter = find(listFamily.begin(), listFamily.end(), fam);
	if (listFamily.end() != iter)
		listFamily.erase(iter);
};
*/
void  Married::ShowMember(){
	list<Family *>::iterator iter1;
	for (iter1 = listFamily.begin(); iter1!= listFamily.end();iter1++){
		(*iter1)->Operation();
		}
	system("pause");
};


