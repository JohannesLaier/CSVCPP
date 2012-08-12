#include <iostream>
#include <string>

class CSVExeption {
	private:
		std::string error;
	public:
		CSVExeption(const std::string &e) {
			error = e;
		}
		void printError(const std::string &errorClass) {
			std::cout << errorClass << ": " << error << std::endl;
		}
};

class CSVfileNotExist : public CSVExeption {
	public:
		CSVfileNotExist(const std::string &e) : CSVExeption(e) {};
};