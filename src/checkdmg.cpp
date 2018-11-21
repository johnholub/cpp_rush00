// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   checkdmg.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: yholub <yholub@student.unit.ua>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/07 17:03:29 by yholub            #+#    #+#             //
//   Updated: 2018/10/07 17:03:29 by yholub           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "../headers/ft_retro.hpp"

t_coord *chCoords(int xch, int ych)
{
	int y;

	t_coord *res;
	res = new t_coord[7];
	y = 0;
	while (y < 8)
	{
		res[y].y = ych - 3;
		res[y].x = xch - 2;
		xch++;
		ych++;
		y++;
	}
	return (res);
}

void checkAccident(MainEvent *event,CharacterFly* charact)
{
	int xc;
	int yc = 0;
	int i;
	t_coord *chCoord;

	chCoord = chCoords(charact->getPosX(), charact->getPosY());
	i = 0;
	while (i < 30)
	{
		yc = 0;
		while (yc < 8)
		{
			if (event->getEnemys()[i].getPosY() == chCoord[yc].y)
			{
				xc = 0;
				while (xc < 8)
				{
					if (event->getEnemys()[i].getPosX() == chCoord[xc].x)
					{
						if (event->getEnemys()[i].getAlive())
						{
							event->getEnemys()[i].setHp(-100);
							event->getEnemys()[i].getAlive();
							charact->setHp(-50);
						}
					}
					xc++;

				}
			}
			yc++;
		}
		i++;
	}
}

void checkdamage(MainEvent *event,CharacterFly* charact)
{
	t_bull *bullets;
	t_bull *beg;
	int xBul;
	int yBul;
	int yEn;
	int xEn;
	int i;

	checkAccident(event, charact);
	i = 0;
	while (i < 30)
	{
		if (event->getEnemys()[i].getAlive())
		{
			beg = charact->getBull();
			bullets = charact->getBull();
			while (bullets)
			{
				yBul = bullets->b->getYpos();
				xBul = bullets->b->getXpos();
				xEn = event->getEnemys()[i].getPosX();
				yEn = event->getEnemys()[i].getPosY();
				if (yBul >= yEn - 2 && yBul <= yEn &&
						xBul >= xEn - 1 && xBul <= xEn + 1)
				{
					event->getEnemys()[i].setHp(-32);
					bullets->b->setStatus();
				}
				bullets = bullets->next;
			}
			charact->setBull(beg);
		}
		i++;
	}
}
