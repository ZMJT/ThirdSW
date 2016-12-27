#include <list>
#pragma once 
using namespace std;
typedef int STATE;

class Observer;
class Subject{
public:
	virtual ~Subject();
	void Notify();								//֪ͨ����ı�״̬��ģʽ�ĺ���
	void Add(Observer *obr);					//��������
	void Remove(Observer *obr);					//ɾ������
	virtual void SetState(STATE sta);		//����״̬
	virtual STATE GetState();					//�õ�״̬
protected:
	STATE subjState;						//ģ�Ᵽ��subject����ı���
	list<Observer*> obrList;				//����ָ�������

};
Subject::~Subject(){							//��������
	list<Observer*>::iterator iter1, iter2,temp;
	for (iter1 = obrList.begin(), iter2 = obrList.end(); iter1 != iter2; ){
		temp = iter1;
		iter1++;
		delete(*temp);							//ɾ��������ָ������Ӧ��Ԫ��
	}
	obrList.clear();						//�������
}
void Subject::Add(Observer* obr){
	cout << "�¼���һ���۲���";
	obrList.push_back(obr);					//������β������observer��ָ��
};

void Subject::Remove(Observer *obr){
	list<Observer*>::iterator iter;					//������
	iter = std::find(obrList.begin(), obrList.end(), obr);
	if (obrList.end() != iter)
	{
		obrList.erase(iter);					//���۲��ߴ�������ɾ��
	}
	cout << "ɾ��һ���۲���\n";
};
void Subject::Notify()
{
	cout << "Notify Observers's State\n";
	list<Observer*>::iterator iter1, iter2;			//������������iter1��ǰ����˶���iter2�����һ��Ԫ�ر��־�ֹ
	for (iter1 = obrList.begin(), iter2 = obrList.end(); iter1 != iter2; ++iter1)//�������update����
	{
		(*iter1)->Update(this);
	}
};
void Subject::SetState(STATE sta){
	cout << "����״̬\n";
	subjState = sta;
};
STATE Subject::GetState(){
	cout << "����״̬";
	return subjState;
};


