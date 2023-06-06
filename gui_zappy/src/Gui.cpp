/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** Gui.cpp
*/

#include "Gui.hpp"
#include "GetOpt.hpp"

Gui::Gui(int ac, char **av)
{
    if (ac != 5) {
        printUsage();
        throw std::invalid_argument("Too many or not enough arguments");
    }
    GetOpt getOpt(ac, av);
    _port = getOpt.getPort();
    _host = getOpt.getHost();
}

void Gui::printUsage()
{
    std::cout << "USAGE: ./zappy_gui -p port -h machine" << std::endl;
    std::cout << "\tport\tis the port number" << std::endl;
    std::cout << "\tmachine\tis the name of the machine; localhost by default" << std::endl;
}

std::string Gui::getPort() const
{
    return _port;
}

std::string Gui::getHost() const
{
    return _host;
}
