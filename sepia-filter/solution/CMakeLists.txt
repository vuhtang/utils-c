enable_language(ASM_NASM)

file(GLOB_RECURSE sources CONFIGURE_DEPENDS
        src/*.c
        src/*.h
        src/*.asm
        include/*.h
        )

add_executable(sepia-filter ${sources})
target_include_directories(sepia-filter PRIVATE src include)
