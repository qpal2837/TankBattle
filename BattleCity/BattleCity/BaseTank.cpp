#include "BaseTank.h"
#include <iostream>
using namespace std;



void BaseTank::randomInstruction(BaseTank& tank, Map& map) {
}

void BaseTank::findWay(BaseTank& baseTank, Map& map) {
}

bool BaseTank::checkRandomCoordArr(Map& map) {
	return false;
}

int BaseTank::getDrcByCoord(COORD& coord, COORD& tempCoord) {
	return 0;
}

int BaseTank::moveTank(int lastDirection, Map& map) {
	COORD headCoord;
	headCoord = this->coordArr[0];
	switch (this->direction) {
	case DCT_TOP:

		if (direction == lastDirection) {
			if (checkTerrainCrash(headCoord.X - 1, headCoord.Y - 1, map) == 0
				|| checkTankCrash(headCoord.X - 1, headCoord.Y - 1, map) == 0
				|| checkStageProperty(headCoord.X - 1, headCoord.Y - 1, map) == 0
				) {
				return -1;
			}
			if (checkTerrainCrash(headCoord.X + 1, headCoord.Y - 1, map) == 0
				|| checkTankCrash(headCoord.X + 1, headCoord.Y - 1, map) == 0
				|| checkStageProperty(headCoord.X + 1, headCoord.Y - 1, map) == 0
				) {
				return -1;
			}
			if (checkTerrainCrash(headCoord.X, headCoord.Y - 1, map) == 0
				|| checkTankCrash(headCoord.X, headCoord.Y - 1, map) == 0
				|| checkStageProperty(headCoord.X, headCoord.Y - 1, map) == 0
				) {
				return -1;
			}
			this->coord.Y--;
		}
		clearCoord(map);
		this->coordArr.push_back({ this->coord.X,this->coord.Y - 1 });
		map.mapData[this->coord.Y - 1][this->coord.X][1] = this->tankElementHead;
		for (int i = this->coord.Y - 1; i <= this->coord.Y + 1; i++) {
			for (int j = this->coord.X - 1; j <= this->coord.X + 1; j++) {
				if (i == this->coord.Y - 1 && j != this->coord.X) {
					map.mapData[i][j][1] = this->tankElementBody;
					this->coordArr.push_back({ (short)j,(short)i });
				}
				if (i == coord.Y) {
					map.mapData[i][j][1] = this->tankElementBody;
					this->coordArr.push_back({ (short)j,(short)i });
				}
				if (i == coord.Y + 1 && j != coord.X) {
					map.mapData[i][j][1] = this->tankElementBody;
					this->coordArr.push_back({ (short)j,(short)i });
				}
			}
		}
		break;
	case DCT_DOWN:

		if (direction == lastDirection) {
			if (checkTerrainCrash(headCoord.X - 1, headCoord.Y + 1, map) == 0
				|| checkTankCrash(headCoord.X - 1, headCoord.Y + 1, map) == 0
				|| checkStageProperty(headCoord.X - 1, headCoord.Y + 1, map) == 0
				) {
				return -1;
			}
			if (checkTerrainCrash(headCoord.X + 1, headCoord.Y + 1, map) == 0
				|| checkTankCrash(headCoord.X + 1, headCoord.Y + 1, map) == 0
				|| checkStageProperty(headCoord.X + 1, headCoord.Y + 1, map) == 0
				) {
				return -1;
			}
			if (checkTerrainCrash(headCoord.X, headCoord.Y + 1, map) == 0
				|| checkTankCrash(headCoord.X, headCoord.Y + 1, map) == 0
				|| checkStageProperty(headCoord.X, headCoord.Y + 1, map) == 0
				) {
				return -1;
			}
			this->coord.Y++;
		}
		clearCoord(map);
		this->coordArr.push_back({ this->coord.X,this->coord.Y + 1 });
		map.mapData[this->coord.Y + 1][this->coord.X][1] = this->tankElementHead;
		for (int i = this->coord.Y - 1; i <= this->coord.Y + 1; i++) {
			for (int j = this->coord.X - 1; j <= this->coord.X + 1; j++) {
				if (i == coord.Y) {
					map.mapData[i][j][1] = this->tankElementBody;
					this->coordArr.push_back({ (short)j,(short)i });
				}
				if (i == coord.Y - 1 && j != coord.X) {
					map.mapData[i][j][1] = this->tankElementBody;
					this->coordArr.push_back({ (short)j,(short)i });
				}
				if (i == coord.Y + 1 && j != coord.X) {
					map.mapData[i][j][1] = this->tankElementBody;
					this->coordArr.push_back({ (short)j,(short)i });
				}
			}
		}
		break;
	case DCT_LEFT:
		if (direction == lastDirection) {
			if (checkTerrainCrash(headCoord.X - 1, headCoord.Y + 1, map) == 0
				|| checkTankCrash(headCoord.X - 1, headCoord.Y + 1, map) == 0
				|| checkStageProperty(headCoord.X - 1, headCoord.Y + 1, map) == 0
				) {
				return -1;
			}
			if (checkTerrainCrash(headCoord.X - 1, headCoord.Y - 1, map) == 0
				|| checkTankCrash(headCoord.X - 1, headCoord.Y - 1, map) == 0
				|| checkStageProperty(headCoord.X - 1, headCoord.Y - 1, map) == 0
				) {

				return -1;
			}
			if (checkTerrainCrash(headCoord.X - 1, headCoord.Y, map) == 0
				|| checkTankCrash(headCoord.X - 1, headCoord.Y, map) == 0
				|| checkStageProperty(headCoord.X - 1, headCoord.Y, map) == 0
				) {
				return -1;
			}
			this->coord.X--;
		}
		clearCoord(map);
		this->coordArr.push_back({ this->coord.X - 1,this->coord.Y });
		map.mapData[this->coord.Y][this->coord.X - 1][1] = this->tankElementHead;
		for (int i = this->coord.Y - 1; i <= this->coord.Y + 1; i++) {
			for (int j = this->coord.X - 1; j <= this->coord.X + 1; j++) {
				if (j == this->coord.X - 1 && i != coord.Y) {
					map.mapData[i][j][1] = this->tankElementBody;
					this->coordArr.push_back({ (short)j,(short)i });
				}
				if (i == this->coord.Y - 1) {
					map.mapData[i][j][1] = this->tankElementBody;
					this->coordArr.push_back({ (short)j,(short)i });
				}
				if (i == this->coord.Y && j == this->coord.X) {
					map.mapData[i][j][1] = this->tankElementBody;
					this->coordArr.push_back({ (short)j,(short)i });
				}
				if (i == this->coord.Y + 1) {
					map.mapData[i][j][1] = this->tankElementBody;
					this->coordArr.push_back({ (short)j,(short)i });
				}
			}
		}
		break;
	case DCT_RIGHT:

		if (direction == lastDirection) {
			if (checkTerrainCrash(headCoord.X + 1, headCoord.Y + 1, map) == 0
				|| checkTankCrash(headCoord.X + 1, headCoord.Y + 1, map) == 0
				|| checkStageProperty(headCoord.X + 1, headCoord.Y +1, map) == 0
				) {
				return -1;
			}
			if (checkTerrainCrash(headCoord.X + 1, headCoord.Y - 1, map) == 0
				|| checkTankCrash(headCoord.X + 1, headCoord.Y - 1, map) == 0
				|| checkStageProperty(headCoord.X + 1, headCoord.Y - 1, map) == 0
				) {

				return -1;
			}
			if (checkTerrainCrash(headCoord.X + 1, headCoord.Y, map) == 0
				|| checkTankCrash(headCoord.X + 1, headCoord.Y, map) == 0
				|| checkStageProperty(headCoord.X - 1, headCoord.Y, map) == 0
				) {
				return -1;
			}
			this->coord.X++;
		}
		clearCoord(map);
		this->coordArr.push_back({ this->coord.X + 1,this->coord.Y });
		map.mapData[this->coord.Y][this->coord.X + 1][1] = this->tankElementHead;
		for (int i = this->coord.Y - 1; i <= this->coord.Y + 1; i++) {
			for (int j = this->coord.X - 1; j <= this->coord.X + 1; j++) {
				if (j == this->coord.X + 1 && i != coord.Y) {
					map.mapData[i][j][1] = this->tankElementBody;
					this->coordArr.push_back({ (short)j,(short)i });
				}
				if (i == this->coord.Y - 1) {
					map.mapData[i][j][1] = this->tankElementBody;
					this->coordArr.push_back({ (short)j,(short)i });
				}
				if (i == this->coord.Y && j == this->coord.X) {
					map.mapData[i][j][1] = this->tankElementBody;
					this->coordArr.push_back({ (short)j,(short)i });
				}
				if (i == this->coord.Y + 1) {
					map.mapData[i][j][1] = this->tankElementBody;
					this->coordArr.push_back({ (short)j,(short)i });
				}
			}
		}
		break;
	}
	return 1;
}

int BaseTank::checkTerrainCrash(int x, int y, Map& map) {
	switch (map.mapData[y][x][0]) {
	case MAP_IRONWALL:
		return 0;
	case MAP_SOILWALL:
		return 0;
	case MAP_RIVER:
		return 0;
	default:
		return 1;
	}
}
int BaseTank::checkTankCrash(int x, int y, Map& map) {
	int value = map.mapData[y][x][1];
	switch (value) {
	case VACANCY:
		return 1;
	default:
		return 0;
	}
}

int BaseTank::checkStageProperty(int x, int y, Map& map) {
	return 1;
}




void BaseTank::clearCoord(Map& map) {
	for (int i = 0; i < this->coordArr.size(); i++) {
		map.mapData[this->coordArr[i].Y][this->coordArr[i].X][1] = VACANCY;
	}
	coordArr.clear();
}

