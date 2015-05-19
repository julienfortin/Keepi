//
// KSymtable.cpp <Keepi>
// 
// Made by	Julien Fortin
// contact	<julien.fortin.it@gmail.com>
//

#include	"KSymtable.hpp"
#include	"KTypes.hpp"

KSymtable::KSymtable() {}

KSymtable::~KSymtable()
{
	for (std::map<std::string, KObject*>::iterator it = this->__symtable.begin(); it != this->__symtable.end(); ++it)
	{
		delete it->second;
	}
}

void	KSymtable::print() const
{
	std::cout 	<< "####################### Symbol table: #######################" << std::endl
				<< "#\tTYPE:\t\tNAME:\t\tVALUE:" << std::endl;
	for (std::map<std::string, KObject*>::const_iterator it = this->__symtable.cbegin(); it != this->__symtable.cend(); ++it)
	{
		if ((*it).second)
			std::cout << "#\t" << it->second->getType() << "\t" << it->first << "\t= " << it->second << std::endl;
		//else
		//	throw KNullPtrException("Null pointer inside Symbol table.");
	}
	std::cout << "#############################################################" << std::endl;
}

void	KSymtable::add(const std::string& key, KObject* value)
{
	KObject* obj = this->__symtable[key];
	if (obj)
		delete obj;
	this->__symtable[key] = value;
}

/*

1 < 2 || 3 > 4 && 2 == 3

*/