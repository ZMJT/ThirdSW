#include <list>
using namespace std;
class Family{
public:
	virtual void Operation()=0;
	virtual void Add(Family* fam){}
//	virtual void Remove(Family*);
//	virtual	Family* GetChild(int depth);
protected:
	Family();
};
class Member:public Family{
public :
	Member();
	~Member();
	void Operation();
	Member(int age, int ifsng);
protected:
	int Age;
	int ifSingle;
};
class Married:public Family{
public :
	Married();
	~Married();
	void Operation() ;
	void Add(Family* fam);
//	void Remove(Family*);
	void ShowMember();
protected:
	list<Family*> listFamily;
};