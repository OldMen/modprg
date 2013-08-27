project( mod_logger )

include_directories( ${core_SOURCE_DIR} ${share_SOURCE_DIR} )

set( mod_logger_HEADERS logger.h loggermodule.h )
set( mod_logger_SOURCES logger.cpp loggermodule.cpp )
set( mod_logger_FORMS	 )

qt4_wrap_cpp( mod_logger_MOC_SOURCES ${mod_logger_HEADERS} )
qt4_wrap_ui( mod_logger_UI_HEADERS ${mod_logger_FORMS} )

add_library( mod_logger MODULE ${mod_logger_SOURCES} ${mod_logger_MOC_SOURCES} ${mod_logger_UI_HEADERS} ${mod_logger_QRC_SOURCES} )
target_link_libraries( mod_logger ${QT_LIBRARIES} )
