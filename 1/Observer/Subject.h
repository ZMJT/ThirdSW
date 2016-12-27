#include <list>
#pragma once 
using namespace std;
typedef int STATE;

class Observer;
class Subject{
public:
	virtual ~Subject();
	void Notify();								//通知对象改变状态，模式的核心
	void Add(Observer *obr);					//新增对象
	void Remove(Observer *obr);					//删除对象
	virtual void SetState(STATE sta);		//设置状态
	virtual STATE GetState();					//得到状态
protected:
	STATE subjState;						//模拟保存subject对象的变量
	list<Observer*> obrList;				//保存指针的链表

};
Subject::~Subject(){							//析构函数
	list<Observer*>::iterator iter1, iter2,temp;
	for (iter1 = obrList.begin(), iter2 = obrList.end(); iter1 != iter2; ){
		temp = iter1;
		iter1++;
		delete(*temp);							//删除链表中指针所对应的元素
	}
	obrList.clear();						//清空链表
}
void Subject::Add(Observer* obr){
	cout << "新加入一个观察者";
	obrList.push_back(obr);					//在链表尾部加入observer的指针
};

void Subject::Remove(Observer *obr){
	list<Observer*>::iterator iter;					//迭代器
	iter = std::find(obrList.begin(), obrList.end(), obr);
	if (obrList.end() != iter)
	{
		obrList.erase(iter);					//将观察者从链表中删除
	}
	cout << "删除一个观察者\n";
};
void Subject::Notify()
{
	cout << "Notify Observers's State\n";
	list<Observer*>::iterator iter1, iter2;			//两个迭代器，iter1从前向后运动，iter2在最后一个元素保持静止
	for (iter1 = obrList.begin(), iter2 = obrList.end(); iter1 != iter2; ++iter1)//逐个调用update函数
	{
		(*iter1)->Update(this);
	}
};
void Subject::SetState(STATE sta){
	cout << "设置状态\n";
	subjState = sta;
};
STATE Subject::GetState(){
	cout << "返回状态";
	return subjState;
};


