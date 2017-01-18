#  Copyright (c) 2016, https://github.com/nebula-im
#  All rights reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

cmake_minimum_required(VERSION 2.8)

project(clientsdk C CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11")
add_compile_options(-fPIC)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

IF(APPLE)
  add_definitions(-DENV_MACOSX)
  FIND_LIBRARY(COREFOUNDATION_LIBRARY CoreFoundation)
  FIND_LIBRARY(FOUNDATION_LIBRARY Foundation)
  FIND_LIBRARY(SYSTEMCONFIGURATION_LIBRARY SystemConfiguration)
  FIND_LIBRARY(NETWORKEXTENSION_LIBRARY NetworkExtension)
  FIND_LIBRARY(CFNETWORK_LIBRARY CFNetwork)
  FIND_LIBRARY(COREWLAN_LIBRARY CoreWLAN)
ENDIF(APPLE)

set(CMAKE_EXE_LINKER_FLAGS
"-framework CoreFoundation -framework CFNetwork -framework CoreWLAN -framework Foundation -framework SystemConfiguration -framework NetworkExtension"
)

include_directories(
${CMAKE_SOURCE_DIR}
${INCLUDE_DIR}
${PROJECT_SOURCE_DIR}/core/mars
${PROJECT_SOURCE_DIR}/core/mars/mars
/usr/local/include
)

link_directories(
/usr/local/lib
/usr/local/mysql/lib
${PROJECT_BINARY_DIR}/lib
)

add_subdirectory(core)
add_subdirectory(proto)
#add_subdirectory(cmdline)

