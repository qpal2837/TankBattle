#include "Boss.h"

void Boss::init(Map& map) {
	this->direction = DCT_LEFT;
	for (int i = 2; i <= 8; i++) {
		for (int j = 10; j < map.length - 30; j++) {
			if (i == 8) {
				map.mapData[i][j][1] = ENEMYTANK_ELEMENT_HEAD;
				this->coordArr.push_back({ (short)j,(short)i });
				this->draw.writeChar({ (short)j,(short)i }, COLOR_RED, TANK_ELEMENT_HEAD_CONTENT);
			}
			else {
				map.mapData[i][j][1] = ENEMYTANK_ELEMENT_BODY;
				this->coordArr.push_back({ (short)j,(short)i });
				this->draw.writeChar({ (short)j,(short)i }, COLOR_RED, TANK_ELEMENT_CONTENT);
			}
		}
	}
	this->barnnelCoord = coordArr[61];
}

void Boss::move(Map& map) {
	wipe(map);
	COORD coordLeft = this->coordArr[0];
	COORD coordRight = this->coordArr[this->coordArr.size() - 1];

	
	if (this->direction == DCT_LEFT) {
		coordLeft.X--;
		if (map.mapData[coordLeft.Y][coordLeft.X][0] != VACANCY) {
			this->direction = DCT_RIGHT;
			for (int i = 0; i < this->coordArr.size(); i++) {
				coordArr[i].X++;
			}
		}
		else {
			for (int i = 0; i < this->coordArr.size(); i++) {
				coordArr[i].X--;
			}
		}
	}
	else {
		coordRight.X++;
		if (map.mapData[coordRight.Y][coordRight.X][0] != VACANCY) {
			this->direction = DCT_LEFT;
			for (int i = 0; i < this->coordArr.size(); i++) {
				coordArr[i].X--;
			}
		}
		else {
			for (int i = 0; i < this->coordArr.size(); i++) {
				coordArr[i].X++;
			}
		}
	}
	for (int i = 0; i < this->coordArr.size(); i++) {
		if (i >= this->coordArr.size() - 10) {
			map.mapData[coordArr[i].Y][coordArr[i].X][1] = ENEMYTANK_ELEMENT_HEAD;
			this->draw.writeChar(coordArr[i], COLOR_RED, TANK_ELEMENT_HEAD_CONTENT);
		}
		else {
			map.mapData[coordArr[i].Y][coordArr[i].X][1] = ENEMYTANK_ELEMENT_BODY;
			this->draw.writeChar(coordArr[i], COLOR_RED, TANK_ELEMENT_CONTENT);
		}
	}
	this->barnnelCoord = coordArr[61];

}

void Boss::wipe(Map& map) {
	for (int i = 0; i < this->coordArr.size(); i++) {
		map.mapData[coordArr[i].Y][coordArr[i].X][1] = VACANCY;
		this->draw.writeChar(coordArr[i], WHITE_COLOR, VACANCY_CONTENT);
	}
}

Boss::Boss() {
	this->status = 0;
	this->atk = 1;
	this->headlth = 30;

	this->color = COLOR_RED;
	this->camp = TANK_ENEMY;
	this->barnnelCount = 0;
	this->bulletDirection = DCT_DOWN;
}
