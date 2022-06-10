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

int main(void)
{
    std::string line, current;                                             

    // (?::(\\d*))? for :x
    std::regex section_test("\\[(\\w*)\\]");
    std::regex value_test("\\s*(\\w+)\\s*=\\s*(\\d+)\\s*");

    std::map<std::string, std::vector<std::map<std::string, std::string>>> config;     

    std::ifstream mapfile ("save.ini");
    if (!mapfile.is_open())
        return (EXIT_FAILURE);

    while (std::getline(mapfile, line)) {
        if (line.length() == 0 || line.at(0) == ';')
            continue;

        std::smatch match;

        if (std::regex_search(line, match, section_test)) {
            current = match[1];
            if (current.empty())
                current = "global";
            if (current != "global" || config[current].empty())
                config[current].push_back(std::map<std::string, std::string>());
        } else if (std::regex_search(line, match, value_test)) {
            if (current.empty()) {
                current = "global";
                if (config[current].empty())
                    config[current].push_back(std::map<std::string, std::string>());
            }
            config[current].back()[match[1]] = match[2];
        }
    }
    mapfile.close();

    for (auto &section : config) {
        std::cout << "[" << section.first << "]" << std::endl;
        for (auto &value : section.second) {
            for (auto &kv : value)
                std::cout << kv.first << " = " << kv.second << std::endl;
            std::cout << std::endl;
        }
    }

    return (EXIT_SUCCESS);
}