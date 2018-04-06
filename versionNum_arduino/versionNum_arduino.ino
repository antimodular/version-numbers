#include "build_version.h"

void setup() {
  Serial.begin(9600);

  Serial.print("version ");
  Serial.println(VERSIONNUM);
}

void loop() {

}
