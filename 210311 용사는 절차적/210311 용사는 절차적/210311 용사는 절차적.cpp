#include <iostream>
#include <conio.h>
#include <ctime>

using namespace std;

struct Hero
{
    string name = " ";
    int maxhp;
    int hp;
    int level = 1;
    int gold = 0;
    int exp;
    int x;
    int y;

};

struct BossMonster
{
    string name = " ";
    int maxhp;
    int hp;
    int dropgold;
    int dropexp;
    int x;
    int y;
    char icon;
    int dead = 0;//-1: 죽음 0: 살아있음
};

struct BossGroup
{
    int bossCnt = 0;
    BossMonster* bossMonsters;
};

struct Potion
{
    string potionName;
    int potionPrice;
    int potionHeal;
};

struct PotionShop
{
    int potionCnt = 4;
    int shop = 0;
    Potion* hpPotion = nullptr;
};

struct Tile
{
    int posX, posY;
    int type;
    char shape;
};

enum MAPSIZE { MAPSIZE_EASY = 10, MAPSIZE_NORMAL = 15, MAPSIZE_HARD = 20 };

enum TILETYPE { FOREST, SWAMP, EARTH };

enum RSP { ROCK, SISSORS, PAPER };

enum BOSSCNT { BOSSCNT_EASY = 3, BOSSCNT_NORMAL = 5, BOSSCNT_HARD = 7 };

enum BOSSMOVE { UPWORD, LEFTWORD, RIGHTWORD, DOWNWORD };

enum DIFFICULT { EASY = 1, NORMAL = 2, HARD = 3 };


string getName();

int getDifficulty();

int getMapSize();

void initHero(Hero& hero, int gameMode);

void initBoss(BossGroup& bossGroup, Hero& h_hero, int gameMode, Tile** map);

void initPotion(PotionShop& potionShop, Hero& hero);

void SetMap(Tile** map, int mapSize, Hero& hero, BossMonster& bossMonster);

void PrintMap(Tile** map, Hero& hero, BossGroup& bossGroup, int mapSize);

void HeroMove(Hero& hero, Tile** map, int mapSize);

void createBoss(BossGroup& bossGroup, Tile** map, int mapSize);




int main()
{
    Hero h_hero;
    BossMonster bossMonster;
    BossGroup bossGroup;
    Potion recoveryPotion;
    PotionShop potionShop;
    int mapSize = 0;
    TILETYPE tileType;
    RSP rsp;
    BOSSCNT bossCnt;
    BOSSMOVE bossMove;
    MAPSIZE size;
    //DIFFICULT gameMode;
    Tile** tile = new Tile * [mapSize];
    
    int gameMode = 1;
    
    int game = 0;

    h_hero.name = getName();

    gameMode = getDifficulty();
    mapSize = getMapSize();
    initHero(h_hero, gameMode);
    initBoss(bossGroup, h_hero, gameMode, tile);
    
    SetMap(tile, mapSize, h_hero, bossMonster);
    createBoss(bossGroup, tile, mapSize);
    
    // 맵
    while (1)
    {
        HeroMove(h_hero, tile, mapSize);
        system("cls");
        PrintMap(tile,h_hero, bossGroup, mapSize);
    }

    //return 0;
}

// 이름 입력
string getName()
{
    string userName;
    cout << "용사님의 이름을 입력해주세요 : ";
    cin >> userName;
    return userName;
}

// 난이도 입력
int getDifficulty()
{
    cout << "탐험 난이도를 입력해 주세요 ( 1 ~ 3 ) : ";
    int difficultyLevel;
    cin >> difficultyLevel;

    if (difficultyLevel == DIFFICULT::EASY)
    {
        cout << "난이도 쉬움을 선택하셨습니다." << endl;
    }

    else if (difficultyLevel == DIFFICULT::NORMAL)
    {
        cout << "난이도 보통을 선택하셨습니다." << endl;
    }

    else if (difficultyLevel == DIFFICULT::HARD)
    {
        cout << "난이도 어려움을 선택했습니다." << endl;
    }
    return difficultyLevel;

}

