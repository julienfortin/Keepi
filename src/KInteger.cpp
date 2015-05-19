//
// KInteger.cpp <Keepi>
// 
// Made by	Julien Fortin
// contact	<julien.fortin.it@gmail.com>
//

#include	"KInteger.hpp"
#include	"KString.hpp"
#include	"KDouble.hpp"
#include	"KBool.hpp"
#include 	"KZeroDivisionException.hpp"

std::string KInteger::TYPE = "KInteger";

KInteger::KInteger(long long int integer)
{
	this->__init(integer);
}

KInteger::KInteger(const KInteger& integer)
{
	this->__init(integer.getValue());
}

KInteger::~KInteger() {}

void	KInteger::__init(long long int integer)
{
	this->__setValue(integer);
}

void	KInteger::__setValue(long long int integer)
{
	this->__integer = integer;
	this->__str 	= std::to_string(integer);
}

long long int 	KInteger::getValue() const
{
	return this->__integer;
}

const std::string&	KInteger::toString() const
{
	return this->__str;
}

const std::string& KInteger::getType() const
{
	return KInteger::TYPE;
}

bool				KInteger::toBool() const
{
	return	this->__integer ? true : false;
}

void		KInteger::neg()
{
	this->__setValue(-this->getValue());
}

KInteger&	KInteger::operator=(const KInteger& integer)
{
	this->__setValue(integer.getValue());
	return *this;
}

KInteger&	KInteger::operator=(long long int integer)
{
	this->__setValue(integer);
	return *this;
}

long long int	KInteger::operator+(const KInteger& integer) const
{
	return this->getValue() + integer.getValue();
}

long long int 	KInteger::operator+(const KBool& b) const
{
	return this->getValue() + b.getValue();
}

double			KInteger::operator+(const KDouble& real) const
{
	return ((double)this->getValue()) + real.getValue();
}

std::string 	KInteger::operator+(const KString& string) const
{
	return this->toString() + string.getValue();
}

long long int	KInteger::operator-(const KInteger& integer) const
{
	return this->getValue() - integer.getValue();
}

long long int	KInteger::operator-(const KBool& b) const
{
	return this->getValue() - b.getValue();
}

double			KInteger::operator-(const KDouble& real) const
{
	return ((double)this->getValue()) - real.getValue();
}

long long int	KInteger::operator*(const KInteger& integer) const
{
	return this->getValue() * integer.getValue();
}

long long int	KInteger::operator*(const KBool& b) const
{
	return this->getValue() * b.getValue();
}

double		KInteger::operator*(const KDouble& real) const
{
	return ((double)this->getValue()) * real.getValue();
}

std::string KInteger::operator*(const KString& string) const
{
	return string.repeatSequence(this->getValue());
}

long long int	KInteger::operator/(const KInteger& integer) const
{
	if (!integer.getValue())
		throw KZeroDivisionException(this->getType());
	return this->getValue() / integer.getValue();
}

long long int	KInteger::operator/(const KBool& b) const
{
	if (!b.getValue())
		throw KZeroDivisionException(this->getType());
	return this->getValue() / b.getValue();
}

double	KInteger::operator/(const KDouble& real) const
{
	if (!real.getValue())
		throw KZeroDivisionException(real.getType());
	return ((double)this->getValue()) - real.getValue();
}
