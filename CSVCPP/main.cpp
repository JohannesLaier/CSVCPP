#include <iostream>
#include "CSV.h"
#include "CSVExceptions.h"

int main()  {
	csvObject obj;
	
	csvTumpel header;
	header.push_back("FirstName");
	header.push_back("LastName");
	header.push_back("Age");
	
	csvTumpel row1;
	row1.push_back("David");
	row1.push_back("Blair");
	row1.push_back("25");

	csvTumpel row2;
	row2.push_back("Joshua");
	row2.push_back("Connor");
	row2.push_back("38");
	
	csvTumpel row3;
	row3.push_back("William");
	row3.push_back("Havering");
	row3.push_back("51");

	
	obj.push_back(header);
	obj.push_back(row1);
	obj.push_back(row2);
	obj.push_back(row3);

	CSV csv;
	csv.setCSVObject(obj);
	try {
		std::cout << "Write the data to the file: " << std::endl << std::endl;
		std::cout << csv.returnCSV() << std::endl;
		csv.writeCSVFile("C:\\Users\\User\\test.csv");
	} catch (CSVfileNotExist exc) {
		exc.printError("main.cpp: ");
		return 1;
	}
	getchar();
	return 0;
};
