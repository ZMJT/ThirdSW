#include <stack>
#include <list>
using namespace std;
class Command{												//Command�࣬�������װ�Ľӿڣ����г�Ա�����麯��
public:

	virtual void execute()=0;
	virtual void unexecute()=0;
	virtual void reexecute()=0;
};
class AnsInputCommand : public Command{						//Command�����࣬����ʵ��Command�Ĺ��ܣ�������������
public :	
	AnsInputCommand();
	void execute();
	void unexecute();
	void reexecute();
};
class Commander{											//Commander�࣬���ڹ���Command��
public:
	Commander();  
	Commander(Command* cmd);
	~Commander();
	void undo();
	void redo();
	void addCommand(Command* cmd);

private:
	stack<Command*> undoStk;								//˽�г�Ա�����浱ǰ��ִ�в���Ч����������
	stack<Command*> redoStk;								//˽�г�Ա�����浱ǰ�ѷ���������ָ��
};
