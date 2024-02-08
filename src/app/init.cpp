#include "init.h"
#include<QDir>

void init() {
  QDir dir;

         // verify if the data directory is created
  dir.mkdir(DATA_DIRECTORY);

         // verify if the template directory is created
  dir.mkdir(TEMPLATE_DIRECTORY);

         // verify if the cs directory is created
  dir.mkdir(CS_DIRECTORY);

         // verify if the config directory is created
  dir.mkdir(CONFIG_DIRECTORY);
}
