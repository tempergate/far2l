project(ImageViewer)

set(SOURCES
    ImageViewer.cpp
)

add_library (ImageViewer MODULE ${SOURCES})
target_link_libraries(ImageViewer utils far2l)
target_compile_definitions(ImageViewer PRIVATE -DWINPORT_DIRECT -DUNICODE)

target_include_directories(${PROJECT_NAME} PRIVATE .)
target_include_directories(${PROJECT_NAME} PRIVATE ../far2l/far2sdk)
target_include_directories(${PROJECT_NAME} PRIVATE ../WinPort)
target_include_directories(${PROJECT_NAME} PRIVATE ../utils/include)

set_target_properties(${PROJECT_NAME} PROPERTIES
	LIBRARY_OUTPUT_DIRECTORY "${INSTALL_DIR}/Plugins/${PROJECT_NAME}/plug"
	PREFIX ""
	SUFFIX ".far-plug-wide")

set(CURRENT_TARGET "ImageViewer")


file(GLOB_RECURSE RESOURCE_FILES
        RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/configs
        "${CMAKE_CURRENT_SOURCE_DIR}/configs/*"
)

add_dependencies(${CURRENT_TARGET} copy_aux_files_for_${CURRENT_TARGET})