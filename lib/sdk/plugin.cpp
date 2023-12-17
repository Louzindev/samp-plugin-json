#include "plugin.h"

logprintf_t logprintf;
void** ppPluginData;

void PluginLoad(void** ppData)
{
	ppPluginData = ppData;
	pAMXFunctions = ppData[PLUGIN_DATA_AMX_EXPORTS];
	logprintf = (logprintf_t)ppData[PLUGIN_DATA_LOGPRINTF];
}