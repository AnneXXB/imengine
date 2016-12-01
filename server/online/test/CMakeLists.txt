include_directories(/usr/local/include ../..)

set (SRC_LIST
  online_session_manager_test.cc
)

add_executable (online_session_manager_test ${SRC_LIST})
target_link_libraries (online_session_manager_test nebula api_proto)


