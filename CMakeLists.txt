cmake_minimum_required(VERSION 3.21)
project(archive_repo)

set(CMAKE_CXX_STANDARD 20)

find_package(Boost CONFIG REQUIRED COMPONENTS serialization)

add_executable(archive_repro main.cpp base.cc derived_one.cc holder.cc util.cc)
target_link_libraries(archive_repro PRIVATE Boost::serialization)
