# add_library(win-hooklib STATIC)
set(CMAKE_CXX_STANDARD 23 ON)

add_executable(win-hook
    main.cpp
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


target_compile_features(win-hook PUBLIC cxx_std_23)
target_compile_definitions(win-hook PUBLIC -DNOMINMAX)
target_compile_options(win-hook PUBLIC /W4 /WX /Debug /Od)

# target_link_libraries(win-hook PUBLIC -lstdc++exp)
# target_link_libraries(win-hook PUBLIC exe-core)
