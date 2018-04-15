#pragma once

#include <string>

class Transazione
{
public:
	Transazione(int importo, const std::string& data)
		: importo_(importo),
		data_(data)
	{}

	bool operator==(const Transazione& other) const {
		return other.importo_ == importo_ && other.data_ == data_;
	}

private:
	int importo_;
	std::string data_;
};