function(add_kc_test name)
  set(source_name "kc${name}test")

  add_executable(${source_name} ${source_name} testutil.cc ${ARGV1})
  target_link_libraries(${source_name} kyotocabinet)

  find_library(BOOST_FILESYSTEM_STATIC_LIBRARY libboost_filesystem.a)
  target_link_libraries(${source_name} ${BOOST_FILESYSTEM_STATIC_LIBRARY})

  find_library(BOOST_SYSTEM_STATIC_LIBRARY libboost_system.a)
  target_link_libraries(${source_name} ${BOOST_SYSTEM_STATIC_LIBRARY})

  add_test(NAME ${source_name} COMMAND ${source_name} WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
 
  set(check_task "check-${name}")

  add_custom_target(${check_task} COMMAND ${CMAKE_CTEST_COMMAND} -R ${source_name})
  add_dependencies(${check_task} ${source_name})
  add_dependencies(check ${check_task})
endfunction()
 
add_kc_test(util ../src/kcutilmgr_impl.cc)
add_kc_test(proto)
add_kc_test(stash)
add_kc_test(cache)
add_kc_test(grass)
add_kc_test(hash ../src/kchashmgr_impl.cc)
add_kc_test(tree ../src/kctreemgr_impl.cc)
add_kc_test(dir ../src/kcdirmgr_impl.cc)
add_kc_test(forest ../src/kcforestmgr_impl.cc)
add_kc_test(poly ../src/kcpolymgr_impl.cc)
add_kc_test(langc)
