/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoytenk <vvoytenk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 13:49:02 by vvoytenk          #+#    #+#             */
/*   Updated: 2018/10/07 13:49:04 by vvoytenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Enemy.hpp"
#include "../headers/ft_retro.hpp"

Enemy::Enemy(void)
{
	std::srand(clock());
	random_pos();
	_hp = 100;
	_alive = false;
	_xMin = MIN_X + 1;
	_xMax = MAX_X - 20;
	_yMin = MIN_Y + 1;
	_yMax = MAX_Y - 2;
	_deley = 50;

	return ;
}

Enemy::Enemy(Enemy const &src)
{
	*this = src;
}

void	Enemy::setItsalive()
{
	_alive = true;
}

Enemy &Enemy::operator=(Enemy const &src)
{
	_xPos = src._xPos;
	_alive = false;
	_yPos = src._yPos;
	_hp = src._hp;
	_deley = src._deley;;
	return (*this);
}

Enemy::~Enemy(void)
{

};

void	Enemy::random_pos(void)
{
	_xPos = 180;
	_yPos = rand() % _yMax - 1;
	if (_yPos < 10)
		_yPos += 10;
}


void	Enemy::print_en(void)
{
	move_enemy();
	mvprintw(_yPos, _xPos,  "-42");
}

void	Enemy::move_enemy(void)
{
	if (_deley > 0)
		--_deley;
	else
	{
		--_xPos;
		if (_xPos < 3)
			_alive = false;
		_deley = 10;
	}
}