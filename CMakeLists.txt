cmake_minimum_required(VERSION 3.0.0)
project(QTest VERSION 0.1.0 LANGUAGES C CXX)

# to use QMetaClass, step 1
set(CMAKE_CXX_STANDARD 20)

include(CTest)
enable_testing()

add_executable(QTest main.cpp)

# to use QMetaClass, step 2
if (WIN32)
    target_compile_options (${PROJECT_NAME} PUBLIC "/Zc:__cplusplus") #msvc
endif(WIN32)

#cmake usage of QMetaClass, step 3
find_package(QMetaClass REQUIRED)
target_include_directories(QTest PRIVATE ${QMetaClass_INCLUDE_DIRS})
target_link_directories(QTest PRIVATE ${QMetaClass_LIBRARIES})
target_link_libraries(QTest QMetaClass)

#copy the shared .dll to current .exe folder, step 4
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ${QMetaClass_LIBRARIES}/QMetaClass.dll ${CMAKE_CURRENT_SOURCE_DIR}/build/${CMAKE_CFG_INTDIR}
)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
