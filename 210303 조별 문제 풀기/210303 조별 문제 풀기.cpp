#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

int main()
{
    //// 1. 알고리즘의 정의중 뜻이 다른 하나는?

    //// 2. 변수(이름짓기 개념)
    //int i = 1;
    //float j = 1.0f;
    //char k = 'h';
    //string s = "hello";

    //cout << i << endl;
    //printf("%.1f\n", j);
    //cout << j << endl;
    //cout << k << endl;
    //cout << s << endl;

    //cout << endl;

    //// 3. 연산자
    //int firstNum;
    //int secondNum;
    //cout << "첫번째 숫자를 입력해 주세요 : ";
    //cin >> firstNum;
    //cout << "두번째 숫자를 입력해 주세요 : ";
    //cin >> secondNum;

    //cout << "더하기 : " << firstNum + secondNum << endl;
    //cout << "빼기   : " << firstNum - secondNum << endl;
    //cout << "곱하기 : " << firstNum * secondNum << endl;
    //cout << "나누기 : " << firstNum / secondNum << endl;
    //cout << "나머지 : " << firstNum % secondNum << endl;

    //cout << endl;

    //// 4. 조건문
    //int inputNum;
    //
    //cout << "홀수 짝수 판별기 : 숫자를 입력해 주세욥 : ";
    //cin >> inputNum;

    //if (inputNum % 2 == 0)
    //{
    //    cout << "입력하신 " << inputNum << "은 짝수입니다." << endl;
    //}
    //else
    //{
    //    cout << "입력하신 " << inputNum << "은 홀수입니다." << endl;
    //}

    //cout << endl;

    //// 5. 반복문

    //for (int i = 5; i < 10; i++)
    //{
    //    cout << i;
    //}
    //cout << endl;

    //for (int i = 4; i < 9; i++)
    //{
    //    cout << i;
    //}
    //cout << endl;

    //for (int i = 3; i < 8; i++)
    //{
    //    cout << i;
    //}
    //cout << endl;

    //for (int i = 2; i < 7; i++)
    //{
    //    cout << i;
    //}
    //cout << endl;

    //for (int i = 1; i < 6; i++)
    //{
    //    cout << i;
    //}
    //cout << endl;

    //cout << endl;
    //
    //// 6. 배열
    //int num[11] = {0,};

    //cout << "[누적 합]" << endl;

    //for (int i = 1; i < 11; i++)
    //{
    //   num[i] = (i + num[i-1]);
    //   cout << num[i] << " ";
    //}
    //cout << endl;

    //cout << endl;
    //
    // 7. 키입력

    //cout << "[알파벳 선택하기]" << endl;
    //cout << "W : 다음 선택, S : 이전 선택, Space : 출력" << endl;

    //char alpa = 'A';
    //cout <<"시작 알파벳: " << alpa << endl;

    //while (1)
    //{
    //    int user = _getch();
    //   // cout << (char)user;

    //    if (user == 87)
    //    {
    //        if ((char)(alpa + 1) > 'Z')
    //        {
    //            cout << "다시해라!" << endl;
    //        }
    //        else
    //        {
    //            cout << (char)(alpa + 1) << endl;
    //            alpa = alpa + 1;
    //        }
    //    }

    //    if (user == 83)
    //    {
    //        if ((char)(alpa - 1) < 'A')
    //        {
    //            cout << "다시하라고!!!!@" << endl;
    //        }
    //        else
    //        {
    //            cout << (char)(alpa - 1) << endl;
    //            alpa = alpa - 1;
    //        }
    //    }

    //    if (user == 32)
    //    {
    //        cout << "드디어 탈출!!!!!!" << endl;
    //        break;
    //        
    //    }

    //}

    //3가지 다른 키에 각각 피아노 건반 도,레,미를 하달
    //7번의 키입력을 받고 저장 : 미레도레미미미(비행기)
    //저장한 값(비행기)과 입력한 값(내가 입력한 비행기)이 같으면 “합격” 출력 후 종료
    //값이 일치하지 않으면 “다시해보세요” 출력 후 다시 7번 연주반복

    cout << "피아노 연주 예시" << endl;
    cout << "건반 도 설정 : a" << endl;
    cout << "건반 레 설정 : s" << endl;
    cout << "건반 미 설정 : d" << endl;

    cout << endl;
    cout << "연주해보세요!" << endl;

    int a[7] = { 100, 115, 97, 155, 100, 100, 100 };


    for (int a = 0; a < 8; a++)
    {
        char putKey = _getch();

        if (putKey == 97)
        {
            cout << "도" << endl;
        }

        if (putKey == 115)
        {
            cout << "레" << endl;
        }

        if (putKey == 100)
        {
            cout << "미" << endl;
        }
        cout << endl;



    }







}

