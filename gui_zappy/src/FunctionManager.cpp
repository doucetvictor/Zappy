/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** FunctionManager.cpp
*/

#include "FunctionManager.hpp"

FunctionManager::FunctionManager()
{
    _fct["msz"] = &msz;
    _fct["bct"] = &bct;
    _fct["tna"] = &tna;
    _fct["pnw"] = &pnw;
    _fct["ppo"] = &ppo;
    _fct["plv"] = &plv;
    _fct["pin"] = &pin;
    _fct["pex"] = &pex;
    _fct["pbc"] = &pbc;
    _fct["pic"] = &pic;
    _fct["pie"] = &pie;
    _fct["pfk"] = &pfk;
    _fct["pdr"] = &pdr;
    _fct["pgt"] = &pgt;
    _fct["pdi"] = &pdi;
    _fct["enw"] = &enw;
    _fct["ebo"] = &ebo;
    _fct["edi"] = &edi;
    _fct["sgt"] = &sgt;
    _fct["seg"] = &seg;
    _fct["smg"] = &smg;
    _fct["suc"] = &suc;
    _fct["sbp"] = &sbp;
}

void FunctionManager::callFunction(std::string command, Map myMap)
{
    std::list<std::string> arguments;
    ParseServerCommands parser;

    if (command.empty())
        return;
    parser.parseCommand(command);
    _fct[arguments.front()](arguments, myMap);
}

std::map<std::string, void (*)(std::list<std::string> arg, Map myMap)> FunctionManager::getFct() const
{
    return _fct;
}

void FunctionManager::setFct(const std::map<std::string, void (*)(std::list<std::string> arg, Map myMap)> &fct)
{
    _fct = fct;
}

void FunctionManager::msz(std::list<std::string> arg, Map &myMap)
{
    if (arg.size() != 2)
        return;
}

void FunctionManager::bct(std::list<std::string> arg, Map &myMap)
{
    if (arg.size() != 9)
        return;
}

void FunctionManager::tna(std::list<std::string> arg, Map &myMap)
{
    if (arg.size() != 1)
        return;
}

void FunctionManager::pnw(std::list<std::string> arg, Map &myMap)
{
    if (arg.size() != 6)
        return;
}

void FunctionManager::ppo(std::list<std::string> arg, Map &myMap)
{
    if (arg.size() != 4)
        return;
}

void FunctionManager::plv(std::list<std::string> arg, Map &myMap)
{
    if (arg.size() != 2)
        return;
}

void FunctionManager::pin(std::list<std::string> arg, Map &myMap)
{
    if (arg.size() != 10)
        return;
}

void FunctionManager::pex(std::list<std::string> arg, Map &myMap)
{
    if (arg.size() != 1)
        return;
}

void FunctionManager::pbc(std::list<std::string> arg, Map &myMap)
{
    if (arg.size() != 2)
        return;
}

void FunctionManager::pic(std::list<std::string> arg, Map &myMap)
{
}

void FunctionManager::pie(std::list<std::string> arg, Map &myMap)
{
    if (arg.size() != 3)
        return;
}

void FunctionManager::pfk(std::list<std::string> arg, Map &myMap)
{
    if (arg.size() != 1)
        return;
}

void FunctionManager::pdr(std::list<std::string> arg, Map &myMap)
{
    if (arg.size() != 2)
        return;
}

void FunctionManager::pgt(std::list<std::string> arg, Map &myMap)
{
    if (arg.size() != 2)
        return;
}

void FunctionManager::pdi(std::list<std::string> arg, Map &myMap)
{
    if (arg.size() != 1)
        return;
}

void FunctionManager::enw(std::list<std::string> arg, Map &myMap)
{
    if (arg.size() != 4)
        return;
}

void FunctionManager::ebo(std::list<std::string> arg, Map &myMap)
{
    if (arg.size() != 1)
        return;
}

void FunctionManager::edi(std::list<std::string> arg, Map &myMap)
{
    if (arg.size() != 1)
        return;
}

void FunctionManager::sgt(std::list<std::string> arg, Map &myMap)
{
    if (arg.size() != 1)
        return;
}

void FunctionManager::seg(std::list<std::string> arg, Map &myMap)
{
    if (arg.size() != 1)
        return;
}

void FunctionManager::smg(std::list<std::string> arg, Map &myMap)
{
    if (arg.size() != 1)
        return;
}

void FunctionManager::suc(std::list<std::string> arg, Map &myMap)
{
}

void FunctionManager::sbp(std::list<std::string> arg, Map &myMap)
{
}
