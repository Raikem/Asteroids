/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Ship.h"
#include "Asteroid.h"
#include "FrameTimer.h"
#include "Laser.h"
#include "Sound.h"

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	static constexpr int nAsteroids = 10;
	static constexpr int maxLaser = 20;
	int nLasers = 0;
	int score = 0;
	MainWindow& wnd;
	Graphics gfx;
	Ship ship;
	FrameTimer ft;
	FrameTimer spaceBarCooldown;
	Asteroid asteroids[nAsteroids];
	Laser lasers[maxLaser];
	std::random_device rd;
	std::mt19937 rng;
	bool isShipAcc = false;
	bool gameOver = true;
	Sound laserSound;
	Sound explosionSound;
	Sound gameoverSound;
	Sound coinSound;
	Sound music;
	std::wstring scoreString;
	/********************************/
	/*  User Variables              */
	/********************************/

};