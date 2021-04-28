function(add_my_math_library name static_or_shared)
    add_library(
        ${name}
        ${static_or_shared}
        src/my_math.cpp
        )
    target_include_directories(${name}
        PUBLIC
        include
        ${CMAKE_CURRENT_BINARY_DIR}
        )
    
    #if(${static_or_shared} STREQUAL STATIC)
    #    target_compile_definitions(
    #        ${name}
    #        PRIVATE
    #        my_math_STATIC
    #        )
    #endif()

    set_target_properties(
        ${name}
        PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
	WINDOWS_EXPORT_ALL_SYMBOLS ON
        )
endfunction()

add_my_math_library(my_math_static STATIC)
add_my_math_library(my_math SHARED)
include(GenerateExportHeader)
generate_export_header(my_math)
generate_export_header(my_math_static)
set(MY_MATH_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR})
