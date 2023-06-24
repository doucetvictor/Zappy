/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** Gui.cpp
*/

#include "Gui.hpp"
#include "Errors.hpp"
#include "GetOpt.hpp"


Gui::Gui(int ac, char **av): _win(sf::VideoMode(1920, 1080), "Zappy") , _map(1920, 1080)
{
    
    if (ac == 2 && std::string(av[1]) == "-help")
        throw std::invalid_argument("Help");
    GetOpt getOpt(ac, av);
    _port = getOpt.getPort();
    _host = getOpt.getHost();
    _comm.setHost(_host);
    _comm.setPort(_port);
    this->_interfaceOn = false;
    std::cout << "Port: " << _port << std::endl;
    std::cout << "Host: " << _host << std::endl;
}

void Gui::initGui()
{
    try {
        this->_comm.connectToServer();
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    this->_comm.writeToServer("msz\n");
    this->_comm.readFromServer();
    std::string mapSize = this->_comm.popCmd();
    while (!mapSize.empty() && mapSize.substr(0, 3) != "msz")
    {
        mapSize = this->_comm.popCmd();
    }
    int firstArg = mapSize.find(' ') + 1;
    std::string width =  mapSize.substr(firstArg, mapSize.find(' ', firstArg) - firstArg);
    int secondArg = mapSize.find(' ', firstArg) + 1;
    std::string height = mapSize.substr(secondArg, mapSize.find(' ', secondArg) - secondArg);
    std::list<std::string> list;
    list.push_back(width);
    list.push_back(height);
    FunctionManager::msz(list, this->_map);
}

void Gui::guiLoop()
{
    while (this->_win.isOpen()) {
        this->_comm.readFromServer();
        std::string cmd;
        while (!(cmd = this->_comm.popCmd()).empty())
        {
            printf("cmd = %s\n", cmd.data());
            this->_cmdHandler.callFunction(cmd, this->_map);
        }
        if (_interfaceOn) {
            printf("tile is cooord is %d %d\n", this->_tileClicked.x, this->_tileClicked.y);
        }
        this->_map.updateTexture();
        this->eventHandler();
        this->_win.clear(sf::Color::Black);
        this->_win.draw(this->_map);
        this->_win.display();
    }
}

std::string Gui::getPort() const
{
    return _port;
}

std::string Gui::getHost() const
{
    return _host;
}

void Gui::eventHandler()
{
    sf::Event event{};
    while (this->_win.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
            this->_win.close();
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right)
            this->_map.moveMap(10, 0);
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left)
            this->_map.moveMap(-10, 0);
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
            this->_map.moveMap(0, -10);
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
            this->_map.moveMap(0, 10);
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::W)
            this->_map.zoom(true);
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::X)
            this->_map.zoom(false);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            try {
                this->_tileClicked = this->_map.getTileInfo(sf::Mouse::getPosition(this->_win));
                this->_interfaceOn = true;
                this->_interface = Interface(this->_tileClicked);
                this->_interface.updateInterface(this->_tileClicked);
            } catch (std::exception &e) {
                e.what();
            }
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
            this->_interfaceOn = false;
        }
    }
}
