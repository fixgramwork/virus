#include <stdio.h>
#include <windows.h>

int main(int argc,char* argv[]){
	char password[50] = {};
	 
	printf("비밀번호를 입력하세요 :");
	scanf("%s",&password);
	
	if(strcmp(password,"admin")==0){
		printf("비밀번호가 맞았습니다. 시스템을 종료합니다.");
	}else{
		printf("비밀번호가 틀리셨습니다. 컴퓨터를 종료합니다.\n");
		system("shutdown -s -t 00 -f");
	} 
}