// 맵 사이즈
int getMapSize()
{
    if (DIFFICULT::EASY)
    {
        return MAPSIZE::MAPSIZE_EASY;
    }

    else if (DIFFICULT::NORMAL)
    {
        return MAPSIZE::MAPSIZE_NORMAL;
    }

    else if (DIFFICULT::HARD)
    {
        return MAPSIZE::MAPSIZE_HARD;
    }
}

// 맵 세팅
void SetMap(Tile** map, int mapSize, Hero& hero, BossMonster& bossMonster)
{
    for (int k = 0; k < mapSize; k++)
    {
        map[k] = new Tile[mapSize];
    }

    for (int j = 0; j < mapSize; j++)
    {
        for (int i = 0; i < mapSize; i++)
        {
            //맵 좌표
            map[j][i].posX = i;
            map[j][i].posY = j;
            //맵 타일을 랜덤으로 뽑아주는 함수
            int randNum = rand() % 3;
            map[j][i].type = randNum;// rand() % 3;

            switch (map[j][i].type)
            {
                //맵 타일의 종류
            case TILETYPE::FOREST:
                map[j][i].shape = 'F';
                break;
            case TILETYPE::SWAMP:
                map[j][i].shape = 'S';
                break;
            case TILETYPE::EARTH:
                map[j][i].shape = 'E';
                break;
            }
        }
    }
}
    /*map[hero.y][hero.x].shape = 'H';
}*/

// 맵 출력
void PrintMap(Tile** map,Hero& hero, BossGroup& bossGroup,int mapSize)
{
    for (int k = 0; k < bossGroup.bossCnt; k++)
        map[bossGroup.bossMonsters[k].x][bossGroup.bossMonsters[k].y].shape = bossGroup.bossMonsters[k].icon;
    for (int j = 0; j < mapSize; j++)
    {
        for (int i = 0; i < mapSize; i++)
        {
            if (i == hero.x && j == hero.y) 
            {
                cout << 'H';
            }
            else 
            {
                cout << map[j][i].shape;
                 
            }                 
            
        }
        cout << endl;
    }
}

// 용사 키 입력
void HeroMove(Hero& hero, Tile** map, int mapSize)
{
    //잔상 없애 주는 조건식
    /*if (map[hero.y][hero.x].type == TILETYPE::FOREST)
    {
        map[hero.y][hero.x].shape = 'F';
    }

    if (map[hero.y][hero.x].type == TILETYPE::SWAMP)
    {
        map[hero.y][hero.x].shape = 'S';
    }

    if (map[hero.y][hero.x].type == TILETYPE::EARTH)
    {
        map[hero.y][hero.x].shape = 'E';
    }*/

    int heroKey = _getch();

    switch (heroKey)
    {
    case 'w':case 'W':
        hero.y--;
        if (hero.y < 0)
        {
            hero.y++;
        }
        break;
    case 's':case 'S':
        hero.y++;
        if (hero.y > mapSize - 1)
        {
            hero.y--;
        }
        break;
    case 'a':case 'A':
        hero.x--;
        if (hero.x < 0)
        {
            hero.x++;
        }
        break;
    case 'd':case 'D':
        hero.x++;
        if (hero.x > mapSize - 1)
        {
            hero.x--;
        }
        break;
    }

    /*map[hero.y][hero.x].shape = 'H';*/
}

// 용사 정보
void initHero(Hero& hero, int gameMode)
{
    hero.maxhp = 100;
    if (gameMode == DIFFICULT::EASY)
    {
        hero.hp = 100;
        cout << "체력은 " << hero.hp << ", ";
    }
    else if (gameMode == DIFFICULT::NORMAL)
    {
        hero.hp = 80;
        cout << "체력은 " << hero.hp << ", ";
    }
    else if (gameMode == DIFFICULT::HARD)
    {
        hero.hp = 60;
        cout << "체력은 " << hero.hp << ", ";
    }
    hero.level = 1;
    hero.exp = 0;
    hero.gold = 0;
    hero.x = 0;
    hero.y = 0;
}

