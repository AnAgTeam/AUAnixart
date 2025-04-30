#include "Logger.hpp"

void Logger::log_info(std::string_view msg) {
	std::cout << "[INFO] " << msg << std::endl;
}

void Logger::log_error(std::string_view msg) {
	std::cout << "[ERROR] " << msg << std::endl;
}

void Logger::log(std::string_view msg) {
	std::cout << msg << std::endl;
}
