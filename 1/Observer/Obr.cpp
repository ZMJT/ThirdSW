#include "Obr.h"
Subject::~Subject(){							//��������
	list<Observer*>::iterator iter1, iter2, temp;
	for (iter1 = obrList.begin(), iter2 = obrList.end(); iter1 != iter2;){
		temp = iter1;
		iter1++;
		delete(*temp);							//ɾ��������ָ������Ӧ��Ԫ��
	}
	obrList.clear();						//�������
}
void Subject::Add(Observer* obr){
	cout << "�¼���һ���۲���"<<endl;
	obrList.push_back(obr);					//������β������observer��ָ��
};

void Subject::Remove(Observer *obr){
	list<Observer*>::iterator iter;					//������
	iter = std::find(obrList.begin(), obrList.end(), obr);
	if (obrList.end() != iter)
	{
		obrList.erase(iter);					//���۲��ߴ�������ɾ��
	}
	cout << "ɾ��һ���۲���"<<endl;
};
void Subject::Notify()
{
	cout << "Notify Observers's State"<<endl;
	list<Observer*>::iterator iter1, iter2;			//������������iter1��ǰ����˶���iter2�����һ��Ԫ�ر��־�ֹ
	for (iter1 = obrList.begin(), iter2 = obrList.end(); iter1 != iter2; ++iter1)//�������update����
	{
		(*iter1)->Update(this);
	}
};
void Subject::SetState(STATE sta){
	cout << "����״̬"<<endl;
	subjState = sta;
};
STATE Subject::GetState(){
	cout << "����״̬"<<endl;
	return subjState;
};
void Observer::Update(Subject* subj){
	if (subj == NULL)
		return;
	obrState = subj->GetState();
	cout << "�۲��ߵ�״̬��" << obrState << endl;
}