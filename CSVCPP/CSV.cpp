#include "CSV.h"
#include "CSVExceptions.h"

#include <fstream>

void CSV::setCSVObject(const csvObject &c) {
	csv = c;
}

csvObject CSV::getCSVObject() {
	return csv;
}

void CSV::writeCSVFile(const std::string &filename) {
	std::ofstream out;
	out.open(filename);
	if (!out.is_open()) {
		out.close();
		throw new CSVfileNotExist("CSVFile invalide Path");
	}
	std::string data = returnCSV();
	out.write(data.c_str(), data.size());
	out.close();
}

std::string CSV::returnCSV() {
	std::string data("");
	for (csvObject::iterator it = csv.begin(); it != csv.end(); ++it) {
		std::string line("");
		csvTumpel tump = *it;
		for (csvTumpel::iterator iter = tump.begin(); iter != tump.end(); ++iter) {
			line.append(*iter);
			line.append(";");
		}
		line.erase(line.size() - 1);
		data.append(line);
		data.append("\n");
	}
	return data;
}
