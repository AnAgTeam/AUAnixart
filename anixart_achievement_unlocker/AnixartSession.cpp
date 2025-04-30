#include "AnixartSession.hpp"
#include <netsess/StringTools.hpp>
#include <netsess/JsonTools.hpp>

using namespace network;
using namespace network::json;

AnixartSession::AnixartSession(std::string_view login) : _login(login) {
	set_default_headers({
		"User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:128.0) Gecko/20100101 Firefox/128.0"
	});
}

AchievementCode AnixartSession::get_achievement(std::string_view name) const {
	std::string url = StringTools::sformat("https://api.anixart.tv/achievement/get/%s", name);
	std::string data;
	InlineJson::open_object(data);
	InlineJson::append(data, "profile_login", _login);
	InlineJson::close_object(data);


	JsonObject response = parse_json(post_request(url, data, "application/json"));
	return ParseJson::get<AchievementCode>(response, "code");
}
