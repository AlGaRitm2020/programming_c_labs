cmake_minimum_required(VERSION 3.16)
project(graph VERSION 0.1 LANGUAGES CXX)

# Включаем автоматическую обработку UI, MOC и RCC
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Устанавливаем стандарт C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Находим Qt
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# Список исходных файлов — все лежат в корне проекта
set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    plotwidget.cpp
    mainwindow.ui
    plotwidget.h        # <-- важно: добавляем заголовочный файл в список
)

# Создаем исполняемый файл
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(graph
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    add_executable(graph ${PROJECT_SOURCES})
endif()

# Добавляем текущую директорию в include path
target_include_directories(graph PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Связываем с библиотекой Qt Widgets
target_link_libraries(graph PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Для Qt 6: завершаем настройки целевого объекта
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(graph)
endif()
