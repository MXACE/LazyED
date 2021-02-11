#ifndef _BACKEND_H
#define _BACKEND_H

#include "event/gameevent.h"
#include "event/shiptargetedevent.h"
#include "configuration.h"

#include <QObject>
#include <QFileSystemWatcher>
#include <QRegularExpression>
#include <QFile>
#include <QDir>

namespace led {

	typedef void (*GameEventCallbackFunction)(GameEvent* event);
	typedef void (*ShipTargettedEventCallbackFunction)(ShipTargettedEvent* event);
	
	class Backend : public QObject {
		Q_OBJECT
		
		private:
			const QRegularExpression journalFileNameRegex = QRegularExpression("Journal\\.[0-9]*\\.[0-9]*\\.log");
			Configuration* config;
			QFileSystemWatcher* fsWatcher;
			qint64 offset;
		public:
		private slots:
			void backendFileChanged(const QString &path);
			void backendDirectoryChanged(const QString &path);
		public:
			Backend(Configuration* config);
			~Backend();
			
	};

}

#endif