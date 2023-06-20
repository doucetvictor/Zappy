/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** player_fork.c
*/

#include <stdio.h>
#include "zappy_server.h"

void player_fork(zappy_client_t *client, char *)
{
    if (spawn_egg(client->server, client->player.team)) {
        dprintf(client->sockfd, "ok\n");
        graphical_pfk(client->server, &client->player);
    } else {
        dprintf(client->sockfd, "ko\n");
    }
}
