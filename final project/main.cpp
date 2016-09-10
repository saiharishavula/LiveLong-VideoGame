#include<allegro5/allegro.h>
#include<allegro5/allegro_primitives.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_font.h>
#include<allegro5/allegro_ttf.h>
#include"variables.h"
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<ctime>


using namespace std;
int Highlight(int x,int y,int level);
void initialisation(int level);
bool collision(int x,int y,int level);
void doorFunc(int box,int level);
void reset(int box,int level);
void qinitialisation(int level);
bool wayColl(int level);
void drawDoor(ALLEGRO_BITMAP *o, ALLEGRO_BITMAP *c,bool cleared[],int level);
void wayFunc(ALLEGRO_BITMAP *way1, ALLEGRO_BITMAP *way2,bool cleared[],int level);

int main()
{
    srand (time(NULL));
    bonus_question=rand()%1+1;
    bonus_house=rand()%1+1;
    ALLEGRO_DISPLAY *display=NULL;
    ALLEGRO_EVENT_QUEUE *event_queue=NULL;
    ALLEGRO_TIMER *myTimer=NULL;
   ALLEGRO_BITMAP *backGround1=NULL;
    ALLEGRO_BITMAP *backGround2=NULL;
    ALLEGRO_BITMAP *backGround3=NULL;
    ALLEGRO_BITMAP *proffl=NULL;
    ALLEGRO_BITMAP *proffu=NULL;
    ALLEGRO_BITMAP *proffd=NULL;
    ALLEGRO_BITMAP *start_bk=NULL;
    ALLEGRO_BITMAP *question_bk=NULL;
    ALLEGRO_BITMAP *end_bk=NULL;
    ALLEGRO_BITMAP *highlight=NULL;
    ALLEGRO_BITMAP *go=NULL;
    ALLEGRO_BITMAP *doorImageO=NULL;
    ALLEGRO_BITMAP *doorImageC=NULL;
    ALLEGRO_BITMAP *me=NULL;
    ALLEGRO_BITMAP *sub_menu=NULL;
    ALLEGRO_BITMAP *way1=NULL;
    ALLEGRO_BITMAP *way2=NULL;
    ALLEGRO_BITMAP *way3=NULL;
    ALLEGRO_FONT *font18=NULL;
    ALLEGRO_FONT *font32=NULL;
    ALLEGRO_FONT *font1=NULL;
    ALLEGRO_BITMAP *smiley1=NULL;
    ALLEGRO_BITMAP *smiley2=NULL;
    ALLEGRO_BITMAP *smiley3=NULL;
    ALLEGRO_BITMAP *smiley4=NULL;
    ALLEGRO_BITMAP *smiley5=NULL;
    ALLEGRO_BITMAP *wait_for_result=NULL;
    ALLEGRO_BITMAP *query_display=NULL;
    ALLEGRO_BITMAP *result_display=NULL;
    ALLEGRO_BITMAP *highscore=NULL;
    ALLEGRO_BITMAP *options=NULL;
    ALLEGRO_BITMAP *score_board_time=NULL;
    ALLEGRO_BITMAP *score_board_gold=NULL;
    ALLEGRO_BITMAP *gold_icon=NULL;
    ALLEGRO_BITMAP *bonus_pic=NULL;
    ALLEGRO_BITMAP *board=NULL;
    ALLEGRO_BITMAP *backGroundi=NULL;
    ALLEGRO_BITMAP *kLeft=NULL;
    ALLEGRO_BITMAP *kRight=NULL;
    ALLEGRO_BITMAP *Final=NULL;



    if(!al_init())
    {
        return -1;
    }

    display=al_create_display(WIDTH,HEIGHT);

    if(!display)
    {
        return -1;
    }

    al_init_primitives_addon();
    al_install_keyboard();
    al_init_image_addon();
    al_init_font_addon();
    al_init_ttf_addon();

    event_queue=al_create_event_queue();
    myTimer=al_create_timer(1.0/FPS);
    backGround1=al_load_bitmap("level1.bmp");
    backGround2=al_load_bitmap("level2.bmp");
    backGround3=al_load_bitmap("level3.bmp");
    proffl=al_load_bitmap("left.bmp");
    proffu=al_load_bitmap("up.bmp");
    proffd=al_load_bitmap("down.bmp");
    way1=al_load_bitmap("way_open.bmp");
    way2=al_load_bitmap("way_closed.bmp");
    way3=al_load_bitmap("way_mid1.bmp");
    start_bk=al_create_bitmap(800,600);
    question_bk=al_create_bitmap(800,600);
    end_bk=al_create_bitmap(800,600);
    highlight=al_load_bitmap("highlight.bmp");
    go=al_load_bitmap("gameover.bmp");
    me=al_load_bitmap("menu.bmp");
    sub_menu=al_load_bitmap("que2.bmp");
    doorImageC=al_load_bitmap("door_closed.bmp");
    doorImageO=al_load_bitmap("door_open.bmp");
    font18 = al_load_font("arial.ttf", 25, 0);
    font32 = al_load_font("arial.ttf", 36, 0);
    font1 = al_load_font("arial.ttf", 18, 0);
    smiley1=al_load_bitmap("s1.bmp");
    smiley2=al_load_bitmap("s2.bmp");
    smiley3=al_load_bitmap("s3.bmp");
    smiley4=al_load_bitmap("s4.bmp");
    smiley5=al_load_bitmap("s5.bmp");
    wait_for_result=al_load_bitmap("wait.bmp");
    query_display=al_load_bitmap("images.bmp");
    result_display=al_load_bitmap("images2.bmp");
    highscore=al_load_bitmap("highscore.bmp");
    options=al_load_bitmap("options.bmp");
    score_board_time=al_load_bitmap("score_board1.bmp");
    score_board_gold=al_load_bitmap("score_board2.bmp");
    gold_icon=al_load_bitmap("gold icon.bmp");
    bonus_pic=al_load_bitmap("bonus.bmp");
    backGroundi=al_load_bitmap("backgroundi.bmp");
    board=al_load_bitmap("board.bmp");
    kLeft=al_load_bitmap("leftk.bmp");
    kRight=al_load_bitmap("rightk.bmp");
    Final=al_load_bitmap("final.bmp");



    al_convert_mask_to_alpha(backGround3,al_map_rgb(255,0,255));
    al_convert_mask_to_alpha(proffl,al_map_rgb(255,0,255));
    al_convert_mask_to_alpha(doorImageO,al_map_rgb(255,0,255));
    al_convert_mask_to_alpha(proffu,al_map_rgb(255,0,255));
    al_convert_mask_to_alpha(proffd,al_map_rgb(255,0,255));
    al_convert_mask_to_alpha(highlight,al_map_rgb(255,255,255));
    al_convert_mask_to_alpha(way1,al_map_rgb(255,0,255));
    al_convert_mask_to_alpha(way2,al_map_rgb(255,0,255));
    al_convert_mask_to_alpha(way3,al_map_rgb(255,0,255));
    al_convert_mask_to_alpha(wait_for_result,al_map_rgb(0,0,0));
    al_convert_mask_to_alpha(highscore,al_map_rgb(0,0,0));

    al_register_event_source(event_queue,al_get_keyboard_event_source());
    al_register_event_source(event_queue,al_get_display_event_source(display));
    al_register_event_source(event_queue,al_get_timer_event_source(myTimer));

    al_start_timer(myTimer);
    al_draw_bitmap(me,0,0,0);
    al_flip_display();
    for(int i=0;i<4;i++)
    {
        random_query_house1[i]=true;
        random_query_house2[i]=true;
        random_query_house3[i]=true;
        random_query_house4[i]=true;
        random_query_house5[i]=true;
    }

    //cout<<random_query<<endl;

    while(!done)
    {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue,&ev);

        if(gameState==START)
        {
            al_draw_bitmap(me,0,0,0);
            al_flip_display();

            if(ev.type==ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                done=true;
            }
            else
            if(ev.type==ALLEGRO_EVENT_KEY_DOWN)
            {
                if(ev.keyboard.keycode==ALLEGRO_KEY_P)
                {
                    cout<<"change state"<<endl;
                    gameState=OPTIONS;
                    cout<<"change state2"<<endl;
                }
                 if(ev.keyboard.keycode==ALLEGRO_KEY_L)
                {
                    gameState=SUBMENU;
                    menu_flag=1;

                }
                 if(ev.keyboard.keycode==ALLEGRO_KEY_I)
                {
                  gameState=SUBMENU;
                    menu_flag=2;

                }
                 if(ev.keyboard.keycode==ALLEGRO_KEY_E)
                {

                    done=true;

                }
                 if(ev.keyboard.keycode==ALLEGRO_KEY_C)
                {
                  gameState=SUBMENU;
                    menu_flag=3;

                }
            }
        }
        else
        if(gameState==SUBMENU)
        {
           if(ev.type==ALLEGRO_EVENT_KEY_DOWN)
            {
                if(ev.keyboard.keycode==ALLEGRO_KEY_B)
                {

                    gameState=START;

                }
            }

            if(menu_flag == 2)
            {
                if(ev.type==ALLEGRO_EVENT_KEY_DOWN)
                {
                    if(ev.keyboard.keycode==ALLEGRO_KEY_LEFT)
                    {
                        if(intChange>0)
                        {
                            intChange--;
                        }
                        else
                            intChange = 4;
                    }

                    else
                    if(ev.keyboard.keycode==ALLEGRO_KEY_RIGHT)
                    {
                        if(intChange<4)
                        {
                            intChange++;
                        }
                        else
                            intChange=0;
                    }
                }
            }

        }
        else
        if(gameState==PLAYING)
        {
            qinitialisation(level);
            notMoving=true;

                if(ev.type==ALLEGRO_EVENT_DISPLAY_CLOSE)
                {
                    done=true;
                }
                else
                if(ev.type == ALLEGRO_EVENT_TIMER)
                {
                    redraw = true;
                    if(count1++%60==0)
                    {

                        gtime++;
                        gold--;

                        if(gtime==60)
                        {
                            gtime1++;
                            gtime=0;
                        }

                        if(gold<0)
                            gameState=END;
                    }

                    if(keys[UP])
                    {
                        notMoving=false;
                        state=1;
                        if(!collision(x,y,level))
                        {
                            y-=moveSpeed;
                            doorFunc(box,level);
                            if(x+iWidth>665&&y+iHeight>345&&y+iHeight<360)
                            {
                                y=360-iHeight;
                            }
                        }
                        else
                            reset(box,level);
                        flag=0;
                        if(++frameUCount >= frameUDelay)
                        {
                            if(++currUFrame >= maxUFrame)
                                currUFrame = 0;
                            frameUCount = 0;
                        }
                        if(y<=0)
                        {
                            y=0;
                        }
                    }
                    else
                    if(keys[DOWN])
                    {
                        notMoving=false;
                        state=2;
                        if(!collision(x,y,level))
                        {
                            y+=moveSpeed;
                            doorFunc(box,level);
                            if(x+iWidth>630&&x+iWidth<665&&y+iHeight>380)
                            {
                                y=380-iHeight;
                            }
                        }
                        else
                            reset(box,level);
                        flag=0;
                        if(++frameDCount >= frameDDelay)
                        {
                            if(++currDFrame >= maxDFrame)
                                currDFrame = 0;
                            frameDCount = 0;
                        }
                        if(y+55>=HEIGHT)
                        {
                            y=HEIGHT-55;
                        }
                    }
                    else
                    if(keys[LEFT])
                    {
                        notMoving=false;
                        state=3;
                        if(!collision(x,y,level))
                        {
                            x-=moveSpeed;
                            doorFunc(box,level);
                            //if(box==8)
                           // {
                            //    y-=1;
                            //}
                        }
                        else
                            reset(box,level);
                        flag=0;
                        if(++frameLCount >= frameLDelay)
                        {
                            if(++currLFrame >= maxLFrame)
                                currLFrame = 0;
                            frameLCount = 0;
                        }
                        if(x<=0)
                        {
                            x=0;
                        }
                    }
                    else
                    if(keys[RIGHT])
                    {
                    if(level==1&&x>680)
                    {
                        cout<<"changing level1"<<endl;
                        level=2;
                        cout<<x<<" "<<y<<endl;
                        initialisation(level);
                        cout<<x<<" "<<y<<endl;
                    }
                    else
                    if(level==2&&x>564 && y+iHeight<355 && y+iHeight>325)
                    {
                        cout<<"changing level2"<<endl;
                        level=3;
                        initialisation(level);
                    }
                        notMoving=false;
                        state=4;
                        if(!collision(x,y,level))
                        {
                           x+=moveSpeed;
                        doorFunc(box,level);
                        if(box==8&&level==1)
                        {
                            y+=1;
                        }
                        if(box==7&&level==2)
                        {
                            y+=1;
                        }
                        if(level==1&&x+iWidth>630&&x+iWidth<635&&y+iHeight>380)
                        {
                            x=630-iWidth;
                        }
                        }
                        else
                            reset(box,level);
                        flag=ALLEGRO_FLIP_HORIZONTAL;
                        if(++frameLCount >= frameLDelay)
                        {
                            if(++currLFrame >= maxLFrame)
                                currLFrame = 0;
                            frameLCount = 0;
                        }
                        if(x+35>WIDTH)
                        {
                            x=WIDTH-35;
                        }
                    }

                    //cout<<"x= "<<x<<" y= "<<y<<endl;
                    //cout<<Highlight(x,y,level)<<" "<<box<<endl;
                }
                else if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
                {
                    switch(ev.keyboard.keycode)
                    {
                        case ALLEGRO_KEY_ESCAPE:
                            keys[ESCAPE]=true;
                            gameState=END;
                            break;
                        case ALLEGRO_KEY_UP:
                            keys[UP] = true;
                            break;
                        case ALLEGRO_KEY_DOWN:
                            keys[DOWN] = true;
                            break;
                        case ALLEGRO_KEY_RIGHT:
                            keys[RIGHT] = true;
                            break;
                        case ALLEGRO_KEY_LEFT:
                            {
                                keys[LEFT] = true;
                                break;
                            }
                        case ALLEGRO_KEY_SPACE:
                            break;
                        /*case ALLEGRO_KEY_ENTER:
                            keys[ENTER] = true;
                            break;*/

                    }
                }
                else if(ev.type == ALLEGRO_EVENT_KEY_UP)
                {
                    switch(ev.keyboard.keycode)
                    {
                        case ALLEGRO_KEY_UP:
                            keys[UP] = false;
                            break;
                        case ALLEGRO_KEY_DOWN:
                            keys[DOWN] = false;
                            break;
                        case ALLEGRO_KEY_RIGHT:
                            keys[RIGHT] = false;
                            break;
                        case ALLEGRO_KEY_LEFT:
                            keys[LEFT] = false;
                            break;
                        case ALLEGRO_KEY_SPACE:
                            if(Highlight(x,y,level)!=0)
                            {
                                if(Highlight(x,y,level)==6)
                                {
                                    gameState = FINAL;
                                }
                                else
                                gameState=QUESTION;
                            }
                            break;
                        case ALLEGRO_KEY_ESCAPE:
                            keys[ESCAPE] = false;
                            break;
                    }
                }
        }
        else
        if(gameState==QUESTION)
        {
            if(count1++%60==0)
            {
                if(time_resume&&reveal==false)
                {
                  gtime++;
                  gold--;

                }
                if(gtime==60)
                {

                    gtime1++;
                    gtime=0;

                }
                if(gold<0)
                    gameState=END;
            }
            if(ev.type==ALLEGRO_EVENT_KEY_DOWN)
            {
                if(ev.keyboard.keycode==ALLEGRO_KEY_ESCAPE)
                {
                    gameState=PLAYING;
                }
            }
            if(ev.type==ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                done=true;
            }
            else
            if(takeAns)
            {
                cout<<"takeAns"<<endl;
                if(ev.type==ALLEGRO_EVENT_KEY_DOWN)
                {
                    switch(ev.keyboard.keycode)
                    {
                        case ALLEGRO_KEY_1:
                            gAnswer=1;
                            if(Highlight(x,y,level)==1)
                            house_1_question++;
                            else
                            if(Highlight(x,y,level)==2)
                            house_2_question++;
                            else
                            if(Highlight(x,y,level)==3)
                            house_3_question++;
                            else
                            if(Highlight(x,y,level)==4)
                            house_4_question++;
                            else
                            if(Highlight(x,y,level)==5)
                            house_5_question++;
                            break;
                        case ALLEGRO_KEY_2:
                            gAnswer=2;
                            if(Highlight(x,y,level)==1)
                            house_1_question++;
                            else
                            if(Highlight(x,y,level)==2)
                            house_2_question++;
                            else
                            if(Highlight(x,y,level)==3)
                            house_3_question++;
                            else
                            if(Highlight(x,y,level)==4)
                            house_4_question++;
                            else
                            if(Highlight(x,y,level)==5)
                            house_5_question++;
                            break;
                        case ALLEGRO_KEY_3:
                            gAnswer=3;
                            if(Highlight(x,y,level)==1)
                            house_1_question++;
                            else
                            if(Highlight(x,y,level)==2)
                            house_2_question++;
                            else
                            if(Highlight(x,y,level)==3)
                            house_3_question++;
                            else
                            if(Highlight(x,y,level)==4)
                            house_4_question++;
                            else
                            if(Highlight(x,y,level)==5)
                            house_5_question++;
                            break;
                        case ALLEGRO_KEY_4:
                            gAnswer=4;
                            if(Highlight(x,y,level)==1)
                            house_1_question++;
                            else
                            if(Highlight(x,y,level)==2)
                            house_2_question++;
                            else
                            if(Highlight(x,y,level)==3)
                            house_3_question++;
                            else
                            if(Highlight(x,y,level)==4)
                            house_4_question++;
                            else
                            if(Highlight(x,y,level)==5)
                            house_5_question++;
                            break;
                    }
                }


                if(ev.type==ALLEGRO_EVENT_KEY_UP)
                {
                    switch(ev.keyboard.keycode)
                    {
                        case ALLEGRO_KEY_1:
                            checkAns=true;
                            fg=1;
                            time_resume=false;
                            decision_pending=true;
                            takeAns=false;
                            break;
                        case ALLEGRO_KEY_2:
                            checkAns=true;
                            fg=2;
                            time_resume=false;
                            decision_pending=true;
                            takeAns=false;
                            break;
                        case ALLEGRO_KEY_3:
                            checkAns=true;
                            fg=3;
                            time_resume=false;
                            decision_pending=true;
                            takeAns=false;
                            break;
                        case ALLEGRO_KEY_4:
                            checkAns=true;
                            fg=4;
                            time_resume=false;
                            decision_pending=true;
                            takeAns=false;
                            break;
                    }

                }
            }

            if(checkAns)
            {
                if(gAnswer==cAnswer)
                {
                    corAns=true;
                    if(Highlight(x,y,level)==1)
                        cleared[1]=true;
                    if(Highlight(x,y,level)==2)
                        cleared[2]=true;
                    if(Highlight(x,y,level)==3)
                        cleared[3]=true;
                    if(Highlight(x,y,level)==4)
                        cleared[4]=true;
                    if(Highlight(x,y,level)==5)
                        cleared[5]=true;
                }
                else
                {
                    corAns=false;
                }
                if(first_time)
                {
                    if(rWait++>150)
                {
                    reveal =true;
                    nextQues=true;
                    time_resume=true;
                    decision_pending=false;
                    rWait=0;
                    first_time=false;
                }

                }
                else
                if(rWait++>280)
                {

                    reveal =true;
                    nextQues=true;
                    time_resume=true;
                    decision_pending=false;
                    rWait=0;
                }
               // reveal=true;
            }
        }
        else
        if(gameState==END)
        {
            if(ev.type==ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                done=true;
            }
            else
            if(ev.type==ALLEGRO_EVENT_KEY_DOWN)
            {
                if(ev.keyboard.keycode==ALLEGRO_KEY_C)
                {
                    initialisation(level);

                }
                else
                if(ev.keyboard.keycode==ALLEGRO_KEY_Q)
                {
                    done=true;
                }
            }

        }
        else
        if(gameState==OPTIONS)
        {
            if(ev.type==ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                done = true;
            }
            else
            if(ev.type==ALLEGRO_EVENT_KEY_DOWN)
            {
                if(ev.keyboard.keycode==ALLEGRO_KEY_1)
                {
                    op = 0;
                    gameState = PLAYING;
                }
                else
                if(ev.keyboard.keycode==ALLEGRO_KEY_2)
                {
                    op = 1;
                    gameState = PLAYING;
                }
                else
                if(ev.keyboard.keycode==ALLEGRO_KEY_3)
                {
                    op = 2;
                    gameState = PLAYING;
                }
                //gameState = PLAYING;
            }

        }
        else
        if(gameState==FINAL)
        {
            if(ev.type==ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                done = true;
            }
        }

        if(gameState==START)
        {
            //cout<<"start"<<endl;

        }
        else
        if(gameState==SUBMENU)
        {
            if(menu_flag==1)
            {
            al_draw_bitmap(sub_menu,0,0,0);
            al_flip_display();

            }
             if(menu_flag==2)
            {
            al_draw_bitmap(board,0,0,0);
            al_draw_scaled_bitmap(backGroundi, 0, 0, 800, 600, 85, 175, 400, 300, 0);
            al_draw_bitmap(kLeft,150,540,0);
            al_draw_text(font18,al_map_rgb(25,255,0), 200, 545, ALLEGRO_ALIGN_LEFT,"PREVIOUS");
            al_draw_bitmap(kRight,400,540,0);
            al_draw_text(font18,al_map_rgb(25,255,0), 450, 545, ALLEGRO_ALIGN_LEFT,"NEXT");
            if(intChange==0){
            al_draw_text(font18, al_map_rgb(225,255,255),370,100, ALLEGRO_ALIGN_CENTER,"These highlighted regions are the places where you");
            al_draw_text(font18, al_map_rgb(225,255,255),370,120, ALLEGRO_ALIGN_CENTER,"will be getting the questions to answer for");
            al_draw_text(font18, al_map_rgb(225,255,255),370,140, ALLEGRO_ALIGN_CENTER,"increasing your gold");
            }
            else if(intChange==1)
            {
            al_draw_text(font18, al_map_rgb(225,255,255),370,100, ALLEGRO_ALIGN_CENTER,"These highlighted regions are the places where you 1");
            al_draw_text(font18, al_map_rgb(225,255,255),370,120, ALLEGRO_ALIGN_CENTER,"will be getting the questions to answer for");
            al_draw_text(font18, al_map_rgb(225,255,255),370,140, ALLEGRO_ALIGN_CENTER,"increasing your gold");
            }
            else if(intChange==2)
            {
            al_draw_text(font18, al_map_rgb(225,255,255),370,100, ALLEGRO_ALIGN_CENTER,"These highlighted regions are the places where you 2");
            al_draw_text(font18, al_map_rgb(225,255,255),370,120, ALLEGRO_ALIGN_CENTER,"will be getting the questions to answer for");
            al_draw_text(font18, al_map_rgb(225,255,255),370,140, ALLEGRO_ALIGN_CENTER,"increasing your gold");
            }
            else if(intChange==3)
            {
            al_draw_text(font18, al_map_rgb(225,255,255),370,100, ALLEGRO_ALIGN_CENTER,"These highlighted regions are the places where you 3");
            al_draw_text(font18, al_map_rgb(225,255,255),370,120, ALLEGRO_ALIGN_CENTER,"will be getting the questions to answer for");
            al_draw_text(font18, al_map_rgb(225,255,255),370,140, ALLEGRO_ALIGN_CENTER,"increasing your gold");
            }
            else if(intChange==4)
            {
            al_draw_text(font18, al_map_rgb(225,255,255),370,100, ALLEGRO_ALIGN_CENTER,"These highlighted regions are the places where you 4");
            al_draw_text(font18, al_map_rgb(225,255,255),370,120, ALLEGRO_ALIGN_CENTER,"will be getting the questions to answer for");
            al_draw_text(font18, al_map_rgb(225,255,255),370,140, ALLEGRO_ALIGN_CENTER,"increasing your gold");
            }
            al_flip_display();

            al_flip_display();

            }
             if(menu_flag==3)
            {
            al_draw_bitmap(sub_menu,0,0,0);
            al_flip_display();

            }

        }
        else
        if(gameState==PLAYING)
        {

           // cout<<bonus_house<<" "<<bonus_question<<" "<<Highlight(x,y,level)<<" "<<current_question<<endl;
                if(Highlight(x,y,level)==1)
                    current_question=house_1_question;
                else
                if(Highlight(x,y,level)==2)
                    current_question=house_2_question;
                else
                if(Highlight(x,y,level)==3)
                    current_question=house_3_question;
                else
                if(Highlight(x,y,level)==4)
                    current_question=house_4_question;
                else
                if(Highlight(x,y,level)==5)
                    current_question=house_5_question;
            if(redraw && al_is_event_queue_empty(event_queue))
            {
                redraw = false;
                frames++;
                if(al_current_time() - gameTime >= 1)
                {
                    gameTime = al_current_time();
                    gameFPS = frames;
                    frames = 0;
                }

               if(level==1)
                {
                    al_draw_bitmap(backGround1,0,0,0);
                    al_draw_bitmap(score_board_time,725,13,0);
                    al_draw_bitmap(score_board_gold,3,13,0);
                }
                else
                if(level==2)
                {
                    al_draw_bitmap(backGround2,0,0,0);
                    al_draw_bitmap(score_board_time,725,13,0);
                    al_draw_bitmap(score_board_gold,3,13,0);
                }
                else
                if(level==3){
                    al_draw_bitmap(backGround3,0,0,0);
                    al_draw_bitmap(score_board_time,725,13,0);
                    al_draw_bitmap(score_board_gold,3,13,0);            //change these
                }
            if(gold<=20)
            {
                if(time_up++>25)
                {
                    //al_draw_textf(font32, al_map_rgb(225, 255, 255),130,137, 0, "%i",gold);
                    al_draw_textf(font18, al_map_rgb(225, 255, 255),17,55, 0, "%i",gold);
                    if(time_up++>50)
                    time_up=0;
                }

            }
            else
               al_draw_textf(font18, al_map_rgb(225, 255, 255),17,55, 0, "%i",gold);
                al_draw_textf(font18, al_map_rgb(255, 255, 255), 735,18, 0, "Mins");
                al_draw_textf(font18, al_map_rgb(225, 255, 255), 745,48, 0, "%i", gtime1);
                al_draw_textf(font18, al_map_rgb(225, 255, 255), 735,78, 0, "Secs");
                al_draw_textf(font18, al_map_rgb(225, 255, 255), 745,111, 0, "%i", gtime);
                if(Highlight(x,y,level)==1)
                {
                    if(first_time_house1)
                    {
                        random_query=rand()%4;
                        first_time_house1=false;
                    }
                   if(level==1)
                        al_draw_bitmap(highlight,130,110,0);
                    else
                    if(level==2)
                        al_draw_bitmap(highlight,0,285,0);
                    else
                    if(level==3){
                         al_draw_bitmap(highlight,130,110,0);
                    }
                }
                else
                if(Highlight(x,y,level)==2)
                {
                     if(first_time_house2)
                    {
                        random_query=rand()%4;
                        first_time_house2=false;
                    }
                    if(level==1)
                        al_draw_bitmap(highlight,355,130,0);
                    else
                    if(level==2)
                        al_draw_bitmap(highlight,165,90,0);
                    else
                        if(level==3)
                        al_draw_bitmap(highlight,355,130,0);
                }
                else
                if(Highlight(x,y,level)==3)
                {
                     if(first_time_house3)
                    {
                        random_query=rand()%4;
                        first_time_house3=false;
                    }
                    if(level==1)
                        al_draw_bitmap(highlight,545,180,0);
                    else
                    if(level==2)
                        al_draw_bitmap(highlight,480,140,0);
                    else
                    if(level==3)
                        al_draw_bitmap(highlight,545,180,0);
                }
                else
                if(Highlight(x,y,level)==5)
                {
                     if(first_time_house5)
                    {
                        random_query=rand()%4;
                        first_time_house5=false;
                    }
                    if(level==1)
                        al_draw_bitmap(highlight,430,440,0);
                    else
                    if(level==2)
                        al_draw_bitmap(highlight,670,500,0);
                    else
                    if(level==3)
                        al_draw_bitmap(highlight,430,440,0);

                }
                else
                if(Highlight(x,y,level)==4)
                {
                     if(first_time_house4)
                    {
                        random_query=rand()%4;
                        first_time_house4=false;
                    }
                    if(level==1)
                        al_draw_bitmap(highlight,130,440,0);
                    else
                    if(level==2)
                        al_draw_bitmap(highlight,340,500,0);
                    else
                    if(level==3)
                        al_draw_bitmap(highlight,130,440,0);
                }

                else
                if(Highlight(x,y,level)==6)
                {
                    /* if(first_time_house6)
                    {
                        random_query=rand()%4;
                        first_time_house4=false;
                    }*/
                    al_draw_bitmap(highlight,715,330,0);
                }

                drawDoor(doorImageO,doorImageC,cleared,level);
                wayFunc(way1,way2,cleared,level);

                if(notMoving)
                {
                    if(state==3||state==4)
                    {
                        al_draw_bitmap_region(proffl, 0, 0, 35, 55, x, y, flag);
                    }
                    else
                    if(state==1)
                    {
                        al_draw_bitmap_region(proffu, 0, 0, 35, 55, x, y, flag);
                    }
                    else
                    if(state==0||state==2)
                    {
                        al_draw_bitmap_region(proffd, 0, 0, 35, 55, x, y, flag);
                    }
                }
                else
                {
                    if(state==3||state==4)
                    {
                        al_draw_bitmap_region(proffl, currLFrame * 35, 0, 35, 55, x, y, flag);
                    }
                    else
                    if(state==1)
                    {
                        al_draw_bitmap_region(proffu, currUFrame * 35, 0, 35, 55, x, y, flag);
                    }
                    else
                    if(state==2)
                    {
                        al_draw_bitmap_region(proffd, currDFrame * 35, 0, 35, 55, x, y, flag);
                    }
                }
            }
         /*   if(cleared[5])
            {    if(level==1)
                {
                    al_draw_bitmap(way1,630,289,0);
                }
                else
                if(level==2)
                {
                    al_draw_bitmap(way1,630,289,0);     //chenge
                }
                else
                    if(level==3)
                {
                    al_draw_bitmap(way1,630,289,0);

                }
            }*/
             if(cleared[5])
            {
                if(level==1)
                {
                    al_draw_bitmap(way3,630,289,0);
                }
                else
                if(level==2)
                {
                   al_draw_bitmap(way3,630,289,0);
                }
            }

           // if(cleared[5])
              //  al_draw_bitmap(way3,630,289,0);


             al_flip_display();
        }
        else
        if(gameState==QUESTION)
        {
            al_draw_bitmap(query_display,0,0,0);
             if(decision_pending)
            {
                al_draw_bitmap(smiley4,327,100,0);
                if(fg==1)
                al_draw_bitmap(wait_for_result,8,426,0);
                else
                if(fg==2)
                al_draw_bitmap(wait_for_result,409,426,0);
                else
                if(fg==3)
                al_draw_bitmap(wait_for_result,8,488,0);
                else
                if(fg==4)
                al_draw_bitmap(wait_for_result,409,488,0);
                al_draw_textf(font18, al_map_rgb(225, 255, 255),372,16, 0, "%i",gold);
                al_draw_textf(font32, al_map_rgb(225, 255, 255),101,132, 0, "Decision");
                al_draw_textf(font32, al_map_rgb(225, 255, 255), 571,130, 0, "Pending");

            }
            if(decision_pending==false)
            {
            al_draw_bitmap(smiley1,335,100,0);
            al_draw_bitmap(gold_icon,145,90,0);
            if(gold<=20)
            {
                if(time_up++>25)
                {
                    al_draw_textf(font32, al_map_rgb(225, 255, 255),135,137, 0, "%i",gold);
                    if(time_up++>50)
                    time_up=0;
                }

            }
            else
            al_draw_textf(font32, al_map_rgb(225, 255, 255),135,137, 0, "%i",gold);
            al_draw_textf(font18, al_map_rgb(255, 255, 255), 599,91, 0, "Mins");
            al_draw_textf(font18, al_map_rgb(225, 255, 255), 608,125, 0, "%i", gtime1);
            al_draw_textf(font18, al_map_rgb(225, 255, 255), 599,153, 0, "Secs");
            al_draw_textf(font18, al_map_rgb(225, 255, 255), 608,185, 0, "%i", gtime);
            }

            ifstream qfile(files[op][Highlight(x,y,level)-1]);
            string str1;
            if(drawQues)
            {
                int qx=44;
                int qy=327;

                    int temporary=0;
                    if(Highlight(x,y,level)==1)
               {
                   if(!random_query_house1[random_query])
                   {
                       for(int i=0;i<4;i++)
                       {
                           if(random_query_house1[i])
                           {
                               random_query=i;
                               //random_query_house1[random_query]=false;
                               temporary=1;
                               break;
                           }
                       }
                       if(temporary==0)
                        random_query=4;

                   }
               }
                    if(Highlight(x,y,level)==2)
               {
                   if(!random_query_house2[random_query])
                   {
                       for(int i=0;i<4;i++)
                       {
                           if(random_query_house2[i])
                           {
                               random_query=i;
                               //random_query_house1[random_query]=false;
                               temporary=1;
                               break;
                           }
                       }
                       if(temporary==0)
                        random_query=4;

                   }
               }

                      if(Highlight(x,y,level)==3)
               {
                   if(!random_query_house3[random_query])
                   {
                       for(int i=0;i<4;i++)
                       {
                           if(random_query_house3[i])
                           {
                               random_query=i;
                               //random_query_house1[random_query]=false;
                               temporary=1;
                               break;
                           }
                       }
                       if(temporary==0)
                        random_query=4;

                   }
               }
                 if(Highlight(x,y,level)==4)
               {
                   if(!random_query_house4[random_query])
                   {
                       for(int i=0;i<4;i++)
                       {
                           if(random_query_house4[i])
                           {
                               random_query=i;
                               //random_query_house1[random_query]=false;
                               temporary=1;
                               break;
                           }
                       }
                       if(temporary==0)
                        random_query=4;

                   }
               }
                    if(Highlight(x,y,level)==5)
               {
                   if(!random_query_house5[random_query])
                   {
                       for(int i=0;i<4;i++)
                       {
                           if(random_query_house5[i])
                           {
                               random_query=i;
                               //random_query_house1[random_query]=false;
                               temporary=1;
                               break;
                           }
                       }
                       if(temporary==0)
                        random_query=4;

                   }
               }

               while(1)
                {
                   getline(qfile, str1);
                   if(str1[0]-'0'==random_query)
                   {
                     break;
                   }
                   else
                   {
                    for(int i=0;i<6;i++)
                    getline(qfile,str1);
                   }

                }
              /*  for(int i=0;i<=pQues[Highlight(x,y,level)-1];i++)
                {
                    getline(qfile,str1);
                }*/
                for(int i=0;i<5;i++)
                {
                    getline(qfile, str1);
                    if(str1!="$")
                    {
                        al_draw_text(font18, al_map_rgb(0,0,0),qx,qy, ALLEGRO_ALIGN_LEFT,str1.c_str());
                    }
                    else
                        break;
                    if(i==1)
                    qy+=80;
                    if(i==3)
                    qy+=23;
                    if(i==0)
                    qy+=25;
                    if(i==2)
                    qy+=43;
                    if(i==4)
                    qy+=32;
                }
                getline(qfile,str1);
                cAnswer=str1[0]-'0';
            }

            if(str1=="$")
            {
                al_draw_bitmap(result_display,0,0,0);
                al_draw_bitmap(smiley5,320,95,0);

                al_draw_text(font32, al_map_rgb(225,255,255),WIDTH/2,HEIGHT/2, ALLEGRO_ALIGN_CENTER,"No More Queries !!!");
                if(++qWait>90)
                {
                    gameState=PLAYING;
                    qWait=0;
                    }
            }


            if(reveal)
            {


                if(corAns)
                {
                  al_draw_bitmap(result_display,0,0,0);
                  al_draw_textf(font18, al_map_rgb(225, 255, 255),372,16, 0, "%i",gold);
                  if(Highlight(x,y,level)==bonus_house&&bonus_question==current_question)
                  {
                     al_draw_bitmap(bonus_pic,259,85,0);
                     al_draw_textf(font32, al_map_rgb(225, 255, 255),101,132, 0, "Lucky");
                     al_draw_textf(font32, al_map_rgb(225, 255, 255), 573,130, 0, "Boy");
                     bonus=true;
                     al_draw_text(font32, al_map_rgb(225, 255, 255), WIDTH/2, 350, ALLEGRO_ALIGN_CENTER, "Its Correct!! Bonus Question..Extra Gold !!");
                  }
                  else
                  {
                  al_draw_bitmap(smiley3,325,100,0);
                  al_draw_textf(font32, al_map_rgb(225, 255, 255),101,132, 0, "Correct");
                  al_draw_textf(font32, al_map_rgb(225, 255, 255), 571,130, 0, "Answer");
                  al_draw_text(font32, al_map_rgb(225, 255, 255), WIDTH/2, 350, ALLEGRO_ALIGN_CENTER, "Hurray !!! Your Gold has been Increased !!!");
                  }

                }
                else
                {
                    al_draw_bitmap(result_display,0,0,0);
                    al_draw_textf(font18, al_map_rgb(225, 255, 255),372,16, 0, "%i",gold);
                    if(Highlight(x,y,level)==bonus_house&&bonus_question==current_question)
                  {
                      bonus=true;
                      al_draw_bitmap(bonus_pic,259,85,0);
                     al_draw_textf(font32, al_map_rgb(225, 255, 255),101,132, 0, "Lucky");
                     al_draw_textf(font32, al_map_rgb(225, 255, 255), 573,130, 0, "Boy");
                     al_draw_text(font32, al_map_rgb(225, 255, 255), WIDTH/2, 350, ALLEGRO_ALIGN_CENTER, "Its Wrong!! Bonus Question..Extra Gold !!");
                  }
                  else
                  {
                    al_draw_bitmap(smiley2,335,95,0);
                    al_draw_textf(font32, al_map_rgb(225, 255, 255),101,132, 0, "Wrong");
                    al_draw_textf(font32, al_map_rgb(225, 255, 255), 571,130, 0, "Answer");
                    al_draw_text(font32, al_map_rgb(225, 255, 255), WIDTH/2, 350, ALLEGRO_ALIGN_CENTER, "Sorry !!! Your Gold has been Reduced !!!");
                  }

                }
                drawQues=false;
                if(++qWait>180)
                {
                    gameState=PLAYING;
                    qWait=0;
                    reveal=false;
                }
            }

            if(nextQues)
            {
               // pQues[Highlight(x,y,level)-1]+=7;
              // qfile.clear();
               //qfile.seekg(0, ios::beg);
               if(Highlight(x,y,level)==1)
                    random_query_house1[random_query]=false;
                if(Highlight(x,y,level)==2)
                    random_query_house2[random_query]=false;
                if(Highlight(x,y,level)==3)
                    random_query_house3[random_query]=false;
                if(Highlight(x,y,level)==4)
                    random_query_house4[random_query]=false;
                if(Highlight(x,y,level)==5)
                    random_query_house5[random_query]=false;
               int temporary=0;
               random_query=rand()%4;

               cout<<random_query<<endl;
               if(Highlight(x,y,level)==1)
               {
                   if(!random_query_house1[random_query])
                   {
                       for(int i=0;i<4;i++)
                       {
                           if(random_query_house1[i])
                           {
                               random_query=i;
                              // random_query_house1[random_query]=false;
                               temporary=1;
                               break;
                           }
                       }
                       if(temporary==0)
                        random_query=4;

                   }
                   else
                   {
                    //random_query_house1[random_query]=false;
                   }

               }
               else
               if(Highlight(x,y,level)==2)
               {
                   if(!random_query_house2[random_query])
                   {
                       for(int i=0;i<4;i++)
                       {
                           if(random_query_house2[i])
                           {
                               random_query=i;
                               //random_query_house2[random_query]=false;
                               temporary=1;
                               break;
                           }
                       }
                       if(temporary==0)
                        random_query=4;

                   }
                   else
                   {
                   // random_query_house2[random_query]=false;
                   }

               }
               else
               if(Highlight(x,y,level)==3)
               {
                   if(!random_query_house3[random_query])
                   {
                       for(int i=0;i<4;i++)
                       {
                           if(random_query_house3[i])
                           {
                               random_query=i;
                              // random_query_house3[random_query]=false;
                               temporary=1;
                               break;
                           }
                       }
                       if(temporary==0)
                        random_query=4;

                   }
                   else
                   {
                    //random_query_house3[random_query]=false;
                   }

               }
               else
               if(Highlight(x,y,level)==4)
               {
                   if(!random_query_house4[random_query])
                   {
                       for(int i=0;i<4;i++)
                       {
                           if(random_query_house4[i])
                           {
                               random_query=i;
                             //  random_query_house4[random_query]=false;
                               temporary=1;
                               break;
                           }
                       }
                       if(temporary==0)
                        random_query=4;

                   }
                   else
                   {
                   // random_query_house4[random_query]=false;
                   }

               }
               else
               if(Highlight(x,y,level)==5)
               {
                   if(!random_query_house5[random_query])
                   {
                       for(int i=0;i<4;i++)
                       {
                           if(random_query_house5[i])
                           {
                               random_query=i;
                              // random_query_house5[random_query]=false;
                               temporary=1;
                               break;
                           }
                       }
                       if(temporary==0)
                        random_query=4;

                   }
                   else
                   {
                   // random_query_house5[random_query]=false;
                   }

               }
               next_query=true;
                nextQues=false;
                if(corAns)
                {

                    if(bonus)
                    {
                        bonus=false;
                        gold+=100;
                    }
                    else
                        gold+=50;


                }

                else
                {

                     if(bonus)
                    {
                        bonus=false;
                        gold+=75;
                    }
                    else
                        gold-=25;
                }

            }
            //al_draw_text(font18, al_map_rgb(123, 234, 012), WIDTH/2, HEIGHT/2, ALLEGRO_ALIGN_CENTER, "YOU HAVE ENTERED QUESTION MODE PRESS ESCAPE");
            al_flip_display();
            al_clear_to_color(al_map_rgb(100,12,125));}

        else
        if(gameState==END)
        {
            al_draw_bitmap(go,0,0,0);
          //  al_draw_bitmap(highscore,380,20,0);
            ifstream h_score(High_score[0]);

            string str2;

            getline(h_score,str2);
            h_min = atoi(str2.c_str());
            getline(h_score,str2);
            h_sec = atoi(str2.c_str());
            int high_score=h_min*60+h_sec;
            int game_score=gtime1*60+gtime;
            if(high_score<=game_score)
            {
                ofstream u_score(High_score[0]);
                  al_draw_bitmap(highscore,380,20,0);
                 u_score<<gtime1<<endl;
                 u_score<<gtime<<endl;

            }




            al_draw_textf(font1, al_map_rgb(0, 0, 0), 538, 249, 0, "0 Min 0 Sec");
            al_draw_textf(font1, al_map_rgb(0, 0, 0), 526, 305, 0, "%i Mins %i Secs", gtime1,gtime);
           // al_draw_textf(font18, al_map_rgb(255, 255, 255), 400, 50, 0, "TOTAL TIME: %i Mins %i Secs", gtime1,gtime);
          //  al_draw_text(font18, al_map_rgb(255, 255, 255), 780, 530, ALLEGRO_ALIGN_RIGHT, "PRESS 'Y' TO CONTINUE 'N' TO EXIT");
            al_flip_display();
        }

        else
        if(gameState==OPTIONS)
        {
              al_draw_bitmap(options,0,0,0);
               al_flip_display();
        }
        else
        if(gameState==FINAL)
        {
            al_draw_bitmap(Final,0,0,0);
            al_flip_display();
            al_rest(5);
            gameState = END;
        }

	}


    {
        al_destroy_event_queue(event_queue);
        al_destroy_timer(myTimer);
        al_destroy_bitmap(backGround1);
        al_destroy_bitmap(backGround2);
        al_destroy_bitmap(backGround3);
        al_destroy_bitmap(start_bk);
        al_destroy_bitmap(question_bk);
        al_destroy_bitmap(end_bk);
        al_destroy_bitmap(proffl);
        al_destroy_bitmap(proffu);
        al_destroy_bitmap(proffd);
        al_destroy_bitmap(highlight);
        al_destroy_bitmap(me);
        al_destroy_bitmap(way2);
        al_destroy_bitmap(way1);
        al_destroy_bitmap(way3);
        al_destroy_bitmap(doorImageO);
        al_destroy_bitmap(doorImageC);
        al_destroy_bitmap(go);
        al_destroy_display(display);
        al_destroy_bitmap(sub_menu);
        al_destroy_bitmap(smiley1);
        al_destroy_bitmap(smiley2);
        al_destroy_bitmap(smiley3);
        al_destroy_bitmap(smiley4);
        al_destroy_bitmap(smiley5);
        al_destroy_bitmap(wait_for_result);
        al_destroy_bitmap(query_display);
        al_destroy_bitmap(result_display);
        al_destroy_bitmap(highscore);
        al_destroy_bitmap(options);
        al_destroy_bitmap(gold_icon);
        al_destroy_bitmap(score_board_time);
        al_destroy_bitmap(score_board_gold);
         al_destroy_bitmap(bonus_pic);
         al_destroy_bitmap(board);
         al_destroy_bitmap(backGroundi);
         al_destroy_bitmap(kLeft);
         al_destroy_bitmap(kRight);
         al_destroy_bitmap(Final);
    }


    return 0;
}
void wayFunc(ALLEGRO_BITMAP *way1, ALLEGRO_BITMAP *way2,bool cleared[],int level)
{
    if(level==1)
    {
        if(!cleared[5])
            al_draw_bitmap(way2,630,330,0);
        else
            al_draw_bitmap(way1,630,330,0);
    }
    else
    if(level==2)
    {
        if(!cleared[5])
            al_draw_bitmap(way2,545,310,0);
        else
            al_draw_bitmap(way1,545,310,0);
    }
}
int Highlight(int x,int y,int level)
{
    int region=0;
    if(level==1)
    {
        if(x>=130&&x+iWidth<=210&&y>=110&&y+iHeight<=180)
        {
            region=1;
            return region;
        }
        else
        if(x>=355&&x+iWidth<=445&&y>=130&&y+iHeight<=200)
        {
             region=2;
            return region;
        }
        else
        if(x>=545&&x+iWidth<=625&&y>=180&&y+iHeight<=250)
        {
             region=3;
            return region;
        }
        else
        if(x>=130&&x+iWidth<=210&&y>=440&&y+iHeight<=510)
        {
             region=4;
            return region;
        }
        else
        if(x>=430&&x+iWidth<=510&&y>=440&&y+iHeight<=510)
        {
             region=5;
            return region;
        }
    }
    else
    if(level==2)
    {
        if(x>=0&&x+iWidth<=80&&y>=285&&y+iHeight<=355)
        {
            region=1;
            return region;
        }
        else
        if(x>=165&&x+iWidth<=245&&y>=90&&y+iHeight<=160)
        {
             region=2;
            return region;
        }
        else
        if(x>=480&&x+iWidth<=560&&y>=140&&y+iHeight<=210)
        {
             region=3;
            return region;
        }
        else
        if(x>=340&&x+iWidth<=420&&y>=500&&y+iHeight<=570)
        {
             region=4;
            return region;
        }
        else
        if(x>=670&&x+iWidth<=750&&y>=500&&y+iHeight<=570)
        {
             region=5;
            return region;
        }
    }
    else
    if(level==3)
    {
    if(x>=130&&x+iWidth<=210&&y>=110&&y+iHeight<=180)
    {
        region=1;
        return region;
    }
    else
    if(x>=355&&x+iWidth<=445&&y>=130&&y+iHeight<=200)
    {
         region=2;
        return region;
    }
    else
    if(x>=545&&x+iWidth<=625&&y>=180&&y+iHeight<=250)
    {
         region=3;
        return region;
    }
    else
    if(x>=430&&x+iWidth<=510&&y>=440&&y+iHeight<=510)
    {
         region=5;
        return region;
    }
    else
    if(x>=130&&x+iWidth<=210&&y>=440&&y+iHeight<=510)
    {
         region=4;
        return region;
    }
    else
    if(x>=715&&x+iWidth<=795&&y>=200&&y+iHeight<=500)
    {
         region=6;
        return region;
    }
    }

    return region;
}

