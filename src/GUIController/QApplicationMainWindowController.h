//
// Created by ebeuque on 05/10/2020.
//

#ifndef FREETUXTV_QAPPLICATIONMAINWINDOWCONTROLLER_H
#define FREETUXTV_QAPPLICATIONMAINWINDOWCONTROLLER_H

#include <QObject>

class QApplicationMainWindow;

class QApplicationMainWindowController: public QObject
{
	Q_OBJECT
public:
	QApplicationMainWindowController();
	virtual ~QApplicationMainWindowController();

public:
	void init(QApplicationMainWindow* pMainWindow);
	void dispose();

private slots:
	void onPreferencesTriggered();
	void onQuitTriggered();

private:
	QApplicationMainWindow* m_pMainWindow;
};


#endif //FREETUXTV_QAPPLICATIONMAINWINDOWCONTROLLER_H