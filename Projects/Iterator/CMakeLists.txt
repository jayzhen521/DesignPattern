get_filename_component(ProjectId ${CMAKE_CURRENT_LIST_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

if(MSVC)
    file(GLOB INCLUDE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/*h)
    file(GLOB SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*cpp)
    add_executable(${ProjectId} ${SRC_FILES} ${INCLUDE_FILES} ${SHADER_FILES})
else()
    add_executable(${ProjectId} ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)
endif()

target_include_directories(${ProjectId} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include)

if(MSVC)
    set_property(TARGET ${ProjectId} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
endif()