cmake_minimum_required(VERSION 3.1)

project(sample_basic)

include(${PROJECT_SOURCE_DIR}/../libdf3d/cmake/libdf3d.cmake)

find_package(Boost REQUIRED)

set(sample_basic_HEADER_FILES
    SampleBasicAppDelegate.h
)

set(sample_basic_SOURCE_FILES
    SampleBasicAppDelegate.cpp
    main.cpp
)

include_directories(
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/../libdf3d/libdf3d
    ${PROJECT_SOURCE_DIR}/../libdf3d/third-party
    ${PROJECT_SOURCE_DIR}/../libdf3d/third-party/bullet/src
    ${PROJECT_SOURCE_DIR}/../libdf3d/third-party/spark/include
    ${PROJECT_SOURCE_DIR}/../libdf3d/third-party/libRocket/Include
    ${Boost_INCLUDE_DIRS}
)

add_definitions(-DBULLET_FORCE_NO_ALIGNMENT)

if (DF3D_BUILD_SHARED_LIB)
    message(STATUS "df3d is shared")
    add_definitions(-DJSON_DLL -DDF3D_SHARED_LIBRARY)
endif()

if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zm200 /wd\"4138\" /wd\"4251\" /wd\"4457\" /wd\"4458\"")

    add_definitions(-D_SCL_SECURE_NO_WARNINGS)
endif()

add_executable(sample_basic
    ${sample_basic_HEADER_FILES}
    ${sample_basic_SOURCE_FILES}
)

TARGET_LINK_LIBRARIES(sample_basic libdf3d)

if (WINDOWS)
    set(PROJECT_BINARY_DIR ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

    function(copy_dll dll_name)
        add_custom_command(TARGET sample_basic
            POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy ${dll_name} ${PROJECT_BINARY_DIR}/.
        )
    endfunction()

    copy_dll(${PROJECT_SOURCE_DIR}/../libdf3d/third-party/prebuilt_win32/OpenAL32.dll)
endif()
