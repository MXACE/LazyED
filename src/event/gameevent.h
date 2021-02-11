#ifndef _GAMEEVENT_H
#define _GAMEEVENT_H

#include <iostream>
#include <QString>
#include <QDateTime>
#include <QJsonObject>
#include <QJsonArray>

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
	
	static enum EventEnum
	{
		LED_EVENT_SHIP_TARGETED,
		
		LED_EVENT_UNDEFINED
	};
	
	void initializeEventTable();
	QString getLocalisedValue(QJsonObject obj, QString name);
	GameEvent parseGameEvent(QJsonObject obj);
	
};


#endif