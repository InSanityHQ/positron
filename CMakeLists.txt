cmake_minimum_required(VERSION 3.10.0)
project(positron VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SURF_VERSION 2.1)

find_package(PkgConfig REQUIRED)

pkg_check_modules(PKGDEPDS REQUIRED IMPORTED_TARGET
    x11
    gcr-3
    glib-2.0
    gio-2.0
    gtk+-3.0
    webkit2gtk-4.0
    webkit2gtk-web-extension-4.0)

add_executable(surf 
    surf/surf.c 
    surf/webext-surf.c)

target_include_directories(surf PUBLIC PkgConfig::PKGDEPDS)
target_link_libraries(surf PUBLIC PkgConfig::PKGDEPDS)
target_compile_definitions(surf PUBLIC 
    VERSION="${SURF_VERSION}" 
    GCR_API_SUBJECT_TO_CHANGE)

