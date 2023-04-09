add_executable(
        ${EXECUTABLE_APP}

        main.cpp)

target_include_directories(
        ${EXECUTABLE_APP} PUBLIC

        ${PROJECT_SOURCE_DIR})

target_link_libraries(
        ${EXECUTABLE_APP}

        ${LIBRARY_CORE})
