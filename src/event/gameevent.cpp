#include "gameevent.h"

led::GameEvent::GameEvent(QString eventName, QDateTime timestamp)
	: eventName(eventName)
	, timestamp(timestamp)
{
	
}

led::GameEvent::~GameEvent()
{
	
}

QString led::GameEvent::toString() {
	char* tmp = (char*)alloca(4096);
	sprintf(tmp, "Generic Game Event: %s, timestamp: %s", this->eventName, this->timestamp.toString("dd/MM/yyyy hh:mm:ss"));
	return QString(tmp);
}