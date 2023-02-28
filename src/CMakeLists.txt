configure_file(lib/Version.hpp.in ${CMAKE_CURRENT_SOURCE_DIR}/lib/Version.hpp)
file(
    GLOB_RECURSE
    TUTORIAL_HEADER_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/*.hpp
)

foreach(header ${TUTORIAL_HEADER_FILES})
    set_source_files_properties(${header} PROPERTIES LANGUAGE CXX)
endforeach(header ${TUTORIAL_HEADER_FILES})
add_library(GlTutorial STATIC ${TUTORIAL_HEADER_FILES})
target_include_directories(GlTutorial PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib)
target_link_libraries(GlTutorial glfw glad spdlog::spdlog)
set_target_properties(GlTutorial PROPERTIES LINKER_LANGUAGE CXX)
add_subdirectory(samples)