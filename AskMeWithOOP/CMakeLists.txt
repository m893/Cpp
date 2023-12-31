project(AskMe)

set(src_files 
 .\source\HelperFunctions.cpp 
 .\source\main.cpp 
 .\source\System.cpp 
 .\source\User.cpp 
 .\source\Question.cpp)

set(header_h
 HelperFunctions.hpp
 System.hpp
 User.hpp
 Question.hpp )

#message(${src_files})
 
add_executable(AskMe ${src_files})

#target_include_directories(AskMe PUBLIC ${header_h})