//
// KString.cpp <Keepi>
// 
// Made by	Julien Fortin
// contact	<julien.fortin.it@gmail.com>
//

#include	"KString.hpp"
#include	"KInteger.hpp"
#include	"KDouble.hpp"
#include	"KBool.hpp"
#include	"KTypeException.hpp"

std::string KString::TYPE = "KString";

KString::KString(const std::string& str)
{
	this->__init(str);
}

KString::KString(const KString& str)
{
	this->__init(str.getValue());
}

KString::KString(const char* str)
{
	this->__init(std::string(str));
}

KString::~KString() {}

void	KString::__init(std::string str)
{
	this->__setValue(str);
}

void	KString::__setValue(const std::string& str)
{
	this->__string = str;
}

const std::string& 	KString::getValue() const
{
	return this->__string;
}

const std::string&	KString::toString() const
{
	return this->__string;
}

const std::string& KString::getType() const
{
	return KString::TYPE;
}

bool				KString::toBool() const
{
	return this->__string != "";
}

std::string 		KString::repeatSequence(int n) const
{
	std::string sequence = "";
	for (; n > 0; n--)
		sequence += this->getValue();
	return sequence;
}

KString&	KString::operator=(const KString& str)
{
	this->__setValue(str.getValue());
	return *this;
}

KString&	KString::operator=(const std::string& str)
{
	this->__setValue(str);
	return *this;
}

std::string 	KString::operator+(const KString& string) const
{
	return this->getValue() + string.toString();
}

std::string 	KString::operator+(const KInteger& integer) const
{
	return std::string(this->getValue() + integer.toString());
}

std::string 	KString::operator+(const KDouble& real) const
{
	return std::string(this->getValue() + real.toString());
}

std::string 	KString::operator+(const KBool& b) const
{
	return std::string(this->getValue() + b.toString());
}

std::string 	KString::operator*(const KInteger& integer) const
{
	return this->repeatSequence(integer.getValue());
}

std::string 	KString::operator*(const KDouble& real) const
{
	return this->repeatSequence(real.getValue());
}

std::string 	KString::operator*(const KString& string) const
{
	throw KTypeException("TypeError: can't multiply sequence by non-number of type '" + this->getType() + "'");
}

