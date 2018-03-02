cmake_minimum_required(VERSION 3.9)
cmake_policy(SET CMP0054 OLD)

include("cmake/HunterGate.cmake")
HunterGate(
        URL "https://github.com/ruslo/hunter/archive/v0.20.13.tar.gz"
        SHA1 "d92042d6e22522516183b86da10e56fb1af73f7a"
)

project(sqlite_server)
set(CMAKE_CXX_STANDARD 14)

hunter_add_package(Boost COMPONENTS regex system filesystem thread)
find_package(Boost CONFIG REQUIRED regex system filesystem thread)

hunter_add_package(nlohmann_json)
find_package(nlohmann_json CONFIG REQUIRED)

hunter_add_package(fmt)
find_package(fmt CONFIG REQUIRED)

add_executable(sqlite_server main.cpp ListenSocket.h Network.h Socket.h SQLiteSocket.cpp SQLiteSocket.h)
target_link_libraries(sqlite_server PUBLIC nlohmann_json fmt::fmt-header-only Boost::regex Boost::system Boost::filesystem Boost::thread)
