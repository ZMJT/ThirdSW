#include <iostream>
#include "Family.h"
#define SINGLE 0
#define MARRIED 1
using namespace std;
Member* CreateMember(){								//�½�һ��Member����
	cout << "�½�һ��Member��������һ������������" << endl;
	int age;
	cin >> age;
	Member* mem1 = new Member(age, SINGLE);
	return mem1;
}
Married* CreateMarried(){							//�½�һ��Married����
	cout << "�½�һ��Married��������һ����ͥ��λ�ҳ������䣬������Ա" << endl;
	int age1, age2;
	cin >> age1 >> age2;
	Member* mem1 = new Member(age1, MARRIED);		//����Married���ع��캯��
	Member* mem2 = new Member(age2, MARRIED);
	Married* mar1=new Married() ;					
	mar1->Add(mem1);								//������������������
	mar1->Add(mem2);
	cout << "�ҳ�������ɣ������Ƿ��к��ӣ���������1����������0" << endl;
	int ifhvch;
	cin >> ifhvch;
	if (ifhvch == 0)								
		return mar1;								//0��ʾ�ü�ͥ��ʱ�޺��ӣ�ֱ�ӽ�������������������λ��
	else {
		cout << "�����Ƿ���䣬��������1����������0" << endl;
		int ifsng1;
		cin >> ifsng1;								//�Ƿ���
		if (ifsng1 == 0)							
			mar1->Add(CreateMember());				//��Member����ָ�����mar1
		else mar1->Add(CreateMarried());			//��Married����ͷλ�÷���mar1
	}
	return mar1;
};
int main(){
	//Composite 
	//2016.12.7
	cout << "��ӭ��������ϵͳ" << endl;
	cout << "�½�һ������" << endl;
	cout << "�����������ϵͳֻ��¼���������ͻ��" << endl;
	cout << "����int�ͱ�������ʾ������0��ʾδ�飬1��ʾ�ѻ�" << endl;
	Married* XMarried = new Married();
	cout << "��1��ʼ" << endl;
	int IfConTn;											
	cin >> IfConTn;
	while (IfConTn)
	{
		cout << "�¶�����" << endl;
		int ifsng;										//���
		cin >> ifsng;
		if (ifsng == 0){
			XMarried->Add(CreateMember());
		}
		else if (ifsng == 1){
			XMarried->Add(CreateMarried());
		}
		cout << "ѡ���Ƿ�����½�����1��ʾ������0��ʾ��ֹ" << endl;
		cin >> IfConTn;
	}
	XMarried->ShowMember();
	return 1;
};


