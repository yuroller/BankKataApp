#pragma once

#include <string>
#include <ostream>

class Transazione
{
public:
	Transazione(int importo, const std::string& data)
		: importo_(importo),
		data_(data)
	{}

	int importo() const { return importo_; }
	std::string data() const { return data_;  }

	bool operator==(const Transazione& other) const {
		return other.importo_ == importo_ && other.data_ == data_;
	}

	friend std::ostream& operator<<(std::ostream&, const Transazione&);

private:
	int importo_;
	std::string data_;
};
