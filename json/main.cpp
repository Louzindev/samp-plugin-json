#include <sdk\plugin.h>
#include "Native.h"
#include "json/json_pool.h"

PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports() {
	return SUPPORTS_VERSION | SUPPORTS_AMX_NATIVES | SUPPORTS_PROCESS_TICK;
}

PLUGIN_EXPORT bool PLUGIN_CALL Load(void** ppData) {
	PluginLoad(ppData);
	JSONPool::Init(2000);
	logprintf("* Pawn JSON Plugin By KriegerDev loaded.");
	return true;
}

PLUGIN_EXPORT int PLUGIN_CALL AmxLoad(AMX* amx) {
	return amx_Register(amx, Native::native_list, -1);
}

PLUGIN_EXPORT void PLUGIN_CALL Unload() {

}

PLUGIN_EXPORT int PLUGIN_CALL AmxUnload(AMX* amx) {
	return 1;
}

PLUGIN_EXPORT void PLUGIN_CALL ProcessTick() {

}