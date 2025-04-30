#pragma once
#include <netsess/UrlSession.hpp>

enum class AchievementCode {
	Success = 0,
	Failed = 1,
	AlreadyGranted = 2,
	NotFound = 3
};

class AnixartSession : public network::UrlSession {
public:
	AnixartSession(std::string_view token);

	AchievementCode get_achievement(std::string_view name) const;

private:
	std::string _token;
};

