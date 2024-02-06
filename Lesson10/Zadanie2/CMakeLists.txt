# CMakeList.txt: проект CMake для project_of_class; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("project_of_class")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (project_of_class "project_of_class.cpp" "project_of_class.h" "Figure.h" "Figure.cpp" "Triangle.h" "Triangle.cpp" "Right_Triangle.h" "Right_Triangle.cpp"
"Equilateral_Triangle.h" "Equilateral_Triangle.cpp" "Isosceles_Triangle.cpp" "Quadrangle.h" "Quadrangle.cpp" "Rectangle.h" "Rectangle.cpp" "Square.h" "Square.cpp"
"Parallelogram.h" "Parallelogram.cpp" "Romb.h" "Romb.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET project_of_class PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
