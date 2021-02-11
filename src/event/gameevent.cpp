#include "gameevent.h"
#include <map>

#include "shiptargetedevent.h"

std::map<QString, led::EventEnum> eventTable;

led::GameEvent::GameEvent(QString eventName, QDateTime timestamp)
	: eventName(eventName)
	, timestamp(timestamp)
{
	
}

led::GameEvent::~GameEvent()
{
	
}

QString led::getLocalisedValue(QJsonObject obj, QString name)
{
	return obj[name + "_Localised"].toString(obj[name].toString("Unknown"));
}

QString led::GameEvent::toString() {
	char* tmp = (char*)alloca(4096);
	sprintf(tmp, "Generic Game Event: %s, timestamp: %s", this->eventName.toStdString(), this->timestamp.toString("dd/MM/yyyy hh:mm:ss").toStdString());
	return QString(tmp);
}

void led::initializeEventTable()
{
	eventTable[QString("ShipTargeted")] = led::LED_EVENT_SHIP_TARGETED;
}

led::GameEvent* led::parseGameEvent(QJsonObject obj)
{
	QString eventName = obj["event"].toString();
	QDateTime timestamp = QDateTime::fromString(obj["timestamp"].toString(), "yyyy-MM-dd'T'hh:mm:ss'T'");
	
	switch (eventTable[eventName]) {
		case LED_EVENT_SHIP_TARGETED: return (led::GameEvent*)new led::ShipTargetedEvent(eventName, timestamp, obj);
	}
	
}