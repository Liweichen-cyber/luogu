cmake_minimum_required(VERSION 3.20)
project(luogu C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# 按洛谷官方难度分类的目录下，每个 .c 文件独立编译成一个可执行程序，
# 文件名（题号）即 target 名，main 互不冲突。
# 新建题目：把 .c 文件（文件名=题号）放进对应难度文件夹即可，无需改本文件。
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.c")
list(FILTER SOURCES EXCLUDE REGEX "/cmake-build")

set(_used "")
foreach(src IN LISTS SOURCES)
    get_filename_component(_name "${src}" NAME_WE)
    # 防止不同文件夹里同名文件导致 target 重名
    if(_name IN_LIST _used)
        string(RANDOM LENGTH 2 _suffix)
        set(_name "${_name}_${_suffix}")
    endif()
    list(APPEND _used "${_name}")
    add_executable("${_name}" "${src}")
endforeach()
