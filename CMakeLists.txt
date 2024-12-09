cmake_minimum_required(VERSION 3.10)

# Имя проекта
project(MyProject)

# Включите Google Test
add_subdirectory(googletest)

# Добавьте ваш исполняемый файл
add_executable(MyExecutable main.cpp)

# Подключите Google Test к вашему исполняемому файлу
target_link_libraries(MyExecutable gtest gtest_main)
