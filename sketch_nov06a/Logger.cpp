#include "Logger.h"
#include "Arduino.h"

Logger::Logger()
{ 
}

void Logger::Log(const char* msg)
{
  Serial.begin(9600);
  Serial.println(msg);
}
