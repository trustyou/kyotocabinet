ADD_EXECUTABLE(kcutiltest kcutiltest.cc testutil.cc ../src/kcutilmgr_impl.cc)
target_link_libraries(kcutiltest kyotocabinet)
ADD_TEST(NAME kcutiltest COMMAND kcutiltest WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
add_dependencies(check kcutiltest)

ADD_EXECUTABLE(kchashtest kchashtest.cc testutil.cc ../src/kchashmgr_impl.cc)
target_link_libraries(kchashtest kyotocabinet)
ADD_TEST(NAME kchashtest COMMAND kchashtest WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
add_dependencies(check kchashtest)
