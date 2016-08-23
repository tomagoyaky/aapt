cmake_minimum_required(VERSION 2.8.11)
MESSAGE("========================================")
IF (WIN32)
    MESSAGE(STATUS "Now is windows")  
ELSEIF (APPLE)
    message(FATAL_ERROR "Now is Apple systens. Please use CentOS to build this project, because the Xcode SDK not compatibled.")  
ELSEIF (UNIX)
    MESSAGE(STATUS "Now is UNIX-like OS's. Including aPPLE os x  and CygWin")  
ENDIF ()

project(AAPT)
#=================================================================================================================
MESSAGE("配置项目变量")
set(DIR_BASE				.)
set(DIR_SRC					${DIR_BASE}/src)
set(DIR_LIB					${DIR_BASE}/lib)
set(DIR_INC					${DIR_BASE}/include)
set(DIR_BUILD				${DIR_BASE}/build)

set(EXECUTABLE_OUTPUT_PATH	${DIR_BASE}/out)

#=================================================================================================================
MESSAGE("配置编译选项和环境变量")
set(CMAKE_ROOT						"${DIR_BASE}")
set(CMAKE_CXX_COMPILER				"c++")
set(CMAKE_CXX_FLAGS					"${CMAKE_CXX_FLAGS} -Wno-format-y2k")
set(CMAKE_CXX_FLAGS_DEBUG			"${CMAKE_CXX_FLAGS_DEBUG} -g")
set(CMAKE_CXX_FLAGS_MINSIZEREL		"${CMAKE_CXX_FLAGS_MINSIZEREL} -Os -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE			"${CMAKE_CXX_FLAGS_RELEASE} -O3 -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO	"${CMAKE_CXX_FLAGS_RELWITHDEBINFO} -O2 -g -DNDEBUG")

add_definitions(-DSTATIC_ANDROIDFW_FOR_TOOLS)
#add_definitions(-D_STRUCT_IOVEC)
#add_definitions(-D__cplusplus=201103L)
#add_definitions(-DOS_PATH_SEPARATOR='/')

#=================================================================================================================
MESSAGE("配置独立编译的宏定义")
#/*    resolver Compat.h报错：#error "_FILE_OFFSET_BITS < 64; large files are not supported on this platform"    */
add_definitions(-DHAVE_OFF64_T)

#/*    resolver Endian.h文件重复定义    */
add_definitions(-DHAVE_ENDIAN_H)
add_definitions(-DHAVE_LITTLE_ENDIAN)

#/*    resolver uio.h文件中的重复定义的“struct iovec”结构体及其俩函数    */
add_definitions(-DHAVE_SYS_UIO_H)

#/*    resolver ‘OS_PATH_SEPARATOR’在此作用域中尚未声明的错误    */
add_definitions(-DOS_PATH_SEPARATOR='/')
add_definitions(-DHAVE_PTHREADS)

include_directories(				${DIR_INC})
link_directories(					${DIR_LIB})
aux_source_directory(${DIR_SRC} 	APP_SRC)
add_executable(aapt 				${APP_SRC})
MESSAGE("build/Makefile生成完毕")
