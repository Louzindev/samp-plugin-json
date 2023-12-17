#ifndef __JSON_POOL_H
#define __JSON_POOL_H
#include <json/json.h>

#define INVALID_JSON_ID -1

namespace JSONPool
{
	extern unsigned int MAX_JSON_ID;
	extern std::vector<JSON*> json_pool;

	void Init(const unsigned int _max_id);
	inline int getPoolSize() { return MAX_JSON_ID; }

	JSON* getJSON(const unsigned int id);
	int createJSON();
	void deleteJSON(const unsigned int id);
	int getEmptySlot();

	int addJSON(const int id, JSON* json);
}

#endif