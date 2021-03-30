#include "Bullet.h"
#include <iostream>
using namespace std;
int Bullet::moveBullet(Map& map, vector<Bullet>* bulletArr) {
	if (checkCrash(map, this->coord)) {
		return -1;
	}
	if (checkTankCrash(map, this->coord)) {
		return -1;
	}
	if (checkBulletCrash(map, this->coord, bulletArr)) {
		if (this->hitCamp != -1) {
			for (int i = 0; i < (*bulletArr).size(); i++) {
				if ((*bulletArr)[i].over == 0 && (*bulletArr)[i].coord.X == this->hitCoord.X && (*bulletArr)[i].coord.Y == this->hitCoord.Y) {
					(*bulletArr)[i].over = 1;
					map.mapData[(*bulletArr)[i].coord.Y][(*bulletArr)[i].coord.X][2] = VACANCY;
					this->draw.drawTerrain((*bulletArr)[i].coord, map.mapData[(*bulletArr)[i].coord.Y][(*bulletArr)[i].coord.X][0]);
					this->draw.repairTank((*bulletArr)[i].coord, (*bulletArr)[i].crossColor, map.mapData[(*bulletArr)[i].coord.Y][(*bulletArr)[i].coord.X][1]);
					break;
				}
			}
		}
		return -1;
	}
	COORD checkCoord;
	switch (this->direction) {
	case DCT_TOP:
		checkCoord = { this->coord.X,this->coord.Y - 1 };
		if (checkCrash(map, checkCoord)) {
			return -1;
		}
		if (checkTankCrash(map, checkCoord)) {
			return -1;
		}
		if (checkBulletCrash(map, checkCoord, bulletArr)) {
			if (this->hitCamp != -1) {
				for (int i = 0; i < (*bulletArr).size(); i++) {
					if ((*bulletArr)[i].over == 0 && (*bulletArr)[i].coord.X == this->hitCoord.X && (*bulletArr)[i].coord.Y == this->hitCoord.Y) {
						(*bulletArr)[i].over = 1;
						map.mapData[(*bulletArr)[i].coord.Y][(*bulletArr)[i].coord.X][2] = VACANCY;
						this->draw.drawTerrain((*bulletArr)[i].coord, map.mapData[(*bulletArr)[i].coord.Y][(*bulletArr)[i].coord.X][0]);
						this->draw.repairTank((*bulletArr)[i].coord, (*bulletArr)[i].crossColor, map.mapData[(*bulletArr)[i].coord.Y][(*bulletArr)[i].coord.X][1]);
						break;
					}
				}
			}
			return -1;
		}
		this->coord.Y--;
		break;
	case DCT_DOWN:
		checkCoord = { this->coord.X,this->coord.Y + 1 };
		if (checkCrash(map, checkCoord)) {
			return -1;
		}
		if (checkTankCrash(map, checkCoord)) {
			return -1;
		}
		if (checkBulletCrash(map, checkCoord, bulletArr)) {
			if (this->hitCamp != -1) {
				for (int i = 0; i < (*bulletArr).size(); i++) {
					if ((*bulletArr)[i].over == 0 && (*bulletArr)[i].coord.X == this->hitCoord.X && (*bulletArr)[i].coord.Y == this->hitCoord.Y) {
						(*bulletArr)[i].over = 1;
						map.mapData[(*bulletArr)[i].coord.Y][(*bulletArr)[i].coord.X][2] = VACANCY;
						this->draw.drawTerrain((*bulletArr)[i].coord, map.mapData[(*bulletArr)[i].coord.Y][(*bulletArr)[i].coord.X][0]);
						this->draw.repairTank((*bulletArr)[i].coord, (*bulletArr)[i].crossColor, map.mapData[(*bulletArr)[i].coord.Y][(*bulletArr)[i].coord.X][1]);
						break;
					}
				}
			}
			return -1;
		}
		this->coord.Y++;
		break;
	case DCT_LEFT:
		checkCoord = { this->coord.X - 1,this->coord.Y };
		if (checkCrash(map, checkCoord)) {
			return -1;
		}
		if (checkTankCrash(map, checkCoord)) {
			return -1;
		}
		if (checkBulletCrash(map, checkCoord, bulletArr)) {
			if (this->hitCamp != -1) {
				for (int i = 0; i < (*bulletArr).size(); i++) {
					if ((*bulletArr)[i].over == 0 && (*bulletArr)[i].coord.X == this->hitCoord.X && (*bulletArr)[i].coord.Y == this->hitCoord.Y) {
						(*bulletArr)[i].over = 1;
						map.mapData[(*bulletArr)[i].coord.Y][(*bulletArr)[i].coord.X][2] = VACANCY;
						this->draw.drawTerrain((*bulletArr)[i].coord, map.mapData[(*bulletArr)[i].coord.Y][(*bulletArr)[i].coord.X][0]);
						this->draw.repairTank((*bulletArr)[i].coord, (*bulletArr)[i].crossColor, map.mapData[(*bulletArr)[i].coord.Y][(*bulletArr)[i].coord.X][1]);
						break;
					}
				}
			}
			return -1;
		}
		this->coord.X--;
		break;
	case DCT_RIGHT:
		checkCoord = { this->coord.X + 1,this->coord.Y };
		if (checkCrash(map, checkCoord)) {
			return -1;
		}
		if (checkTankCrash(map, checkCoord)) {
			return -1;
		}
		if (checkBulletCrash(map, checkCoord, bulletArr)) {
			if (this->hitCamp != -1) {
				for (int i = 0; i < (*bulletArr).size(); i++) {
					if ((*bulletArr)[i].over == 0 && (*bulletArr)[i].coord.X == this->hitCoord.X && (*bulletArr)[i].coord.Y == this->hitCoord.Y) {
						(*bulletArr)[i].over = 1;
						map.mapData[(*bulletArr)[i].coord.Y][(*bulletArr)[i].coord.X][2] = VACANCY;
						this->draw.drawTerrain((*bulletArr)[i].coord, map.mapData[(*bulletArr)[i].coord.Y][(*bulletArr)[i].coord.X][0]);
						this->draw.repairTank((*bulletArr)[i].coord, (*bulletArr)[i].crossColor, map.mapData[(*bulletArr)[i].coord.Y][(*bulletArr)[i].coord.X][1]);
						break;
					}
				}
			}
			return -1;
		}
		this->coord.X++;
		break;
	}
	map.mapData[this->coord.Y][this->coord.X][2] = this->beFromFire;
	drawBullet();

	return 0;
}

