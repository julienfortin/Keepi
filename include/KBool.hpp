//
// KBool.hpp <Keepi>
// 
// Made by	Julien Fortin
// contact	<julien.fortin.it@gmail.com>
//

#ifndef __KBOOL_HPP__
#define	__KBOOL_HPP__

#include	<string>

class KInteger;
class KString;
class KDouble;

class KBool
{
private:
	KBool();

	static std::string	TYPE;

	bool		__bool;
	std::string	__str;

	void	__init(bool);
	void	__setValue(bool);

protected:
public:
	KBool(bool);
	~KBool();

	KBool&				operator=(const KBool&);
	KBool&				operator=(bool);

	long long int		operator+(const KInteger&) const;
	double				operator+(const KDouble&) const;
	std::string 		operator+(const KString&) const;
	bool 				operator+(const KBool&) const;

	const std::string&	getType() const;
	const std::string&	toString() const;
	bool				getValue() const;
};

#endif /* __KBOOL_HPP__ */