void initialisation(int level)
{
     //cout<<"h";
    if(level==1)
    {
        gameState=START;
        x=0;
        y=285;
        state=0;
        bonus_question=rand()%4+1;
        bonus_house=rand()%5+1;
        box=0;
        gtime=0;
        gtime1=0;
        notMoving=true;
        gold=500;
        for(int i=0;i<4;i++)
    {
        random_query_house1[i]=true;
    }
    for(int i=0;i<4;i++)
    {
        random_query_house2[i]=true;
    }
    for(int i=0;i<4;i++)
    {
        random_query_house3[i]=true;
    }
    for(int i=0;i<4;i++)
    {
        random_query_house4[i]=true;
    }
    for(int i=0;i<4;i++)
    {
        random_query_house5[i]=true;
    }
        for(int i=0;i<7;i++)
        {
            keys[i]=false;
        }
        for(int i=0;i<5;i++)
        {
            pQues[i]=0;
        }
        for(int i=0;i<=5;i++)
        {
            cleared[i]=true;
        }
    }
    else
    if(level==2)
    {
        x=190;
        y=530;
        state=0;
        box=0;
        bonus_question=rand()%4+1;
        bonus_house=rand()%5+1;
        notMoving=true;
    for(int i=0;i<4;i++)
    {
        random_query_house1[i]=true;
    }
    for(int i=0;i<4;i++)
    {
        random_query_house2[i]=true;
    }
    for(int i=0;i<4;i++)
    {
        random_query_house3[i]=true;
    }
    for(int i=0;i<4;i++)
    {
        random_query_house4[i]=true;
    }
    for(int i=0;i<4;i++)
    {
        random_query_house5[i]=true;
    }
        for(int i=0;i<7;i++)
        {
            keys[i]=false;
        }
        for(int i=0;i<5;i++)
        {
            pQues[i]=0;
        }
        for(int i=0;i<=5;i++)
        {
            cleared[i]=true;
        }

    }
    else
    if(level==3)
 {
    x=0;
    y=285;
    state=0;
    box=0;
    //gold=120;
    notMoving=true;
    bonus_question=rand()%4+1;
    bonus_house=rand()%5+1;
    for(int i=0;i<4;i++)
    {
        random_query_house1[i]=true;
    }
    for(int i=0;i<4;i++)
    {
        random_query_house2[i]=true;
    }
    for(int i=0;i<4;i++)
    {
        random_query_house3[i]=true;
    }
    for(int i=0;i<4;i++)
    {
        random_query_house4[i]=true;
    }
    for(int i=0;i<4;i++)
    {
        random_query_house5[i]=true;
    }

    for(int i=0;i<7;i++)
    {
        keys[i]=false;
    }
    for(int i=0;i<5;i++)
    {
        pQues[i]=0;
    }
    for(int i=0;i<=5;i++)
    {
        cleared[i]=false;
    }
 }
}