Bullet::Bullet(BaseTank& tank, Map& map, int atk) {
	this->direction = tank.direction;
	this->atk = atk;
	this->over = 0;
	this->hitCamp == -1;
	this->color = tank.color;
	switch (tank.camp) {
	case TANK_PLAY_P1:
		this->beFromFire = P1_TANK_BULLET;
		break;
	case TANK_PLAY_P2:
		this->beFromFire = P2_TANK_BULLET;
		break;
	case TANK_ENEMY:
		this->beFromFire = ENEMY_BULLET;
		break;
	}
	switch (tank.direction) {
	case DCT_TOP:
		this->coord = { tank.coord.X,tank.coord.Y - 2 };
		if (checkCrash(map, this->coord)) {
			break;
		}
		if (checkTankCrash(map, this->coord)) {
			break;
		}
		if (checkBulletCrash(map, this->coord)) {
			break;
		}
		map.mapData[this->coord.Y][this->coord.X][2] = this->beFromFire;
		drawBullet();
		break;
	case DCT_DOWN:
		this->coord = { tank.coord.X,tank.coord.Y + 2 };
		if (checkCrash(map, this->coord)) {
			break;
		}
		if (checkTankCrash(map, this->coord)) {
			break;
		}
		if (checkBulletCrash(map, this->coord)) {
			break;
		}
		map.mapData[this->coord.Y][this->coord.X][2] = this->beFromFire;
		drawBullet();
		break;
	case DCT_LEFT:
		this->coord = { tank.coord.X - 2,tank.coord.Y };
		if (checkCrash(map, this->coord)) {
			break;
		}
		if (checkTankCrash(map, this->coord)) {
			break;
		}
		if (checkBulletCrash(map, this->coord)) {
			break;
		}
		map.mapData[this->coord.Y][this->coord.X][2] = this->beFromFire;
		drawBullet();
		break;
	case DCT_RIGHT:
		this->coord = { tank.coord.X + 2,tank.coord.Y };
		if (checkCrash(map, this->coord)) {
			break;
		}
		if (checkTankCrash(map, this->coord)) {
			break;
		}
		if (checkBulletCrash(map, this->coord)) {
			break;
		}
		map.mapData[this->coord.Y][this->coord.X][2] = this->beFromFire;
		drawBullet();
		break;
	}
}

