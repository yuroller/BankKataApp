#include "stdafx.h"
#include "Transazione.h"
#include <ostream>

std::ostream& operator<<(std::ostream& os, const Transazione& tr)
{
	return os << "Transazione[" << tr.importo_ << ',' << tr.data_ << ']';
}