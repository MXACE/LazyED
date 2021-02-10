#ifndef _GAMEEVENT_H
#define _GAMEEVENT_H

#include <iostream>
#include <QString>
#include <QDateTime>

namespace led {
	
	class GameEvent {
		// private variables
		private:
		// public variables
		public:
		const QString eventName;
		const QDateTime timestamp;
		
		// private functions
		private:
		//public functions
		public:
		GameEvent(QString eventName, QDateTime timestamp);
		~GameEvent();
		
		QString toString();
	};
	
	
};


#endif