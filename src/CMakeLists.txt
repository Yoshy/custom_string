cmake_minimum_required(VERSION 3.6)

set ( PROJECT_NAME custom_string )
set ( CMAKE_CXX_STANDARD 11 )

project ( ${PROJECT_NAME} )

include_directories ( "${PROJECT_SOURCE_DIR}/custom_string" )
add_subdirectory ( custom_string )
set ( EXTRA_LIBS ${EXTRA_LIBS} custom_string )

# Reverse Lexicographical order target
set ( REVLEX_SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/revlex.cpp )
add_executable ( revlex ${REVLEX_SOURCE_FILES} )
target_link_libraries ( revlex ${EXTRA_LIBS} )
set_property ( DIRECTORY PROPERTY VS_STARTUP_PROJECT revlex )

install ( TARGETS revlex DESTINATION ${CMAKE_SOURCE_DIR}/../bin )
