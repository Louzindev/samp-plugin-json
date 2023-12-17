#if defined _inc_JSON
	#undef _inc_JSON
#endif

#if defined _JSON_included
	#endinput
#endif
#define _JSON_included

#if !defined INVALID_JSON_ID
    #define INVALID_JSON_ID (JSON_ID:-1)
#endif

#if !defined MAX_JSON_ID
    #define MAX_JSON_ID (JSON_ID:2000)
#endif

native JSON_ID:json_create();
native json_destroy(JSON_ID:json);

native json_add_int(JSON_ID:json, const key[], const value);
native json_add_float(JSON_ID:json, const key[], const Float:value);
native json_add_string(JSON_ID:json, const key[], const value[]);
native json_add_bool(JSON_ID:json, const key[], const bool:value);
native json_add_json(JSON_ID:json, const key[], JSON_ID:value);

native json_clean(JSON_ID:json, const key[]);

native json_get_int(JSON_ID:json, const key[]);
native Float:json_get_float(JSON_ID:json, const key[]);
native json_get_string(JSON_ID:json, const key[], value[], const size = sizeof(value));
native bool:json_get_bool(JSON_ID:json, const key[]);
native json_get_json(JSON_ID:json, const key[]);
