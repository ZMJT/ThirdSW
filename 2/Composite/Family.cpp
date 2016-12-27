#include "Family.h"
#include <iostream>
using namespace std;
Family::Family(){}
//Member的函数实现
Member::Member(){}

Member::~Member(){}

void Member::Operation(){
	cout << "年龄是"<< Age << endl;
	if (ifSingle)
		cout << "恩爱" << endl;
	else cout << "汪汪！" << endl;
	return;
};

Member::Member(int age, int ifsng){
	Age = age;
	ifSingle = ifsng;
}
//Married的函数实现
Married::Married(){}

void Married::Operation(){
	cout << "下面是一个家庭" << endl;
	list<Family*>::iterator iter1;
	for (iter1 = listFamily.begin(); iter1 != listFamily.end();iter1++){
		(*iter1)->Operation();
	}
};

void Married::Add(Family* fam){
	if (fam != NULL){
		cout << "加入一个新成员" << endl;
		listFamily.push_back(fam);
	}
	else return;
	return;
};
/*
void Married::Remove(Family* fam){
	cout << "失去一个成员" << endl;
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


