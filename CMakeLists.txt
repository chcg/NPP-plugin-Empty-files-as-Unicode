cmake_minimum_required( VERSION 3.10 )

project( "Notepad++ encoding fix plugin" )

if( ${CMAKE_SIZEOF_VOID_P} EQUAL 4 )
    set( PLUGIN_NAME_SUFFIX "32-bit" )
elseif( ${CMAKE_SIZEOF_VOID_P} EQUAL 8 )
    set( PLUGIN_NAME_SUFFIX "64-bit" )
else()
    message( FATAL_ERROR "The selected toolchain isn't recognized as 32-bit or 64-bit." )
endif()


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
set_property(TARGET empty-files-as-unicode.${PLUGIN_NAME_SUFFIX} PROPERTY CXX_STANDARD 17)
set_property(TARGET empty-files-as-unicode.${PLUGIN_NAME_SUFFIX} PROPERTY CXX_STANDARD_REQUIRED ON)

# avoid compiler warning C4996: 'std::codecvt_mode': warning STL4017: std::wbuffer_convert, std::wstring_convert, and the <codecvt> header (containing std::codecvt_mode, std::codecvt_utf8, std::codecvt_utf16, and std::codecvt_utf8_utf16) are deprecated in C++17.
ADD_DEFINITIONS(-D_SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING)