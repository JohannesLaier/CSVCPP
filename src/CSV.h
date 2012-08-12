#pragma once
#include <iostream>
#include <string>
#include <vector>

typedef std::vector<std::string> csvTumpel;
typedef std::vector<std::vector<std::string>> csvObject;

class CSV {
	private:
		std::string filename;
		csvObject csv;
	public:
		void setCSVObject(const csvObject &csv);
		csvObject getCSVObject();

		void writeCSVFile(const std::string &filename);
		std::string returnCSV();
};