// 몬스터 정보
void initBoss(BossGroup& bossGroup, Hero& h_hero, int gameMode, Tile** map)
{
    //난이도에 따른 몬스터 수 설정
    if (gameMode == DIFFICULT::EASY)
    {   
        bossGroup.bossCnt = BOSSCNT::BOSSCNT_EASY;
        cout << "몬스터는 " << bossGroup.bossCnt << "마리 입니다." << endl;
    }
    else if (gameMode == DIFFICULT::NORMAL)
    {
        bossGroup.bossCnt = BOSSCNT::BOSSCNT_NORMAL;
        cout << "몬스터는 " << bossGroup.bossCnt << "마리 입니다." << endl;
    }
    else if (gameMode == DIFFICULT::HARD)
    {
        bossGroup.bossCnt = BOSSCNT::BOSSCNT_HARD;
        cout << "몬스터는 " << bossGroup.bossCnt << "마리 입니다." << endl;
    }

    bossGroup.bossMonsters = new BossMonster[bossGroup.bossCnt]; 
}

// 상점 정보
void initPotion(PotionShop& potionShop, Hero& hero)
{
    potionShop.hpPotion = new Potion[potionShop.potionCnt];

    potionShop.hpPotion[0].potionName = "파워에이드";
    potionShop.hpPotion[0].potionPrice = 70;
    potionShop.hpPotion[0].potionHeal = hero.hp = 100;

    potionShop.hpPotion[1].potionName = "게토레이";
    potionShop.hpPotion[1].potionPrice = 60;
    potionShop.hpPotion[1].potionHeal = hero.hp + 40;

    potionShop.hpPotion[2].potionName = "토레타";
    potionShop.hpPotion[2].potionPrice = 50;
    potionShop.hpPotion[2].potionHeal = hero.hp + 30;

    potionShop.hpPotion[3].potionName = "2%";
    potionShop.hpPotion[3].potionPrice = 40;
    potionShop.hpPotion[3].potionHeal = hero.hp + 20;
}

// 몬스터 위치 정보....??
void createBoss(BossGroup& bossGroup, Tile** map, int mapSize)
{
    
    for (int i = 0; i < bossGroup.bossCnt; i++)
    {
        
        bossGroup.bossMonsters[i].x = rand() % mapSize; 
        bossGroup.bossMonsters[i].y = rand() % mapSize;

        if (bossGroup.bossMonsters[i].x == 0 && bossGroup.bossMonsters[i].y == 0)
        {
            i--; 
            continue;
        }
    }


	for (int i = 0; i < bossGroup.bossCnt; i++)
	{
		if (map[bossGroup.bossMonsters[i].y][bossGroup.bossMonsters[i].x].type == TILETYPE::FOREST)
		{
			bossGroup.bossMonsters[i].name = "치코리타";
			bossGroup.bossMonsters[i].icon = 'C';
			bossGroup.bossMonsters[i].maxhp = 10;
			bossGroup.bossMonsters[i].hp = bossGroup.bossMonsters->maxhp;
			bossGroup.bossMonsters[i].dropgold = rand() % 9 + 1;
			bossGroup.bossMonsters[i].dropexp = rand() % 9 + 1;
		}

		else if (map[bossGroup.bossMonsters[i].y][bossGroup.bossMonsters[i].x].type == TILETYPE::SWAMP)
		{
			bossGroup.bossMonsters[i].name = "물짱이";
			bossGroup.bossMonsters[i].icon = 'W';
			bossGroup.bossMonsters[i].maxhp = 20;
			bossGroup.bossMonsters[i].hp = bossGroup.bossMonsters->maxhp;
			bossGroup.bossMonsters[i].dropgold = rand() % 20 + 1;
			bossGroup.bossMonsters[i].dropexp = rand() % 20 + 1;
		}

		else if (map[bossGroup.bossMonsters[i].y][bossGroup.bossMonsters[i].x].type == TILETYPE::EARTH)
		{
			bossGroup.bossMonsters[i].name = "꼬마돌";
			bossGroup.bossMonsters[i].icon = 'G';
			bossGroup.bossMonsters[i].maxhp = 30;
			bossGroup.bossMonsters[i].hp = bossGroup.bossMonsters->maxhp;
			bossGroup.bossMonsters[i].dropgold = rand() % 50 + 1;
			bossGroup.bossMonsters[i].dropexp = rand() % 50 + 1;
		}
	}
    
    
}