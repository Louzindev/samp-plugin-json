#ifndef __JSON_NATIVE_H
#define __JSON_NATIVE_H
#include <sdk\plugin.h>
#include <json/json.h>

namespace Native
{
	// native JSON_ID:json_create();
	cell json_create(AMX* amx, cell* params);

	// native json_destroy(JSON_ID:json);
	cell json_destroy(AMX* amx, cell* params);

	// native json_add_int(JSON_ID:json, const key[], const value);
	cell json_add_int(AMX* amx, cell* params);

	// native json_add_float(JSON_ID:json, const key[], const Float:value);
	cell json_add_float(AMX* amx, cell* params);

	// native json_add_string(JSON_ID:json, const key[], const value[]);
	cell json_add_string(AMX* amx, cell* params);

	// native json_add_bool(JSON_ID:json, const key[], const bool:value);
	cell json_add_bool(AMX* amx, cell* params);

	// native json_add_json(JSON_ID:json, const key[], JSON_ID:value);
	cell json_add_json(AMX* amx, cell* params);

	// native json_clean(JSON_ID:json, const key[]);
	cell json_clean(AMX* amx, cell* params);

	// native json_get_int(JSON_ID:json, const key[]);
	cell json_get_int(AMX* amx, cell* params);

	// native json_get_float(JSON_ID:json, const key[]);
	cell json_get_float(AMX* amx, cell* params);

	// native json_get_string(JSON_ID:json, const key[], value[], const size = sizeof(value));
	cell json_get_string(AMX* amx, cell* params);

	// native json_get_bool(JSON_ID:json, const key[]);
	cell json_get_bool(AMX* amx, cell* params);

	// native json_get_json(JSON_ID:json, const key[]);
	cell json_get_json(AMX* amx, cell* params);

	extern "C" const AMX_NATIVE_INFO native_list[];
}
#endif