//
// KTypeErrorExecption.hpp <Keepi>
// 
// Made by	Julien Fortin
// contact	<julien.fortin.it@gmail.com>
//

#ifndef __KZERODIVISIONEXCEPTION_HPP__
#define __KZERODIVISIONEXCEPTION_HPP__

#include	<exception>
#include	<string>

class KZeroDivisionException : public std::exception
{
private:
	std::string		_type;

protected:
public:
	KZeroDivisionException(std::string const& type) throw();

	KZeroDivisionException() throw();

	~KZeroDivisionException() throw();

	virtual const char*	what() const throw();
};

#endif /* __KZERODIVISIONEXCEPTION_HPP__ */
