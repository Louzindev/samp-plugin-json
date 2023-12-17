#include <json/json.h>

JSON::JSON(const int _id)
{
	m_id = _id;
	m_jobj = nlohmann::json::object();
}

JSON::JSON()
{
}

JSON::JSON(const int _id, const nlohmann::json& jobj)
{
	m_id = _id;
	m_jobj = jobj;
}