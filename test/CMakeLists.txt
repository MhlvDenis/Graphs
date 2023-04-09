set(
        SOURCES_TEST_CORE

        core/TestAlgorithms.cpp
        core/TestIO.cpp
        core/TestJson.cpp)

set(
        SOURCES_TEST

        test.cpp
        ${SOURCES_TEST_CORE})

add_executable(
        ${EXECUTABLE_TEST}

        ${SOURCES_TEST})

target_include_directories(
        ${EXECUTABLE_TEST} PUBLIC

        ${PROJECT_SOURCE_DIR}
        ${INCLUDE_GTEST})

target_link_libraries(
        ${EXECUTABLE_TEST}

        ${LIBRARY_CORE}
        ${LIBRARY_GTEST})
