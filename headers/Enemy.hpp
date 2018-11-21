/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoytenk <vvoytenk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 13:49:16 by vvoytenk          #+#    #+#             */
/*   Updated: 2018/10/07 13:49:18 by vvoytenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

#include "CharacterFly.hpp"

class Enemy : public CharacterFly
{
public:
	Enemy(void);
	Enemy(Enemy const &src);
	virtual ~Enemy(void);

	Enemy &operator=(Enemy const &src);

	void	random_pos(void);
	void	print_en(void);
	void	setItsalive();
	void	move_enemy(void);

private:
	int		_deley;
};

#endif