void qinitialisation(int level)
{
    cAnswer=0;
    gAnswer=0;
    checkAns=false;
    takeAns=true;
    corAns=false;
    reveal=false;
    drawQues=true;
    qWait=0;
}

bool collision(int x,int y,int level)
{
     if(level==1)
    {
        if(y+iHeight>=290&&y+iHeight<=340&&x>=0&&x+iWidth<=200)
        {
            box=1;
            return false;
        }
        else
        if(y+iHeight>=220&&y+iHeight<=290&&x>=140&&x+iWidth<=610)
        {
            box=2;
            return false;
        }
        else
        if(x>=270&&x+iWidth<=340&&y+iHeight>=290&&y+iHeight<=490)
        {
            box=3;
            return false;
        }
        if(x>=130&&x+iWidth<=630&&y+iHeight>=490&&y+iHeight<=540)
        {
            box=4;
            return false;
        }
        if(x>=565&&x+iWidth<=630&&y+iHeight>=340&&y+iHeight<=540)
        {
            box=5;
            return false;
        }
        if(y+iHeight>=155&&y+iHeight<=220&&x>=140&&x+iWidth<=200)
        {
            box=6;
            return false;
        }
        if(y+iHeight>=175&&y+iHeight<=220&&x>=365&&x+iWidth<=425)
        {
            box=7;
            return false;
        }
        if(x+iWidth>=630&&x<=685&&y+iHeight>=340&&y+iHeight<=400)
        {
           // if(!wayColl())
                box=8;
                return false;
        }
    }
    else
    if(level==2)
    {
        if(y+iHeight>=535&&y+iHeight<=600&&x>=150&&x+iWidth<=255)
        {
            box=1;
            return false;
        }
        if(y+iHeight>=130&&y+iHeight<=535&&x>=175&&x+iWidth<=230)
        {
            box=2;
            return false;
        }
        if(y+iHeight>=325&&y+iHeight<=365&&x>=0&&x<=495)
        {
            box=3;
            return false;
        }
        if(y+iHeight>=175&&y+iHeight<=535&&x>=495&&x+iWidth<=545)
        {
            box=4;
            return false;
        }
        if(y+iHeight>=535&&y+iHeight<=575&&x>=345&&x+iWidth<=750)
        {
            box=5;
            return false;
        }
        if(y+iHeight>=310&&y+iHeight<=370&&x>=545&&x+iWidth<=650)
        {
            box=6;
            return false;
        }
        if(x+iWidth>=545 && x<=650 && y+iHeight<355 && y+iHeight>325)
        {
           // if(!wayColl())
                box=7;
                return false;
        }
    }
    else
    if(level==3)
    {
    if(y+iHeight>=290&&y+iHeight<=340&&x>=0&&x+iWidth<=200)
    {
        box=1;
        return false;
    }
    else
    if(y+iHeight>=220&&y+iHeight<=290&&x>=140&&x+iWidth<=610)
    {
        box=2;
        return false;
    }
    else
    if(x>=270&&x+iWidth<=340&&y+iHeight>=290&&y+iHeight<=490)
    {
        box=3;
        return false;
    }
    if(x>=130&&x+iWidth<=630&&y+iHeight>=490&&y+iHeight<=540)
    {
        box=4;
        return false;
    }
    if(x>=565&&x+iWidth<=630&&y+iHeight>=340&&y+iHeight<=540)
    {
        box=5;
        return false;
    }
    if(y+iHeight>=155&&y+iHeight<=220&&x>=140&&x+iWidth<=200)
    {
        box=6;
        return false;
    }
    if(y+iHeight>=175&&y+iHeight<=220&&x>=365&&x+iWidth<=425)
    {
        box=7;
        return false;
    }
    if(x+iWidth>=630&&x<=800&&y+iHeight>=330&&y+iHeight<=380)
    {
       // if(!wayColl())
        {
            box=8;
            return false;
        }
    }
    }
    return true;
}
void reset(int box,int level)
{
     if(level==1)
    {
        if(box==1)
        {
            if(y+iHeight<290)
                y=290-iHeight;
            if(y+iHeight>340)
                y=340-iHeight;
            if(x+iWidth>200)
                x=200-iWidth;
        }
        if(box==2)
        {
            if(y+iHeight<220)
                y=220-iHeight;
            if(y+iHeight>290)
                y=290-iHeight;
            if(x<140)
                x=140;
            if(x+iWidth>610)
                x=610-iWidth;
        }
        if(box==3)
        {
            if(y+iHeight<290)
                y=290-iHeight;
            if(y+iHeight>490)
                y=490-iHeight;
            if(x<270)
                x=270;
            if(x+iWidth>340)
                x=340-iWidth;
        }
        if(box==4)
        {
            if(y+iHeight<490)
                y=490-iHeight;
            if(y+iHeight>540)
                y=540-iHeight;
            if(x<130)
                x=130;
            if(x+iWidth>630)
                x=630-iWidth;
        }
        if(box==5)
        {
            if(y+iHeight<340)
                y=340-iHeight;
            if(y+iHeight>540)
                y=540-iHeight;
            if(x<565)
                x=565;
            if(x+iWidth>630)
                x=630-iWidth;
        }
        if(box==6)
        {
            if(y+iHeight<155)
                y=155-iHeight;
            if(y+iHeight>220)
                y=220-iHeight;
            if(x<140)
                x=140;
            if(x+iWidth>200)
                x=200-iWidth;
        }
        if(box==7)
        {
            if(y+iHeight<175)
                y=175-iHeight;
            if(y+iHeight>220)
                y=220-iHeight;
            if(x<365)
                x=365;
            if(x+iWidth>425)
                x=425-iWidth;
        }
        if(box==8)
        {
            if(y+iHeight<340)
                y=340-iHeight;
            if(y+iHeight>400)
                y=400-iHeight;
            if(x+iWidth<630)
                x=630-iWidth;
            if(x>685)
                x=685;
        }
    }
    else
    if(level==2)
    {
        if(box==1)
        {
            if(y+iHeight<535)
                y=535-iHeight;
            if(y+iHeight>600)
                y=600-iHeight;
            if(x<150)
                x=150;
            if(x+iWidth>255)
                x=255-iWidth;
        }
        if(box==2)
        {
            if(y+iHeight<130)
                y=130-iHeight;
            if(y+iHeight>535)
                y=535-iHeight;
            if(x<175)
                x=175;
            if(x+iWidth>230)
                x=230-iWidth;
        }
        if(box==3)
        {
            if(y+iHeight<325)
                y=325-iHeight;
            if(y+iHeight>365)
                y=365-iHeight;
            if(x<0)
                x=0;
            if(x>495)
                x=495;
        }
        if(box==4)
        {
            if(y+iHeight<175)
                y=175-iHeight;
            if(y+iHeight>535)
                y=535-iHeight;
            if(x<495)
                x=495;
            if(x+iWidth>545)
                x=545-iWidth;
        }
        if(box==5)
        {
            if(y+iHeight<535)
                y=535-iHeight;
            if(y+iHeight>575)
                y=575-iHeight;
            if(x<345)
                x=345;
            if(x+iWidth>750)
                x=750-iWidth;
        }
        if(box==6)
        {
             //if(y+iHeight>=310&&y+iHeight<=370&&x>=545&&x+iWidth<=650)
            if(y+iHeight<370)
                y=370-iHeight;
            if(y+iHeight>575)
                y=575-iHeight;
            if(x<650)
                x=650;
            if(x+iWidth>545)
                x=545-iWidth;

        }
         if(box==7)
        {
           // if(y+iHeight>=310&&y+iHeight<=370&&x>=545&&x+iWidth<=650)
            if(y+iHeight<360)
                y=360-iHeight;
            if(y+iHeight>340)
                y=325-iHeight;
            if(x<650)
                x=650;
            if(x+iWidth>545)
                x=545-iWidth;
        }
    }
    else
    if(level==3)
    {
    if(box==1)
    {
        if(y+iHeight<290)
            y=290-iHeight;
        if(y+iHeight>340)
            y=340-iHeight;
        if(x+iWidth>200)
            x=200-iWidth;
    }
    if(box==2)
    {
        if(y+iHeight<220)
            y=220-iHeight;
        if(y+iHeight>290)
            y=290-iHeight;
        if(x<140)
            x=140;
        if(x+iWidth>610)
            x=610-iWidth;
    }
    if(box==3)
    {
        if(y+iHeight<290)
            y=290-iHeight;
        if(y+iHeight>490)
            y=490-iHeight;
        if(x<270)
            x=270;
        if(x+iWidth>340)
            x=340-iWidth;
    }
    if(box==4)
    {
        if(y+iHeight<490)
            y=490-iHeight;
        if(y+iHeight>540)
            y=540-iHeight;
        if(x<130)
            x=130;
        if(x+iWidth>630)
            x=630-iWidth;
    }
    if(box==5)
    {
        if(y+iHeight<340)
            y=340-iHeight;
        if(y+iHeight>540)
            y=540-iHeight;
        if(x<565)
            x=565;
        if(x+iWidth>630)
            x=630-iWidth;
    }
    if(box==6)
    {
        if(y+iHeight<155)
            y=155-iHeight;
        if(y+iHeight>220)
            y=220-iHeight;
        if(x<140)
            x=140;
        if(x+iWidth>200)
            x=200-iWidth;
    }
    if(box==7)
    {
        if(y+iHeight<175)
            y=175-iHeight;
        if(y+iHeight>220)
            y=220-iHeight;
        if(x<365)
            x=365;
        if(x+iWidth>425)
            x=425-iWidth;
    }
    if(box==8)
    {
        if(y+iHeight<330)
            y=330-iHeight;
        if(y+iHeight>380)
            y=380-iHeight;
        if(x+iWidth<630)
            x=630-iWidth;
        if(x>800)
            x=800;
    }
    }
}


