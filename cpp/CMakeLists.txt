cmake_minimum_required(VERSION 3.9)
project(leetcode C CXX)

option(WITH_DEBUG_SYMBOLS "With debug symbols" ON)

if(WITH_DEBUG_SYMBOLS)
    set(DEBUG_SYMBOLS "-g")
endif()

set(CMAKE_CXX_FLAGS "-O0 -pipe -Wall -W -fPIC -std=c++14 -fstrict-aliasing -Wno-invalid-offsetof -Wno-unused-parameter -fno-omit-frame-pointer -Wno-sign-compare -Wno-narrowing -Wno-unused-variable")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${DEBUG_SYMBOLS}")
set(CMAKE_C_FLAGS "-O0 -pipe -Wall -W -fPIC -fstrict-aliasing -Wno-unused-parameter -fno-omit-frame-pointer")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${DEBUG_SYMBOLS}")
set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR})

include_directories(
    ${PROJECT_SOURCE_DIR}
)

file(GLOB_RECURSE UTILS_SOURCES "${PROJECT_SOURCE_DIR}/utils/*.cpp")
file(GLOB_RECURSE GRAPH_SOURCES "${PROJECT_SOURCE_DIR}/graph/*.cpp")
file(GLOB_RECURSE INIT_SOURCES  "${PROJECT_SOURCE_DIR}/init/*.cpp")
file(GLOB_RECURSE INTERVAL_SOURCES "${PROJECT_SOURCE_DIR}/interval/*.cpp")
file(GLOB_RECURSE DP_SOURCES "${PROJECT_SOURCE_DIR}/dp/*.cpp")
file(GLOB_RECURSE MATH_SOURCES "${PROJECT_SOURCE_DIR}/math/*.cpp")
file(GLOB_RECURSE BACKTRACE_SOURCES "${PROJECT_SOURCE_DIR}/backtrace/*.cpp")
file(GLOB_RECURSE ARRAY_SOURCES "${PROJECT_SOURCE_DIR}/array/*.cpp")

add_library(leetcode-lib STATIC "${UTILS_SOURCES}" 
                                "${GRAPH_SOURCES}"
                                "${INIT_SOURCES}"
                                "${INTERVAL_SOURCES}"
                                "${DP_SOURCES}"
                                "${MATH_SOURCES}"
                                "${BACKTRACE_SOURCES}"
                                "${ARRAY_SOURCES}")

add_executable(leetcode "${PROJECT_SOURCE_DIR}/main.cpp")
target_link_libraries(leetcode leetcode-lib)

file(COPY ${PROJECT_SOURCE_DIR}/graph/
     DESTINATION ${CMAKE_INSTALL_PREFIX}/output/include/graph
     FILES_MATCHING
     PATTERN "*.h")

file(COPY ${PROJECT_SOURCE_DIR}/utils/
     DESTINATION ${CMAKE_INSTALL_PREFIX}/output/include/utils
     FILES_MATCHING
     PATTERN "*.h")

file(COPY ${PROJECT_SOURCE_DIR}/nlohmann/
     DESTINATION ${CMAKE_INSTALL_PREFIX}/output/include/nlohmann
     FILES_MATCHING
     PATTERN "*.h"
     PATTERN "*.hpp")

file(COPY ${PROJECT_SOURCE_DIR}/init/
     DESTINATION ${CMAKE_INSTALL_PREFIX}/output/include/init
     FILES_MATCHING
     PATTERN "*.h")     

file(COPY ${PROJECT_SOURCE_DIR}/interval/
     DESTINATION ${CMAKE_INSTALL_PREFIX}/output/include/interval
     FILES_MATCHING
     PATTERN "*.h")    

file(COPY ${PROJECT_SOURCE_DIR}/dp/
     DESTINATION ${CMAKE_INSTALL_PREFIX}/output/include/dp
     FILES_MATCHING
     PATTERN "*.h")   

file(COPY ${PROJECT_SOURCE_DIR}/math/
     DESTINATION ${CMAKE_INSTALL_PREFIX}/output/include/math
     FILES_MATCHING
     PATTERN "*.h")   

file(COPY ${PROJECT_SOURCE_DIR}/backtrace/
     DESTINATION ${CMAKE_INSTALL_PREFIX}/output/include/backtrace
     FILES_MATCHING
     PATTERN "*.h") 

file(COPY ${PROJECT_SOURCE_DIR}/array/
     DESTINATION ${CMAKE_INSTALL_PREFIX}/output/include/array
     FILES_MATCHING
     PATTERN "*.h") 

install(TARGETS leetcode leetcode-lib
    RUNTIME DESTINATION output/bin
    LIBRARY DESTINATION output/lib
    ARCHIVE DESTINATION output/lib
)
