#ifndef _SHIPTARGETTEDEVENT_H
#define _SHIPTARGETTEDEVENT_H

#include "gameevent.h"


namespace led {
	
	class ShipTargetedEvent : GameEvent {
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
			ShipTargetedEvent(QString eventName, QDateTime timestamp, QJsonObject obj);
			~ShipTargetedEvent();
	};
	
}

#endif