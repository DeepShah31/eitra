    #include <iostream>
    #include <graphics>
    using namespace std;
    void main()
    {
       int gd=DETECT,gm;
       initgraph(&gd,&gm,"");
      line(350,100,450,200);
      line(250,200,450,200);
      line(250,200,350,100);
      setfillstyle(LINE_FILL,RED);
      floodfill(350,120,WHITE);
      line(240,205,460,205);
      line(240,205,350,95);
      line(460,205,350,95);
      setfillstyle(SOLID_FILL,DARKGRAY);
      floodfill(350,97,WHITE);
      line(295,150,295,120);
      line(310,135,310,115);
      line(290,120,315,115);
      line(290,120,290,116);
      line(315,115,315,111);
      line(290,116,315,111);
      setfillstyle(SOLID_FILL,BROWN);
      floodfill(297,117,WHITE);
      floodfill(297,127,WHITE);
      line(255,205,255,295);
      line(445,205,445,295);
      line(255,295,445,295);
      line(330,290,370,290);
      line(330,290,330,220);
      line(370,290,370,220);
      line(330,220,370,220);
      setfillstyle(SOLID_FILL,DARKGRAY);
      floodfill(335,285,WHITE);
      circle(365,257,2);
      setfillstyle(SOLID_FILL,BLACK);
      floodfill(365,257,WHITE);
      line(280,260,306,260);
      line(280,260,280,220);
      line(306,260,306,220);
      line(280,220,306,220);
      line(293,260,293,220);
      line(280,240,306,240);
      line(275,260,280,260);
      line(306,260,311,260);
      line(275,260,275,264);
      line(311,260,311,264);
      line(275,264,311,264);
      setfillstyle(SOLID_FILL,RED);
      floodfill(277,263,WHITE);
      setfillstyle(SOLID_FILL,CYAN);
      floodfill(282,258,WHITE);
      floodfill(304,258,WHITE);
      floodfill(282,222,WHITE);
      floodfill(304,222,WHITE);
      line(390,260,430,260);
      line(390,220,430,220);
      line(390,220,390,260);
      line(430,220,430,260);
      line(410,220,410,260);
      line(390,240,430,240);
      line(385,260,390,260);
      line(430,260,435,260);
      line(385,260,385,264);
      line(435,260,435,264);
      line(385,264,435,264);
      setfillstyle(SOLID_FILL,CYAN);
      floodfill(392,258,WHITE);
      floodfill(428,258,WHITE);
      floodfill(392,222,WHITE);
      floodfill(428,222,WHITE);
      setfillstyle(SOLID_FILL,RED);
      floodfill(387,263,WHITE);
      settextstyle(4,HORIZ_DIR,1);
      outtextxy(200,350,"Press any key to open the door");
      getch();
      cleardevice();
      line(350,100,450,200);
      line(250,200,450,200);
      line(250,200,350,100);
      setfillstyle(LINE_FILL,RED);
      floodfill(350,120,WHITE);
      line(240,205,460,205);
      line(240,205,350,95);
      line(460,205,350,95);
      setfillstyle(SOLID_FILL,DARKGRAY);
      floodfill(350,97,WHITE);
      line(295,150,295,120);
      line(310,135,310,115);
      line(290,120,315,115);
      line(290,120,290,116);
      line(315,115,315,111);
      line(290,116,315,111);
      setfillstyle(SOLID_FILL,BROWN);
      floodfill(297,117,WHITE);
      floodfill(297,127,WHITE);
      line(255,205,255,295);
      line(445,205,445,295);
      line(255,295,445,295);
      line(330,290,370,290);
      line(330,290,330,220);
      line(370,290,370,220);
      line(330,220,370,220);
      line(290,220,330,220);
      line(290,220,290,290);
      line(290,290,330,290);
      line(350,220,350,230);
      line(354,220,354,230);
      circle(352,233,4);
      circle(295,257,2);
      setfillstyle(SOLID_FILL,LIGHTGRAY);
      floodfill(352,223,WHITE);
      setfillstyle(SOLID_FILL,YELLOW);
      floodfill(352,233,WHITE);
      setfillstyle(SOLID_FILL,DARKGRAY);
      floodfill(296,285,WHITE);
      setfillstyle(SOLID_FILL,BLACK);
      floodfill(295,257,WHITE);
      line(280,260,290,260);
      line(280,260,280,220);
      line(280,220,306,220);
      line(280,240,290,240);
      line(275,260,280,260);
      line(275,260,275,264);
      line(275,264,290,264);
      setfillstyle(SOLID_FILL,RED);
      floodfill(277,263,WHITE);
      setfillstyle(SOLID_FILL,CYAN);
      floodfill(282,258,WHITE);
      floodfill(282,222,WHITE);
      line(390,260,430,260);
      line(390,220,430,220);
      line(390,220,390,260);
      line(430,220,430,260);
      line(410,220,410,260);
      line(390,240,430,240);
      line(385,260,390,260);
      line(430,260,435,260);
      line(385,260,385,264);
      line(435,260,435,264);
      line(385,264,435,264);
      setfillstyle(SOLID_FILL,CYAN);
      floodfill(392,258,WHITE);
      floodfill(428,258,WHITE);
      floodfill(392,222,WHITE);
      floodfill(428,222,WHITE);
      setfillstyle(SOLID_FILL,RED);
      floodfill(387,263,WHITE);
      getch();
      closegraph();
    }