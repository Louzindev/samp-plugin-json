#ifndef __JSON_UTILS_H
#define __JSON_UTILS_H
#include <sdk/plugin.h>
char* getAmxString(AMX* amx, cell data);
bool setAmxString(AMX* amx, cell data, const char* str, int size);
#endif