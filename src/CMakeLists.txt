add_library(winlib STATIC)
add_library(consolelib STATIC)

add_subdirectory(hooks)
add_subdirectory(events)
add_subdirectory(utils)
add_subdirectory(registry)
add_subdirectory(console)

add_executable(win-hack
    main.cpp
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


target_compile_features(winlib PUBLIC cxx_std_23)
target_compile_definitions(winlib PUBLIC -DNOMINMAX)

# target_compile_options(winlib PUBLIC /W4 /WX /Debug /Od)
target_compile_options(winlib PUBLIC -Wall -Werror -Wextra)


target_compile_features(consolelib PUBLIC cxx_std_23)
target_compile_definitions(consolelib PUBLIC -DNOMINMAX)

# target_compile_options(consolelib PUBLIC /W4 /WX /Debug /Od)
target_compile_options(consolelib PUBLIC -Wall -Werror -Wextra)


# target_link_libraries(winlib PUBLIC -lstdc++exp)
target_link_libraries(win-hack PUBLIC winlib consolelib)

target_include_directories(winlib PUBLIC ${PROJECT_SOURCE_DIR}/ ${PROJECT_SOURCE_DIR}/src)
target_include_directories(consolelib PUBLIC ${PROJECT_SOURCE_DIR}/ ${PROJECT_SOURCE_DIR}/src)
