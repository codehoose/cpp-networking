#pragma once

#include <string>
#include <fstream>
#include <vector>

class CQotd
{
public:

	// Constructor
	CQotd(std::string filename);

	// Get a random quote from the file
	std::string GetRandomQuote();

private:

	// The quotes
	std::vector<std::string> quotes;
};
