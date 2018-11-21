// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   beg_game.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: yholub <yholub@student.unit.ua>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/07 08:47:06 by yholub            #+#    #+#             //
//   Updated: 2018/10/07 08:47:07 by yholub           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "../headers/ft_retro.hpp"


WINDOW *	init_game(WINDOW *win)
{
	createNcurse();
	win = create_win();
	int x = 0;
	while (++x < MAX_X - 1)
		mvwprintw(win, 50, x, "_");
	wrefresh(win);
	return (win);
}

void	getResult(WINDOW *win, int hp)
{
	int c;

	init_pair(1, COLOR_RED, COLOR_BLACK);
	wattron(win, COLOR_PAIR(1));
	if (hp <= 0)
		mvwprintw(win, 52, 70 ,"Unfortunately you die :_(");
	else
		mvwprintw(win, 52, 70 ,"!!!!! Congratulations. you win! !!!!!!");
	wrefresh(win);
	while (1)
	{
		c = getch();
		if (c == 'q')
		{
			endwin();
			exit(1);
		}
	}
}

void	begin_game()
{
	char **sky;
	WINDOW *win = NULL;
	win = init_game(win);
	CharacterFly *charact;
	charact = new CharacterFly;
	sky = init_sky();
	time_t z_time = time(0);
	int game = 0;
	MainEvent *event = new MainEvent;
	int i;
	while (1)
	{
		win = print_sky(win, sky);
		win = print_character(win, charact);
		win = print_enemy(win, event);
		checkdamage(event, charact);
		i = 0;

		while (i < 30)
		{
			if (event->getEnemys()[i].getHp() <= 0)
			{
				if (event->getEnemys()[i].getAlive())
				{
					event->getEnemys()[i].setAlive();
					event->incEnc();
					game++;
				}
			}
			i++;
		}
		mvwprintw(win, 53 , 20 , "HP : %.3i %%", charact->getHp());
		mvwprintw(stdscr, 54, 160, "Time: %ld", (time(0) - z_time));
		mvprintw(55, 21 ,"Frags %i / 30", game);
		mvprintw(55, 160 ,"Press <WASD> to move");
		mvprintw(56, 160 ,"Press <Spase> to shoot");
		mvprintw(57, 160 ,"Press <q> to quit");
		if (game == 30 || charact->getHp() <= 0 || event->getinEnout() > 32)
		{
			getResult(win, charact->getHp());
			endwin();
			break;
		}
	}
	delete charact;
	endwin();
}