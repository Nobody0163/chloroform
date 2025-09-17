project(ChloroformTesting)

file(GLOB_RECURSE files ./*.hpp ./*.cpp)

add_executable(ChloroformTesting ${files})
target_link_libraries(ChloroformTesting Chloroform)