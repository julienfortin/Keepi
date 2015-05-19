//
// KTypes.hpp <Keepi>
// 
// Made by	Julien Fortin
// contact	<julien.fortin.it@gmail.com>
//

#ifndef	__KTYPES_HPP__
#define __KTYPES_HPP__

#include	"KObject.hpp"

std::ostream&	operator<<(std::ostream&, KInteger*);
std::ostream&	operator<<(std::ostream&, KString*);
std::ostream&	operator<<(std::ostream&, KDouble*);
std::ostream&	operator<<(std::ostream&, KBool*);
std::ostream&	operator<<(std::ostream&, KObject*);

#endif /* __KTYPES_HPP__ */
