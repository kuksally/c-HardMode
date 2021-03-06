#include <iostream>
#include <string>
#include <ctime>
#include <conio.h>

using namespace std;

int main()
{
    cout << "==========================================" << endl;
    cout << endl;
    cout << "              <용사는 절차적>             " << endl;
    cout << "        지금부터 모험을 시작합니다        " << endl;
    cout << "      힘내세요 용사님!!!!!!!!!!!!!!!!!    " << endl;
    cout << endl;
    cout << "==========================================" << endl;

    // 플레이어 이름 입력
    string playerName;
    cout << "용사님의 이름을 입력해 주세요 : ";
    cin >> playerName;

    // 유저 hp
    int hp = 0;
    // 몬스터
    int monster = 0;

    // 난이도 입력
    int gameMode;
    cout << "난이도를 선택해 주세요 : (1) 쉬움 (2) 보통 (3) 어려움 : ";
    cin >> gameMode;

    // 난이도 설정하기   
    if (gameMode == 1)
    {
        hp = 100, monster = 1;
        cout << "난이도는 쉬움 , 체력 = " << hp << " , 몬스터 수 = " << monster << " 마리 입니다." << endl;
    }
    if (gameMode == 2)
    {
        hp = 80, monster = 2;
        cout << "난이도는 보통 , 체력 = " << hp << " , 몬스터 수 = " << monster << " 마리 입니다." << endl;
    }
    if (gameMode == 3)
    {
        hp = 60, monster = 3;
        cout << "난이도는 보통 , 체력 = " << hp << " , 몬스터 수 = " << monster << " 마리 입니다." << endl;
    }
    cout << endl;

    // 가위바위보 값
    int ga = 0;
    int ba = 1;
    int bo = 2;


    while (1)
    {
        // 맵
        while (1)
        {
         
            srand(time(NULL));

            int playerPosX = 0, playerPosY = 0;
            int exitPosX = 0, exitPosY = 0;

            // 맵 데이터 저장
            char map[10][10];
            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    map[i][j] = '#';
                }
            }

            // 플레이어 정보 적용
            map[playerPosY][playerPosX] = 'O';


            // 탈출구 정보 적용
            exitPosX = rand() % 9 + 1;
            exitPosY = rand() % 9 + 1;

            map[exitPosY][exitPosX] = 'E';

            // 몬스터 처리 완료



            while (1)
            {

                system("cls");

                cout << "================================================================================" << endl;
                cout << endl;

                if (gameMode == 1)
                {
                    cout << "           난이도는 쉬움 , 체력 = " << hp << " , 몬스터 수 = " << monster << " 마리 입니다." << endl;
                }
                if (gameMode == 2)
                {
                    cout << "           난이도는 보통 , 체력 = " << hp << " , 몬스터 수 = " << monster << " 마리 입니다." << endl;
                }
                if (gameMode == 3)
                {
                    cout << "           난이도는 어려움 , 체력 = " << hp << " , 몬스터 수 = " << monster << " 마리 입니다." << endl;
                }
                cout << endl;
                cout << "================================================================================" << endl;
                cout << endl;
                cout << "                               던전을 탐험해보자!                           " << endl;
                cout << endl;

                // 맵 출력
                for (int i = 0; i < 10; i++)
                {
                    for (int j = 0; j < 10; j++)
                    {
                        cout << map[i][j];
                    }
                    cout << endl;
                }


                map[playerPosY][playerPosX] = '#';

                // 플레이어 키 입력

                int playerKey = _getch();

                switch (playerKey)
                {
                case 'w': case 'W':
                    playerPosY--;
                    break;
                case 's': case 'S':
                    playerPosY++;
                    break;
                case 'a': case 'A':
                    playerPosX--;
                    break;
                case 'd': case 'D':
                    playerPosX++;
                    break;
                }

                map[playerPosY][playerPosX] = 'O';

                if (playerPosX == exitPosX && playerPosY == exitPosY)
                {
                    cout << endl;
                    cout << "야생의 몬스터를 만났습니다!" << endl;
                    cout << endl;
                    cout << "전투를 준비해 주세요" << endl;
                    cout << endl;
                    break;
                }

            }
            break;
        }


        // 플레이어 입력값
        int inputNum;

        for (int i = 0; i < 1; i)
        {
            if (monster != 0 || hp != 0)
            {
                cout << "가위 = 0 / 바위 = 1 / 보 = 2 중에 선택해 주세욥 (숫자로 입력하기^^) = ";
                cin >> inputNum;
                cout << endl;
            }
            else
            {
                break;
            }


            // 플레이어 값 표시
            cout << endl;
            cout << "플레이어 값 : ";

            if (inputNum == 0)
            {
                cout << "플레이어는 가위를 냈습니다~!" << endl;
            }
            else if (inputNum == 1)
            {
                cout << "플레이어는 바위를 냈습니다~!" << endl;
            }
            else if (inputNum == 2)
            {
                cout << "플레이어는 보를 냈습니다~!" << endl;
            }
            else if (inputNum >= 3)
            {
                cout << "잘못된 값을 입력하셨습니다! 다시 입력해 주세용" << endl;
            }
            // 컴퓨터 가위바위보 랜덤값
            int com;
            srand(time(NULL));
            com = rand() % 3;

            // 몬스터 값 표시
            cout << "몬스터 값 : ";

            if (com == 0)
            {
                cout << "몬스터는 가위를 냈습니다~!" << endl;
            }
            else if (com == 1)
            {
                cout << "몬스터는 바위를 냈습니다~!" << endl;
            }
            else if (com == 2)
            {
                cout << "몬스터는 보를 냈습니다~!" << endl;
            }
            

            // 가위바위보결과
            if (inputNum == com) // draw
            {
                cout << endl;
                cout << "비겼습니다~ 다시 한 번 입력해 주세요!" << endl;

            }
            cout << endl;

            if ((inputNum - com == -1) || (inputNum - com == 2)) // lose
            {
                cout << endl;
                cout << "졌습니다ㅜㅜ" << endl;
                hp = hp - 10;
                cout << endl;
                cout << "체력을 10 잃었어요ㅠ^ㅠ " << "현재 남은 체력은 " << hp << "입니다." << endl;
                cout << endl;


                if (hp == 0)
                {
                    i++;
                }

            }
            cout << endl;


            if ((inputNum - com == -2) || (inputNum - com == 1)) // win
            {
                // 골드 랜덤으로 획득
                int gold;
                gold = rand() % 10;
                cout << "이겼습니다! 현재 남은 체력은 " << hp << " 이며, " << gold << "Gold를 획득했습니다." << endl;
                monster = monster - 1;
                cout << endl;
                cout << "남은 몬스터 수는 " << monster << "마리 입니다!" << endl;
                cout << endl;



                // break;
                int store = 0;
                // 상점
                if (monster != 0)
                {
                    cout << "몬스터를 처리해서 물약 상점에 갈 수 있게 되었는데 가볼래요?" << endl;
                    cout << endl;
                    cout << "(1) 당연하지, 바로 가보자! (2) 관심없어" << endl;
                    cin >> store;
                    cout << endl;

                    if (store == 1)
                    {
                        cout << "물약 상점에 오신 것을 환영합니다 " << playerName << " 용사님!" << endl;
                        cout << "어떤 종류의 물약을 찾고 계신가요?!" << endl;
                        cout << "보유 gold : " << gold << endl;
                        cout << "(1) 파워에이드 (용사님의 체력을 순식간에 모두 회복시켜줘요) : 50 gold" << endl;
                        cout << "(2) 포카리스웨트 (용사님의 체력을 35 회복시켜줘요)          : 40 gold" << endl;
                        cout << "(3) 게토레이 (용사님의 체력을 25 회복시켜줘요)              : 30 gold" << endl;
                        cout << "(4) 콜라 (용사님의 체력을 15 회복시켜줘요)                  : 20 gold" << endl;
                        cout << "(5) 마음이 바뀌었어 안살래" << endl;

                        cout << endl;

                        int drink = 0;

                        cout << "물건을 고르셨나요? : " << endl;
                        cout << endl;
                        cout << "응! 나는 이거면 돼 : ";
                        cin >> drink;
                        cout << endl;


                        if (drink == 1)
                        {
                            hp = 100;
                            gold = gold - 50;
                            cout << "체력이 모두 회복되었습니다!" << endl;
                            cout << "현재 체력은 " << hp << "이고, 잔여 gold는 " << gold << " gold 입니다." << endl;
                            cout << "체력을 회복했으니 던전으로 돌아가 볼까요?!" << endl;
                            cout << endl;
                        }
                        if (drink == 2)
                        {
                            hp = hp + 35;
                            gold = gold - 40;
                            cout << "체력이 35 회복되었습니다!" << endl;
                            cout << "현재 체력은 " << hp << "이고, 잔여 gold는 " << gold << " gold 입니다." << endl;
                            cout << "체력을 회복했으니 던전으로 돌아가 볼까요?!" << endl;
                            cout << endl;
                        }
                        if (drink == 3)
                        {
                            hp = hp + 25;
                            gold = gold - 30;
                            cout << "체력이 25 회복되었습니다!" << endl;
                            cout << "현재 체력은 " << hp << "이고, 잔여 gold는 " << gold << " gold 입니다." << endl;
                            cout << "체력을 회복했으니 던전으로 돌아가 볼까요?!" << endl;
                            cout << endl;
                        }
                        if (drink == 4)
                        {
                            hp = hp + 15;
                            gold = gold - 20;
                            cout << "체력이 모두 회복되었습니다!" << endl;
                            cout << "현재 체력은 " << hp << "이고, 잔여 gold는 " << gold << " gold 입니다." << endl;
                            cout << "체력을 회복했으니 던전으로 돌아가 볼까요?!" << endl;
                            cout << endl;
                        }
                        if (drink == 5)
                        {
                            cout << "아무것도 구매하지 않으신다구요?! 아쉽네요... 용사님 그럼 다음에 또 만나요." << endl;
                            cout << endl;
                        }
                        if ((gold - drink) < gold)
                        {
                            cout << "gold가 부족해요 용사님! 몬스터를 더 잡고 돌아오세요!" << endl;
                        }

                    }
                    else if (store == 2)
                    {
                        cout << "그럼 계속해서 모험을 하러 가요!" << endl;
                    }
                    cout << endl;
                    i++;
                }
                i++;


            }
        }
        if (monster == 0)
        {
            cout << "==========================================" << endl;
            cout << endl;
            cout << " 몬스터를 모두 처리하셨어요! 오늘의 모험 끝! " << endl;
            cout << endl;
            cout << "==========================================";
            break;
        }
        cout << endl;

        if (hp == 0)
        {
            cout << "용사님의 체력이 0이 되었습니다! 아쉽지만 다시 도전해주세용" << endl;
            break;
        }

        
    }

}
