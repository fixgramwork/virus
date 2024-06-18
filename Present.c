#pragma warning(disable:4996)
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    //first레이블 때문에 레이블 앞에 만든 변수
    int message;
//만약 첫번째 창에서 NO를 눌렀을때 WARNINGS창에서 돌아오게 해주는 레이블
first:
        //첫번째 메시지 창
       message = MessageBox(NULL, TEXT("~아 생일 축하해~ \n 어? 근데 친구를 믿었네? 어쩔수 없지 너는 지금부터 게임을 해야해"), TEXT("생일 축하축하"), MB_YESNO | MB_ICONQUESTION);

       //첫번째 레이블 조건문
    if(message != IDNO) {
        //second레이블 때문에 레이블 앞에 만든 변수
        int secondmessage;
    second:
            secondmessage = MessageBox(NULL, TEXT("이제부터 게임을 시작할게"), TEXT("게임 시작 페이지"), MB_YESNO | MB_ICONQUESTION);
            //두번째 창에서 아니요를 눌렀을때 계속 2번째 창만 보여주는 코드
        while (secondmessage == IDNO) {
            goto second;
        }
        if (secondmessage == IDYES) {
            int thirdmessage = MessageBox(NULL, TEXT("지금부터 랜덤한 시간이 지날때 마다 글자가 1글자씩 나올거야 그 글자들을 다 기억하고 프로그램 마지막에 글자를 쳐서 맞추면 너에게 선물을 줄게\n연습 게임을 해볼까? \n 확인을 누르고 10초만 기다려봐 그럼 창이 뜰거야"), TEXT("게임 설명"), MB_OK);
						
            int fourmessage = MessageBox(NULL, TEXT("잘했어! 이제부터 게임 시작이야\n 확인을 누르면 시작이 될거야"), TEXT("연습게임"), MB_OK);
            int fivemessage = MessageBox(NULL, TEXT("너"), TEXT("1번째 글자"), MB_OK);
            int sixmessage = MessageBox(NULL, TEXT("의"), TEXT("2번째 글자"), MB_OK);
            int sevenmessage = MessageBox(NULL, TEXT("선"), TEXT("3번째 글자"), MB_OK);
            int elightmessage = MessageBox(NULL, TEXT("물"), TEXT("4번째 글자"), MB_OK);
            int ninemessage = MessageBox(NULL, TEXT("은"), TEXT("5번째 글자"), MB_OK);
            int tenmessage = MessageBox(NULL, TEXT("없"), TEXT("6번째 글자"), MB_OK);
            int elevemessage = MessageBox(NULL, TEXT("어"), TEXT("7번째 글자"), MB_OK);
            int twolevemessage = MessageBox(NULL, TEXT("이제 게임은 끝났어 이 프로그램은 확인버튼을 누르면 바로 꺼지고 자동으로 지워질거야\n이제 글자 확인 프로그램으로 너의 글자가 맞는지 확인해봐"), TEXT("게임 끝"), MB_OK);
        }
    }
    //첫번째 창에서 NO를 눌렀을때 WARNINGS창을 뜨게 해주는 조건문
    else if (message == IDNO) {
        int WARNINGS = MessageBox(NULL, TEXT("어? 프로그램을 종료 할려고? 안되지 돌아가"), TEXT("돌아가"), MB_OK | MB_ICONASTERISK);
            goto first;
    }

    //실행이 다끝나고 파일을 자체적으로 삭제시켜주는 코드
    char filename1[10] = "study.exe";//""는 파일 이름 넣기
    int r;

    r = unlink(filename1);
    if (r == 0) {
        printf(">> [unlink] %s 파일을 삭제하였습니다.\n", filename1);
    }
    else {
        printf(" >> [unlink] %s 파일을 삭제할수 없습니다.\n", filename1);
    }
    return 0;

}
