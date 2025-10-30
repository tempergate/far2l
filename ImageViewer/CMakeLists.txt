project(ImageViewer)

set(SOURCES
    ImageViewer.cpp
)

add_library(${PROJECT_NAME} MODULE ${SOURCES})

target_link_libraries(${PROJECT_NAME} utils far2l)

target_compile_definitions(${PROJECT_NAME} PRIVATE -DWINPORT_DIRECT -DUNICODE)

target_include_directories(${PROJECT_NAME} PRIVATE ../far2l/far2sdk)
target_include_directories(${PROJECT_NAME} PRIVATE ../WinPort)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY "${INSTALL_DIR}/Plugins/${PROJECT_NAME}/plug"
        PREFIX ""
        SUFFIX ".far-plug-wide")

set(CURRENT_TARGET "ImageViewer")

# If you have any resource/config files to install, add them here
# For example, if you have config files:
# file(GLOB_RECURSE RESOURCE_FILES
#         RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/configs
#         "${CMAKE_CURRENT_SOURCE_DIR}/configs/*"
# )
# 
# setup_target_auxiliary_files(${CURRENT_TARGET}
#         RESOURCE_FILES
#         ${CMAKE_CURRENT_SOURCE_DIR}/configs
#         "${INSTALL_DIR}/Plugins/${CURRENT_TARGET}/plug"
# )
# 
# add_dependencies(${CURRENT_TARGET} copy_aux_files_for_${CURRENT_TARGET})

# Install from the custom build location
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/output/${PROJECT_NAME}.far-plug-wide"
    DESTINATION "${INSTALL_DIR}/Plugins/ImageViewer/plug"
    OPTIONAL
)

# If you need to install additional files (headers, configs, etc.)
# install(FILES ${RESOURCE_FILES} 
#     DESTINATION "${INSTALL_DIR}/Plugins/${PROJECT_NAME}/plug"
# )