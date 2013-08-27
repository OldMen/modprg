project( modprg )
cmake_minimum_required( VERSION 2.6 )

find_package( Qt4 REQUIRED )
set( QT_USE_QTXML 1 )
include( ${QT_USE_FILE} )

add_subdirectory( share )
add_subdirectory( core )
add_subdirectory( modules )
