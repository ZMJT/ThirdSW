#include <iostream>
#include "Family.h"
#define SINGLE 0
#define MARRIED 1
using namespace std;
Member* CreateMember(){								//新建一个Member对象
	cout << "新建一个Member对象，输入一个单身狗的年龄" << endl;
	int age;
	cin >> age;
	Member* mem1 = new Member(age, SINGLE);
	return mem1;
}
Married* CreateMarried(){							//新建一个Married对象
	cout << "新建一个Married对象，输入一个家庭两位家长的年龄，两名成员" << endl;
	int age1, age2;
	cin >> age1 >> age2;
	Member* mem1 = new Member(age1, MARRIED);		//调用Married重载构造函数
	Member* mem2 = new Member(age2, MARRIED);
	Married* mar1=new Married() ;					
	mar1->Add(mem1);								//将两个变量放入链表
	mar1->Add(mem2);
	cout << "家长创建完成，请问是否有孩子？有则输入1，无则输入0" << endl;
	int ifhvch;
	cin >> ifhvch;
	if (ifhvch == 0)								
		return mar1;								//0表示该家庭暂时无孩子，直接结束创建，并返回链表位置
	else {
		cout << "孩子是否婚配，是则输入1，否则输入0" << endl;
		int ifsng1;
		cin >> ifsng1;								//是否单身
		if (ifsng1 == 0)							
			mar1->Add(CreateMember());				//将Member对象指针放入mar1
		else mar1->Add(CreateMarried());			//将Married链表头位置放入mar1
	}
	return mar1;
};
int main(){
	//Composite 
	//2016.12.7
	cout << "欢迎来到家族系统" << endl;
	cout << "新建一个家族" << endl;
	cout << "方便起见，本系统只采录人物的年龄和婚否" << endl;
	cout << "均用int型变量来表示，其中0表示未婚，1表示已婚" << endl;
	Married* XMarried = new Married();
	cout << "按1开始" << endl;
	int IfConTn;											
	cin >> IfConTn;
	while (IfConTn)
	{
		cout << "新对象婚否" << endl;
		int ifsng;										//婚否
		cin >> ifsng;
		if (ifsng == 0){
			XMarried->Add(CreateMember());
		}
		else if (ifsng == 1){
			XMarried->Add(CreateMarried());
		}
		cout << "选择是否继续新建对象，1表示继续，0表示终止" << endl;
		cin >> IfConTn;
	}
	XMarried->ShowMember();
	return 1;
};


