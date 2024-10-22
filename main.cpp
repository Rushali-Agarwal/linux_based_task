// linux based task _ command line script


#include <iostream>
#include <cstdlib>  // For system()
#include <string>
#include <bits/stdc++.h>  // For various C++ utilities

// Function prototypes
void showHelp();
void showVersion();
void listServices();
void systemLoad();
void startService(const std::string &serviceName);
void stopService(const std::string &serviceName);
void checkDiskUsage();
void monitorProcesses();
void analyzeLogs();
void backupFiles(const std::string &path);








// Function to display help
void showHelp() {

    std::cout << "Usage: Enter one of the following commands:\n";
    std::cout << "Commands:\n";
    
    
    std::cout << "  help                  Show help information.\n";
    std::cout << "  version               Show version information.\n";
    std::cout << "  service list          List running services.\n";
    std::cout << "  service start <name>  Start a service.\n";
    std::cout << "  service stop <name>   Stop a service.\n";
    std::cout << "  system load           Show system load averages.\n";
    std::cout << "  disk usage            Check disk usage.\n";
    std::cout << "  process monitor       Monitor system processes.\n";
    std::cout << "  logs analyze          Analyze system logs.\n";
    std::cout << "  backup <path>         Backup system files from the given path.\n";
}

// Function to display version
void showVersion() {
    
    std::cout << "sysopctl version 0.1.0\n";
}

// Function to list running services


void listServices() {
    std::cout << "Listing active services...\n";
    system("systemctl list-units --type=service");
}

// Function to show system load averages
void systemLoad() {
    std::cout << "Current system load...\n";
    system("uptime");
}

// Function to start a service
void startService(const std::string &serviceName) {
    std::string command = "systemctl start " + serviceName;
    system(command.c_str());

    std::cout << "Started service: " << serviceName << "\n";
}

// Function to stop a service
void stopService(const std::string &serviceName) {
    std::string command = "systemctl stop " + serviceName;
    system(command.c_str());
    std::cout << "Stopped service: " << serviceName << "\n";
}

// Function to check disk usage


void checkDiskUsage() {
    std::cout << "Disk usage by partition:\n";
    system("df -h");
}

// Function to monitor system processes
void monitorProcesses() {
    std::cout << "Monitoring processes (press q to exit)...\n";
    system("top");
}

// Function to analyze system logs
void analyzeLogs() {
    std::cout << "Analyzing system logs...\n";
    system("journalctl -p 3 -xb");
}


// Function to backup system files using rsync
void backupFiles(const std::string &path) {
    std::string command = "rsync -av --progress " + path + " /backup/";
    std::cout << "Backing up files from: " << path << "\n";
    system(command.c_str());
}








// Main function to take input from the user and execute commands interactively
int main() {
    std::string command;
    
    while (true) {
        // Prompt for command input
        std::cout << "\nsysopctl> ";
        std::getline(std::cin, command);

        // Trim the input to ignore leading/trailing spaces
        std::istringstream iss(command);
        std::vector<std::string> tokens;
        std::string token;
        while (iss >> token) {
            tokens.push_back(token);
        }

        // No input provided
        if (tokens.empty()) {
            continue;
        }

        // Handle commands
        if (tokens[0] == "help") {
            showHelp();
        } else if (tokens[0] == "version") {
            showVersion();
        } else if (tokens[0] == "service" && tokens.size() == 2 && tokens[1] == "list") {
            listServices();
        } else if (tokens[0] == "system" && tokens.size() == 2 && tokens[1] == "load") {
            systemLoad();
        } else if (tokens[0] == "service" && tokens.size() == 3 && tokens[1] == "start") {
            startService(tokens[2]);
        } else if (tokens[0] == "service" && tokens.size() == 3 && tokens[1] == "stop") {
            stopService(tokens[2]);
        } else if (tokens[0] == "disk" && tokens.size() == 2 && tokens[1] == "usage") {
            checkDiskUsage();
        } else if (tokens[0] == "process" && tokens.size() == 2 && tokens[1] == "monitor") {
            monitorProcesses();
        } else if (tokens[0] == "logs" && tokens.size() == 2 && tokens[1] == "analyze") {
            analyzeLogs();
        } else if (tokens[0] == "backup" && tokens.size() == 2) {
            backupFiles(tokens[1]);
        } else if (tokens[0] == "exit") {
            std::cout << "Exiting sysopctl...\n";
            break;
        } else {
            std::cout << "Error: Unknown command. Type 'help' for usage information.\n";
        }
    }

    return 0;
}
