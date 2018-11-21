// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Bullets.hpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: yholub <yholub@student.unit.ua>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/07 13:27:21 by yholub            #+#    #+#             //
//   Updated: 2018/10/07 13:27:21 by yholub           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef BULlETS_HPP
# define BULlETS_HPP

class	Bullets{
 public:
  Bullets();
  Bullets(int y, int x);
  Bullets(const Bullets &sec);
  Bullets &operator=(Bullets const &src);
  bool	getStatus();
  int	getXpos();
  int	getYpos();
  void	setStatus();
  ~Bullets();
  void	flyForw();
 private:
  bool _death;
  int _xPos;
  int _yPos;
};

#endif