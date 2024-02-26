/*
 * Logger.c
 *
 *  Created on: Feb 26, 2024
 *      Author: NoteBook
 */




#include <stdio.h>
#include <stdarg.h>
#include <time.h>

// Enum to represent different output channels
typedef enum {
    FILE_OUTPUT,     // Output to a file
    CONSOLE_OUTPUT   // Output to the console
} OutputChannel;

// Enum to represent different severity levels
typedef enum {
    INFO,     // Informational message
    WARNING,  // Warning message
    ERROR     // Error message
} SeverityLevel;

// Struct to represent a logger
typedef struct {
    OutputChannel outputChannel;  // Selected output channel
    FILE *fileStream;             // File stream for file output
    const char *logFile;          // Path to the log file
    SeverityLevel severityLevel;  // Severity level for filtering log messages
} Logger;

// Function to initialize a logger with default values
void initLogger(Logger *logger) {
    logger->outputChannel = FILE_OUTPUT;  // Default output channel is file
    logger->fileStream = NULL;           // File stream is initially NULL
    logger->logFile = "./log.txt";       // Default log file path
    logger->severityLevel = INFO;        // Default severity level is INFO
}

// Function to set the output channel of a logger
void setOutputChannel(Logger *logger, OutputChannel channel) {
    logger->outputChannel = channel;
}

// Function to configure the log file path of a logger
void fileCfg(Logger *logger, const char *filePath) {
    logger->logFile = filePath;
}

// Function to set the severity level of a logger
void setSeverityLevel(Logger *logger, SeverityLevel level) {
    logger->severityLevel = level;
}

// Function to get the current time and format it as a string
void getCurrentTime(char *buffer, size_t bufferSize) {
    time_t t;
    struct tm *tm_info;

    time(&t);
    tm_info = localtime(&t);

    strftime(buffer, bufferSize, "%Y-%m-%d %H:%M:%S", tm_info);
}

// Function to write a log message to a file with timestamp and severity level
void writeToFile(Logger *logger, const char *message, SeverityLevel level) {
    // Check if the message severity is equal to or higher than the logger's severity level
    if (level >= logger->severityLevel) {
        char timestamp[20];
        getCurrentTime(timestamp, sizeof(timestamp));

        logger->fileStream = fopen(logger->logFile, "a");
        if (logger->fileStream != NULL) {
            fprintf(logger->fileStream, "[%s] [%s] %s\n", timestamp,
                    (level == INFO) ? "INFO" : (level == WARNING) ? "WARNING" : "ERROR", message);
            fclose(logger->fileStream);
        } else {
            fprintf(stderr, "Error opening log file.\n");
        }
    }
}

// Function to write a log message to the console with timestamp and severity level
void writeToConsoleWithTime(const char *message, struct tm *localTime) {
    printf("[%04d-%02d-%02d %02d:%02d:%02d] %s\n",
           localTime->tm_year + 1900, localTime->tm_mon + 1, localTime->tm_mday,
           localTime->tm_hour, localTime->tm_min, localTime->tm_sec, message);
}

// Function to write a log message to a file with timestamp and severity level
void writeToFileWithTime(Logger *logger, const char *message, struct tm *localTime) {
    logger->fileStream = fopen(logger->logFile, "a");
    if (logger->fileStream != NULL) {
        fprintf(logger->fileStream, "[%04d-%02d-%02d %02d:%02d:%02d] %s\n",
                localTime->tm_year + 1900, localTime->tm_mon + 1, localTime->tm_mday,
                localTime->tm_hour, localTime->tm_min, localTime->tm_sec, message);
        fclose(logger->fileStream);
    } else {
        fprintf(stderr, "Error opening log file: %s\n", logger->logFile);
    }
}

// Function to write a formatted log message to the selected output channel
void writeLog(Logger *logger, SeverityLevel level, const char *format, ...) {
    if (level >= logger->severityLevel) {
        va_list args;
        va_start(args, format);

        // Formatting the log message
        char buffer[256];
        vsnprintf(buffer, sizeof(buffer), format, args);

        va_end(args);

        // Get the current date and time
        time_t currentTime = time(NULL);
        struct tm *localTime = localtime(&currentTime);

        // Writing to the selected output channel
        switch (logger->outputChannel) {
            case FILE_OUTPUT:
                writeToFileWithTime(logger, buffer, localTime);
                break;
            case CONSOLE_OUTPUT:
                writeToConsoleWithTime(buffer, localTime);
                break;
            default:
                break;
        }
    }
}

// Function to clear the content of a log file
void clearLogFile(const char *filePath) {
    // Open the log file in "w" mode (write mode)
    FILE *fileStream = fopen(filePath, "w");

    // Check if the file is successfully opened
    if (fileStream != NULL) {
        // Close the file stream to clear its content
        fclose(fileStream);
    } else {
        // Print an error message to the standard error stream if file opening fails
        fprintf(stderr, "Error opening log file for clearing.\n");
    }
}

// Main function
int main() {
    // Initialize logger_1
    Logger logger_1;
    initLogger(&logger_1);

    // Set output channel to file
    setOutputChannel(&logger_1, FILE_OUTPUT);

    // Clear the log file (comment this line if you don't want to clear the file)
    clearLogFile("./log.txt");

    // Set severity level
    setSeverityLevel(&logger_1, INFO);

    // Write log messages with severity levels
    writeLog(&logger_1, INFO, "This is an informational message.");
    writeLog(&logger_1, INFO, "This is another informational message.");  // Adjusted severity level to INFO
    writeLog(&logger_1, WARNING, "This is a warning message.");
    writeLog(&logger_1, ERROR, "This is an error message.");

    // Separate loggers with a clear distinction in severity level
    Logger logger;
    initLogger(&logger);

    // Set output channel to console
    setOutputChannel(&logger, CONSOLE_OUTPUT);

    // Clear the log file (comment this line if you don't want to clear the file)

    // Set severity level
    setSeverityLevel(&logger, WARNING);

    // Write log messages with severity levels
    writeLog(&logger, INFO, "This is an informational message.");
    writeLog(&logger, WARNING, "This is a warning message.");
    writeLog(&logger, ERROR, "This is an error message.");

    // Return 0 to indicate successful program execution
    return 0;
}
