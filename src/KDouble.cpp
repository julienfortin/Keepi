//
// KDouble.cpp <Keepi>
// 
// Made by	Julien Fortin
// contact	<julien.fortin.it@gmail.com>
//

#include	"KDouble.hpp"
#include	"KInteger.hpp"
#include 	"KString.hpp"
#include	"KBool.hpp"
#include	"KZeroDivisionException.hpp"

std::string KDouble::TYPE = "KDouble";

KDouble::KDouble(double real)
{
	this->__init(real);
}

KDouble::KDouble(const KDouble& real)
{
	this->__init(real.getValue());
}

KDouble::~KDouble() {}

void	KDouble::__init(double real)
{
	this->__setValue(real);
}

void	KDouble::__setValue(double real)
{
	this->__double 	= real;
	this->__str		= std::to_string(real);
}

double	KDouble::getValue() const { return this->__double; }

const std::string&	KDouble::getType() const { return KDouble::TYPE; }
const std::string&	KDouble::toString() const { return this->__str; }

bool	KDouble::toBool() const
{
	return this->__double ? true : false;
}

void		KDouble::neg()
{
	this->__setValue(-this->getValue());
}

KDouble&	KDouble::operator=(const KDouble& real)
{
	this->__setValue(real.getValue());
	return *this;
}

KDouble&	KDouble::operator=(double real)
{
	this->__setValue(real);
	return *this;
}

double 		KDouble::operator+(const KDouble& real) const
{
	return this->getValue() + real.getValue();
}

double 		KDouble::operator+(const KBool& b) const
{
	return this->getValue() + b.getValue();
}

double 		KDouble::operator+(const KInteger& integer) const
{
	return this->getValue() + ((double)integer.getValue());
}

std::string KDouble::operator+(const KString& string) const
{
	return this->toString() + string.getValue();
}

double 		KDouble::operator-(const KDouble& real) const
{
	return this->getValue() - real.getValue();
}

double 		KDouble::operator-(const KBool& b) const
{
	return this->getValue() - b.getValue();
}

double 		KDouble::operator-(const KInteger& integer) const
{
	return this->getValue() - ((double)integer.getValue());
}

double 		KDouble::operator*(const KDouble& real) const
{
	return this->getValue() * real.getValue();
}

double 		KDouble::operator*(const KBool& b) const
{
	return this->getValue() * b.getValue();
}

double 		KDouble::operator*(const KInteger& integer) const
{
	return this->getValue() * ((double)integer.getValue());
}

std::string KDouble::operator*(const KString& string) const
{
	return string.repeatSequence(this->getValue());
}

double 		KDouble::operator/(const KDouble& real) const
{
	if (!real.getValue())
		throw KZeroDivisionException(real.getType());
	return this->getValue() / real.getValue();
}

double 		KDouble::operator/(const KBool& b) const
{
	if (!b.getValue())
		throw KZeroDivisionException(b.getType());
	return this->getValue() / b.getValue();
}

double 		KDouble::operator/(const KInteger& integer) const
{
	if (!integer.getValue())
		throw KZeroDivisionException(integer.getType());
	return this->getValue() / ((double)integer.getValue());
}