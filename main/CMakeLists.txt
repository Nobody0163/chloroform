project(Chloroform)

file(GLOB_RECURSE files *.hpp *.cpp)

add_library(Chloroform SHARED ${files})
target_link_libraries(Chloroform nlohmann_json::nlohmann_json)
target_include_directories(Chloroform PUBLIC .)