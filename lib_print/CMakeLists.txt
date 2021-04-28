function(add_my_print_library name static_or_shared)
    add_library(
        ${name}
        ${static_or_shared}
        src/my_print.cpp
    )
    #target_link_libraries(
    #    ${name}
    #    $<IF:$<STREQUAL:${TYPE},SHARED>,my_math,my_math_static>
    #    #my_math
    #    )
    if(${static_or_shared} STREQUAL SHARED)
        target_link_libraries(
            ${name}
            my_math
            )
    endif()

    if(${static_or_shared} STREQUAL STATIC)
        target_link_libraries(
            ${name}
            my_math_static
            )
    endif()
    target_include_directories(
        ${name}
        PUBLIC
        include
        ../my_math/include
        ${MY_MATH_BINARY_DIR}
        )
    set_target_properties(
        ${name}
        PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
        )
endfunction()
add_my_print_library(my_print_static STATIC)
add_my_print_library(my_print SHARED)

