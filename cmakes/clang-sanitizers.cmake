
message("USE_SANITIZER=${USE_SANITIZER}")
message("CMAKE_CXX_FLAGS=${CMAKE_CXX_FLAGS}")

function(append value)
    foreach(variable ${ARGN})
        set(${variable} "${${variable}} ${value}" PARENT_SCOPE)
    endforeach(variable)
endfunction()

if(USE_SANITIZER)
    append("-g" CMAKE_C_FLAGS CMAKE_CXX_FLAGS)

    if(USE_SANITIZER MATCHES "([Ll]eak)")
        message(STATUS "Building with Leak sanitizer")

        append("-fsanitize=leak" CMAKE_C_FLAGS CMAKE_CXX_FLAGS)

    elseif("${USE_SANITIZER}" MATCHES "([Aa]ddress)")
        message(STATUS "Building with Address sanitizer")
        append("-O1" CMAKE_C_FLAGS CMAKE_CXX_FLAGS)
        append("-fno-omit-frame-pointer" CMAKE_C_FLAGS CMAKE_CXX_FLAGS)

        append("-fsanitize=address" CMAKE_C_FLAGS CMAKE_CXX_FLAGS)

    elseif(USE_SANITIZER MATCHES "([Tt]hread)")
        message(STATUS "Building with Thread sanitizer")
        append("-O1" CMAKE_C_FLAGS CMAKE_CXX_FLAGS)

        append("-fsanitize=thread" CMAKE_C_FLAGS CMAKE_CXX_FLAGS)

    elseif("${USE_SANITIZER}" MATCHES "([Mm]emory)")
        message(STATUS "Building with Memory sanitizer")
        append("-O1" CMAKE_C_FLAGS CMAKE_CXX_FLAGS)
        append("-fno-omit-frame-pointer" CMAKE_C_FLAGS CMAKE_CXX_FLAGS)

        append("-fsanitize=memory" CMAKE_C_FLAGS CMAKE_CXX_FLAGS)

    elseif("${USE_SANITIZER}" MATCHES "([Uu]ndefined)")
        message(STATUS "Building with undefined sanitizer")

        append("-fsanitize=undefined" CMAKE_C_FLAGS CMAKE_CXX_FLAGS)

    else()
        message(
        FATAL_ERROR "Unsupported value of USE_SANITIZER: ${USE_SANITIZER}")
    endif()
endif()


message("CMAKE_CXX_FLAGS=${CMAKE_CXX_FLAGS}")
