if (TUTORIAL_GENERATE_DOCS)
    configure_file(src/Doxyfile.in Doxyfile)
    set(DOXYGEN_SKIP_DOT ON)
    find_package(Doxygen)
    if(DOXYGEN_FOUND)
        add_custom_target(
            docs ALL
            COMMAND ${DOXYGEN_EXECUTABLE} Doxyfile
        )
    else(DOXYGEN_FOUND)
        message(WARNING "Doxygen not found, docs generation skiped")
    endif(DOXYGEN_FOUND)
endif(TUTORIAL_GENERATE_DOCS)