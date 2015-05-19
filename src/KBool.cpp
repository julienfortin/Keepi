//
// KBool.cpp <Keepi>
// 
// Made by	Julien Fortin
// contact	<julien.fortin.it@gmail.com>
//

#include	"KBool.hpp"
#include	"KInteger.hpp"
#include	"KDouble.hpp"
#include	"KString.hpp"

std::string	KBool::TYPE = "KBool";

KBool::KBool(bool b)
{
	this->__init(b);
}

KBool::~KBool() {}

void	KBool::__init(bool b)
{
	this->__setValue(b);
}

void	KBool::__setValue(bool b)
{
	this->__bool = b;
	this->__str = b ? "true" : "false";
}

const std::string&	KBool::getType() const { return KBool::TYPE; }
const std::string&	KBool::toString() const { return this->__str; }
bool				KBool::getValue() const { return this->__bool; }

KBool&			KBool::operator=(const KBool& b)
{
	this->__setValue(b.getValue());
	return *this;
}

KBool&			KBool::operator=(bool b)
{
	this->__setValue(b);
	return *this;
}

bool 			KBool::operator+(const KBool& b) const
{
	return this->getValue() + b.getValue();
}

long long int	KBool::operator+(const KInteger& integer) const
{
	return this->getValue() + integer.getValue();
}

double			KBool::operator+(const KDouble& real) const
{
	return this->getValue() + real.getValue();
}

std::string 	KBool::operator+(const KString& string) const
{
	return this->toString() + string.toString();
}
