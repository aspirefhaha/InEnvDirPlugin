#ifndef INENVDIRPLUGIN_H
#define INENVDIRPLUGIN_H

#include "inenvdirplugin_global.h"
#include <QtCore/qcoreevent.h>
#include <QtCore/QString>
enum OUTFSTYPE {
	OUTFTDRIVE=1,
	OUTFTSPEC,
	OUTFTDIR,
	OUTFTFILE,
	OUTFTUNKNOWN
};

class QFhahaEvent : public QEvent
{
private:
    QString mstr;

public:
    const static Type TYPE = static_cast<Type>(QEvent::User+10);
    explicit QFhahaEvent(QString s):
    QEvent(TYPE)
	{
		mstr = s;
	};
    QString str(){
		return mstr;
	}
};


class INENVDIRPLUGIN_EXPORT InEnvDirPlugin
{
public:
	InEnvDirPlugin();
	~InEnvDirPlugin();

	static OUTFSTYPE GetFileInfoInDir(QString parentPath,int num,QString & absPath);
	static int GetSubItemCount(QString parentPath);

private:

};

INENVDIRPLUGIN_EXPORT bool InEnvGetOutFileInfo(QString fspath,QString &filename,QString &filesize, QString &filetype,QString & filelastmodifytime);
INENVDIRPLUGIN_EXPORT bool InEnvGetOutDriveInfo(QString fspath,QString &filename,QString &filesize, QString &filetype,QString & filelastmodifytime);

INENVDIRPLUGIN_EXPORT bool InEnvCopyFileFromOutEnv(QString outpath,QString inpath);
extern "C" {
INENVDIRPLUGIN_EXPORT int InEnvMinimizeWin(void);
}
#endif // INENVDIRPLUGIN_H
