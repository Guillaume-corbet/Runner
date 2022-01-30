/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** my_runner
*/

#ifndef MY_RUNNER_H_
#define MY_RUNNER_H_

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/Transform.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Clock.h>
#include <SFML/System/Types.h>
#include <SFML/System/InputStream.h>
#include <SFML/System/Vector3.h>
#include <SFML/Graphics/RenderStates.h>
#include <SFML/Audio.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/Audio/Music.h>
#include <SFML/Graphics/Font.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>
#include "./lib/my/my.h"
#include "./lib/my_printf/my_printf.h"
#include "get_next_line.h"

struct node_spike
{
    sfVector2f move_spike;
    sfSprite *sprite_spike;
    sfTexture *texture_spike;
    struct node_spike *p_next;
    struct node_spike *p_prev;
};

typedef struct dlist_spike
{
    size_t length;
    struct node_spike *p_tail;
    struct node_spike *p_head;
}rlist_spike;

typedef struct runner
{
    sfRenderWindow *window;
    sfVideoMode video_mode;
    sfIntRect rect_character;
    sfIntRect rect_firework;
    sfVector2f move_character;
    sfVector2f move_ground;
    sfVector2f move_fond_second;
    sfVector2f move_fond;
    sfVector2f pos_castle;
    sfVector2f pos_firework;
    sfVector2f pos_score;
    sfVector2f pos_score_number;
    sfVector2f pos_pause;
    sfVector2f mult;
    sfClock *clock_game;
    sfClock *clock_map;
    sfEvent event;
    sfTime time_game;
    sfTime time_map;
    sfText *score_number;
    sfText *score;
    sfText *pause;
    sfText *lose;
    sfText *win;
    sfMusic *music;
    sfMusic *music_ending;
    sfMusic *music_lose;
    sfFont *font;
    sfColor color;
    sfSprite *sprite_character;
    sfSprite *sprite_fond;
    sfSprite *sprite_fond_second;
    sfSprite *sprite_ground;
    sfSprite *sprite_castle;
    sfSprite *sprite_firework;
    sfTexture *texture_character;
    sfTexture *texture_fond;
    sfTexture *texture_fond_second;
    sfTexture *texture_ground;
    sfTexture *texture_castle;
    sfTexture *texture_firework;
    float seconds_game;
    float seconds_map;
    int n;
    int up;
    int jump;
    int scores;
    int pause_ok;
    int count_point;
    int loser;
    int winner;
    char *map;
}runner_t;

void dlist_append_second_spike(rlist_spike *p_list_spike,
struct node_spike *p_new);
void dlist_append_spike(rlist_spike *p_list_spike);

void castle_create(runner_t *);

void character_create(runner_t *);
rlist_spike *character_main(runner_t *, rlist_spike *p_list_spike);
void hitbox_spike(runner_t *, rlist_spike *p_list_spike);
void hitbox_spike_lost(runner_t *, rlist_spike *);

void destroy(runner_t *, rlist_spike *p_list_spike);
void destroy_spike(runner_t *, rlist_spike *);

int ending_lost(runner_t *);
int ending_win(runner_t *);

void event_main(runner_t *, rlist_spike *p_list_spike);

void firework_create(runner_t *);

void fond_create(runner_t *);
void fond_main(runner_t *);

rlist_spike *dlist_new_spike(void);
void dlist_remove_spike(rlist_spike *p_list_spike, int position);
void dlist_remove_second_spike(rlist_spike *p_list_spike,
struct node_spike *p_temp, int position);
void dlist_remove_third_spike(rlist_spike *, struct node_spike *, int, int);

void music_create(runner_t *);

char *int_to_str(int);
void create_game(runner_t *ru);
int main_game(runner_t *ru, rlist_spike *p_list_spike);

void fonc_pause(runner_t *, rlist_spike *p_list_spike);

rlist_spike *spike_create(runner_t *, rlist_spike *p_list_spike);
rlist_spike *spike_main(runner_t *, rlist_spike *p_list_spike);

char *get_next_line(int fd);
void stock_map(runner_t *, char **);
void reading_map(runner_t *, rlist_spike *);
void ending(runner_t *, rlist_spike *);
void ending_castle(runner_t *, rlist_spike *);

void text_create(runner_t *);
void text_create_second(runner_t *);
void text_main(runner_t *);

int usage(runner_t *, int, char **);

void window_create(runner_t *);

#endif /* !MY_RUNNER_H_ */