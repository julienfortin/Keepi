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

protected:
public:
	Keepi(bool = false);
	~Keepi();

	void	assign(const std::string&, KObject*) const;
	void	dsymtab() const;
	void	_exit() ;
};

#endif /* __KEEPI_HPP__ */
