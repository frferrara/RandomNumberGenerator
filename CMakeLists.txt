cmake_minimum_required( VERSION 2.8 )

project( RandNumGen )

set( CMAKE_BUILD_TYPE "Release" )

set( CMAKE_CXX_FLAGS_DEBUG "-W -Wextra -g -O0" )
set( CMAKE_CXX_FLAGS_RELEASE "" )

include_directories( ${PROJECT_SOURCE_DIR}/RNGInterface
                     ${PROJECT_SOURCE_DIR}/RandomNumberGenerator
                     ${PROJECT_SOURCE_DIR}/Ran32
                     ${PROJECT_SOURCE_DIR}/Ran64
                     ${PROJECT_SOURCE_DIR}/Marsaglia32
                     ${PROJECT_SOURCE_DIR}/Marsaglia64 )
add_subdirectory( RNGInterface )
add_subdirectory( RandomNumberGenerator )
add_subdirectory( Ran32 )
add_subdirectory( Ran64 )
add_subdirectory( Marsaglia32 )
add_subdirectory( Marsaglia64 )

add_executable( main main.cpp )
target_link_libraries( main 
                       RandomNumberGenerator
                       Ran32
                       Ran64
                       Marsaglia32
                       Marsaglia64 )