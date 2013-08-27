project( core )

include_directories( ${share_SOURCE_DIR} )

set( core_HEADERS workspace.h moduleloader.h )
set( core_SOURCES main.cpp workspace.cpp moduleloader.cpp )
set( core_FORMS	 )

qt4_wrap_cpp( core_MOC_SOURCES ${core_HEADERS} )
qt4_wrap_ui( core_UI_HEADERS ${core_FORMS} )
# qt4_add_resources( core_QRC_SOURCES core.qrc )

add_executable( modprg ${core_SOURCES} ${core_MOC_SOURCES} ${core_UI_HEADERS} ${core_QRC_SOURCES} )
target_link_libraries( modprg ${QT_LIBRARIES} )
