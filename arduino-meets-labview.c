// Simulate a command protocol between LabVIEW and Arduino
#include <stdio.h> // Logs
#include <string.h> // Parsing

static int led = 0; // LED state
static int adc = 512; // ADC value

const char* process(const char* cmd) { // Process LabVIEW command
  if (!cmd) return "ERR"; // Guard
  if (!strcmp(cmd, "SET LED 1")) { led = 1; return "OK"; } // LED on
  if (!strcmp(cmd, "SET LED 0")) { led = 0; return "OK"; } // LED off
  if (!strcmp(cmd, "GET ADC")) { static char buf[32]; snprintf(buf, sizeof(buf), "ADC=%d", adc); return buf; } // Read ADC
  if (!strcmp(cmd, "PING")) { return "PONG"; } // Health check
  return "UNKNOWN"; // Unknown
}

int main(void) { // Entry
  printf("Arduino Meets LabVIEW\n"); // Title
  const char* seq[] = {"PING","SET LED 1","GET ADC","SET LED 0","GET ADC"}; // Sequence
  for (int i = 0; i < 5; ++i) { // Iterate
    const char* res = process(seq[i]); // Process
    printf("CMD='%s' RES='%s' LED=%d\n", seq[i], res, led); // Log
  } // End loop
  return 0; // Exit
} // End main
