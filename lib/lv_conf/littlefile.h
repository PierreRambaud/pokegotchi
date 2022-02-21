#ifndef LITTLEFILE_H
#define LITTLEFILE_H

#include <LittleFS.h>

class LittleFile {
 public:
  LittleFile(File file);

  File get_file() { return _file; }

 protected:
  File _file;
};

#endif
