//
// KObject.hpp <Keepi>
// 
// Made by	Julien Fortin
// contact	<julien.fortin.it@gmail.com>
//

#ifndef __KOBJECT_HPP__
#define	__KOBJECT_HPP__

#include	"KInteger.hpp"
#include	"KString.hpp"
#include 	"KDouble.hpp"
#include	"KBool.hpp"

class KObject
{
private:
	KObject();

	void		__init();

	KInteger*	__integer;
	KString*	__string;
	KDouble*	__double;
	KBool*		__bool;

protected:
public:
	~KObject();

	KObject(long long int);
	KObject(double);
	KObject(char *);
	KObject(bool);
	KObject(std::string);

	KInteger*		getInteger() const;
	KDouble*		getDouble() const;
	KString*		getString() const;
	KBool*			getBool() const;

	bool 			toBool() const;

	const std::string&	getType() const;

	static KObject*	add(KObject*, KObject*);
	static KObject*	sub(KObject*, KObject*);
	static KObject*	div(KObject*, KObject*);
	static KObject*	mul(KObject*, KObject*);
	static KObject*	_and(KObject*, KObject*);
	static KObject* _or(KObject*, KObject*);
	static KObject* neg(KObject*);
};

#endif /* __KOBJECT_HPP__ */