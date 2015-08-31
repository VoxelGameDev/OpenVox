 file(GLOB_RECURSIVE h_target_files ${CMAKE_CURRENT_LIST_DIR}/include/*.h})
 file(GLOB_RECURSIVE hpp_target_files ${CMAKE_CURRENT_LIST_DIR}/include/*.hpp})
 file(GLOB_RECURSIVE inl_target_files ${CMAKE_CURRENT_LIST_DIR}/include/*.inl})
 file(GLOB_RECURSIVE cpp_target_files ${CMAKE_CURRENT_LIST_DIR}/src/*.cpp})
 
 ADD_LIBRARY(Engine ALL SOURCES
   ${h_target_files}
   ${hpp_target_files}
   ${inl_target_files}
   ${cpp_target_files}
 )