Bullet::Bullet(Boss& boss, COORD& coord, Map& map, int atk) {
	this->direction = boss.bulletDirection;
	this->atk = atk;
	this->over = 0;
	this->hitCamp == -1;
	this->color = boss.color;
	switch (boss.camp) {
	case TANK_PLAY_P1:
		this->beFromFire = P1_TANK_BULLET;
		break;
	case TANK_PLAY_P2:
		this->beFromFire = P2_TANK_BULLET;
		break;
	case TANK_ENEMY:
		this->beFromFire = ENEMY_BULLET;
		break;
	}
	switch (boss.direction) {
	case DCT_TOP:
		this->coord = coord;
		if (checkCrash(map, this->coord)) {
			break;
		}
		if (checkTankCrash(map, this->coord)) {
			break;
		}
		if (checkBulletCrash(map, this->coord)) {
			break;
		}
		map.mapData[this->coord.Y][this->coord.X][2] = this->beFromFire;
		drawBullet();
		break;
	case DCT_DOWN:
		this->coord = coord;
		if (checkCrash(map, this->coord)) {
			break;
		}
		if (checkTankCrash(map, this->coord)) {
			break;
		}
		if (checkBulletCrash(map, this->coord)) {
			break;
		}
		map.mapData[this->coord.Y][this->coord.X][2] = this->beFromFire;
		drawBullet();
		break;
	case DCT_LEFT:
		this->coord = coord;
		if (checkCrash(map, this->coord)) {
			break;
		}
		if (checkTankCrash(map, this->coord)) {
			break;
		}
		if (checkBulletCrash(map, this->coord)) {
			break;
		}
		map.mapData[this->coord.Y][this->coord.X][2] = this->beFromFire;
		drawBullet();
		break;
	case DCT_RIGHT:
		this->coord = coord;
		if (checkCrash(map, this->coord)) {
			break;
		}
		if (checkTankCrash(map, this->coord)) {
			break;
		}
		if (checkBulletCrash(map, this->coord)) {
			break;
		}
		map.mapData[this->coord.Y][this->coord.X][2] = this->beFromFire;
		drawBullet();
		break;
	}
}

