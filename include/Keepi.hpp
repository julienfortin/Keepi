//
// Keepi.hpp <Keepi>
// 
// Made by	Julien Fortin
// contact	<julien.fortin.it@gmail.com>
//

#ifndef	__KEEPI_HPP__
#define	__KEEPI_HPP__

#include	"KSymtable.hpp"

class Keepi
{
private:
	Keepi(const Keepi&);
	Keepi&	operator=(const Keepi&);

	bool		__debug;
	KSymtable*	__symtable;

	void		__init(bool);
	void 		__prompt(void) const;

protected:
public:
	Keepi(bool = false);
	~Keepi();

	void	assign(const std::string&, KObject*) const;
	void	dsymtab() const;

	void	result(KObject*) const;

	void	_exit(void) ;
};

#endif /* __KEEPI_HPP__ */
