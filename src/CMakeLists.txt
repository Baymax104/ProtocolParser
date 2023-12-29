set(INCLUDE_DIR ../lib/Include)
set(LINK_DIR ../lib/Lib/x64)

include_directories(${INCLUDE_DIR})
link_directories(${LINK_DIR})
link_libraries(Packet wpcap)

aux_source_directory(. SRC)

add_executable(ICMP ${SRC})