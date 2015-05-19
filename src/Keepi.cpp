//
// Keepi.cpp <Keepi>
// 
// Made by	Julien Fortin
// contact	<julien.fortin.it@gmail.com>
//

#include	<cstdlib>
#include	"Keepi.hpp"
#include	"KTypes.hpp"

Keepi::Keepi(bool debug)
{
	this->__init(debug);
	this->__prompt();
}

Keepi::~Keepi() 
{
	delete this->__symtable;
}

void	Keepi::__init(bool debug)
{
	this->__debug = debug;
	this->__symtable = new KSymtable();
}

void	Keepi::__prompt(void) const
{
	std::cout << ">>> ";
}

void	Keepi::result(KObject* result) const
{
	if (result)
		std::cout << "" << result << std::endl;
	this->__prompt();
}

void	Keepi::dsymtab() const { this->__symtable->print(); }

void	Keepi::assign(const std::string& key, KObject* value) const
{
	this->__symtable->add(key, value);
}

void	Keepi::_exit(void) 
{
	delete this->__symtable;
	exit(EXIT_SUCCESS);
}