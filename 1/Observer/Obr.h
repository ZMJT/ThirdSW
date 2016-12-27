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
	void Update(Subject *subj);					//通知observer状态发生变化
protected :
	STATE obrState;						
};

#endif

class Subject{
public:
	virtual ~Subject();
	void Notify();								//通知对象改变状态，模式的核心
	void Add(Observer *obr);					//新增对象
	void Remove(Observer *obr);					//删除对象
	virtual void SetState(STATE sta);			//设置状态
	virtual STATE GetState();					//得到状态
protected:
	STATE subjState;							//模拟保存subject对象的变量
	list<Observer*> obrList;					//保存指针的链表

};



