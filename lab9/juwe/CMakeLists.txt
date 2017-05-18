
project(juwe)

set(HEDEAR_FILES Prowiant.h Piwo.h Tymbark.h TanieWino.h Wodka.h Woda.h Plecak.h Student.h Sklep.h Apka.h)
set(SOURCE_FILES Prowiant.cpp Piwo.cpp Tymbark.cpp TanieWino.cpp Wodka.cpp Woda.cpp Plecak.cpp Student.cpp Sklep.cpp Apka.cpp)

add_library(libjuwe STATIC ${SOURCE_FILES})
target_include_directories(libjuwe PUBLIC .)

add_executable(juwe ${SOURCE_FILES} main.cpp)

target_link_libraries(juwe libjuwe)

