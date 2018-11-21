// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   CharacterFly.cpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: yholub <yholub@student.unit.ua>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/07 11:00:37 by yholub            #+#    #+#             //
//   Updated: 2018/10/07 11:00:38 by yholub           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ft_retro.hpp"
#include "CharacterFly.hpp"

CharacterFly::CharacterFly()
{
	_xPos = 2;
	_yPos = 25;
	_hp = 100;
	_bCount = 0;
	_bull = NULL;
	_xMin = MIN_X + 1;
	_xMax = MAX_X - 10;
	_yMin = MIN_Y + 1;
	_yMax = MAX_Y - 2;
	_alive = true;
}

CharacterFly::CharacterFly(int y, int x)
{
	_xPos = y;
	_yPos = x;
	_hp = 100;
	_bull = NULL;
	_bCount = 0;
	_xMin = MIN_X + 1;
	_xMax = MAX_X - 10;
	_yMin = MIN_Y + 1;
	_yMax = MAX_Y - 2;
	_alive = true;
}

CharacterFly::CharacterFly(const CharacterFly &sec)
{
	*this = sec;
}

CharacterFly & CharacterFly::operator=(CharacterFly const &src)
{
	_xPos = src._xPos;
	_yPos = src._yPos;
	_hp = src._hp;
	_bCount = src._bCount;
	_bull = src._bull;
	_alive = src._alive;
	return (*this);
}

CharacterFly::~CharacterFly()
{

}

int	CharacterFly::getHp()
{
	return this->_hp;
}

int	CharacterFly::getPosX()
{
	return this->_xPos;
}

int	CharacterFly::getPosY()
{
	return this->_yPos;
}
void	CharacterFly::setPosX(int i)
{
	i++;
	this->_xPos = _xPos + i;
}

void	CharacterFly::setPosY(int i)
{
	i++;
	this->_yPos = _yPos + i;
}

void	CharacterFly::setHp(int dmg)
{
	this->_hp += dmg;
}

void	CharacterFly::changePos(int key)
{
	if (key == 'w' && _yPos - 1 > _yMin)
		--_yPos;
	else if (key == 's' && _yPos + 1 < _yMax)
		++_yPos;
	else if (key == 'a' && _xPos - 3 > _xMin)
		_xPos -= 3;
	else if (key == 'd' && _xPos + 3 < _xMax)
		_xPos += 3;
}

void	CharacterFly::cheackFirst()
{
	t_bull *tmp;

	tmp = _bull;
	if (_bull)
	{
		if (_bull->b->getStatus())
		{
			if (_bull->next)
			{
				_bull = _bull->next;
				delete tmp->b;
				delete tmp;
				_bCount--;
			}
			else
			{
				delete _bull->b;
				delete _bull;
				_bCount--;
			}
		}
	}
}

void	CharacterFly::remBull()
{
	t_bull *tmp;
	t_bull *tmp2;
	if (_bull)
	{
		while (_bull->b->getStatus() && getBcount() > 0)
			cheackFirst();
		if (_bull)
		{
			tmp = _bull;
			while (_bull)
			{
				if (_bull->next)
				{
					if (_bull->next->b->getStatus())
					{
						tmp2 = _bull->next;
						if (_bull->next->next)
							_bull->next = _bull->next->next;
						else
							_bull->next = NULL;
						delete tmp2->b;
						delete tmp2;
						--_bCount;
					}
				}
				_bull = _bull->next;
			}
			_bull = tmp;
		}
	}
}

void	CharacterFly::bulletFly()
{
	t_bull *tmp;
	tmp = _bull;
	while (_bull)
	{
		_bull->b->flyForw();
		_bull = _bull->next;
	}
	_bull = tmp;
	remBull();
}

void	CharacterFly::newSoot(int y, int x)
{
	t_bull* tmp = _bull;
	if (_bCount == 0)
	{
		_bull = new t_bull;
		_bull->b = new Bullets(y, x);
		_bull->next = NULL;
		_bCount++;
	}
	else
	{
		while (_bull->next)
			_bull = _bull->next;
		_bull->next = new t_bull;
		_bull->next->b = new Bullets(y, x);
		_bull->next->next = NULL;
		_bCount++;
		_bull = tmp;
	}
}

void	CharacterFly::setBull(t_bull* newBull)
{
	_bull = newBull;
}

void 	CharacterFly::setAlive()
{
	_alive = false;
}

bool 	CharacterFly::getAlive()
{
	return this->_alive;
}

int	CharacterFly::getBcount()
{
	return this->_bCount;
}

t_bull* CharacterFly::getBull()
{
	return this->_bull;
}