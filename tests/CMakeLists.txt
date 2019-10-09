# General declarations

enable_testing()

# Some variables

set(SOURCE_DIR src)
set(PARENT_SOURCE_DIR ../src)

# Static boost libraries

find_library(BOOST_FILESYSTEM_STATIC_LIBRARY libboost_filesystem.a)
find_library(BOOST_SYSTEM_STATIC_LIBRARY libboost_system.a)

# Custom check target (semi-compatible with GNU Autotools target)

add_custom_target(check)

# Includes directory

include_directories(include ../include)

# Binaries

function(add_kc_test_binary source_name)
  add_executable(${source_name} ${SOURCE_DIR}/${source_name} ${SOURCE_DIR}/${source_name}_impl)
  target_link_libraries(${source_name} kyotocabinet)
  install(TARGETS ${source_name} RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
endfunction()

add_kc_test_binary(kcutiltest)
add_kc_test_binary(kcprototest)
add_kc_test_binary(kcstashtest)
add_kc_test_binary(kccachetest)
add_kc_test_binary(kcgrasstest)
add_kc_test_binary(kchashtest)
add_kc_test_binary(kctreetest)
add_kc_test_binary(kcdirtest)
add_kc_test_binary(kcforesttest)
add_kc_test_binary(kcpolytest)
add_kc_test_binary(kclangctest)

# Tests

function(add_kc_test check_task test_binary_name)
  set(check_task_executable "${check_task}-bin")

  add_executable(${check_task_executable} EXCLUDE_FROM_ALL ${SOURCE_DIR}/${check_task} ${SOURCE_DIR}/${test_binary_name}_impl ${SOURCE_DIR}/testutil ${ARGV2})
  target_link_libraries(${check_task_executable} kyotocabinet ${BOOST_FILESYSTEM_STATIC_LIBRARY} ${BOOST_SYSTEM_STATIC_LIBRARY})
  add_test(NAME ${check_task} COMMAND ${check_task_executable} WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

  add_custom_target(${check_task} COMMAND ${CMAKE_CTEST_COMMAND} -R ${check_task})
  add_dependencies(${check_task} ${check_task_executable})
  add_dependencies(check ${check_task})
endfunction()

add_kc_test(check-util kcutiltest ${PARENT_SOURCE_DIR}/kcutilmgr_impl)
add_kc_test(check-proto kcprototest)
add_kc_test(check-stash kcstashtest)
add_kc_test(check-cache kccachetest)
add_kc_test(check-grass kcgrasstest)
add_kc_test(check-hash kchashtest ${PARENT_SOURCE_DIR}/kchashmgr_impl)
add_kc_test(check-tree kctreetest ${PARENT_SOURCE_DIR}/kctreemgr_impl)
add_kc_test(check-dir kcdirtest ${PARENT_SOURCE_DIR}/kcdirmgr_impl)
add_kc_test(check-forest kcforesttest ${PARENT_SOURCE_DIR}/kcforestmgr_impl)
add_kc_test(check-poly kcpolytest ${PARENT_SOURCE_DIR}/kcpolymgr_impl)
add_kc_test(check-langc kclangctest)
