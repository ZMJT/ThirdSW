#include "Command.h"
#include <iostream>
using namespace std;
list<int > AnsList;												//�������洢��ǰ��Ч�Ĵ�	
list<int > AnsList1;											//�����������洢��ǰ�ѷ����Ĵ�
void IfUndoOrRedo(Commander* commander){						//���ú�������ѯ�Ƿ���Ҫundo/redo��ִ��
	int ifur = 0;
	cout << "�Ƿ�Undo/Redo��Undo����1��Redo����2����������0" << endl;
	cin >> ifur;
	if (ifur == 1){
		cout << "undo" << endl;
		commander->undo();										//ִ��undo
	}
	else if (ifur == 2){
		cout << "redo" << endl;
		commander->redo();										//ִ��redo
	}
	else return;
		IfUndoOrRedo(commander);								//�ݹ����
	return;
}; 
void showAnswer(){												//��ӡ��ǰAnsList������Ԫ��
	cout << "���ڵ����д���" << endl;
	list<int>::iterator iter;
	for (iter = AnsList.begin(); iter != AnsList.end(); iter++){
		cout << *iter << " ";
	}
	cout << endl;
}
void showA(){													//��ӡ��ǰAnsList1������Ԫ��
	cout << "���ڵ����з�������" << endl;
	list<int>::iterator iter;
	for (iter = AnsList1.begin(); iter != AnsList1.end(); iter++){
		cout << *iter << " ";
	}
	cout << endl;
}
int getAnsNum(){												//����AnsList��Ԫ�ظ���
	return AnsList.size();
}

int main(){													
	//UndoRedo
	//2016.12.10
	Commander* cmder = new Commander();							//�������Commander
	cout << "����ʱ�䵽"<< endl;
	cout << "������ģ��Ϊѡ����ģ�飬��ʮ���⣬ÿ���ĸ�ѡ��" << endl;
	cout << "��ֱ���1��2��3��4��ӦA��B��C��D�ĸ�ѡ��" << endl;
	for (int Num = 0; Num < 10;){
		AnsInputCommand* acmd = new AnsInputCommand();
		cout << "��" <<Num+1 << "��" << endl;
		cout << "balabala" << endl;	
		cmder->addCommand(acmd);								//��acmd����Commander����ִ��
		showAnswer();											
		showA();												
		IfUndoOrRedo(cmder);									//���ú���
		Num = AnsList.size();									//��ȡ��ǰ�Ѵ���ĸ���
	}
	cout << "���Խ���" << endl;
	system("pause");
	return 1;
}