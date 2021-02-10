#include "shiptargettedevent.h"


led::ShipTargettedEvent::ShipTargettedEvent(QString eventName, QDateTime timestamp)
	: GameEvent(eventName, timestamp)
{
	this->targetLocked = false;
	this->shipName = "Unknown";
	this->scanStage = 0;
	this->pilotName = "Unknown";
	this->pilotRank = "Unknown";
	this->shieldHealth = 0;
	this->hullHealth = 0;
	this->faction = "Unknown";
	this->legalStatus = "Unknown";
	this->bounty = 0;
	this->subsystem = "Unknown";
	this->subsystemHealth = 0;
	this->power = "Unknown";
}

led::ShipTargettedEvent::ShipTargettedEvent(QString eventName, QDateTime timestamp, QString shipName, uint8_t scanStage)
	: ShipTargettedEvent(eventName, timestamp)
{
	this->targetLocked = true;
	this->shipName = shipName;
	this->scanStage = scanStage;
}

led::ShipTargettedEvent::ShipTargettedEvent(QString eventName, QDateTime timestamp, QString shipName, uint8_t scanStage, QString pilotName, QString pilotRank)
	: ShipTargettedEvent(eventName, timestamp, shipName, scanStage)
{
	this->pilotName = pilotName;
	this->pilotRank = pilotRank;
}

led::ShipTargettedEvent::ShipTargettedEvent(QString eventName, QDateTime timestamp, QString shipName, uint8_t scanStage, QString pilotName, QString pilotRank, float shieldHealth, float hullHealth)
	: ShipTargettedEvent(eventName, timestamp, shipName, scanStage, pilotName, pilotRank)
{
	this->shieldHealth = shieldHealth;
	this->hullHealth = hullHealth;
}

led::ShipTargettedEvent::ShipTargettedEvent(QString eventName, QDateTime timestamp, QString shipName, uint8_t scanStage, QString pilotName, QString pilotRank, float shieldHealth, float hullHealth,
											QString faction, QString legalStatus, uint32_t bounty, QString subsystem, float subsystemHealth, QString power)
	: ShipTargettedEvent(eventName, timestamp, shipName, scanStage, pilotName, pilotRank, shieldHealth, hullHealth)
{
	this->faction = faction;
	this->legalStatus = legalStatus;
	this->bounty = bounty;
	this->subsystem = subsystem;
	this->subsystemHealth = subsystemHealth;
	this->power = power;
}

led::ShipTargettedEvent::~ShipTargettedEvent()
{
	
}