//
// KTypes.hpp <Keepi>
// 
// Made by	Julien Fortin
// contact	<julien.fortin.it@gmail.com>
//
#include "DEBUG.h"
#include	<ostream>
#include	"KTypes.hpp"

std::ostream&	operator<<(std::ostream& os, KInteger* obj)
{
    os << obj->toString();
    return os;
}

std::ostream&	operator<<(std::ostream& os, KString* obj)
{
    os << obj->toString();
    return os;
}

std::ostream&	operator<<(std::ostream& os, KDouble* obj)
{
    os << obj->toString();
    return os;
}

std::ostream&	operator<<(std::ostream& os, KBool* obj)
{
    os << obj->toString();
    return os;
}

std::ostream&	operator<<(std::ostream& os, KObject* obj)
{
	if (obj->getInteger())
		os << obj->getInteger();
	else if (obj->getString())
		os << obj->getString();
	else if (obj->getDouble())
		os << obj->getDouble();
	else if (obj->getBool())
		os << obj->getBool();
    return os;
}
