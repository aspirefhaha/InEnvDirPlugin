#ifndef INENVDIRPLUGIN_GLOBAL_H
#define INENVDIRPLUGIN_GLOBAL_H

#include <QtCore/qglobal.h>

#ifdef INENVDIRPLUGIN_LIB
# define INENVDIRPLUGIN_EXPORT Q_DECL_EXPORT
#else
# define INENVDIRPLUGIN_EXPORT Q_DECL_IMPORT
#endif

#endif // INENVDIRPLUGIN_GLOBAL_H