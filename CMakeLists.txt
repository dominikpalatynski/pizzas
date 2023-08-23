cmake_minimum_required(VERSION 3.11.0)


project(Pizza)
include_directories(src)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        main # release-1.10.0
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)



enable_testing()



# add_executable(${PROJECT_NAME} src/main.cpp )
add_executable(${PROJECT_NAME}-ut test/PizzeriaTest.cpp test/mocks/PizzaMock.hpp src/Pizza.cpp src/Pizza.hpp src/Pizzeria.cpp src/Funghi.cpp src/Margherita.cpp src/TimeDummy.hpp )

# target_link_libraries(${PROJECT_NAME} SRC )
target_link_libraries(${PROJECT_NAME}-ut gtest_main)
target_link_libraries(${PROJECT_NAME}-ut gmock_main)



include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}-ut)