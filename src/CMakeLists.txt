# build sources
SET(src "")

# add current directory to sources
SET(current_dir ${CMAKE_CURRENT_LIST_DIR})
aux_source_directory(${current_dir} src)

# build project with sources
add_executable(${CMAKE_PROJECT_NAME} ${src})
