#include "Native.h"
#include <json/json_pool.h>
#include <json/json.h>
#include <json/utils.h>

namespace Native
{
	// native JSON_ID:json_create();
	cell json_create(AMX* amx, cell* params)
	{
		int id = JSONPool::createJSON();
		logprintf("json_create: %d", id);
		return id;
	}

	// native json_destroy(JSON_ID:json);
	cell json_destroy(AMX* amx, cell* params)
	{
		const auto id = static_cast<unsigned int>(params[1]);
		JSONPool::deleteJSON(id);
		return 1;
	}

	// native json_add_int(JSON_ID:json, const key[], const value);
	cell json_add_int(AMX* amx, cell* params)
	{
		const auto id = static_cast<unsigned int>(params[1]);
		const char* key = getAmxString(amx, params[2]);
		const auto value = static_cast<int>(params[3]);

		JSON* json = JSONPool::getJSON(id);
		if (json == nullptr)
		{
			return 0;
		}

		return json->addValue(key, value);
	}

	// native json_add_float(JSON_ID:json, const key[], const Float:value);
	cell json_add_float(AMX* amx, cell* params)
	{
		const auto id = static_cast<unsigned int>(params[1]);
		const char* key = getAmxString(amx, params[2]);
		const auto value = amx_ctof(params[3]);

		JSON* json = JSONPool::getJSON(id);
		if (json == nullptr)
		{
			return 0;
		}

		return json->addValue(key, value);
	}

	// native json_add_string(JSON_ID:json, const key[], const value[]);
	cell json_add_string(AMX* amx, cell* params)
	{
		const auto id = static_cast<unsigned int>(params[1]);
		const char* key = getAmxString(amx, params[2]);
		const auto value = getAmxString(amx, params[3]);

		JSON* json = JSONPool::getJSON(id);
		if (json == nullptr)
		{
			return 0;
		}
		std::string str(value);
		return json->addValue(key, str);
	}

	// native json_add_bool(JSON_ID:json, const key[], const bool:value);
	cell json_add_bool(AMX* amx, cell* params)
	{
		const auto id = static_cast<unsigned int>(params[1]);
		const char* key = getAmxString(amx, params[2]);
		const auto value = static_cast<bool>(params[3]);

		JSON* json = JSONPool::getJSON(id);
		if (json == nullptr)
		{
			return 0;
		}

		return json->addValue(key, value);
	}

	// native json_add_json(JSON_ID:json, const key[], JSON_ID:value);
	cell json_add_json(AMX* amx, cell* params)
	{
		const auto id = static_cast<unsigned int>(params[1]);
		const char* key = getAmxString(amx, params[2]);
		const auto value = static_cast<unsigned int>(params[3]);

		JSON* json = JSONPool::getJSON(id);
		if (json == nullptr)
		{
			return 0;
		}

		JSON* json_value = JSONPool::getJSON(value);
		if (json_value == nullptr)
		{
			return 0;
		}

		return json->addJson(key, json_value);
	}

	// native json_clean(JSON_ID:json, const key[]);
	cell json_clean(AMX* amx, cell* params)
	{
		const auto id = static_cast<unsigned int>(params[1]);
		const char* key = getAmxString(amx, params[2]);

		JSON* json = JSONPool::getJSON(id);
		if (json == nullptr)
		{
			return 0;
		}

		return json->removeValue(key);
	}

	// native json_get_int(JSON_ID:json, const key[]);
	cell json_get_int(AMX* amx, cell* params)
	{
		const auto id = static_cast<unsigned int>(params[1]);
		const char* key = getAmxString(amx, params[2]);

		JSON* json = JSONPool::getJSON(id);
		if (json == nullptr)
		{
			return 0;
		}

		return json->getValue<int>(key);
	}

	// native json_get_float(JSON_ID:json, const key[]);
	cell json_get_float(AMX* amx, cell* params)
	{
		const auto id = static_cast<unsigned int>(params[1]);
		const char* key = getAmxString(amx, params[2]);

		JSON* json = JSONPool::getJSON(id);
		if (json == nullptr)
		{
			return 0;
		}
		const float value = json->getValue<float>(key);
		return amx_ftoc(value);
	}

	// native json_get_string(JSON_ID:json, const key[], value[], const size = sizeof(value));
	cell json_get_string(AMX* amx, cell* params)
	{
		const auto id = static_cast<unsigned int>(params[1]);
		const char* key = getAmxString(amx, params[2]);

		JSON* json = JSONPool::getJSON(id);
		if (json == nullptr)
		{
			return 0;
		}

		auto value = json->getValue<std::string>(key);
		
		return setAmxString(amx, params[3], value.c_str(), params[4]);
	}

	// native json_get_bool(JSON_ID:json, const key[]);
	cell json_get_bool(AMX* amx, cell* params)
	{
		const auto id = static_cast<unsigned int>(params[1]);
		const char* key = getAmxString(amx, params[2]);

		JSON* json = JSONPool::getJSON(id);
		if (json == nullptr)
		{
			return 0;
		}

		auto value = json->getValue<bool>(key);
		return value;
	}

	// native JSON_ID:json_get_json(JSON_ID:json, const key[]);
	cell json_get_json(AMX* amx, cell* params)
	{
		const auto id = static_cast<unsigned int>(params[1]);
		const char* key = getAmxString(amx, params[2]);

		JSON* json = JSONPool::getJSON(id);
		if (json == nullptr)
		{
			return 0;
		}

		auto json_value = json->getValue<nlohmann::json>(key);

		const int new_id = JSONPool::getEmptySlot();
		JSONPool::addJSON(new_id, new JSON(new_id, json_value));

		return new_id;
	
	}

	const AMX_NATIVE_INFO native_list[] = {
		{ "json_create", json_create },
		{ "json_destroy", json_destroy },
		{ "json_add_int", json_add_int },
		{ "json_add_float", json_add_float },
		{ "json_add_string", json_add_string },
		{ "json_add_bool", json_add_bool },
		{ "json_add_json", json_add_json },
		{ "json_clean", json_clean },
		{ "json_get_int", json_get_int },
		{ "json_get_float", json_get_float },
		{ "json_get_string", json_get_string },
		{ "json_get_bool", json_get_bool },
		{ "json_get_json", json_get_json },
		{ nullptr, nullptr }
	};
}