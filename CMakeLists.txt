cmake_minimum_required(VERSION 3.15)

# ป้องกันข้อผิดพลาด Compatibility กับเวอร์ชัน CMake ที่ใหม่เกินไป
if(POLICY CMP0177)
    cmake_policy(SET CMP0177 NEW)
endif()

project(DoMeAFavorGame VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/5.0.tar.gz
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE  # แก้ไข Warning เรื่อง Timestamp
)

set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(raylib)

# กำหนด Include directories ให้ตรงกับโปรเจกต์ (ถ้ามีโฟลเดอร์ include แยก หรือจะใช้ src ด้วยก็ได้)
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/src)

# ใช้ GLOB_RECURSE เพื่อดึงไฟล์ .cpp ทั้งหมดในโฟลเดอร์ src และ Sub-folder ทุกชั้นโดยอัตโนมัติ
file(GLOB_RECURSE SOURCES "src/*.cpp")

# [จุดสำคัญ] เพิ่ม WIN32 ตรงนี้ เพื่อบอก CMake ว่านี่คือ Windows GUI Application (แก้ปัญหา WinMain)
# หากต้องการให้มีหน้าต่าง Console ดำๆ ขึ้นมาแสดง Log ด้วย ให้ลบคำว่า WIN32 ออกครับ
add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

if(WIN32)
    target_link_libraries(${PROJECT_NAME} PRIVATE winmm ole32 shell32)
endif()