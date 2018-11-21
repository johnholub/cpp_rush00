// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   MainEvent.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: yholub <yholub@student.unit.ua>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/07 09:02:06 by yholub            #+#    #+#             //
//   Updated: 2018/10/07 09:02:07 by yholub           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "MainEvent.hpp"
#include "Enemy.hpp"

MainEvent::MainEvent()
{
	_enMax = 30;
	_inMap = 0;
	_enCount = 0;
	return ;
}

MainEvent::MainEvent(MainEvent const &src)
{
	*this = src;
}

MainEvent::~MainEvent()
{
	return ;
}

MainEvent &MainEvent::operator=(MainEvent const &src)
{
	_enCount = src._enCount;
	_enMax = src._enMax;
	return (*this);
}

void MainEvent::setEnemy(void)
{
	int i = 0;
	int liv = 0;
	while (i < 30)
	{
		if (_enemies[i].getAlive())
			liv++;
		i++;
	}
	if (liv == 0)
		_inMap = 0;
	if (_inMap == 0)
	{
		while (_inMap < 4)
		{
			_enemies[_enCount].setItsalive();
			_inMap++;
			_enCount++;
		}
	}
}

int	MainEvent::getinEnout()
{
	return  _enCount;
}

Enemy	 *MainEvent::getEnemys(void)
{
	return _enemies;
}

void	MainEvent::incEnc()
{
	_inMap -= 1;
}

void MainEvent::PrintAlive(void)
{
	int i = 0;
	while (i < 30)
	{
		if (_enemies[i].getAlive())
		{
			_enemies[i].print_en();
		}
		i++;
	}
}
