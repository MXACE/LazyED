#ifndef _BACKEND_H
#define _BACKEND_H

#include "event/gameevent.h"
#include "configuration.h"

namespace led {

	typedef void (*GameEventCallbackFunction)(GameEvent* event);
	
	class Backend : QObject {
		private:
			const QRegularExpression journalFileNameRegex = QRegularExpression("Journal\\.[0-9]*\\.[0-9]*\\.log");
			Configuration* config;
			QFileSystemWatcher* fsWatcher;
		public:
		private:
			void backendFileChanged(QString path);
			void backendDirectoryChanged(QString path);
		public:
			Backend(Configuration* config);
			~Backend();
			
	}

}

#endif