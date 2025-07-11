cmake_minimum_required(VERSION 3.15..4.0)

project(PubIP VERSION 1.0.0
	DESCRIPTION "Fetch public IP from an API endpoint."
	LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
			 GIT_TAG da40186618909b1a7363d4e4495aa899c6e0eb75) #1.12.0
FetchContent_MakeAvailable(cpr)

FetchContent_Declare(fmt GIT_REPOSITORY https://github.com/fmtlib/fmt
			 GIT_TAG 40626af88bd7df9a5fb80be7b25ac85b122d6c21) #11.2.0
FetchContent_MakeAvailable(fmt)

add_executable(pubip main.cpp)
target_compile_features(pubip PUBLIC cxx_std_23)
set_target_properties(pubip PROPERTIES CXX_EXTENSIONS OFF)
target_link_libraries(pubip PRIVATE fmt::fmt
			    PRIVATE cpr::cpr)
