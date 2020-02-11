
#include <qdir.h>

#include <qfileinfo.h>
#include <qdatetime.h>
#include <QtGui/QtGui>
#include <QtGui/QApplication>
//#include <QtCore/QCloseEvent>
#include "inenvdirplugin.h"

InEnvDirPlugin::InEnvDirPlugin()
{

}

InEnvDirPlugin::~InEnvDirPlugin()
{

}


OUTFSTYPE InEnvDirPlugin::GetFileInfoInDir(QString parentPath,int num,QString & absPath)
{
	QDir rootDir = QDir(parentPath);
	OUTFSTYPE childType = OUTFTUNKNOWN;
	rootDir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks | QDir::AllDirs | QDir::NoDotAndDotDot);
	//rootDir.setSorting(QDir::Size | QDir::Reversed);
	QFileInfoList list = rootDir.entryInfoList();//返回这个目录中所有目录和文件的QFileInfo对象的列表
	if(!list.isEmpty()){
		QFileInfo tem = list.at(num);
		absPath =  tem.absoluteFilePath() ;
		if(!tem.isDir()){
			childType = OUTFTFILE;
		}else {
			childType = OUTFTDIR;
		}
	}
	return childType;
}

int InEnvDirPlugin::GetSubItemCount(QString parentPath)
{
	QDir curDir(parentPath);
	curDir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks | QDir::AllDirs|QDir::NoDotAndDotDot);
	//curDir.setSorting(QDir::Size | QDir::Reversed);
	QFileInfoList list = curDir.entryInfoList();//返回这个目录中所有目录和文件的QFileInfo对象的列表
	return list.size();
}

bool InEnvGetOutFileInfo(QString fspath,QString &filename,QString &filesize, QString &filetype,QString & filelastmodifytime)
{
	QFileInfo info(fspath);
	filename = info.fileName();
	filesize = info.isDir()?"":QString::number(info.size());
	filetype = info.isFile()?"File":"File Folder";
	filelastmodifytime = info.lastModified().toString("yyyy-MM-dd hh::mm::ss");
	return true;
}

bool InEnvGetOutDriveInfo(QString fspath,QString &filename,QString &filesize, QString &filetype,QString & filelastmodifytime)
{
	QFileInfo info(fspath);
	filename = info.absoluteFilePath();
	filesize = info.isDir()?"":QString::number(info.size());
	filetype = "Drive";
	filelastmodifytime = info.lastModified().toString("yyyy-MM-dd hh::mm::ss");
	return true;
}

bool InEnvCopyFileFromOutEnv(QString outpath,QString inpath)
{
	QFileInfo info(outpath);

	if(!QFile::copy(outpath, inpath+QDir::separator()+info.fileName()))
	{
		return false;
	}
	return true;
}



int InEnvMinimizeWin()
{
	int  key = Qt::Key_Delete ;

    //QKeyEvent EventPress(QEvent::KeyPress,key,Qt::NoModifier); 
	//QMouseEvent *me = dynamic_cast<QMouseEvent* >(e);      
    {
		QString outStr = QString("X: %1  Y: %2").arg(1).arg(2) ;
        QFhahaEvent event(outStr );
		qDebug() << "Send " << outStr;
		QCloseEvent closeEvent;
		QHideEvent hideEvent;
        //QApplication::postEvent(qApp,&event);         //发送自定义事件
		QApplication::sendEvent(qApp,&event);         //发送自定义事件
		//QApplication::sendEvent(QGuiApplication::topLevelWindows(),&closeEvent);
		//QApplication::sendEvent(qGuiApp,&closeEvent);
		//QApplication::sendEvent(qApp,&closeEvent);
		QApplication::sendEvent(qApp,&hideEvent);
		qDebug() << "Send Hide" ;
    }
	//QCoreApplication::sendEvent(qApp,QStringEvent
	//QGuiApplication::topLevelWindows();
	return 1;
}