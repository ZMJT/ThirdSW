#include "Command.h"
#include <iostream>
using namespace std;
list<int > AnsList;												//答案链表，存储当前有效的答案	
list<int > AnsList1;											//废弃答案链表，存储当前已废弃的答案
void IfUndoOrRedo(Commander* commander){						//调用函数，问询是否需要undo/redo并执行
	int ifur = 0;
	cout << "是否Undo/Redo？Undo输入1，Redo输入2，否则输入0" << endl;
	cin >> ifur;
	if (ifur == 1){
		cout << "undo" << endl;
		commander->undo();										//执行undo
	}
	else if (ifur == 2){
		cout << "redo" << endl;
		commander->redo();										//执行redo
	}
	else return;
		IfUndoOrRedo(commander);								//递归调用
	return;
}; 
void showAnswer(){												//打印当前AnsList的所有元素
	cout << "现在的所有答案是" << endl;
	list<int>::iterator iter;
	for (iter = AnsList.begin(); iter != AnsList.end(); iter++){
		cout << *iter << " ";
	}
	cout << endl;
}
void showA(){													//打印当前AnsList1的所有元素
	cout << "现在的所有废弃答案是" << endl;
	list<int>::iterator iter;
	for (iter = AnsList1.begin(); iter != AnsList1.end(); iter++){
		cout << *iter << " ";
	}
	cout << endl;
}
int getAnsNum(){												//返回AnsList的元素个数
	return AnsList.size();
}

int main(){													
	//UndoRedo
	//2016.12.10
	Commander* cmder = new Commander();							//本程序的Commander
	cout << "考试时间到"<< endl;
	cout << "本考试模块为选择题模块，共十道题，每题四个选项" << endl;
	cout << "请分别用1，2，3，4对应A，B，C，D四个选项" << endl;
	for (int Num = 0; Num < 10;){
		AnsInputCommand* acmd = new AnsInputCommand();
		cout << "第" <<Num+1 << "题" << endl;
		cout << "balabala" << endl;	
		cmder->addCommand(acmd);								//将acmd放入Commander，并执行
		showAnswer();											
		showA();												
		IfUndoOrRedo(cmder);									//调用函数
		Num = AnsList.size();									//读取当前已答题的个数
	}
	cout << "考试结束" << endl;
	system("pause");
	return 1;
}