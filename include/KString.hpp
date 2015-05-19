//
// KString.hpp <Keepi>
// 
// Made by	Julien Fortin
// contact	<julien.fortin.it@gmail.com>
//

#ifndef __KSTRING__HPP__
#define	__KSTRING__HPP__

#include	<string>

class KInteger;
class KDouble;
class KBool;

class KString
{
private:
	static std::string 	TYPE;

	std::string 	__string;

	void			__init(std::string);
	void			__setValue(const std::string&);

protected:
public:
	KString(const std::string& = "");
	KString(const KString&);
	KString(const char*);

	~KString();

	KString&			operator=(const KString&);
	KString&			operator=(const std::string&);

	std::string 		operator+(const KString&) const;
	std::string 		operator+(const KInteger&) const;
	std::string 		operator+(const KDouble&) const;
	std::string 		operator+(const KBool&) const;

	std::string 		operator*(const KString&) const;
	std::string 		operator*(const KInteger&) const;
	std::string 		operator*(const KDouble&) const;


	const std::string&	getValue() const;
	const std::string&	toString() const;
	const std::string&	getType() const;

	bool				toBool() const;

	std::string 		repeatSequence(int) const;
};

#endif /* __KINTEGER__HPP__ */