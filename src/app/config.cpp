#include "config.h"
#include <QDir>

#ifdef _WIN32
const QString DATA_DIRECTORY = QDir::homePath() + "\\AppData\\Roaming\\rollZZ\\data\\";
const QString CONFIG_DIRECTORY = QDir::homePath() + "\\AppData\\Roaming\\rollZZ\\config\\";
const QString TEMPLATE_DIRECTORY = DATA_DIRECTORY + "template\\";
const QString CS_DIRECTORY = DATA_DIRECTORY + "cs\\";
#else
const QString DATA_DIRECTORY = QDir::homePath() + "/.local/share/rollZZ/";
const QString CONFIG_DIRECTORY = QDir::homePath() + "/.config/rollZZ/";
const QString TEMPLATE_DIRECTORY = DATA_DIRECTORY + "template/";
const QString CS_DIRECTORY = DATA_DIRECTORY + "cs/";
#endif