void drawDoor(ALLEGRO_BITMAP *o, ALLEGRO_BITMAP *c,bool cleared[],int level)
{
    if(level==1)
    {
        if(!cleared[1])
            al_draw_bitmap(c,230,205,0);
        else
            al_draw_bitmap(o,230,205,0);

        if(!cleared[2])
            al_draw_bitmap(c,490,205,0);
        else
            al_draw_bitmap(o,490,205,0);

        if(!cleared[3])
            al_draw_rotated_bitmap(c,5,45,305,345,3.146/2,0);
        else
            al_draw_rotated_bitmap(o,5,45,305,345,3.146/2,0);

        if(!cleared[4])
            al_draw_bitmap(c,380,470,0);
        else
            al_draw_bitmap(o,380,470,0);
    }
    else
    if(level==2)
    {
        if(!cleared[1])
            al_draw_rotated_bitmap(c,5,45,200,210,3.146/2,0);
        else
            al_draw_rotated_bitmap(o,5,45,200,210,3.146/2,0);

        if(!cleared[2])
            al_draw_bitmap(c,470,300,0);
        else
            al_draw_bitmap(o,470,300,0);

        if(!cleared[3])
            al_draw_rotated_bitmap(c,5,45,515,450,3.146/2,0);
        else
            al_draw_rotated_bitmap(o,5,45,515,450,3.146/2,0);

        if(!cleared[4])
            al_draw_bitmap(c,600,510,0);
        else
            al_draw_bitmap(o,600,510,0);
    }
    else
    if(level==3)
    {
    if(!cleared[1])
        al_draw_bitmap(c,230,205,0);
    else
        al_draw_bitmap(o,230,205,0);

    if(!cleared[2])
        al_draw_bitmap(c,490,205,0);
    else
        al_draw_bitmap(o,490,205,0);

    if(!cleared[3])
        al_draw_rotated_bitmap(c,5,45,305,345,3.146/2,0);
    else
        al_draw_rotated_bitmap(o,5,45,305,345,3.146/2,0);

    if(!cleared[4])
        al_draw_bitmap(c,380,470,0);
    else
        al_draw_bitmap(o,380,470,0);
    if(!cleared[5])
        al_draw_bitmap(c,637,315,0);
    else
        al_draw_bitmap(o,637,315,0);
    }
}

