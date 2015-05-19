//
// KTypeErrorException.cpp <Keepi>
// 
// Made by	Julien Fortin
// contact	<julien.fortin.it@gmail.com>
//

#include	"KTypeException.hpp"

KTypeException::KTypeException(const std::string& what) throw() : exception()
{
	this->_what = what;
}

KTypeException::KTypeException() throw() : exception() 
{
}

KTypeException::~KTypeException() throw()
{
}

const char*	KTypeException::what() const throw()
{
	return this->_what.c_str();
}