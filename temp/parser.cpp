/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** parser
*/

#include <iostream>
#include <fstream>
#include <regex>
#include <string>

static std::vector<std::string> map;
static std::map<std::string, std::vector<std::map<std::string, std::string>>> config; 

void parseMap()
{
    const std::regex title("\\[(map)\\]");
    const std::regex value("\\\"([.|x]+)\\\"");
    std::string line, current;
    std::smatch match;

    std::ifstream file ("save.ini");
    if (!file.is_open())
        exit (EXIT_FAILURE);
    while (std::getline(file, line)) {
        if (line.length() == 0 || line.at(0) == ';')
            continue;
        if (current.empty() && std::regex_search(line, match, title))
            current = "map";
        else if (current == "map" && std::regex_search(line, match, value))
            map.push_back(match[1]);
        else if (current == "map")
            break;
    }

    if (map.empty())
        return;
    std::cout << "[map]" << std::endl;
    for (auto& line : map)
        std::cout << line << std::endl;
    std::cout << std::endl;
}

void parseConfig()
{                                            
    // (?::(\\d*))? for :x
    const std::regex title("\\[(\\w*)\\]");
    const std::regex value("\\s*(\\w+)\\s*=\\s*(\\d+)\\s*");    
    std::string line, current; 
    std::smatch match;

    std::ifstream file ("save.ini");
    if (!file.is_open())
        exit (EXIT_FAILURE);

    while (std::getline(file, line)) {
        if (line.length() == 0 || line.at(0) == ';')
            continue;

        if (std::regex_search(line, match, title) && match[1] != "map") {
            current = match[1];
            if (current.empty())
                current = "global";
            if (current != "global" || config[current].empty())
                config[current].push_back(std::map<std::string, std::string>());
        } else if (current != "map" && std::regex_search(line, match, value)) {
            if (current.empty()) {
                current = "global";
                if (config[current].empty())
                    config[current].push_back(std::map<std::string, std::string>());
            }
            config[current].back()[match[1]] = match[2];
        }
    }
    file.close();

    for (auto &section : config) {
        std::cout << "[" << section.first << "]" << std::endl;
        for (auto &value : section.second) {
            for (auto &kv : value)
                std::cout << kv.first << " = " << kv.second << std::endl;
            std::cout << std::endl;
        }
    }
}

int main(void)
{
    parseMap();
    parseConfig();
}
