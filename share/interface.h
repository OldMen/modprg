#ifndef INTERFACE_H
#define INTERFACE_H

#include "corelib_global.h"

class CORELIB_EXPORT Interface
{
public:
	virtual ~Interface() {}
};

Q_DECLARE_INTERFACE( Interface, "com.modprg.Interface/1.0" )

#endif // INTERFACE_H
