cmake_minimum_required(VERSION 3.10)
project(taskmgr_cmake C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Включение всех предупреждений
if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra -g)
endif()

# Структура каталогов
set(SRC_DIR src)
set(INCLUDE_DIR include)
set(BIN_DIR bin)
set(OBJ_DIR build)

# Создание списка исходных файлов
file(GLOB SRC_FILES "${SRC_DIR}/*.c")

# Создание исполняемого файла
add_executable(${PROJECT_NAME} ${SRC_FILES})

# Установка путей для выходных файлов
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR}
    ARCHIVE_OUTPUT_DIRECTORY ${OBJ_DIR}
    LIBRARY_OUTPUT_DIRECTORY ${OBJ_DIR}
)

# Включение каталога с заголовками
target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIR})