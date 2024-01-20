cmake_minimum_required(VERSION 3.5)

project(rollZZ VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_compile_options(-Wall -Wextra -g)

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Widgets Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

################################################################################
#                                   mongocxx                                   #
################################################################################

if(EXISTS /usr/local/include/mongocxx/v_noabi)
    # when the lib is installed on the machine
    find_package(libmongocxx REQUIRED)
    find_package(libbsoncxx REQUIRED)
    include_directories(${LIBMONGOCXX_INCLUDE_DIR})
    include_directories(${LIBBSONCXX_INCLUDE_DIR})
    include_directories("/usr/local/include/mongocxx/v_noabi")
    include_directories("/usr/local/include/bsoncxx/v_noabi")
    include_directories("/usr/local/include/libmongoc-1.0")
    include_directories("/usr/local/include/libbson-1.0")
    include_directories("/usr/local/lib")
elseif(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/lib/mongo-cxx/include/mongocxx/v_noabi/)
    # local installation of libbson & mongocxx (must use the install script in lib/)
    include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/mongo-cxx/include/mongocxx/v_noabi/
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/mongo-cxx/include/bsoncxx/v_noabi/
        )
    link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/mongo-cxx/lib/)
    set(LIBMONGOCXX_LIBRARIES mongocxx)
    set(LIBBSONCXX_LIBRARIES bsoncxx)
else()
    message(FATAL_ERROR "mongocxx is not available")
endif()

################################################################################
#                                  serializer                                  #
################################################################################

if (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/lib/serializer-cpp/)
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/serializer-cpp/serializer/)
endif()

################################################################################
#                                      Qt                                      #
################################################################################

set(PROJECT_SOURCES
        src/app/main.cpp
        src/app/config.cpp
        src/app/init.cpp
        src/app/mainwindow.cpp
        src/app/mainwindow.h
        ressources/mainwindow.ui
)

include_directories(
    src/
    src/tools/widgets/
    src/tools/
    src/CS/
    src/app/
    src/app/widgets/
    src/app/widgets/cscreator/
    src/app/widgets/cscreator/popup/
    src/app/widgets/cscreator/components/
    )

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(rollZZ
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        src/app/widgets/gamelist.h src/app/widgets/gamelist.cpp
        src/app/widgets/cscreator/cscreator.h src/app/widgets/cscreator/cscreator.cpp
        src/app/widgets/cscreator/popup/basicstatpopup.h src/app/widgets/cscreator/popup/basicstatpopup.cpp
        src/app/widgets/cscreator/popup/cscreatorpopup.h src/app/widgets/cscreator/popup/cscreatorpopup.cpp
        src/app/widgets/cscreator/popup/sectionpopup.h src/app/widgets/cscreator/popup/sectionpopup.cpp
        src/app/widgets/cscreator/popup/descriptorpopup.h src/app/widgets/cscreator/popup/descriptorpopup.cpp
        src/app/widgets/cscreator/popup/equipmentpopup.h src/app/widgets/cscreator/popup/equipmentpopup.cpp
        src/app/widgets/cscreator/components/section.h src/app/widgets/cscreator/components/section.cpp
        src/app/widgets/cscreator/components/part.h src/app/widgets/cscreator/components/part.cpp
        src/app/widgets/cscreator/popup/tabpopup.h src/app/widgets/cscreator/popup/tabpopup.cpp
        src/app/mongodb/mongodb.hpp src/app/mongodb/mongodb.cpp
        src/CS/cs.h src/CS/cs.cpp
        src/CS/part.h src/CS/part.cpp
        src/CS/section.h src/CS/section.cpp
        src/CS/component.h src/CS/component.cpp
        src/CS/bonusstat.h src/CS/bonusstat.cpp
        src/CS/basicstat.h src/CS/basicstat.cpp
        src/CS/liststat.h src/CS/liststat.cpp
        src/CS/equipment.h src/CS/equipment.cpp
        src/CS/attacks.h src/CS/attacks.cpp
        src/CS/descriptor.h src/CS/descriptor.cpp
        src/CS/dice.h src/CS/dice.cpp
        src/CS/item.h src/CS/item.cpp
        src/CS/weapon.h src/CS/weapon.cpp
        src/CS/caracteristic.h src/CS/caracteristic.cpp
        src/app/widgets/cscreator/popup/bonusstatpopup.h src/app/widgets/cscreator/popup/bonusstatpopup.cpp
        src/app/widgets/cscreator/popup/liststatpopup.h src/app/widgets/cscreator/popup/liststatpopup.cpp
        src/app/widgets/cscreator/popup/attackspopup.h src/app/widgets/cscreator/popup/attackspopup.cpp
        src/app/widgets/cscreator/components/basicstat.h src/app/widgets/cscreator/components/basicstat.cpp
        src/app/widgets/cscreator/components/component.h src/app/widgets/cscreator/components/component.cpp
        src/app/widgets/cscreator/components/bonusstat.h src/app/widgets/cscreator/components/bonusstat.cpp
        src/app/widgets/cscreator/components/liststat.h src/app/widgets/cscreator/components/liststat.cpp
        src/app/widgets/cscreator/components/descriptor.h src/app/widgets/cscreator/components/descriptor.cpp
        src/app/widgets/cscreator/components/equipment.h src/app/widgets/cscreator/components/equipment.cpp
        src/app/widgets/cscreator/components/attacks.h src/app/widgets/cscreator/components/attacks.cpp
        src/app/widgets/tools/listelement.h src/app/widgets/tools/listelement.cpp
        src/app/widgets/cseditor/components/attacks.cpp src/app/widgets/cseditor/components/attacks.h
        src/app/widgets/cseditor/components/basicstat.cpp src/app/widgets/cseditor/components/basicstat.h
        src/app/widgets/cseditor/components/bonusstat.cpp src/app/widgets/cseditor/components/bonusstat.h
        src/app/widgets/cseditor/components/component.cpp src/app/widgets/cseditor/components/component.h
        src/app/widgets/cseditor/components/descriptor.cpp src/app/widgets/cseditor/components/descriptor.h
        src/app/widgets/cseditor/components/equipment.cpp src/app/widgets/cseditor/components/equipment.h
        src/app/widgets/cseditor/components/item.cpp src/app/widgets/cseditor/components/item.h
        src/app/widgets/cseditor/components/liststat.cpp src/app/widgets/cseditor/components/liststat.h
        src/app/widgets/cseditor/components/caracteristic.cpp src/app/widgets/cseditor/components/caracteristic.h
        src/app/widgets/cseditor/components/section.cpp src/app/widgets/cseditor/components/section.h
        src/app/widgets/cseditor/components/weapon.cpp src/app/widgets/cseditor/components/weapon.h
        src/app/widgets/cseditor/cseditor.cpp src/app/widgets/cseditor/cseditor.h
        src/tools/widgets/diceedit.h src/tools/widgets/diceedit.cpp
    )

target_link_libraries(rollZZ PRIVATE ${LIBMONGOCXX_LIBRARIES})
target_link_libraries(rollZZ PRIVATE ${LIBBSONCXX_LIBRARIES})
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET rollZZ APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(rollZZ SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(rollZZ
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(rollZZ PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.rollZZ)
endif()
set_target_properties(rollZZ PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS rollZZ
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(rollZZ)
endif()
