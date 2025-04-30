#include "AnixartSession.hpp"
#include <netsess/StringTools.hpp>
#include <netsess/JsonTools.hpp>

using namespace network;
using namespace network::json;

AnixartSession::AnixartSession(std::string_view token) : _token(token) {
	set_default_headers({
		"User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:128.0) Gecko/20100101 Firefox/128.0"
	});
}

AchievementCode AnixartSession::get_achievement(std::string_view name) const {
	std::string url = StringTools::sformat("https://api.anixart.tv/achievement/get/%s", name);
	UrlParameters params({
		KeyValue("token", _token)
	});
	JsonObject response = parse_json(get_request(url, {}, params));
	return ParseJson::get<AchievementCode>(response, "code");
}
