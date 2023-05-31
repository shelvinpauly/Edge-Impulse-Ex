// Class recognition threshold
const float RECOGNITION_THRESHOLD=0.90;

// Class labels
const String LABEL_NOISE    = "noise";
const String LABEL_SHIELDUP = "shieldup";

// Functions for identifying and performing recognition classes

/**
 * @brief     Custom setup code
 * 
 **/
void customSetup() {
    
  // Set up  LED pin for output
  pinMode (LED_BUILTIN, OUTPUT);
  
  // Blink LED to say "Hello"
  for (int i=0;i<3;i++) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay (50);
    digitalWrite(LED_BUILTIN, LOW);
    delay (200);
  }

}

/**
 * @brief     Return the first class from interference results > threshold
 * 
 **/
int identifyClass (ei_impulse_result_t results, int numResults, float threshold) {
  
  // Select the first class that's greater than or equal to the threshold
  for (int i=0; i<numResults; i++) {
    if (results.classification[i].value > threshold) {
      return i;
    }
  }
  return -1;
}

/**
 * @brief     Implement actions for the recognition result
 * 
 **/
void implementResult (ei_impulse_result_t result) {

    // See if a class has been recognized
  int recognizedClass = identifyClass(result, EI_CLASSIFIER_LABEL_COUNT, RECOGNITION_THRESHOLD);

  // If a class is recognized (meaning greater than or equal to zero)
  if (recognizedClass >= 0) {
    // Retrieve the class' label
    String recognizedLabel = result.classification[recognizedClass].label;
    // If a class is noise, turn the LED off
    if (recognizedLabel == LABEL_NOISE) {
      digitalWrite (LED_BUILTIN, LOW);
    // If the class is SHIELD UP turn the LED on
    } else if (recognizedLabel == LABEL_SHIELDUP) {
      digitalWrite (LED_BUILTIN, HIGH);
    }
  }
}
