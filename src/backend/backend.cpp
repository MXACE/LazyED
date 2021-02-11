#include "backend.h"


#include <iostream>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>



void backendFileChanged(QString path);
void backendDirChanged(QString path);

led::Backend::Backend(led::Configuration* configuration)
{
	this->config = configuration;
	this->offset = 0;
		
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
	
	
	QObject::connect(this->fsWatcher, &QFileSystemWatcher::fileChanged, this, &led::Backend::backendFileChanged);
	QObject::connect(this->fsWatcher, &QFileSystemWatcher::directoryChanged, this, &led::Backend::backendDirectoryChanged);
	
	// find the newest journal
	QDir dir(this->config->eliteDangerousJournalPath);
	QStringList journals = dir.entryList().filter(this->journalFileNameRegex);
	// if there is no journal, don't set an active journal
	if (journals.length() > 0) {
		journals.sort();
		this->fsWatcher->addPath(this->config->eliteDangerousJournalPath + "/" + journals.last());
	}
	
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
void led::Backend::backendFileChanged(const QString &path)
{
	
	// first check if the file is a journal
	if (this->journalFileNameRegex.match(path).hasMatch()) {
		// read the journal
		QFile journal(path);
		
		// TODO: handle failures of file opening
		if (journal.open(QFile::ReadOnly)) {
			// skip lines that have already been read
			journal.seek(this->offset);
			
			// read lines that have not yet been read and update linesRead accordingly
			while (!journal.atEnd()) {
				QString line = journal.readLine();
				if (line.length() > 0) {
					// parse the line
					QJsonDocument doc = QJsonDocument::fromJson(line.toUtf8(), nullptr);
					
					if (doc.isObject()) {
						QJsonObject event = doc.object();
						
						std::cout << "Event read: " << event["event"].toString().toStdString() << std::endl;
						
						this->offset = journal.pos();
					}
				}
			}
			
			// close the journal
			journal.close();
		} else {
			std::cerr << "Could not open journal file for reading" << std::endl;
		}
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
void led::Backend::backendDirectoryChanged(const QString &path)
{
	// check if the newest journal is begin watched by fsWatcher
	QDir dir(this->config->eliteDangerousJournalPath);
	QStringList files_tmp = dir.entryList().filter(this->journalFileNameRegex);
	QStringList files;
	
	// if no journal files are here, return
	if (files_tmp.length() == 0) return;
	
	for (QString str : files_tmp)
		files.append(str.prepend(this->config->eliteDangerousJournalPath + "/"));
	
	files.sort();
	
	if (!this->fsWatcher->files().contains(files.last())) {
		if (this->fsWatcher->files().length() != 0)
			this->fsWatcher->removePaths(this->fsWatcher->files().filter(this->journalFileNameRegex));
		this->fsWatcher->addPath(this->config->eliteDangerousJournalPath + "/" + files.last());
		this->offset = 0;
	}
}