int Bullet::checkCrash(Map& map, COORD& coord) {
	switch (map.mapData[coord.Y][coord.X][0]) {
	case VACANCY:
	case MAP_SOILWALL_DESTORY:
	case BASE_DESTORY:
		return 0;
	case MAP_IRONWALL:
		this->over = 1;
		return 1;
	case MAP_SOILWALL:
		map.mapData[coord.Y][coord.X][0] = MAP_SOILWALL_DESTORY;
		this->draw.drawTerrain(coord, MAP_SOILWALL_DESTORY);
		this->over = 1;
		return 1;
	case BASE:
		this->over = 0;
		for (int i = map.width - 6; i < map.width - 1; i++) {
			for (int j = map.length / 2 - 4; j < map.length / 2 + 3; j++) {
				if ((i <= map.width - 2 && i >= map.width - 5 && j == map.length / 2 - 1)
					|| (j == map.length / 2 && i == map.width - 5)
					|| (i == map.width - 3 && j >= map.length / 2 - 3 && j <= map.length / 2 + 1)) {
					map.mapData[i][j][0] = BASE_DESTORY;
					this->draw.writeChar({ (short)j,(short)i }, WHITE_COLOR, BASE_DESTORY_CONTENT);
				}
			}
		}
		return 1;


	}
	return 0;
}

void Bullet::drawBullet() {
	this->draw.writeChar(this->coord, this->color, BULLET_CONTENT);
}

int Bullet::checkTankCrash(Map& map, COORD& coord) {
	int value = map.mapData[coord.Y][coord.X][1];
	switch (value) {
	case P1_TANK_ELEMENT_HEAD:
	case P1_TANK_ELEMENT_BODY:
		if (this->beFromFire == P1_TANK_BULLET || this->beFromFire == P2_TANK_BULLET) {
			this->crossColor = COLOR_BLUE;
			return 1;
		}
		else {
			this->over = 1;
			hitTank = 1;
			hitCoord = coord;
			hitCamp = TANK_PLAY_P1;
			return 1;
		}
		break;
	case P2_TANK_ELEMENT_HEAD:
	case P2_TANK_ELEMENT_BODY:
		if (this->beFromFire == P1_TANK_BULLET || this->beFromFire == P2_TANK_BULLET) {
			this->crossColor = COLOR_CYAN;

			return 1;
		}
		else {
			this->over = 1;
			hitTank = 1;
			hitCoord = coord;
			hitCamp = TANK_PLAY_P2;
			return 1;
		}
		break;

	case ENEMYTANK_ELEMENT_HEAD:
	case ENEMYTANK_ELEMENT_BODY:
		if (this->beFromFire == ENEMY_BULLET) {
			this->crossColor = COLOR_PURPLE;
			return 1;
		}
		else {
			this->over = 1;
			hitTank = 1;
			hitCoord = coord;
			hitCamp = TANK_ENEMY;
			return 1;
		}
		break;
	}
	return 0;
}
int Bullet::checkBulletCrash(Map& map, COORD& coord, vector<Bullet>* bulletArr) {
	int value = map.mapData[coord.Y][coord.X][2];
	switch (map.mapData[coord.Y][coord.X][2]) {
	case P1_TANK_BULLET:
		this->hitCamp = P1_TANK_BULLET;
		this->hitCoord = coord;

		this->over = 1;
		return 1;
	case P2_TANK_BULLET:
		this->hitCamp = P2_TANK_BULLET;
		this->hitCoord = coord;
		this->over = 1;
		return 1;
	case ENEMYTANK_BULLET:
		this->hitCamp = ENEMYTANK_BULLET;
		this->hitCoord = coord;
		this->over = 1;
		return 1;
	default:
		return 0;
	}
}
int Bullet::checkBulletCrash(Map& map, COORD& coord) {
	int value = map.mapData[coord.Y][coord.X][2];
	switch (map.mapData[coord.Y][coord.X][2]) {
	case P1_TANK_BULLET:
		this->hitCamp = P1_TANK_BULLET;
		this->hitCoord = coord;

		this->over = 1;
		return 1;
	case P2_TANK_BULLET:
		this->hitCamp = P2_TANK_BULLET;
		this->hitCoord = coord;
		this->over = 1;
		return 1;
	case ENEMYTANK_BULLET:
		this->hitCamp = ENEMYTANK_BULLET;
		this->hitCoord = coord;
		this->over = 1;
		return 1;
	default:
		return 0;
	}
}
Bullet::Bullet() {
}

