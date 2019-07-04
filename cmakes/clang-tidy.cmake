
find_program(
    CLANG_TIDY_BIN
    NAMES "clang-tidy"
    DOC "Path to clang-tidy executable"
    )
if(NOT CLANG_TIDY_BIN)
    message(STATUS "clang-tidy not found.")
else()
    message(STATUS "clang-tidy found: ${CLANG_TIDY_BIN}")
    set(DO_CLANG_TIDY "${CLANG_TIDY_BIN}" "-checks=*,-clang-analyzer-alpha.*")
endif()


set_target_properties(
    task PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
    COMPILE_FLAGS "${WARNING_FLAGS}"
)

if(CLANG_TIDY_BIN)
    set_target_properties(
        task PROPERTIES
        CXX_CLANG_TIDY "${DO_CLANG_TIDY}"
    )
endif()
