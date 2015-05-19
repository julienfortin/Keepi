//
// KInteger.hpp <Keepi>
// 
// Made by	Julien Fortin
// contact	<julien.fortin.it@gmail.com>
//

#ifndef __KINTEGER__HPP__
#define	__KINTEGER__HPP__

#include	<string>

class KString;
class KDouble;
class KBool;

class KInteger
{
private:
	static std::string 	TYPE;

	long long int 	__integer;

	std::string		__str;

	void			__init(long long int);
	void			__setValue(long long int);

protected:
public:
	KInteger(long long int = 0);
	KInteger(const KInteger&);

	~KInteger();

	KInteger&			operator=(const KInteger&);
	KInteger&			operator=(long long int);

	long long int		operator+(const KInteger&) const;
	long long int 		operator+(const KBool&) const;
	double				operator+(const KDouble&) const;
	std::string 		operator+(const KString&) const;

	long long int 		operator-(const KBool&) const;
	long long int		operator-(const KInteger&) const;
	double				operator-(const KDouble&) const;

	long long int		operator/(const KInteger&) const;
	long long int 		operator/(const KBool&) const;
	double				operator/(const KDouble&) const;

	long long int		operator*(const KInteger&) const;
	long long int 		operator*(const KBool&) const;
	double				operator*(const KDouble&) const;
	std::string 		operator*(const KString&) const;


	long long int		getValue() const;

	bool				toBool() const;
	const std::string&	toString() const;
	const std::string&	getType() const;

	void				neg();
};

#endif /* __KINTEGER__HPP__ */