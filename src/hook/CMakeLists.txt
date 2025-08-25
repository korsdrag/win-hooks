# add_library(win-hooklib)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

target_compile_features(win-hooklib PUBLIC cxx_std_23)
target_compile_options(win-hooklib PUBLIC /W4 /WX /Debug /Od)

# target_link_libraries(win-hook PUBLIC -lstdc++exp)
target_link_libraries(win-hook PUBLIC win-hooklib)
