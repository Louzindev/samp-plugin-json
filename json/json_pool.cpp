#include <json/json_pool.h>

namespace JSONPool
{
	unsigned int MAX_JSON_ID = 0;
	std::vector<JSON*> json_pool;

	void Init(const unsigned int _max_id)
	{
		MAX_JSON_ID = _max_id;
		json_pool.resize(MAX_JSON_ID, nullptr);
	}

	JSON* getJSON(const unsigned int id)
	{
		return json_pool[id];
	}

	int createJSON()
	{
		const int id = getEmptySlot();
		if(id == INVALID_JSON_ID)
		{
			return INVALID_JSON_ID;
		}
		json_pool[id] = new JSON(id);
		return id;
	}

	void deleteJSON(const unsigned int id)
	{
		if(json_pool[id] != nullptr)
		{
			delete json_pool[id];
			json_pool[id] = nullptr;
		}
	}

	int getEmptySlot()
	{
		for(unsigned int i = 0; i < MAX_JSON_ID; i++)
		{
			if(json_pool[i] == nullptr)
			{
				return i;
			}
		}
		return INVALID_JSON_ID;
	}

	int addJSON(const int id, JSON* json)
	{
		if(id == INVALID_JSON_ID)
		{
			return INVALID_JSON_ID;
		}
		json_pool[id] = json;
		return id;
	}
}