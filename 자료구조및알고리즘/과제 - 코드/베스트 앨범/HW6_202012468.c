/*제목 : 과제 6 베스트 앨범
 * 생성자 : 김현서 202012468
 * 생성 일자 : 2021-06-08*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 6262)	// 스택 크기 초과 경고 무시

struct MusicList {	// musiclist : 장르, play 횟수, index(고유번호)

	char genre[30];

	int play;

	int index;
};

struct Album {	// 베스트 앨범에 들어갈 곡 선정 전 앨범 리스트 : musiclist, 장르, 총 play 횟수, 수록곡 개수

	struct MusicList musiclist[100];

	char genre[30];

	int play_sum;

	int music_num;
};

int main() {

	char genres[10001] = { 0, };	// 조건 : genres와 plays의 길이는 같으며 이는 1 이상 10000 이하입니다.

	char plays[10001] = { 0, };	// 조건 : genres와 plays의 길이는 같으며 이는 1 이상 10000 이하입니다.

	int num = 0, cnt = 0;


	
	printf("Genres : ");

	fflush(stdin);	// stdin 비워주기

	fgets(genres, 10001, stdin);	// genres에 입력

	genres[strlen(genres) - 1] = '\0';	// \n 제거 위함


	
	printf("Plays : ");

	fflush(stdin);	// stdin 비워주기

	fgets(plays, 10001, stdin);

	plays[strlen(plays) - 1] = '\0';	// \n 제거 위함



	int GenLen = strlen(genres);
	
	int PlayLen = strlen(plays);


	struct MusicList list[10001] = { {{0},0,0} };	// 초기화

	for (int i = 0; i < GenLen; i++) {

		char temp_genres[30] = { 0 };

		int j = 0;


		
		if (genres[i] == 34) {	// "(큰따옴표) 아스키 코드 = 34

			i++;

			while (genres[i] != 34) {	// 닫는 큰 따옴표가 나오기 전까지

				list[cnt].genre[j] = genres[i];	// list의 genre에 genres 저장

				i++;

				j++;

			}

			cnt++;

		}

	}

	int COUNT = cnt;


	
	for (int i = 0; i < PlayLen; i++) {

		if (plays[i] >= 48 && plays[i] <= 57) {	// ASCII code 48 = 10진수 '0' ~ ASCII code 57 = 10진수 '9'

			while (plays[i] >= 48 && plays[i] <= 57) {	// ASCII code 48 = 10진수 '0' ~ ASCII code 57 = 10진수 '9'

				list[num].play = list[num].play * 10 + plays[i] - 48;	// 한 자리수씩 올라가기 때문에 (이전 수 *10), 48을 빼주는 이유는 아스키 코드에서 정수로 바꾸기 위함

				i++;

			}

			list[num].index = num;

			num++;

		}

	}

	int NUMBER = num;


	
	if (COUNT != NUMBER) {

		printf("genres와 plays의 개수가 다릅니다.");

		exit(-1);

	}


	struct Album album[100] = { {{{0},0,0}}, {0}, 0, 0 };	// genre 종류 100개 이하

	int count = 0;	// album에 들어있는 장르의 개수 0으로 초기화


	
	for (int k = 0; k < COUNT; k++) {

		int result = 1, n = 0, GenreLen = strlen(list[k].genre), N = 0;


		
		for (n = 0; n < count + 1; n++) {

			for (int i = 0; i < GenreLen; i++) {

				if (album[n].genre[i] != list[k].genre[i]) {

					break;	// 한 자라도 어긋나면 바로 

				}


				
				else if (album[n].genre[i] == list[k].genre[i]) {

					result = 0;

				}

				N = n;	// 모두 일치하는 경우 N = n

			}

		}


		
		if (result == 1) {	// 같은 genre가 없는 경우

			for (int i = 0; i < GenreLen; i++) {

				album[count].genre[i] = list[k].genre[i];	// album genre로 넣기

				album[count].musiclist[0].genre[i] = list[k].genre[i];	// music list 안의 genre로 넣기

			}

			album[count].play_sum = list[k].play;	// 같은 장르의 총 play 횟수

			album[count].musiclist[0].play = list[k].play;	// music list 안의 play 횟수로 넣기

			album[count].musiclist[0].index = list[k].index;	// music list 안의 index 번호

			album[count].music_num = 1;		// 같은 장르의 총 music 개수

			count++;	// album에 들어있는 장르의 개수

		}


		
		else if (result == 0) {	// 같은 genre가 있는 경우

			int temp_num = album[N].music_num;	// 같은 장르의 노래 개수

			for (int i = 0; i < GenreLen; i++)

				album[N].musiclist[temp_num].genre[i] = list[k].genre[i];	// 같은 장르의 music list에 k번째 곡 장르명 추가하기


			
			album[N].play_sum += list[k].play;	// 같은 장르의 총 play 횟수

			album[N].musiclist[temp_num].play = list[k].play;	// 같은 장르의 music list에 k번째 곡 play 횟수 추가하기

			album[N].musiclist[temp_num].index = list[k].index;	// 같은 장르의 music list에 k번째 곡 index 번호 추가하기

			album[N].music_num += 1;	// 같은 장르의 곡 수 1개 증가

		}

	}



	struct Album temp = { {{{0},0,0}} , { 0 }, 0, 0 };
	
	for (int j = 0; j < count + 1; j++) {	// 버블정렬로 plays_sum 기준으로 Album 장르별 내림차순 정렬

		for (int p = 0; p < count - j; p++) {

			if (album[p].play_sum < album[p + 1].play_sum) {	// p번째 장르의 총 play 횟수가 p+1번째 총 play 횟수보다 적다면 순서 바꾸기

				temp = album[p];

				album[p] = album[p + 1];

				album[p + 1] = temp;

			}

		}

	}


	
	struct MusicList temp_musiclist = { {0},0,0 };

	for (int j = 0; j < count + 1; j++) {

		for (int i = 0; i < album[j].music_num + 1; i++) {	// 버블정렬로 plays 기준으로 Album 내의 각 곡 인덱스별 내림차순 정렬

			for (int p = 0; p < album[j].music_num - i; p++) {

				if (album[j].musiclist[p].play < album[j].musiclist[p + 1].play) {	// j장르 내의 p번째 곡의 play 횟수가 p+1번째 곡의 play 횟수보다 적다면 두 곡 순서 바꾸기

					temp_musiclist = album[j].musiclist[p];

					album[j].musiclist[p] = album[j].musiclist[p + 1];

					album[j].musiclist[p + 1] = temp_musiclist;

				}


				
				if (album[j].musiclist[p].play == album[j].musiclist[p + 1].play) {	// j 장르 내의 두 곡 순서가 같다면 index가 작은 순으로 정렬하기

					if (album[j].musiclist[p].index > album[j].musiclist[p + 1].index) {

						temp_musiclist = album[j].musiclist[p];

						album[j].musiclist[p] = album[j].musiclist[p + 1];

						album[j].musiclist[p + 1] = temp_musiclist;

					}

				}

			}

		}

	}


	printf("[");

	for (int j = 0; j < count; j++) {

		if (album[j].music_num == 1)	// 한 장르 내의 곡이 1개일 때

			printf("%d,", album[j].musiclist[0].index);

		if (album[j].music_num >= 2) {	// 한 장르 내의 곡이 2개 이상일 때

			printf("%d,", album[j].musiclist[0].index);

			printf("%d,", album[j].musiclist[1].index);

		}

	}

	printf("\b]\n");	// \b는 마지막 반점 하나 지워주기 위함

	
	return 0;

}
