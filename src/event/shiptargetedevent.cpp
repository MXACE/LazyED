#include "shiptargetedevent.h"




led::ShipTargetedEvent::ShipTargetedEvent(QString eventName, QDateTime timestamp, QJsonObject obj)
	: GameEvent(eventName, timestamp)
{
	this->targetLocked = obj["TargetLocked"].toBool(false);
	this->scanStage = obj["ScanStage"].toInt(0);
	this->shipName = led::getLocalisedValue(obj, "Ship");
	this->pilotName = led::getLocalisedValue(obj, "PilotName");
	this->pilotRank = led::getLocalisedValue(obj, "PilotRank");
	this->shieldHealth = obj["ShieldHealth"].toDouble(0);
	this->hullHealth = obj["HullHealth"].toDouble(0);
	this->faction = led::getLocalisedValue(obj, "Faction");
	this->legalStatus = led::getLocalisedValue(obj, "LegalStatus");
	this->bounty = obj["Bounty"].toInt(0);
	this->subsystem = led::getLocalisedValue(obj, "SubSystem");
	this->subsystemHealth = obj["SubSystemHealth"].toDouble(0);
	this->power = led::getLocalisedValue(obj, "Power");
	
}

led::ShipTargetedEvent::~ShipTargetedEvent()
{
	
}