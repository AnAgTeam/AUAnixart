#pragma once
#include <string_view>
#include <iostream>

class Logger {
public:
	static void log_info(std::string_view msg);
	static void log_error(std::string_view msg);
	static void log(std::string_view msg);
};

