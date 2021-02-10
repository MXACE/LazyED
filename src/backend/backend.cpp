#include "backend.h"

#include <QFile>
#include <QFileSystemWatcher>
#include <QRegularExpression>
#include <QFile>
#include <QDir>



void backendFileChanged(QString path);
void backendDirChanged(QString path);

led::Backend::Backend(led::Configuration* configuration)
{
	this->config = configuration;
	
	// set the QFileSystemWatcher so that any new files are detected and such that the newest journal is detected
	this->fsWatcher = new QFileSystemWatcher();
	// this is the directory that contains all journals
	this->fsWatcher->addPath(this->config->eliteDangerousJournalPath);
	
	// these are all the status files
	this->fsWatcher->addPath(this->config->eliteDangerousJournalPath + "/Cargo.json");
	this->fsWatcher->addPath(this->config->eliteDangerousJournalPath + "/Market.json");
	this->fsWatcher->addPath(this->config->eliteDangerousJournalPath + "/ModulesInfo.json");
	this->fsWatcher->addPath(this->config->eliteDangerousJournalPath + "/NavRoute.json");
	this->fsWatcher->addPath(this->config->eliteDangerousJournalPath + "/Outfitting.json");
	this->fsWatcher->addPath(this->config->eliteDangerousJournalPath + "/Shipyard.json");
	this->fsWatcher->addPath(this->config->eliteDangerousJournalPath + "/Status.json");
	
	// find the newest journal
	QDir dir(this->config->eliteDangerousJournalPath);
	QStringList journals = dir.entryList().filter(this->journalFileNameRegex);
	// if there is no journal, don't set an active journal
	if (journals.length() > 0) {
		journals.sort();
		this->fsWatcher->addPath(journals.last());
	}
	
	QObject::connect(fsWatcher, SIGNAL(fileChanged(QString)), this, SLOT(backendFileChanged(QString)));
	QObject::connect(fsWatcher, SIGNAL(directoryChanged(QString)), this, SLOT(backendDirectoryChanged(QString)));
}

led::Backend::~Backend()
{
	this->fsWatcher->removePaths(fsWatcher->files());
	this->fsWatcher->removePaths(fsWatcher->directories());
	delete this->fsWatcher;
}


/*
 * This function is called whenever a file that is being watched, is modified. This function
 * identifies all events that have happened in the file and calls all necessary callout given to
 * the backend accordingly.
 */
void led::Backend::backendFileChanged(QString path)
{
	// first check if the file is a journal
	if (this->journalFileNameRegex.match(path).hasMatch()) {
		
	} else if (path.endsWith("Cargo.json")) {
		
	} else if (path.endsWith("Market.json")) {
		
	} else if (path.endsWith("ModulesInfo.json")) {
		
	} else if (path.endsWith("NavRoute.json")) {
		
	} else if (path.endsWith("Outfitting.json")) {
		
	} else if (path.endsWith("Shipyard.json")) {
		
	} else if (path.endsWith("Status.json")) {
		
	}
}

/*
 * This function is called when a new file is created or one is deleted.
 * If a new journal is created, this function will update the active journal and
 * remove the old journal from the QFileSystemWatcher
 */
void led::Backend::backendDirectoryChanged(QString path)
{
	// check if the newest journal is begin watched by fsWatcher
	QDir dir(this->config->eliteDangerousJournalPath);
	QStringList files = dir.entryList().filter(this->journalFileNameRegex);
	files.sort();
	if (!this->fsWatcher->files().contains(files.last())) {
		this->fsWatcher->removePaths(this->fsWatcher->files().filter(this->journalFileNameRegex));
		this->fsWatcher->addPath(files.last());
	}
}