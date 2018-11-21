// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   characterMove.cpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: yholub <yholub@student.unit.ua>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/07 11:28:33 by yholub            #+#    #+#             //
//   Updated: 2018/10/07 11:28:34 by yholub           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "../headers/ft_retro.hpp"

void	check_pos_change(CharacterFly *charact)
{
	int c;

	c = getch();
	if (c == 'a' || c == 'd' || c == 'w' || c == 's')
		charact->changePos(c);
	if (c == ' ')
		charact->newSoot(charact->getPosY() ,charact->getPosX() + 3);
	if (c == 'q')
	{
		endwin();
		exit(1);
	}
}

WINDOW*		check_bullets(WINDOW* win, CharacterFly *charact)
{
	t_bull *tmp;

	int i = 0;
	tmp = charact->getBull();
	if (charact->getBcount())
	{
		charact->bulletFly();
		init_pair(2, COLOR_GREEN, COLOR_BLACK);
		wattron(win, COLOR_PAIR(2));
		wattron(win, A_BOLD);

		while (tmp)
		{
			i++;
			mvwprintw(win, tmp->b->getYpos(), tmp->b->getXpos() + 1, "125");
			mvwprintw(win, tmp->b->getYpos(), MAX_X - 2, " ");
			tmp = tmp->next;
		}
		wattroff(win, A_BOLD);
		wattroff(win, COLOR_PAIR(2));

	}
	return win;
}

WINDOW*		print_character(WINDOW* win, CharacterFly *charact)
{
	check_pos_change(charact);
	win = check_bullets(win, charact);
	mvwprintw(win, charact->getPosY() - 1, charact->getPosX() + 1, "%s", (char*)PLAYER_FIG_ONE);
	mvwprintw(win, charact->getPosY(), charact->getPosX() + 1, "%s", (char*)PLAYER_FIG_TWO);
	mvwprintw(win, charact->getPosY() + 1, charact->getPosX() + 1, "%s", (char*)PLAYER_FIG_THR);
	wrefresh(win);
	return (win);
}

WINDOW 	*print_enemy(WINDOW *win, MainEvent *event)
{
	event->setEnemy();
	event->PrintAlive();
	wrefresh(win);
	return (win);
}