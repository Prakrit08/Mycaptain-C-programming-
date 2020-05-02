#include<stdio.h>
#include<dos.h>
#include<windows.h>
#include<winbase.h>
#include<conio.h>
#include<time.h>
#include<string.h>
FILE *fnew;
HANDLE rHnd, wHnd;
char input;
int initializeconsolehandles();
void file();
void locate(int,int);
void tab1();
void tab2();
void tab3();
void tab4();
void tab5();
void date();
struct team
{
    char timein[9],timeout[9],batsmanname[50];
    int _4s,_6s,ballsfaced,totalruns,mtsplayed;
    char timeplayed[9],howout[20],fielder[30],bowler[30];
} teamA[11],teamB[11];

struct bowlingteam
{
    char bowler[30];
    int ballthrownincurrentover,overs,maidens,runs,wickets,noballs,wides;
    float average;
} bowlingteamA[8],bowlingteamB[8];
struct gamedetails//for the records of game details//
{
    char competition[20],playedAt[50],venue[30],matchbetween[30],versus[30],tosswonby[30],electedto[20],date[30],input;
    int inningsof,overs;
} gamedetailA,gamedetailB;
struct wickets
{
    int atruns;
    int overnumber;
} wicketsA[8],wicketsB[8];
struct undo
{
    struct team teamArecord[11],teamBrecord[11];
    struct bowlingteam bowlingteamArecord[8],bowlingteamBrecord[8];
    struct wickets wicketsArecord[8],wicketsBrecord[8];
} steps[10];
