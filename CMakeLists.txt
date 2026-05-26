cmake_minimum_required(VERSION 3.16)
project(sdl3Engine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    ${CMAKE_SOURCE_DIR}/src/*.cpp
)

list(FILTER SOURCES EXCLUDE REGEX ".*/build/.*")

add_executable(app ${SOURCES})

target_include_directories(app PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

target_compile_options(app PRIVATE
  -Wall -Wextra -Werror -Wno-error=unused-variable
)

# -------------------------
# SDL3
# -------------------------
find_package(SDL3 REQUIRED)
target_link_libraries(app PRIVATE SDL3::SDL3)

# -------------------------
# SDL3_image
# -------------------------
find_package(SDL3_image REQUIRED)
target_link_libraries(app PRIVATE SDL3_image::SDL3_image)

# -------------------------
# SDL3_ttf
# -------------------------
find_package(PkgConfig REQUIRED)

pkg_check_modules(SDL3_TTF REQUIRED sdl3-ttf)

target_include_directories(app PRIVATE ${SDL3_TTF_INCLUDE_DIRS})
target_link_libraries(app PRIVATE ${SDL3_TTF_LIBRARIES})
# -------------------------
# Doxygen
# -------------------------
find_package(Doxygen REQUIRED)

if(DOXYGEN_FOUND)
    set(DOXYGEN_IN ${CMAKE_SOURCE_DIR}/Doxyfile)

    add_custom_target(doc_doxygen
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_IN}
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM
    )
endif()
