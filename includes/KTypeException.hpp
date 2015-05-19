//
// KTypeErrorExecption.hpp <Keepi>
// 
// Made by	Julien Fortin
// contact	<julien.fortin.it@gmail.com>
//

#ifndef __KTYPEEXCEPTION_HPP__
#define __KTYPEEXCEPTION_HPP__

#include	<exception>
#include	<string>

class KTypeException : public std::exception
{
private:
	std::string		_what;

protected:
public:
	KTypeException(std::string const& what) throw();

	KTypeException() throw();

	~KTypeException() throw();

	virtual const char*	what() const throw();
};

#endif /* __KTYPEEXCEPTION_HPP__ */