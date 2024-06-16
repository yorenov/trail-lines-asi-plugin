message("Looking for DirectX9...")

file(GLOB DX9_SEARCH_PATHS
	"C:/Program Files (x86)/Microsoft DirectX SDK*/Include"
	"$ENV{DXSDK_DIR}/Include"
	"$ENV{PROGRAMFILES}/Microsoft DirectX SDK*/Include"
)

find_path(DX9_INCLUDE_DIRS
          NAMES d3dx9.h 
          PATHS ${DX9_SEARCH_PATHS})


set(DX9_LIBRARY_PATHS
    "$ENV{DXSDK_DIR}/Lib/x86/"
    "C:/Program Files (x86)/Windows Kits/8.1/lib/winv6.3/um/x86/"
    "C:/Program Files (x86)/Windows Kits/8.0/lib/win8/um/x86/"
    "C:/Program Files (x86)/Windows Kits/10/lib/10.0.14393.0/um/x86/"
    "C:/Program Files (x86)/Windows Kits/10/lib/10.0.10586.0/um/x86/"
	"C:/Program Files (x86)/Windows Kits/10/Lib/10.0.15063.0/um/x86/"
	"C:/Program Files (x86)/Windows Kits/10/Lib/10.0.16299.0/um/x86/"
)

find_library(DX9_LIB d3dx9 ${DX9_LIBRARY_PATHS} NO_DEFAULT_PATH)
set(DX9_LIBRARIES ${DX9_LIB})

add_library(DirectX9 INTERFACE)

target_include_directories(DirectX9 INTERFACE ${DX9_INCLUDE_DIRS})
target_link_libraries(DirectX9 INTERFACE ${DX9_LIBRARIES})