#pragma once
#include <iostream>
#include <list>
#ifndef OBSERVER_H
#define OBSERVER_H
using namespace std;
typedef int STATE;
class Subject;
class Observer{
public:
	void Update(Subject *subj);					//֪ͨobserver״̬�����仯
protected :
	STATE obrState;						
};

#endif

class Subject{
public:
	virtual ~Subject();
	void Notify();								//֪ͨ����ı�״̬��ģʽ�ĺ���
	void Add(Observer *obr);					//��������
	void Remove(Observer *obr);					//ɾ������
	virtual void SetState(STATE sta);			//����״̬
	virtual STATE GetState();					//�õ�״̬
protected:
	STATE subjState;							//ģ�Ᵽ��subject����ı���
	list<Observer*> obrList;					//����ָ�������

};



