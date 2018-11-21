// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   move_sky.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: yholub <yholub@student.unit.ua>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/07 10:36:08 by yholub            #+#    #+#             //
//   Updated: 2018/10/07 10:36:08 by yholub           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "../headers/ft_retro.hpp"
#include <cstdio>

char **init_sky()
{
	char **sky;
	int x;
	int y = 0;
	sky = new char*[MAX_Y];
	while (y < MAX_Y - 1)
	{
		sky[y] = new char[MAX_X];
		y++;
	}
	y = 0;
	while (y < MAX_Y - 1)
	{
		x = 0;
		while (x < MAX_X - 1)
		{
			sky[y][x] = ' ';
			x++;
		}
		y++;
	}
	sky[2][10] = '*';
	sky[7][11] = '*';
	sky[20][170] = '*';
	sky[32][102] = '*';
	sky[42][70] = '*';
	sky[12][78] = '*';
	sky[45][121] = '*';
	sky[25][189] = '*';
	sky[43][25] = '*';
	sky[47][149] = '*';
	sky[29][167] = '*';
	sky[41][121] = '*';
	sky[1][190] = '*';
	sky[12][174] = '*';
	sky[45][10] = '*';
	sky[1][21] = '*';
	return (sky);
}

void	move_sky(char **sky)
{
	int x;
	int y = 1;

	while (y < MAX_Y - 1)
	{
		x = 1;
		while (x < MAX_X - 1)
		{
			if (sky[y][x] == '*')
			{
				if (x == 1)
				{
					sky[y][x] = ' ';
					sky[y][MAX_X - 2] = '*';
				}
				else
				{
					sky[y][x] = ' ';
					sky[y][x - 1] = '*';
				}
			}
			x++;
		}
		y++;
	}
}

WINDOW *	print_sky(WINDOW *win, char **sky)
{
	int y = 1;
	int x;
	move_sky(sky);
	while (y < MAX_Y - 1)
	{
		x = 1;
		while (x < MAX_X - 1)
		{
			mvwprintw(win, y, x, "%c", sky[y][x - 1]);
			x++;
		}
		y++;
	}
	wrefresh(win);
	return (win);
}