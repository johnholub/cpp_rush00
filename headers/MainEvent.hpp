// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   MainEvent.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: yholub <yholub@student.unit.ua>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/07 09:02:20 by yholub            #+#    #+#             //
//   Updated: 2018/10/07 09:02:20 by yholub           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef MAIN_EVENT_HPP
# define MAIN_EVENT_HPP

#define MAX_X 200
#define MAX_Y 50
#define MIN_X 1
#define MIN_Y 1

#include <iostream>
#include <ncurses.h>
#include "CharacterFly.hpp"
#include "Enemy.hpp"


class	MainEvent
{
 public:
  MainEvent();
  MainEvent(const MainEvent &sec);
  MainEvent &operator=(MainEvent const &src);
  ~MainEvent();
  void PrintAlive(void);
  void setEnemy(void);
  Enemy	*getEnemys(void);
  void	incEnc();
  int	getinEnout();
 private:
  Enemy	_enemies[30];
  int	_enCount;
  int 	_inMap;
  int	_enMax;
};

#endif
