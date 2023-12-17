#ifndef __JSON_H_
#define __JSON_H_
#include <string>
#include <json/nlohmann_json.hpp>
#include <vector>

class JSON
{
public:
	static unsigned int json_count;

	JSON(const int _id);
	JSON(const int _id, const nlohmann::json& jobj);
	JSON();

	int getId() const { return m_id; }
	std::string getJsonString() const { return m_jstr; }
	nlohmann::json getJsonObject() const { return m_jobj; }

	template<typename T>
	bool addValue(const char* key, const T value)
	{
		if (m_jobj[key].is_null())
		{
			m_jobj[key] = value;
			return true;
		}
		return false;
	}

	template<typename T>
	inline T getValue(const char* key) const
	{
		auto it = m_jobj.find(key);
		if (it != m_jobj.end()) {
			return it.value();
		}

		return T();
	}

	template<>
	inline std::string getValue<std::string>(const char* key) const
	{
		auto it = m_jobj.find(key);
		if (it != m_jobj.end() && !it.value().is_null()) {
			return it.value();
		}
		return "null value";
	}

	inline bool addJson(const char* key, JSON* json)
	{
		if (m_jobj[key].is_null())
		{
			m_jobj[key] = json->getJsonObject();
			return true;
		}
		return false;
	}

	inline bool removeValue(const char* key)
	{
		if (!m_jobj[key].is_null())
		{
			m_jobj.erase(key);
			return true;
		}
		return false;
	}

private:
	unsigned int m_id;
	std::string m_jstr;
	nlohmann::json m_jobj;
};
#endif