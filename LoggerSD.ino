#include <SD_MMC.h>


// Digital Pin for Binary Input
#define DATA_PIN 33

// File Name
const char* filename = "binary_data.txt";

void setup() {
  // Configure Data Pin as Input
  pinMode(DATA_PIN, INPUT);
};

void loop() {
  // Open the file for writing
  File dataFile = SD_MMC.open(filename, FILE_WRITE);

    while (true) {
      // Read the binary value from the data pin
      for (int i = 0; i < 32; i++) {
        int bitValue = digitalRead(DATA_PIN);
        // Write the bit to the file
        dataFile.print(bitValue);
      }
      // Add a newline character after each 500ms
      dataFile.println();
    }

    // Close the file
    dataFile.close();
}