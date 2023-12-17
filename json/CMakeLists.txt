include(AMXConfig)
include(AddSAMPPlugin)

add_samp_plugin(json 
	"${SDK}/amxplugin.cpp"
	"${SDK}/plugin.cpp"
	"${JSON_INCLUDE_DIR}/json/nloman_json.hpp"
	"Native.h"
	"Native.cpp"
	"utils.cpp"
	"json.cpp"
	"json_pool.cpp"
	"main.cpp"
	"main.def"
)

target_include_directories(json PRIVATE
	${LIB}
	${JSON_INCLUDE_DIR}
)

if (MSVC)
    target_compile_options(json PRIVATE "/MP")
endif()

install(TARGETS json DESTINATION ${SAMPSVR_PLUGIN_DIR})
install(FILES ${JSON_INCLUDE_DIR}/json.inc DESTINATION ${SAMPSVR_INCLUDE_DIR})
