// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   CharacterFly.hpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: yholub <yholub@student.unit.ua>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/07 11:00:46 by yholub            #+#    #+#             //
//   Updated: 2018/10/07 11:00:47 by yholub           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef CHARACTER_FLY_HPP
# define CHARACTER_FLY_HPP

# include <iostream>
#include "Bullets.hpp"

typedef struct s_bull
{
  Bullets *b;
  s_bull	*next;
}				t_bull;

class	CharacterFly
{
 public:
  CharacterFly();
  CharacterFly(int y, int x);
  CharacterFly(const CharacterFly &sec);
  CharacterFly &operator=(CharacterFly const &src);
  ~CharacterFly();
  int	getHp();
  int	getPosX();
  int	getPosY();
  void	setPosX(int i);
  void	setPosY(int i);
  void	changePos(int key);
  void	setHp(int dmg);
  void 	newSoot(int y, int x);
  int	getBcount();
  t_bull* getBull();
  void	setBull(t_bull* newBull);
  void	cheackFirst();
  void	remBull();
  void	bulletFly();
  bool 	getAlive();
  void 	setAlive();
 protected:
  t_bull *_bull;
  int _bCount;
  int _xPos;
  int _yPos;
  int _hp;
  int _xMin;
  int _xMax;
  int _yMin;
  int _yMax;
  bool _alive;
};
#endif

