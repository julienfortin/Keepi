//
// KDouble.cpp <Keepi>
// 
// Made by	Julien Fortin
// contact	<julien.fortin.it@gmail.com>
//

#ifndef	__KDOUBLE_HPP__
#define __KDOUBLE_HPP__

#include	<string>

class KInteger;
class KString;
class KBool;

class KDouble
{
private:
	static std::string 	TYPE;

	double 			__double;

	std::string		__str;

	void			__init(double);
	void			__setValue(double);

	KDouble();

protected:
public:
	KDouble(double);
	KDouble(const KDouble&);
	~KDouble();

	KDouble&			operator=(const KDouble&);
	KDouble&			operator=(double);

	double				operator+(const KDouble&) const;
	double 				operator+(const KBool&) const;
	double				operator+(const KInteger&) const;
	std::string 		operator+(const KString&) const;
	
	double 				operator-(const KDouble&) const;
	double 				operator-(const KBool&) const;
	double 				operator-(const KInteger&) const;

	double 				operator*(const KDouble&) const;
	double 				operator*(const KBool&) const;
	double 				operator*(const KInteger&) const;
	std::string 		operator*(const KString&) const;

	double 				operator/(const KDouble&) const;
	double 				operator/(const KBool&) const;
	double 				operator/(const KInteger&) const;


	double				getValue() const;
	const std::string&	getType() const;
	const std::string&	toString() const;
	bool				toBool() const;

	void				neg();
};

#endif /* __KDOUBLE_HPP__ */