// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   visual.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: yholub <yholub@student.unit.ua>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/07 08:43:47 by yholub            #+#    #+#             //
//   Updated: 2018/10/07 08:43:47 by yholub           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "../headers/ft_retro.hpp"

WINDOW		*create_win(void)
{
	WINDOW	*win;

	win = newwin(MAX_Y + 10, MAX_X, 1, 1);
	box(win, 0, 0);
	refresh();
	wrefresh(win);
	return (win);
}

void createNcurse()
{
	initscr();

	keypad(stdscr, true);
	noecho();
	curs_set(0);
	if (COLS < MAX_X)
	{
		endwin();
		std::cout << "Too small window width!" << std::endl;
		exit(0);
	}
	if (LINES < MAX_Y)
	{
		endwin();
		std::cout << "Too small window height!" << std::endl;
		exit(0);
	}
	nodelay(stdscr, true);
	start_color();
}