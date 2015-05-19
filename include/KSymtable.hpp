//
// KSymtable.hpp <Keepi>
// 
// Made by	Julien Fortin
// contact	<julien.fortin.it@gmail.com>
//

#ifndef __KSYMTABLE_HPP__
#define __KSYMTABLE_HPP__

#include	<map>
#include	<iostream>

#include	"KObject.hpp"

class KSymtable
{
private:
	std::map<std::string, KObject*>		__symtable; 

	KSymtable(const KSymtable&);
	KSymtable 	operator=(const KSymtable&);

protected:
public:
	KSymtable();
	~KSymtable();

	void	print() const;

	void	add(const std::string&, KObject* value);

/*
	template <typename T>
	T	resolveIdentifier(const char* name) const
	{
		std::string key = name;
		KeepiSymMap::const_iterator it = this->_symtable.find(key);
		if (it != this->_symtable.cend())
		{
			try
			{
				KNumber<T>* number = reinterpret_cast<KNumber<T>*>(it->second);
				if (number)
					return number->getValue();
				else
					key = "\"" + key + "\": null pointer";
			}
			catch(std::exception const &e)
			{
				std::cerr << e.what() << std::endl;
			}
		}
		throw KUndefinedIdentifierException(key);
	};

	*/
};

#endif