#ifndef _SHIPTARGETTEDEVENT_H
#define _SHIPTARGETTEDEVENT_H

#include "gameevent.h"


namespace led {
	
	class ShipTargettedEvent : GameEvent {
		private:
		public:
			bool targetLocked;
			QString shipName;
			uint8_t scanStage;
			QString pilotName;
			QString pilotRank;
			float shieldHealth;
			float hullHealth;
			QString faction;
			QString legalStatus;
			uint64_t bounty;
			QString subsystem;
			float subsystemHealth;
			QString power;
		private:
		public:
			ShipTargettedEvent(QString eventName, QDateTime timestamp);
			ShipTargettedEvent(QString eventName, QDateTime timestamp, QString shipName, uint8_t scanStage);
			ShipTargettedEvent(QString eventName, QDateTime timestamp, QString shipName, uint8_t scanStage, QString pilotName, QString pilotRank);
			ShipTargettedEvent(QString eventName, QDateTime timestamp, QString shipName, uint8_t scanStage, QString pilotName, QString pilotRank, float shieldHealth, float hullHealth);
			ShipTargettedEvent(QString eventName, QDateTime timestamp, QString shipName, uint8_t scanStage, QString pilotName, QString pilotRank, float shieldHealth, float hullHealth,
							   QString faction, QString legalStatus, uint32_t bounty, QString subsystem, float subsystemHealth, QString power);
			~ShipTargettedEvent();
	};
	
}

#endif