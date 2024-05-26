cmake_minimum_required(VERSION 3.10)
project(LibrarySystem)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set paths for SQLite3
set(SQLITE3_INCLUDE_DIR "/Users/markuseichelhardt/anaconda3/include")
set(SQLITE3_LIBRARY "/Users/markuseichelhardt/anaconda3/lib/libsqlite3.dylib")

# Add the executable
add_executable(LibrarySystem
    main.cc
    book.cc
    database.cc
    library.cc
    user.cc
)

# Include directories
target_include_directories(LibrarySystem
    PRIVATE
    ${SQLITE3_INCLUDE_DIR}
)

# Link libraries
target_link_libraries(LibrarySystem
    PRIVATE
    ${SQLITE3_LIBRARY}
)
