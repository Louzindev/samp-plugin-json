#include <json/utils.h>

char* getAmxString(AMX* amx, cell data)
{
	int len;
	cell* addr = nullptr;
	amx_GetAddr(amx, data, &addr);
	amx_StrLen(addr, &len);
	if(len)
	{
		len++;
		auto str = new char[len];
		amx_GetString(str, addr, 0, len);
		return str;
	}
	else
	{
		return nullptr;
	}

}

bool setAmxString(AMX* amx, cell data, const char* str, int size)
{
	cell* addr = nullptr;
	amx_GetAddr(amx, data, &addr);
	return amx_SetString(addr, str, 0, 0, size) == AMX_ERR_NONE;
}