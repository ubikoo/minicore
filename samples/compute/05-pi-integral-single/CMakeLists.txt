project(05-pi-integral-single)

add_executable(${PROJECT_NAME}
    main.cpp
    model.cpp
    common.h
    model.h)

target_link_libraries(${PROJECT_NAME} PRIVATE corebase coremath corecompute)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR})

file(COPY data DESTINATION ${PROJECT_BINARY_DIR})
