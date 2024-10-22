// linux based task _ command line script


#include <iostream>
#include <cstdlib>  // For system()
#include <string>
#include <bits/stdc++.h>  // For various C++ utilities


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