void doorFunc(int box,int level)
{
    if(level==1)
    {
        if(box==2)
        {
            if(!cleared[1])
            {
                if(x+iWidth>235)
                    x=235-iWidth;
            }
            if(!cleared[2])
            {
                if(x+iWidth>495)
                    x=495-iWidth;
            }
        }
        if(box==3)
        {
            if(!cleared[3])
            {
                if(y+iHeight>345)
                    y=345-iHeight;
            }
        }
         if(box==4)
        {
            if(!cleared[4])
            {
                if(x+iWidth>385)
                    x=385-iWidth;
            }
        }
        if(box==5)
        {
            if(!cleared[5])
            {
                if(x+iWidth>630)
                    x=630-iWidth;
            }
        }
    }
    else
    if(level==2)
    {
        if(box==2)
        {
            if(!cleared[1])
            {
                if(y<175)
                    y=175;
            }
            if(!cleared[2])
            {
                if(x>440)
                    x=440;
            }
        }
        else
        if(box==3)
        {
            if(!cleared[2])
            {
                if(x>440)
                    x=440;
            }
        }
        else
        if(box==4)
        {
            if(!cleared[3])
            {
                if(y>395)
                    y=395;
            }
        }
        if(box==5)
        {
            if(!cleared[4])
            {
                if(x>570)
                    x=570;
            }
        }
    }
    else
    if(level==3)
    {
    if(box==2)
    {
        if(!cleared[1])
        {
            if(x+iWidth>230)
                x=230-iWidth;
        }
        if(!cleared[2])
        {
            if(x+iWidth>490)
                x=490-iWidth;
        }
    }
    if(box==3)
    {
        if(!cleared[3])
        {
            if(y+iHeight>345)
                y=345-iHeight;
        }
    }
     if(box==4)
    {
        if(!cleared[4])
        {
            if(x+iWidth>380)
                x=380-iWidth;
        }
    }
    if(box==5)
    {
        if(!cleared[5])
        {
            if(x+iWidth>630)
                x=630-iWidth;
        }
    }
    }
}


