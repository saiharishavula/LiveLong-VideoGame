
#include<iostream>
using namespace std;
    enum KEYS{UP, DOWN, LEFT, RIGHT, SPACE, ESCAPE, ENTER,FINAL};
    bool keys[7] = {false, false, false, false, false, false, false};
    bool random_query_house1[4];
    bool random_query_house2[4];
    bool random_query_house3[4];
    bool random_query_house4[4];
    bool random_query_house5[4];




    enum STATE{START,SUBMENU, PLAYING, QUESTION, END, OPTIONS};

    const int maxLFrame = 9;
	int currLFrame = 0;
	int frameLCount = 0;
	int frameLDelay = 4;
	int frameLWidth = 35;
	int frameLHeight = 55;
	int menu_flag;

    const int maxUFrame = 8;
	int currUFrame = 0;
	int frameUCount = 0;
	int frameUDelay = 4;
	int frameUWidth = 35;
	int frameUHeight = 55;

	const int maxDFrame = 9;
	int currDFrame = 0;
	int frameDCount = 0;
	int frameDDelay = 4;
	int frameDWidth = 35;
	int frameDHeight = 55;

	int iWidth=35;
	int iHeight=55;

    int WIDTH=800;
    int HEIGHT=600;


    int moveSpeed=3;
    int flag=0;
    int state=0;
    bool redraw=false;
    bool notMoving=true;

    float gameTime = 0;
	int frames = 0;
	int gameFPS = 0;
	int FPS=60;

    bool done=false;
    int x=0;
    int y=285;
    int gtime=0;
    int gtime1=0;
    int gold=120;
    int gameState=START;
    int count1=0;

    int timeState=0;

    int box=0;

    int cAnswer=0;
    int gAnswer=0;
    bool takeAns=true;
    bool checkAns=false;
    bool corAns=false;
    bool reveal=false;
    bool drawQues=true;
    int qWait=0;
    int rWait=0;
    int fg=0;
    bool time_resume=true;
    bool decision_pending=false;
    int time_up=0;
    int pQues[5]={0};
    bool nextQues=false;
    int temp_size;
    int h_min=0;
    int h_sec=0;
    int temp=1;
    int bonus_question;
    int bonus_house;
    int house_1_question=1;
    int house_2_question=1;
    int house_3_question=1;
    int house_4_question=1;
    int house_5_question=1;
    int current_question=0;
    bool bonus=false;
    bool first_time=true;
    bool first_time_house1=true;
    bool first_time_house2=true;
    bool first_time_house3=true;
    bool first_time_house4=true;
    bool first_time_house5=true;

    int random_query;
    bool next_query=true;
    const char *High_score[]={
        "1.txt"
    };

    const char *files[][5]=
    {
        {"questions/file1.txt",
        "questions/file2.txt",
        "questions/file3.txt",
        "questions/file4.txt",
        "questions/file5.txt",
        },
        {
        "questions/file3.txt",
        "questions/file2.txt",
        "questions/file1.txt",
        "questions/file5.txt",
        "questions/file4.txt",
        },
        {
        "questions/file5.txt",
        "questions/file1.txt",
        "questions/file2.txt",
        "questions/file4.txt",
        "questions/file3.txt",
        }
    };
    int level=1;
    int door[]={0};//0 =closed 1=open
    bool cleared[6] = {false,false,false,false,false,false};

    int op = 0;
    int intChange = 0;


