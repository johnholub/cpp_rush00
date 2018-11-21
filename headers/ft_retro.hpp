// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ft_retro.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: yholub <yholub@student.unit.ua>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/07 08:32:44 by yholub            #+#    #+#             //
//   Updated: 2018/10/07 08:32:44 by yholub           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FT_RETRO_HPP
# define FT_RETRO_HPP

# define PLAYER_FIG_ONE " _|\\\\__"
# define PLAYER_FIG_TWO "}_   __ )>"
# define PLAYER_FIG_THR "  |//    "

#include <ncurses.h>
#include <iostream>
#include <string>
#include "MainEvent.hpp"
#include "CharacterFly.hpp"
#include <unistd.h>
#include "Enemy.hpp"

typedef struct s_cord
{
  int x;
  int y;

}			 t_coord;

static  int s_game = 0;

WINDOW*		print_character(WINDOW* win, CharacterFly* charact);
WINDOW *	print_sky(WINDOW *win, char **sky);
char ** 	init_sky();
WINDOW		*create_win(void);
void 		createNcurse();
void		begin_game();
WINDOW 		*print_enemy(WINDOW *win, MainEvent *event);
void		checkdamage(MainEvent *event,CharacterFly* charact);

#endif