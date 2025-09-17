project(Chloroform)

file(GLOB_RECURSE files *.hpp *.cpp)

add_library(Chloroform SHARED ${files})
target_include_directories(Chloroform PUBLIC .)