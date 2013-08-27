#ifndef CORELIB_GLOBAL_H
#define CORELIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined ( BUILD_CORELIB )
#  define CORELIB_EXPORT Q_DECL_EXPORT
#else
#  define CORELIB_EXPORT Q_DECL_IMPORT
#endif

#endif // CORELIB_GLOBAL_H
