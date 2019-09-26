# General declarations

include(GNUInstallDirs)
cmake_minimum_required(VERSION 3.0)
cmake_policy(SET CMP0048 NEW)
project(kyotocabinet VERSION 1.2.77)

# Some variables

set(LIBVER "16")
set(LIBREV "13")
set(FMTVER "2")

set(LIBRARY_VERSION "${LIBVER}.${LIBREV}.${FMTVER}")

set(SOURCE_PATH "src")
set(INCLUDE_PATH "include")
set(TESTS_PATH "tests")

# Setting paths for output

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Includes directory

include_directories(include)

# Additional compiler and linker flags

set(ADDITIONAL_CPP_FLAGS "-fPIC -Wall -Wextra -D_KC_PREFIX=\\\"${CMAKE_INSTALL_PREFIX}\\\" -D_KC_INCLUDEDIR=\\\"${CMAKE_INSTALL_INCLUDEDIR}\\\" -D_KC_LIBDIR=\\\"{CMAKE_INSTALL_LIBDIR}\\\" -D_KC_BINDIR=\\\"${CMAKE_INSTALL_BINDIR}\\\" -D_KC_LIBEXECDIR=\\\"${CMAKE_INSTALL_LIBEXECDIR}\\\" -D_KC_APPINC=\\\"${CMAKE_INSTALL_INCLUDEDIR}\\\" -D_KC_APPLIBS=\\\"${CMAKE_INSTALL_LIBDIR}\\\" -D_KC_VERSION=\\\"${PROJECT_VERSION}\\\" -D_KC_LIBVER=${LIBVER} -D_KC_LIBREV=${LIBREV} -D_KC_FMTVER=${FMTVER}")

set(CMAKE_C_FLAGS "${ADDITIONAL_CPP_FLAGS} ${CMAKE_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${ADDITIONAL_CPP_FLAGS} ${CMAKE_CXX_FLAGS}")

link_libraries(-lz -lstdc++ -lpthread -lm -lc)

# Kyotocabinet library

add_library(kyotocabinet SHARED ${SOURCE_PATH}/kcutil.cc ${SOURCE_PATH}/kcthread.cc ${SOURCE_PATH}/kcfile.cc ${SOURCE_PATH}/kccompress.cc ${SOURCE_PATH}/kccompare.cc ${SOURCE_PATH}/kcmap.cc ${SOURCE_PATH}/kcregex.cc ${SOURCE_PATH}/kcdb.cc ${SOURCE_PATH}/kcplantdb.cc ${SOURCE_PATH}/kcprotodb.cc ${SOURCE_PATH}/kcstashdb.cc ${SOURCE_PATH}/kccachedb.cc ${SOURCE_PATH}/kchashdb.cc ${SOURCE_PATH}/kcdirdb.cc ${SOURCE_PATH}/kctextdb.cc ${SOURCE_PATH}/kcpolydb.cc ${SOURCE_PATH}/kcdbext.cc ${SOURCE_PATH}/kclangc.cc ${SOURCE_PATH}/modp_b64.cc)

set_target_properties(kyotocabinet PROPERTIES VERSION ${LIBRARY_VERSION} PUBLIC_HEADER "${INCLUDE_PATH}/kccommon.h;${INCLUDE_PATH}/kcutil.h;${INCLUDE_PATH}/kcthread.h;${INCLUDE_PATH}/kcfile.h;${INCLUDE_PATH}/kccompress.h;${INCLUDE_PATH}/kccompare.h;${INCLUDE_PATH}/kcmap.h;${INCLUDE_PATH}/kcregex.h;${INCLUDE_PATH}/kcdb.h;${INCLUDE_PATH}/kcplantdb.h;${INCLUDE_PATH}/kcprotodb.h;${INCLUDE_PATH}/kcstashdb.h;${INCLUDE_PATH}/kccachedb.h;${INCLUDE_PATH}/kchashdb.h;${INCLUDE_PATH}/kcdirdb.h;${INCLUDE_PATH}/kctextdb.h;${INCLUDE_PATH}/kcpolydb.h;${INCLUDE_PATH}/kcdbext.h;${INCLUDE_PATH}/kclangc.h")

# Binaries

add_executable(kcutilmgr src/kcutilmgr.cc)
target_link_libraries(kcutilmgr kyotocabinet)

add_executable(kchashmgr src/kchashmgr.cc)
target_link_libraries(kchashmgr kyotocabinet)

add_executable(kctreemgr src/kctreemgr.cc)
target_link_libraries(kctreemgr kyotocabinet)

add_executable(kcdirmgr src/kcdirmgr.cc)
target_link_libraries(kcdirmgr kyotocabinet)

add_executable(kcforestmgr src/kcforestmgr.cc)
target_link_libraries(kcforestmgr kyotocabinet)

add_executable(kcpolymgr src/kcpolymgr.cc)
target_link_libraries(kcpolymgr kyotocabinet)

# Installation targets

install(TARGETS kyotocabinet kcutilmgr kchashmgr kctreemgr kcdirmgr kcforestmgr kcpolymgr LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

