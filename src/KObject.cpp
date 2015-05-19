//
// KObject.cpp <Keepi>
// 
// Made by	Julien Fortin
// contact	<julien.fortin.it@gmail.com>
//

#include "DEBUG.h"

#include	"KObject.hpp"
#include	"KTypeException.hpp"

KObject::KObject(long long int integer)
{
	this->__init();
	this->__integer = new KInteger(integer);
}

KObject::KObject(double real)
{
	this->__init();
	this->__double = new KDouble(real);
}

KObject::KObject(char *str)
{
	size_t len = strlen(str);
	str[len - 1] = 0;

	this->__init();
	this->__string = new KString(str);
}

KObject::KObject(std::string str)
{
	this->__init();
	this->__string = new KString(str);
}

KObject::KObject(bool b)
{
	this->__init();
	this->__bool = new KBool(b);
}

KObject::~KObject()
{
	delete this->__integer;
	delete this->__string;
	delete this->__double;
	delete this->__bool;
}

void	KObject::__init()
{
	this->__integer = 0;
	this->__string 	= 0;
	this->__double	= 0;
	this->__bool 	= 0;
}

KInteger*	KObject::getInteger() const { return this->__integer; }
KString*	KObject::getString() const { return this->__string; }
KDouble*	KObject::getDouble() const { return this->__double; }
KBool*		KObject::getBool() const { return this->__bool; }

const std::string&	KObject::getType() const
{
	if (this->getInteger())
		return this->getInteger()->getType();
	else if (this->getString())
		return this->getString()->getType();
	else if (this->getDouble())
		return this->getDouble()->getType();
	else if (this->getBool())
		return this->getBool()->getType();
	throw KTypeException("TypeInternalError: Empty interface KObject.");
}

bool 			KObject::toBool() const
{
	if (this->getInteger())
		return this->getInteger()->toBool();
	else if (this->getString())
		return this->getString()->toBool();
	else if (this->getDouble())
		return this->getDouble()->toBool();
	else if (this->getBool())
		return this->getBool()->getValue();
	throw KTypeException("TypeInternalError: Empty interface KObject.");}

KObject*	KObject::add(KObject* obj1, KObject* obj2)
{
	KInteger*	integer1 = obj1->getInteger();
	KInteger*	integer2 = obj2->getInteger();

	KDouble*	double1 = obj1->getDouble();
	KDouble*	double2	= obj2->getDouble();

	KString*	string1 = obj1->getString();
	KString*	string2 = obj2->getString();

	KBool*		bool1 = obj1->getBool();
	KBool*		bool2 = obj2->getBool();

	if (integer1 && integer2)
		return new KObject(*integer1 + *integer2);
	else if (integer1 && double2)
		return new KObject(*integer1 + *double2);
	else if (integer1 && string2)
		return new KObject(*integer1 + *string2);
	else if (integer2 && double2)
		return new KObject(*integer1 + *bool2);
	else if (double1 && double2)
		return new KObject(*double1 + *double2);
	else if (double1 && integer2)
		return new KObject(*double1 + *integer2);
	else if (double1 && string2)
		return new KObject(*double1 + *string2);
	else if (double1 && bool2)
		return new KObject(*double1 + *bool2);
	else if (string1 && string2)
		return new KObject(*string1 + *string2);
	else if (string1 && integer2)
		return new KObject(*string1 + *integer2);
	else if (string1 && double2)
		return new KObject(*string1 + *double2);
	else if (string1 && bool2)
		return new KObject(*string1 + *bool2);
	else if (bool1 && bool2)
		return new KObject(*bool1 + *bool2);
	else if (bool1 && integer2)
		return new KObject(*bool1 + *integer2);
	else if (bool1 && double2)
		return new KObject(*bool1 + *double2);
	else if (bool1 && string2)
		return new KObject(*bool1 + *string2);
	throw KTypeException("TypeError: unsupported operand type(s) for +");
}

KObject*	KObject::sub(KObject* obj1, KObject* obj2)
{
	KInteger*	integer1 = obj1->getInteger();
	KInteger*	integer2 = obj2->getInteger();

	KDouble*	double1 = obj1->getDouble();
	KDouble*	double2	= obj2->getDouble();

	if (integer1 && integer2)
		return new KObject(*integer1 - *integer2);
	else if (integer1 && double2)
		return new KObject(*integer1 - *double2);
	else if (double1 && double2)
		return new KObject(*double1 - *double2);
	else if (double1 && integer2)
		return new KObject(*double1 - *integer2);
	throw KTypeException("TypeError: unsupported operand type(s) for -");
}

KObject*	KObject::div(KObject* obj1, KObject* obj2)
{
	KInteger*	integer1 = obj1->getInteger();
	KInteger*	integer2 = obj2->getInteger();

	KDouble*	double1 = obj1->getDouble();
	KDouble*	double2	= obj2->getDouble();

	if (integer1 && integer2)
		return new KObject(*integer1 / *integer2);
	else if (integer1 && double2)
		return new KObject(*integer1 / *double2);
	else if (double1 && double2)
		return new KObject(*double1 / *double2);
	else if (double1 && integer2)
		return new KObject(*double1 / *integer2);
	throw KTypeException("TypeError: unsupported operand type(s) for /");
}

KObject*	KObject::mul(KObject* obj1, KObject* obj2)
{
	KInteger*	integer1 = obj1->getInteger();
	KInteger*	integer2 = obj2->getInteger();

	KDouble*	double1 = obj1->getDouble();
	KDouble*	double2	= obj2->getDouble();

	KString*	string1 = obj1->getString();
	KString*	string2 = obj2->getString();

	if (integer1 && integer2)
		return new KObject(*integer1 * *integer2);
	else if (integer1 && double2)
		return new KObject(*integer1 * *double2);
	else if (integer1 && string2)
		return new KObject(*integer1 * *string2);
	else if (double1 && double2)
		return new KObject(*double1 * *double2);
	else if (double1 && integer2)
		return new KObject(*double1 * *integer2);
	else if (double1 && string2)
		return new KObject(*double1 * *string2);
	else if (string1 && string2)
		return new KObject(*string1 * *string2);
	else if (string1 && integer2)
		return new KObject(*string1 * *integer2);
	else if (string1 && double2)
		return new KObject(*string1 * *double2);
	throw KTypeException("TypeError: unsupported operand type(s) for *");
}

KObject*	KObject::neg(KObject* obj)
{
	KInteger* integer = obj->getInteger();
	KDouble* real = obj->getDouble();
	if (integer)
		integer->neg();
	else if (real)
		real->neg();
	else
		throw KTypeException("TypeError: bad operand type for unary -");
	return obj;
}

KObject*	KObject::_and(KObject* obj1, KObject* obj2)
{
	return new KObject(obj1->toBool() && obj2->toBool());
}

KObject*	KObject::_or(KObject*obj1, KObject* obj2)
{
	return new KObject(obj1->toBool() || obj2->toBool());
}
