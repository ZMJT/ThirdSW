#include "Obr.h"
Subject::~Subject(){							//析构函数
	list<Observer*>::iterator iter1, iter2, temp;
	for (iter1 = obrList.begin(), iter2 = obrList.end(); iter1 != iter2;){
		temp = iter1;
		iter1++;
		delete(*temp);							//删除链表中指针所对应的元素
	}
	obrList.clear();						//清空链表
}
void Subject::Add(Observer* obr){
	cout << "新加入一个观察者"<<endl;
	obrList.push_back(obr);					//在链表尾部加入observer的指针
};

void Subject::Remove(Observer *obr){
	list<Observer*>::iterator iter;					//迭代器
	iter = std::find(obrList.begin(), obrList.end(), obr);
	if (obrList.end() != iter)
	{
		obrList.erase(iter);					//将观察者从链表中删除
	}
	cout << "删除一个观察者"<<endl;
};
void Subject::Notify()
{
	cout << "Notify Observers's State"<<endl;
	list<Observer*>::iterator iter1, iter2;			//两个迭代器，iter1从前向后运动，iter2在最后一个元素保持静止
	for (iter1 = obrList.begin(), iter2 = obrList.end(); iter1 != iter2; ++iter1)//逐个调用update函数
	{
		(*iter1)->Update(this);
	}
};
void Subject::SetState(STATE sta){
	cout << "设置状态"<<endl;
	subjState = sta;
};
STATE Subject::GetState(){
	cout << "返回状态"<<endl;
	return subjState;
};
void Observer::Update(Subject* subj){
	if (subj == NULL)
		return;
	obrState = subj->GetState();
	cout << "观察者的状态是" << obrState << endl;
}