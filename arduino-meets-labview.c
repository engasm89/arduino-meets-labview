/*
 * Course: Arduino Meets Labview
 * Platform: Arduino
 * Author: Ashraf S A AlMadhoun
 * 
 * Description:
 * This code demonstrates the core concepts taught in the "Arduino Meets Labview" course.
 * It provides a practical implementation that students can study, modify, and
 * use as a foundation for their own projects.
 * 
 * Learning Objectives:
 * - Understand the fundamental principles covered in this course
 * - Practice implementing the concepts with real code
 * - Build a working example that can be extended
 * 
 * Hardware Requirements:
 * - Development board (Arduino)
 * - Components as specified in CIRCUIT.md
 * - USB cable for programming
 * 
 * Pin Connections:
 * Refer to CIRCUIT.md for detailed wiring diagrams and pin assignments.
 * 
 * Usage:
 * 1. Review the code structure and comments
 * 2. Connect hardware according to CIRCUIT.md
 * 3. Upload code to your development board
 * 4. Monitor serial output for debugging
 * 
 * Course Link: https://www.udemy.com/course/arduino-meets-labview/
 * Repository: https://github.com/engasm89/arduino-meets-labview
 * 
 * Copyright (c) 2025 Ashraf S A AlMadhoun
 * Licensed under MIT License
 */

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

int main(void) { // Program entry point
  printf("Arduino Meets LabVIEW\n"); // Title
  const char* seq[] = {"PING","SET LED 1","GET ADC","SET LED 0","GET ADC"}; // Sequence
  for (int i = 0; i < 5; ++i) { // Iterate
    const char* res = process(seq[i]); // Process
    printf("CMD='%s' RES='%s' LED=%d\n", seq[i], res, led); // Log
  } // End loop
  return 0; // Exit
} // End of main function
