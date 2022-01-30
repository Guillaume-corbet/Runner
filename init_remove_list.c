/*
** EPITECH PROJECT, 2018
** CPE_pushswap_2018
** File description:
** init_stock_list
*/

#include "my_runner.h"

rlist_spike *dlist_new_spike(void)
{
    rlist_spike *p_new = malloc(sizeof(*p_new));
    if (p_new != NULL) {
        p_new->length = 0;
        p_new->p_head = NULL;
        p_new->p_tail = NULL;
    }
    return (p_new);
}

void dlist_remove_second_spike(rlist_spike *p_list,
struct node_spike *p_temp, int position)
{
    if (p_list->length == 1) {
        p_list->p_tail = NULL;
    } else if (p_temp->p_next == NULL) {
        p_list->p_tail = p_temp->p_prev;
        p_list->p_tail->p_next = NULL;
    } else if (p_temp->p_prev == NULL) {
        p_list->p_head = p_temp->p_next;
        p_list->p_head->p_prev = NULL;
    } else {
        p_temp->p_next->p_prev = p_temp->p_prev;
        p_temp->p_prev->p_next = p_temp->p_next;
    }
}

void dlist_remove_third_spike(rlist_spike *p_list,
struct node_spike *p_temp, int position, int i)
{
    if (position == i) {
        dlist_remove_second_spike(p_list, p_temp, position);
        free(p_temp);
        p_list->length = p_list->length - 1;
    } else {
        p_temp = p_temp->p_next;
    }
}

void dlist_remove_spike(rlist_spike *p_list, int position)
{
    if (p_list != NULL) {
        struct node_spike *p_temp = p_list->p_head;
        int i = 1;
        while (p_temp != NULL && i <= position) {
            dlist_remove_third_spike(p_list, p_temp, position, i);
            i++;
        }
    }
}