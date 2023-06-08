/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** player.c
*/

#include <time.h>
#include "zappy_server.h"

zappy_player_t *get_player_by_id(zappy_server_t *server, int id)
{
    zappy_client_t *client = NULL;

    for (int i = 0; i < ZAPPY_SERVER_MAX_CLIENTS; ++i) {
        client = &server->clients[i];
        if (client->player.id != 0 && client->player.id == id) {
            return &client->player;
        }
    }
    return NULL;
}

void add_player_command(zappy_client_t* client, zappy_pcmd_t *pcmd)
{
    for (int i = 0; i < 10; ++i) {
        if (client->player.cmds[i].pcmd == NULL) {
            client->player.cmds[i].start = time(NULL);
            client->player.cmds[i].pcmd = pcmd;
            return;
        }
    }
}
