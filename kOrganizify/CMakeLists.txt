cmake_minimum_required(VERSION 3.5)

project(kOrganizify VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Network)
find_package(Qt${QT_VERSION_MAJOR}Multimedia REQUIRED)

set(PROJECT_SOURCES
        src/appwindow.cpp
        src/basicevent.cpp
        src/basiceventwindow.cpp
        src/calendar.cpp
        src/client.cpp
        src/event.cpp
        src/eventwindow.cpp
        src/main.cpp
        src/mainwindow.cpp
        src/responsewindow.cpp
        src/notifications.cpp
        src/notificationswindow.cpp
        src/saveload.cpp
        src/scheduler.cpp
        src/settings.cpp
        src/settingswindow.cpp
        src/syncdeniedwindow.cpp
        src/syncresponsewindow.cpp
        src/syncwindow.cpp
        src/task.cpp
        src/toDoList.cpp
        src/user.cpp
)

set(HEADERS
        src/appwindow.h
        src/basicevent.h
        src/basiceventwindow.h
        src/calendar.h
        src/client.h
        src/event.h
        src/eventwindow.h
        src/mainwindow.h
        src/responsewindow.h
        src/notifications.h
        src/notificationswindow.h
        src/saveload.h
        src/scheduler.h
        src/settings.h
        src/settingswindow.h
        src/syncdeniedwindow.h
        src/syncresponsewindow.h
        src/syncwindow.h
        src/task.h
        src/toDoList.h
        src/user.h
)

set(FORMS
        src/appwindow.ui
        src/basiceventwindow.ui
        src/eventwindow.ui
        src/mainwindow.ui
        src/responsewindow.ui
        src/notificationswindow.ui
        src/settingswindow.ui
        src/syncdeniedwindow.ui
        src/syncresponsewindow.ui
        src/syncwindow.ui
)

set(RESOURCES
    resources.qrc
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(kOrganizify
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        ${HEADERS}
        ${FORMS}
        ${RESOURCES}
)
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET kOrganizify APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(kOrganizify SHARED
            ${PROJECT_SOURCES}
            ${HEADERS}
            ${FORMS}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(kOrganizify
            ${PROJECT_SOURCES}
            ${HEADERS}
            ${FORMS}
        )
    endif()
endif()

target_link_libraries(kOrganizify
    PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Network
    Qt${QT_VERSION_MAJOR}::Multimedia
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.kOrganizify)
endif()
set_target_properties(kOrganizify PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS kOrganizify
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(kOrganizify)
endif()
