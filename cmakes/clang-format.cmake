
# foreach (SOURCE_FILE ${ALL_SOURCES})
#     message(${SOURCE_FILE})
# endforeach ()

add_custom_target(
        clangformat
        COMMAND /usr/bin/clang-format
        -style=LLVM
        -i
        ${ALL_SOURCES}
)
