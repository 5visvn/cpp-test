project(chapterFirstExample)
cmake_minimum_required(VERSION 2.6)

include_directories(
  # $ENV{BOOST_ROOT}
  $ENV{GMOCK_HOME}/googlemock/include
  $ENV{GMOCK_HOME}/googletest/include
)

link_directories(
  $ENV{GMOCK_HOME}/googlemock/mybuild
  $ENV{GMOCK_HOME}/googletest/mybuild
  # $ENV{BOOST_ROOT}/lib
)

# set(Boost_USE_STATIC_LIBS ON)

add_definitions(-std=c++11)

# find_package(
  # Boost $ENV{BOOST_VERSION}
  # COMPONENTS filesystem system
# )

set(
  sources
  main.cc
  SubscriberPot.cc
  SubscriberPod.cc
  ReflectTest.cc
)

add_executable(
  Reflect ${sources}
)

target_link_libraries(
  Reflect
  # ${Boost_LIBRARIES}
  gmock
  gtest
  pthread
)


