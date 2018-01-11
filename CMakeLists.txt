cmake_minimum_required( VERSION 3.9 )

project( "Notepad++ encoding fix plugin" )

if( ${CMAKE_SIZEOF_VOID_P} EQUAL 4 )
    set( PLUGIN_NAME_SUFFIX "32-bit" )
elseif( ${CMAKE_SIZEOF_VOID_P} EQUAL 8 )
    set( PLUGIN_NAME_SUFFIX "64-bit" )
else()
    message( FATAL_ERROR "The selected toolchain isn't recognized as 32-bit or 64-bit." )
endif()

add_compile_options("/std:c++latest")

include_directories(
    source/reusable
    source/third-party-libraries
    )

add_library( empty-files-as-unicode.${PLUGIN_NAME_SUFFIX} MODULE
    source/plugin/menu.cpp
    source/plugin/plugin-dll-interface.cpp
    source/plugin/@libraries/console-output.include.cpp
    source/plugin/@libraries/tinyxml2.include.cpp
    )

#requires cmake 3.10
#set_property(TARGET empty-files-as-unicode.${PLUGIN_NAME_SUFFIX} PROPERTY CXX_STANDARD 17)
#set_property(TARGET empty-files-as-unicode.${PLUGIN_NAME_SUFFIX} PROPERTY CXX_STANDARD_REQUIRED ON)