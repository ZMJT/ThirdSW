#include <stack>
#include <list>
using namespace std;
class Command{												//Command类，将命令封装的接口，所有成员都是虚函数
public:

	virtual void execute()=0;
	virtual void unexecute()=0;
	virtual void reexecute()=0;
};
class AnsInputCommand : public Command{						//Command的子类，具体实现Command的功能，链表输入命令
public :	
	AnsInputCommand();
	void execute();
	void unexecute();
	void reexecute();
};
class Commander{											//Commander类，用于管理Command类
public:
	Commander();  
	Commander(Command* cmd);
	~Commander();
	void undo();
	void redo();
	void addCommand(Command* cmd);

private:
	stack<Command*> undoStk;								//私有成员，保存当前已执行并有效的所有命令
	stack<Command*> redoStk;								//私有成员，保存当前已废弃的所有指令
};
