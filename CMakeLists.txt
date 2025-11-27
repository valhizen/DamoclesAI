# CMakeList.txt : CMake project for DamoclesAI, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.10)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("DamoclesAI")

# Explicit, stable list of sources and headers for reliable dependency tracking.
set(DAMOCLESAI_SOURCES
  "${CMAKE_SOURCE_DIR}/src/DamoclesAI.cpp"
 "src/FileLoader.cpp"  "src/Encoder.cpp" "src/Vocabulary.cpp")

set(DAMOCLESAI_HEADERS
 "src/DamoclesAI.h"
"src/FileLoader.h"
 "src/Encoder.h" "src/Vocabulary.h")

# Add source to this project's executable.
add_executable (DamoclesAI
  ${DAMOCLESAI_SOURCES}
  ${DAMOCLESAI_HEADERS}
)

# Ensure target uses C++20 when supported (keeps original conditional behavior).
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET DamoclesAI PROPERTY CXX_STANDARD 20)
endif()

# Make headers available to the target (private include).
target_include_directories(DamoclesAI PRIVATE "${CMAKE_SOURCE_DIR}/include")

# TODO: Add tests and install targets if needed.
