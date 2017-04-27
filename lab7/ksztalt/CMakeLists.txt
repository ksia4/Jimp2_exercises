project(ksztalt)

set(HEDEAR_FILES Ksztalt.h Kwadrat.h Trojkat.h)
set(SOURCE_FILES Ksztalt.cpp Kwadrat.cpp Trojkat.cpp)

add_library(libksztalt STATIC ${SOURCE_FILES})
target_include_directories(libksztalt PUBLIC .)

add_executable(ksztalt ${SOURCE_FILES} main.cpp)

target_link_libraries(ksztalt libksztalt)