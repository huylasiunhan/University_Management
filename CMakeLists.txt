cmake_minimum_required(VERSION 3.14)
project(UniversityManagement)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ============================================
# Include tất cả thư mục con trong SOURCE_CODE
# ============================================

include_directories(
    SOURCE_CODE/MAIN
    SOURCE_CODE/LOGIC/SCHEDULE_SERVICE
    SOURCE_CODE/LOGIC/CLASS_SECTION_SERVICE
    SOURCE_CODE/LOGIC/MajorService
    SOURCE_CODE/LOGIC/SCORE_SERVICE
    SOURCE_CODE/LOGIC/CourseService
    SOURCE_CODE/LOGIC/RegistrationService
    SOURCE_CODE/MODULE/HEADER
    SOURCE_CODE/MODULE/IMPLEMENTATION
    SOURCE_CODE/DATA/STORAGE
    SOURCE_CODE/DATA/DATA_ACCESSING
)

# ===============================
# Build ứng dụng chính (main.cpp)
# ===============================

add_executable(main_exec
    SOURCE_CODE/MAIN/main.cpp

    # MODULE
    SOURCE_CODE/MODULE/SOURCE/Student.cpp
    SOURCE_CODE/MODULE/SOURCE/ClassSection.cpp
    SOURCE_CODE/MODULE/SOURCE/Score.cpp
    SOURCE_CODE/MODULE/SOURCE/Time.cpp
    SOURCE_CODE/MODULE/SOURCE/Person.cpp
    SOURCE_CODE/MODULE/SOURCE/Teacher.cpp
    SOURCE_CODE/MODULE/SOURCE/Major.cpp
    SOURCE_CODE/MODULE/SOURCE/Course.cpp

    # LOGIC
    SOURCE_CODE/LOGIC/MAJOR_SERVICE/MajorService.cpp
    SOURCE_CODE/LOGIC/CLASS_SECTION_SERVICE/ClassSectionService.cpp
    SOURCE_CODE/LOGIC/SCHEDULE_SERVICE/ScheduleService.cpp
    SOURCE_CODE/LOGIC/SCORE_SERVICE/ScoreService.cpp
    SOURCE_CODE/LOGIC/COURSE_SERVICE/CourseService.cpp
    SOURCE_CODE/LOGIC/REGISTRATION_SERVICE/RegistrationService.cpp


    # DATA
    SOURCE_CODE/DATA/DATA_ACCESSING/FileManaging.cpp

)

# ===================================
# Google Test cho thư mục test/
# ===================================

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
set(BUILD_GMOCK OFF)
set(BUILD_GTEST ON)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(test_runner
    test/test_main.cpp

    # Bạn có thể thêm file test khác tại đây:
    # test/StudentTest.cpp
    # test/ScoreServiceTest.cpp
)

target_link_libraries(test_runner
    gtest
    gtest_main
)

add_test(NAME AllTests COMMAND test_runner)
