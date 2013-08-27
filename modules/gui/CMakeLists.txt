project( mod_gui )

include_directories( ${core_SOURCE_DIR} ${share_SOURCE_DIR} ${mod_gui_BINARY_DIR} )

set( mod_gui_HEADERS mainwindow.h mainwindowimpl.h guimodule.h )
set( mod_gui_SOURCES mainwindow.cpp mainwindowimpl.cpp guimodule.cpp )
set( mod_gui_FORMS	 ui/mainwindow.ui )

qt4_wrap_cpp( mod_gui_MOC_SOURCES ${mod_gui_HEADERS} )
qt4_wrap_ui( mod_gui_UI_HEADERS ${mod_gui_FORMS} )

add_library( mod_gui MODULE ${mod_gui_SOURCES} ${mod_gui_MOC_SOURCES} ${mod_gui_UI_HEADERS} ${mod_gui_QRC_SOURCES} )
target_link_libraries( mod_gui ${QT_LIBRARIES} )
