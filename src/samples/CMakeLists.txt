macro(add_sample sample_name)
    add_executable(${sample_name} ${ARGN})
    target_link_libraries(${sample_name} GlTutorial)
    target_include_directories(${sample_name} PRIVATE ../lib/)
endmacro(add_sample)

file(GLOB samples_dirs RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/*)
foreach(dir ${samples_dirs})
    if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${dir})
        file(
            GLOB sample_sources 
            RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} 
            ${CMAKE_CURRENT_SOURCE_DIR}/${dir}/*.cpp 
            ${CMAKE_CURRENT_SOURCE_DIR}/${dir}/*.h
        )
        message(STATUS "Sample ${dir}: ${sample_sources}")
        add_sample(${dir} ${sample_sources})
    endif(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${dir})
endforeach(dir ${samples_dirs})

