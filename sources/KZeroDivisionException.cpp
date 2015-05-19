//
// KZeroDivisionException.cpp <Keepi>
// 
// Made by	Julien Fortin
// contact	<julien.fortin.it@gmail.com>
//

#include	"KZeroDivisionException.hpp"

KZeroDivisionException::KZeroDivisionException(const std::string& type) throw() : exception()
{
	this->_type = type;
}

KZeroDivisionException::KZeroDivisionException() throw() : exception() 
{
}

KZeroDivisionException::~KZeroDivisionException() throw()
{
}

const char*	KZeroDivisionException::what() const throw()
{
	return std::string("ZeroDivisionError: " + this->_type + " division or modulo by zero").c_str();
}