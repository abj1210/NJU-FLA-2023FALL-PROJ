project(turing)

add_subdirectory(TuringMachine)

add_subdirectory(ReadTMfile)

add_executable(${PROJECT_NAME} main.cpp)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../bin)

target_link_libraries(${PROJECT_NAME} PUBLIC Readtmfile)

target_include_directories(${PROJECT_NAME} PUBLIC
                           ${PROJECT_BINARY_DIR}
                           ${PROJECT_SOURCE_DIR}/ReadTMfile
                           )

target_link_libraries(${PROJECT_NAME} PUBLIC Tmachine)

target_include_directories(${PROJECT_NAME} PUBLIC
                           ${PROJECT_BINARY_DIR}
                           ${PROJECT_SOURCE_DIR}/TuringMachine
                           )