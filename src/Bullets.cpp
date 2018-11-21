// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Bullets.cpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: yholub <yholub@student.unit.ua>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/07 13:26:58 by yholub            #+#    #+#             //
//   Updated: 2018/10/07 13:26:58 by yholub           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "MainEvent.hpp"
#include "Bullets.hpp"

Bullets::Bullets()
{
	_yPos = 2;
	_xPos = 25;
	_death = false;
}

Bullets::Bullets(int y, int x)
{
	_yPos = y;
	_xPos = x;
	_death = false;
}

Bullets::Bullets(const Bullets &sec)
{
	*this = sec;
}

Bullets& Bullets::operator=(Bullets const &src)
{
	_xPos = src._xPos;
	_yPos = src._yPos;
	_death = src._death;
	return (*this);
}

void	 Bullets::flyForw()
{
	if (_xPos + 1 < MAX_X - 4)
		_xPos++;
	else
		_death = true;
}

Bullets::~Bullets()
{

}
void	Bullets::setStatus()
{
	_death = true;
}

bool	Bullets::getStatus()
{
	return this->_death;
}

int	Bullets::getXpos()
{
	return this->_xPos;
}

int	Bullets::getYpos()
{
	return this->_yPos;
}

