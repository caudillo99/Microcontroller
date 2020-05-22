#include "song.h"

//Author:Uknownint
PROGMEM const struct note ImperialMarch[]={
	{a, TEMPO_500},
	{a, TEMPO_500},
	{a, TEMPO_500},
	{f, TEMPO_500*3/4},
	{cH, TEMPO_500*1/4},

	{a, TEMPO_500},
	{f, TEMPO_500*3/4},
	{cH, TEMPO_500*1/4},
	{a, TEMPO_500*2},
	

	{eH, TEMPO_500},
	{eH, TEMPO_500},
	{eH, TEMPO_500},
	{fH, TEMPO_500*3/4},
	{cH, TEMPO_500*1/4},

	{gS, TEMPO_500},
	{f, TEMPO_500*3/4},
	{cH, TEMPO_500*1/4},
	{a, TEMPO_500*2},
	

	{aH, TEMPO_500},
	{a, TEMPO_500*3/4},
	{a, TEMPO_500*1/4},
	{aH, TEMPO_500},
	{gSH, TEMPO_500/2},
	{gH, TEMPO_500/2},

	{fSH, TEMPO_500*1/4},
	{fH, TEMPO_500*1/4},
	{fSH, TEMPO_500/2},
	{0,TEMPO_500/2},
	{aS, TEMPO_500/2},
	{dSH, TEMPO_500},
	{dH, TEMPO_500/2},
	{cSH, TEMPO_500/2},
	

	{cH, TEMPO_500*1/4},
	{b, TEMPO_500*1/4},
	{cH, TEMPO_500/2},
	{0,TEMPO_500/2},
	{f, TEMPO_500*1/4},
	{gS, TEMPO_500},
	{f, TEMPO_500*3/4},
	{a, TEMPO_500*1/4},

	{cH, TEMPO_500},
	{a, TEMPO_500*3/4},
	{cH, TEMPO_500*1/4},
	{eH, TEMPO_500*2},

	{aH, TEMPO_500},
	{a, TEMPO_500*3/4},
	{a, TEMPO_500*1/4},
	{aH, TEMPO_500},
	{gSH, TEMPO_500/2},
	{gH, TEMPO_500/2},

	{fSH, TEMPO_500*1/4},
	{fH, TEMPO_500*1/4},
	{fSH, TEMPO_500/2},
	{0,TEMPO_500/2},
	{aS, TEMPO_500/2},
	{dSH, TEMPO_500},
	{dH, TEMPO_500/2},
	{cSH, TEMPO_500/2},
	
	{cH, TEMPO_500*1/4},
	{b, TEMPO_500*1/4},
	{cH, TEMPO_500/2},
	{0,TEMPO_500/2},
	{f, TEMPO_500/2},
	{gS, TEMPO_500},
	{f, TEMPO_500*3/4},
	{cH, TEMPO_500*1/4},

	{a, TEMPO_500},
	{f, TEMPO_500*3/4},
	{c, TEMPO_500*1/4},
	{a, TEMPO_500*2}
	
};

//Author:Jose Manuel Gallegos Lopez
PROGMEM const struct note AngelesAzules[]={
	{bL, TEMPO_500*3/8},
	{d, TEMPO_500*3/8},
	{fS, TEMPO_500*3/8},
	{b, TEMPO_500*5/4},

	{a, TEMPO_500*3/8},
	{gS, TEMPO_500*3/4},
	{fS, TEMPO_500*3/8},
	{d, TEMPO_500*3/4},
	{bL, TEMPO_500*3/2},
	//first bit

	{bL, TEMPO_500*3/8},
	{d, TEMPO_500*3/8},
	{fS, TEMPO_500*3/8},
	{b, TEMPO_500*5/4},

	{a, TEMPO_500*3/8},
	{gS, TEMPO_500*3/4},
	{fS, TEMPO_500*3/8},
	{d, TEMPO_500*3/4},
	{bL, TEMPO_500*3/2},
	//first bit

	{d, TEMPO_500*3/8},
	{d, TEMPO_500*3/8},
	{d, TEMPO_500*3/8},
	{cS, TEMPO_500*3/8},
	{d, TEMPO_500*5/8},
	{aL, TEMPO_500*5/4},

	{d, TEMPO_500*3/8},
	{d, TEMPO_500*3/8},
	{cS, TEMPO_500*3/8},
	{d, TEMPO_500*5/8},
	{aL, TEMPO_500*5/8},

//****************

	{fS, TEMPO_500*3/8},
	{fS, TEMPO_500*3/8},
	{fS, TEMPO_500*3/8},
	{e, TEMPO_500*3/8},
	{fS, TEMPO_500*5/8},
	{cS, TEMPO_500*5/4},

	{fS, TEMPO_500*3/8},
	{fS, TEMPO_500*3/8},
	{e, TEMPO_500*3/8},
	{fS, TEMPO_500*5/8},
	{cS, TEMPO_500*5/8},

//*****************

	{g, TEMPO_500*1/2},
	{g, TEMPO_500*1/2},
	{g, TEMPO_500*1/2},
	{g, TEMPO_500*1/2},
	{e, TEMPO_500*1/2},
	{d, TEMPO_500*1/2},
	{cS, TEMPO_500*3},

	{g, TEMPO_500*1/2},
	{g, TEMPO_500*1/2},
	{g, TEMPO_500*1/2},
	{g, TEMPO_500*1/2},
	{e, TEMPO_500*1/2},
	{d, TEMPO_500*1/2},
	{cS, TEMPO_500*3},

//Se repite todo*****

	{d, TEMPO_500*3/8},
	{d, TEMPO_500*3/8},
	{d, TEMPO_500*3/8},
	{cS, TEMPO_500*3/8},
	{d, TEMPO_500*5/8},
	{aL, TEMPO_500*5/4},

	{d, TEMPO_500*3/8},
	{d, TEMPO_500*3/8},
	{cS, TEMPO_500*3/8},
	{d, TEMPO_500*5/8},
	{aL, TEMPO_500*5/8},

//****************

	{fS, TEMPO_500*3/8},
	{fS, TEMPO_500*3/8},
	{fS, TEMPO_500*3/8},
	{e, TEMPO_500*3/8},
	{fS, TEMPO_500*5/8},
	{cS, TEMPO_500*5/4},

	{fS, TEMPO_500*3/8},
	{fS, TEMPO_500*3/8},
	{e, TEMPO_500*3/8},
	{fS, TEMPO_500*5/8},
	{cS, TEMPO_500*5/8},

//*****************

	{g, TEMPO_500*1/2},
	{g, TEMPO_500*1/2},
	{g, TEMPO_500*1/2},
	{g, TEMPO_500*1/2},
	{e, TEMPO_500*1/2},
	{d, TEMPO_500*1/2},
	{cS, TEMPO_500*3},

	{g, TEMPO_500*1/2},
	{g, TEMPO_500*1/2},
	{g, TEMPO_500*1/2},
	{g, TEMPO_500*1/2},
	{e, TEMPO_500*1/2},
	{d, TEMPO_500*1/2},
	{cS, TEMPO_500*3}
	//and we're done
};


//Cardenas Arciniega Jesus Francisco
PROGMEM const struct note DragonBallGT[]={
/*
	{a, TEMPO_500*1/5},
	//	{0, TEMPO_250*1/4},
	{b, TEMPO_500*1/5},
	//	{0, TEMPO_250*1/4},
	{c, TEMPO_500*1/5},
	//	{0, TEMPO_250*1/4},
	{d, TEMPO_500*1/5},
	//	{0, TEMPO_250*1/4},
	{e, TEMPO_500*1/5},
	//	{0, TEMP*1/4},
	{f, TEMPO_500*1/5},
	//	{0, TEMPO_250*1/4},
	{g, TEMPO_500*1/5},
	{a, TEMPO_500*1/5},
	//	{0, TEMPO_250*1/4},
	{b, TEMPO_500*1/5},
	//	{0, TEMPO_250*1/4},
	{c, TEMPO_500*1/5},
	//	{0, TEMPO_250*1/4},
	{d, TEMPO_500*1/5},
	//	{0, TEMPO_250*1/4},
	{e, TEMPO_500*1/5},
	//	{0, TEMP*1/4},
	{f, TEMPO_500*1/5},
	//	{0, TEMPO_250*1/4},
	{g, TEMPO_500*1/5},
	{0, TEMPO_250*2},
*/
	{g, TEMPO_500*1/2},
	{0, TEMPO_250*1/4},
	{g, TEMPO_500*1/2},
	{0, TEMPO_250*3/4},
	{e, TEMPO_500*1/4},
	{0, TEMPO_250*1/4},
	{f, TEMPO_500*1/4},
	{0, TEMPO_250*1/4},
	{g, TEMPO_500*1/4},
	{0, TEMPO_250*1/4},
	{a, TEMPO_500*1/4},
	{0, TEMPO_250*1/4},
	{g, TEMPO_500*1/2},
	{0, TEMPO_250*1/2},
	{f, TEMPO_500*1/2},
	{0, TEMPO_250*1/2},
	{e, TEMPO_500*1/2},
	{0, TEMPO_250*1/2},
	{d, TEMPO_500*1/2},
	{0, TEMPO_250*1/2},
	{e, TEMPO_500*1/2},
	{0, TEMPO_250*1/2},
	{e, TEMPO_500*1/2},
	{0, TEMPO_250},
	{c, TEMPO_500*1/4},
	{0, TEMPO_250*1/4},
	{d, TEMPO_500*1/4},
	{0, TEMPO_250*1/4},
	{e, TEMPO_500*1/4},
	{0, TEMPO_250*1/4},
	{f, TEMPO_500*1/4},
	{0, TEMPO_250*1/2},
	{e, TEMPO_500*1/2},
	{0, TEMPO_250*1/2},
	{d, TEMPO_500*1/2},
	{0, TEMPO_250*1/2},
	{c, TEMPO_500*1/2},
	{0, TEMPO_250*1/2},
	{aa, TEMPO_500*1/2},
	{0, TEMPO_250*1/2},
	{a, TEMPO_500*1/2},
	{0, TEMPO_250*1/2},
	{a, TEMPO_500*1/4},
	{0, TEMPO_250},
	{c, TEMPO_500*1/2},
	{0, TEMPO_250*1/2},
	{a, TEMPO_500*1/2},
	{0, TEMPO_250*1/2},
	{g, TEMPO_500*1/2},
	{0, TEMPO_250*1/2},
	{c, TEMPO_500},
	{0, TEMPO_250},
	{d, TEMPO_500*1/4},
	{0, TEMPO_250*1/4},
	{e, TEMPO_500*1/4},
	{0, TEMPO_250*1/4},
	{f, TEMPO_500*1/2},
	{0, TEMPO_250*1/2},
	{e, TEMPO_500*1/2},
	{0, TEMPO_250*1/2},
	{d, TEMPO_500*1/2},
	{0, TEMPO_250*1/2},
	{c, TEMPO_500*1/2},
	{0, TEMPO_250*1/2},
	{d, TEMPO_500*1/2},
	{0, TEMPO_250*1/2},
	{c, TEMPO_500*1/2},
	{0, TEMPO_250*1/2},

	{0, TEMPO_250},
	{0, TEMPO_500},
	//************************************************
	{cH,TEMPO_500*3/4},
	{0,	TEMPO_250*1/6},
	{cH,TEMPO_500*3/4},
	{0, TEMPO_250*1/4},
	{fH,TEMPO_500*3},
	{0, TEMPO_250*1/4},
	{aH,TEMPO_500*3/4},
	{0, TEMPO_250*1/4},
	{gH,TEMPO_500*3/4},
	{0, TEMPO_250*1/4},
	{fH,TEMPO_500*3/4},
	{0, TEMPO_250*1/4},
	{gH,TEMPO_500*3},
	{0, TEMPO_250},
	{dH,TEMPO_500*1/2},
	{0, TEMPO_250*1/4},
	{eH,TEMPO_500*1/2},
	{0, TEMPO_250*1/2},
	{fH,TEMPO_500},
	{0, TEMPO_250*1/2},
	{fH,TEMPO_500*3/4},
	{0, TEMPO_250*1/4},
	{gH,TEMPO_500*1/4},
	{0, TEMPO_250*1/4},
	{fH,TEMPO_500*1/4},
	{0, TEMPO_250*2},
	{eH,TEMPO_500*1/4},
	{0, TEMPO_250*1/4},
	{0, TEMPO_250*2},

	{cH,TEMPO_500*3/4},
	{0, TEMPO_250*1/6},
	{cH,TEMPO_500*3/4},
	{0, TEMPO_250*1/4},
	{fH,TEMPO_500*3},
	{0, TEMPO_250*1/4},
	{aH,TEMPO_500*3/4},
	{0, TEMPO_250*1/4},
	{gH,TEMPO_500*3/4},
	{0, TEMPO_250*1/4},
	{fH,TEMPO_500*3/4},
	{0, TEMPO_250*1/4},
	{gH,TEMPO_500*3},
	{0, TEMPO_250},
	{dH,TEMPO_500*1/2},
	{0, TEMPO_250*1/4},
	{eH,TEMPO_500*1/2},
	{0, TEMPO_250*1/2},
	{fH,TEMPO_500},
	{0, TEMPO_250*1/2},
	{fH,TEMPO_500*3/4},
	{0, TEMPO_250*1/4},
	{gH,TEMPO_500*1/4},
	{0, TEMPO_250*1/4},
	{fH,TEMPO_500*1/4},
	{0, TEMPO_250*2},
	{eH,TEMPO_500*1/4},
	{0, TEMPO_250*1/4},
};


//Author:Cerezo Nicanor Vicente
PROGMEM const struct note Clocks[]={
	{dSH, TEMPO_500*1/2},
	{aS,  TEMPO_500*1/2},
	{g,  TEMPO_500*1/2},
	{dSH,  TEMPO_500*1/2},
	{aS, TEMPO_500*1/2},
	{g,  TEMPO_500*1/2},
	{dSH, TEMPO_500*1/2},
	{aS, TEMPO_500*1/2},
	{cSH,  TEMPO_500*1/2},
	{aS,  TEMPO_500*1/2},
	{f,  TEMPO_500*1/2},
	{cSH,  TEMPO_500*1/2},
	{aS,  TEMPO_500*1/2},
	{f, TEMPO_500*1/2},
	{cSH,  TEMPO_500*1/2},
	{aS, TEMPO_500*1/2},
	{cSH, TEMPO_500*1/2},
	{aS,  TEMPO_500*1/2},
	{f,  TEMPO_500*1/2},
	{cSH,  TEMPO_500*1/2},
	{aS, TEMPO_500*1/2},
	{f,  TEMPO_500*1/2},
	{cSH,  TEMPO_500*1/2},
	{aS,  TEMPO_500*1/2},
	{c, TEMPO_500*1/2},
	{gS, TEMPO_500*1/2},
	{f,  TEMPO_500*1/2},
	{cH, TEMPO_500*1/2},
	{gS,  TEMPO_500*1/2},
	{f,  TEMPO_500*1/2},
	{cH,  TEMPO_500*1/2},
	{gS,  TEMPO_500*1/2},
	{dSH, TEMPO_500*1/2},
	{aS, TEMPO_500*1/2},
	{g,  TEMPO_500*1/2},
	{dSH, TEMPO_500*1/2},
	{aS, TEMPO_500*1/2},
	{g,  TEMPO_500*1/2},
	{dSH, TEMPO_500*1/2},
	{aS,  TEMPO_500*1/2},
	{cSH,  TEMPO_500*1/2},
	{aS,  TEMPO_500*1/2},
	{f, TEMPO_500*1/2},
	{cSH,  TEMPO_500*1/2},
	{aS,  TEMPO_500*1/2},
	{f,  TEMPO_500*1/2},
	{cSH,  TEMPO_500*1/2},
	{aS,  TEMPO_500*1/2},
	{cSH,  TEMPO_500*1/2},
	{aS,  TEMPO_500*1/2},
	{f,  TEMPO_500*1/2},
	{cSH,  TEMPO_500*1/2},
	{aS,  TEMPO_500*1/2},
	{f, TEMPO_500*1/2},
	{cSH, TEMPO_500*1/2},
	{aS,  TEMPO_500*1/2},
	{cH, TEMPO_500*1/2},
	{gS,  TEMPO_500*1/2},
	{f,  TEMPO_500*1/2},
	{cH, TEMPO_500*1/2},
	{gS,  TEMPO_500*1/2},
	{f, TEMPO_500*1/2},
	{cH, TEMPO_500*1/2},
	{gS,  TEMPO_500*1/2},

	{dSH, TEMPO_500/3},
	{aS, TEMPO_500/3},
	{g, TEMPO_500/3},
	{dSH, TEMPO_500/3},
	{aS, TEMPO_500/3},
	{g, TEMPO_500/3},
	{dSH, TEMPO_500/3},
	{aS, TEMPO_500/3},
	{cSH, TEMPO_500/3},
	{aS, TEMPO_500/3},
	{f, TEMPO_500/3},
	{cSH, TEMPO_500/3},
	{aS, TEMPO_500/3},
	{f, TEMPO_500/3},
	{cSH, TEMPO_500/3},
	{aS, TEMPO_500/3},
	{cSH, TEMPO_500/3},
	{aS, TEMPO_500/3},
	{f, TEMPO_500/3},
	{cSH, TEMPO_500/3},
	{aS, TEMPO_500/3},
	{f, TEMPO_500/3},
	{cSH, TEMPO_500/3},
	{aS, TEMPO_500/3},
	{cH, TEMPO_500/3},
	{gS, TEMPO_500/3},
	{f, TEMPO_500/3},
	{cH, TEMPO_500/3},
	{gS, TEMPO_500/3},
	{f, TEMPO_500/3},
	{cH, TEMPO_500/3},
	{gS, TEMPO_500/3},
	{dSH, TEMPO_500/3},
	{aS, TEMPO_500/3},
	{g, TEMPO_500/3},
	{dSH, TEMPO_500/3},
	{aS, TEMPO_500/3},
	{g, TEMPO_500/3},
	{dSH, TEMPO_500/3},
	{aS, TEMPO_500/3},
	{cSH, TEMPO_500/3},
	{aS, TEMPO_500/3},
	{f, TEMPO_500/3},
	{cSH, TEMPO_500/3},
	{aS, TEMPO_500/3},
	{f, TEMPO_500/3},
	{cSH, TEMPO_500/3},
	{aS, TEMPO_500/3},
	{cSH, TEMPO_500/3},
	{aS, TEMPO_500/3},
	{f, TEMPO_500/3},
	{cSH, TEMPO_500/3},
	{aS, TEMPO_500/4},
	{f, TEMPO_500/3},
	{cSH, TEMPO_500/3},
	{aS, TEMPO_500/3},
	{cH, TEMPO_500/3},
	{gS, TEMPO_500/3},
	{f, TEMPO_500/3},
	{cH, TEMPO_500/3},
	{gS, TEMPO_500/3},
	{f, TEMPO_500/3},
	{cH, TEMPO_500/3},
	{gS, TEMPO_500/3},

	{g, TEMPO_500*3/4},
	{g, TEMPO_500*1/2},
	{g, TEMPO_500*3/4},

	{aS, TEMPO_500*1/4},
	{cSH, TEMPO_500*1/4},
	{cH, TEMPO_500*3/4},
	{f, TEMPO_500*3/4},

	{f, TEMPO_500*3/4},
	{f, TEMPO_500*1/2},
	{f, TEMPO_500*3/4},

	{aS, TEMPO_500*1/6},
	{f, TEMPO_500*1/2},
	{f, TEMPO_500*3/4},
	{g, TEMPO_500*1/2},

	{g, TEMPO_500*3/4},
	{g, TEMPO_500*1/2},
	{g, TEMPO_500*3/4},

	{f, TEMPO_500*1/4},
	{cSH, TEMPO_500*1/4},
	{cH, TEMPO_500*1/4},
	{f, TEMPO_500*3/4},

	{f, TEMPO_500*3/4},
	{f, TEMPO_500*1/2},
	{f, TEMPO_500*3/4},
	{f, TEMPO_500*3/4},

	{dSH, TEMPO_500*1/3},
	{aS,  TEMPO_500*1/3},
	{g,  TEMPO_500*1/3},
	{dSH,  TEMPO_500*1/3},
	{aS, TEMPO_500*1/3},
	{g,  TEMPO_500*1/3},
	{dSH, TEMPO_500*1/3},
	{aS, TEMPO_500*1/3},
	{cSH,  TEMPO_500*1/3},
	{aS,  TEMPO_500*1/3},
	{f,  TEMPO_500*1/3},
	{cSH,  TEMPO_500*1/3},
	{aS,  TEMPO_500*1/3},
	{f, TEMPO_500*1/3},
	{cSH,  TEMPO_500*1/3},
	{aS, TEMPO_500*1/3},
	{cSH, TEMPO_500*1/3},
	{aS,  TEMPO_500*1/3},
	{f,  TEMPO_500*1/3},
	{cSH,  TEMPO_500*1/3},
	{aS, TEMPO_500*1/3},
	{f,  TEMPO_500*1/3},
	{cSH,  TEMPO_500*1/3},
	{aS,  TEMPO_500*1/3},
	{c, TEMPO_500*1/3},
	{gS, TEMPO_500*1/3},
	{f,  TEMPO_500*1/3},
	{cH, TEMPO_500*1/3},
	{gS,  TEMPO_500*1/3},
	{f,  TEMPO_500*1/3},
	{cH,  TEMPO_500*1/3},
	{gS,  TEMPO_500*1/3},
	{dSH, TEMPO_500*1/3},
	{aS, TEMPO_500*1/3},
	{g,  TEMPO_500*1/3},
	{dSH, TEMPO_500*1/3},
	{aS, TEMPO_500*1/3},
	{g,  TEMPO_500*1/3},
	{dSH, TEMPO_500*1/3},
	{aS,  TEMPO_500*1/3},
	{cSH,  TEMPO_500*1/3},
	{aS,  TEMPO_500*1/3},
	{f, TEMPO_500*1/3},
	{cSH,  TEMPO_500*1/3},
	{aS,  TEMPO_500*1/3},
	{f,  TEMPO_500*1/3},
	{cSH,  TEMPO_500*1/3},
	{aS,  TEMPO_500*1/3},
	{cSH,  TEMPO_500*1/3},
	{aS,  TEMPO_500*1/3},
	{f,  TEMPO_500*1/3},
	{cSH,  TEMPO_500*1/3},
	{aS,  TEMPO_500*1/3},
	{f, TEMPO_500*1/3},
	{cSH, TEMPO_500*1/3},
	{aS,  TEMPO_500*1/3},
	{cH, TEMPO_500*1/3},
	{gS,  TEMPO_500*1/3},
	{f,  TEMPO_500*1/3},
	{cH, TEMPO_500*1/3},
	{gS,  TEMPO_500*1/3},
	{f, TEMPO_500*1/3},
	{cH, TEMPO_500*1/3},
	{gS,  TEMPO_500*1/3}
};


PROGMEM const struct note Mario[]={
	//INTRO
	{e, TEMPO_600/4},
	{e, TEMPO_600/4},
	{0, TEMPO_600/4},
	{e, TEMPO_600/4},
	{0, TEMPO_600/4},
	{c, TEMPO_600/4},
	{e, TEMPO_600/4},
	{0, TEMPO_600/4},
	{g, TEMPO_600/4},
	{0, TEMPO_600/4},
	{0, TEMPO_600/2},
	{gL, TEMPO_600/4},
	{0, TEMPO_600/4},
	{0, TEMPO_600/2},
	//PARTE A
	{c, TEMPO_600/4},
	{0, TEMPO_600/4},
	{0, TEMPO_600/4},
	{gL, TEMPO_600/4},
	{0, TEMPO_600/2},
	{eL, TEMPO_600/4},
	{0, TEMPO_600/4},
	{0, TEMPO_600/4},
	{aL, TEMPO_600/4},
	{0, TEMPO_600/4},
	{bL, TEMPO_600/4},
	{0, TEMPO_600/4},
	{aSL, TEMPO_600/4},
	{aL, TEMPO_600/4},
	{0, TEMPO_600/4},
	{gL, TEMPO_600/3},
	{e, TEMPO_600/3},
	{g, TEMPO_600/3},
	{a, TEMPO_600/4},
	{0, TEMPO_600/4},
	{f, TEMPO_600/4},
	{g, TEMPO_600/4},
	{0, TEMPO_600/4},
	{e, TEMPO_600/4},
	{0, TEMPO_600/4},
	{c, TEMPO_600/4},
	{d, TEMPO_600/4},
	{bL, TEMPO_600/4},
	{0, TEMPO_600/2},
	{c, TEMPO_600/4},
	{0, TEMPO_600/4},
	{0, TEMPO_600/4},
	{gL, TEMPO_600/4},
	{0, TEMPO_600/2},
	{eL, TEMPO_600/4},
	{0, TEMPO_600/4},
	{0, TEMPO_600/4},
	{aL, TEMPO_600/4},
	{0, TEMPO_600/4},
	{bL, TEMPO_600/4},
	{0, TEMPO_600/4},
	{aSL, TEMPO_600/4},
	{aL, TEMPO_600/4},
	{0, TEMPO_600/4},
	{gL, TEMPO_600/3},
	{e, TEMPO_600/3},
	{g, TEMPO_600/3},
	{a, TEMPO_600/4},
	{0, TEMPO_600/4},
	{f, TEMPO_600/4},
	{g, TEMPO_600/4},
	{0, TEMPO_600/4},
	{e, TEMPO_600/4},
	{0, TEMPO_600/4},
	{c, TEMPO_600/4},
	{d, TEMPO_600/4},
	{bL, TEMPO_600/4},
	{0, TEMPO_600/2},
	//PARTE B
	{0, TEMPO_600/2},
	{g, TEMPO_600/4},
	{fS,TEMPO_600/4},
	{e, TEMPO_600/4},
	{dS, TEMPO_600/4},
	{0, TEMPO_600/4},
	{e, TEMPO_600/4},
	{0, TEMPO_600/4},
	{gSL, TEMPO_600/4},
	{aL, TEMPO_600/4},
	{c, TEMPO_600/4},
	{0, TEMPO_600/4},
	{aL, TEMPO_600/4},
	{c, TEMPO_600/4},
	{d,TEMPO_600/4},
	{0, TEMPO_600/2},
	{g, TEMPO_600/4},
	{fS, TEMPO_600/4},
	{e, TEMPO_600/4},
	{dS, TEMPO_600/4},
	{0, TEMPO_600/4},
	{e,TEMPO_600/4},
	{0, TEMPO_600/4},
	{cH, TEMPO_600/4},
	{0, TEMPO_600/4},
	{cH, TEMPO_600/4},
	{cH, TEMPO_600/4},
	{0, TEMPO_600/4},
	{0,TEMPO_600/2},
	{0, TEMPO_600/2},
	{g, TEMPO_600/4},
	{fS, TEMPO_600/4},
	{e, TEMPO_600/4},
	{dS, TEMPO_600/4},
	{0, TEMPO_600/4},
	{e,TEMPO_600/4},
	{0, TEMPO_600/4},
	{gSL, TEMPO_600/4},
	{aL, TEMPO_600/4},
	{c, TEMPO_600/4},
	{0, TEMPO_600/4},
	{aL, TEMPO_600/4},
	{c, TEMPO_600/4},
	{d,TEMPO_600/4},
	{0, TEMPO_600/2},
	{dS, TEMPO_600/4},
	{0, TEMPO_600/4},
	{0, TEMPO_600/4},
	{d, TEMPO_600/4},
	{0,TEMPO_600/2},
	{c, TEMPO_600/4},
	{0, TEMPO_600/4},
	{0, TEMPO_600/2},
	{0,TEMPO_600},
	{0, TEMPO_600/2},
	{g, TEMPO_600/4},
	{fS, TEMPO_600/4},
	{e, TEMPO_600/4},
	{dS, TEMPO_600/4},
	{0, TEMPO_600/4},
	{e,TEMPO_600/4},
	{0, TEMPO_600/4},
	{gSL, TEMPO_600/4},
	{aL, TEMPO_600/4},
	{c, TEMPO_600/4},
	{0, TEMPO_600/4},
	{aL, TEMPO_600/4},
	{c, TEMPO_600/4},
	{d,TEMPO_600/4},
	{0, TEMPO_600/2},
	{g, TEMPO_600/4},
	{fS, TEMPO_600/4},
	{e, TEMPO_600/4},
	{dS, TEMPO_600/4},
	{0, TEMPO_600/4},
	{e,TEMPO_600/4},
	{0, TEMPO_600/4},
	{cH, TEMPO_600/4},
	{0, TEMPO_600/4},
	{cH, TEMPO_600/4},
	{cH, TEMPO_600/4},
	{0, TEMPO_600/4},
	{0,TEMPO_600/2},
	{0, TEMPO_600/2},
	{g, TEMPO_600/4},
	{fS, TEMPO_600/4},
	{e, TEMPO_600/4},
	{dS, TEMPO_600/4},
	{0, TEMPO_600/4},
	{e,TEMPO_600/4},
	{0, TEMPO_600/4},
	{gSL, TEMPO_600/4},
	{aL, TEMPO_600/4},
	{c, TEMPO_600/4},
	{0, TEMPO_600/4},
	{aL, TEMPO_600/4},
	{c, TEMPO_600/4},
	{d,TEMPO_600/4},
	{0, TEMPO_600/2},
	{dS, TEMPO_600/4},
	{0, TEMPO_600/4},
	{0, TEMPO_600/4},
	{d, TEMPO_600/4},
	{0,TEMPO_600/2},
	{c, TEMPO_600/4},
	{0, TEMPO_600/4},
	{0, TEMPO_600/2},
	{0,TEMPO_600},
	//PARTE C
	{c, TEMPO_600/4},
	{c, TEMPO_600/4},
	{0, TEMPO_600/4},
	{c, TEMPO_600/4},
	{0, TEMPO_600/4},
	{c, TEMPO_600/4},
	{d, TEMPO_600/4},
	{0, TEMPO_600/4},
	{e, TEMPO_600/4},
	{c, TEMPO_600/4},
	{0, TEMPO_600/4},
	{aL, TEMPO_600/4},
	{gL, TEMPO_600/4},
	{0,TEMPO_600/4},
	{0,TEMPO_600/2},
	{c, TEMPO_600/4},
	{c, TEMPO_600/4},
	{0, TEMPO_600/4},
	{c, TEMPO_600/4},
	{0, TEMPO_600/4},
	{c, TEMPO_600/4},
	{d, TEMPO_600/4},
	{e,TEMPO_600/4},
	{0,TEMPO_600*2},
	{c, TEMPO_600/4},
	{c, TEMPO_600/4},
	{0, TEMPO_600/4},
	{c, TEMPO_600/4},
	{0, TEMPO_600/4},
	{c, TEMPO_600/4},
	{d, TEMPO_600/4},
	{0, TEMPO_600/4},
	{e, TEMPO_600/4},
	{c, TEMPO_600/4},
	{0, TEMPO_600/4},
	{aL, TEMPO_600/4},
	{gL, TEMPO_600/4},
	{0, TEMPO_600/4},
	{0,TEMPO_600/2},
	{e, TEMPO_600/4},
	{e, TEMPO_600/4},
	{0, TEMPO_600/4},
	{e, TEMPO_600/4},
	{0, TEMPO_600/4},
	{c, TEMPO_600/4},
	{e, TEMPO_600/4},
	{0,TEMPO_600/4},
	{g, TEMPO_600/4},
	{0, TEMPO_600/4},
	{0, TEMPO_600/2},
	{gL, TEMPO_600/4},
	{0, TEMPO_600/4},
	{0, TEMPO_600/2},
	//PARTE D
	{e, TEMPO_600/4},
	{c, TEMPO_600/4},
	{0, TEMPO_600/4},
	{gL, TEMPO_600/4},
	{0, TEMPO_600/2},
	{gSL, TEMPO_600/4},
	{0,TEMPO_600/4},
	{aL, TEMPO_600/4},
	{f, TEMPO_600/4},
	{0, TEMPO_600/4},
	{f, TEMPO_600/4},
	{aL, TEMPO_600/4},
	{0, TEMPO_600/4},
	{0,TEMPO_600/2},
	{bL, TEMPO_600/3},
	{a, TEMPO_600/3},
	{a, TEMPO_600/3},
	{a, TEMPO_600/3},
	{g, TEMPO_600/3},
	{f,TEMPO_600/3},
	{e, TEMPO_600/4},
	{c, TEMPO_600/4},
	{0, TEMPO_600/4},
	{aL, TEMPO_600/4},
	{gL, TEMPO_600/4},
	{0, TEMPO_600/4},
	{0,TEMPO_600/2},
	{e, TEMPO_600/4},
	{c, TEMPO_600/4},
	{0, TEMPO_600/4},
	{gL, TEMPO_600/4},
	{0, TEMPO_600/2},
	{gSL, TEMPO_600/4},
	{0,TEMPO_600/4},
	{aL, TEMPO_600/4},
	{f, TEMPO_600/4},
	{0, TEMPO_600/4},
	{f, TEMPO_600/4},
	{aL, TEMPO_600/4},
	{0, TEMPO_600/4},
	{0,TEMPO_600/2},
	{bL, TEMPO_600/4},
	{f, TEMPO_600/4},
	{0, TEMPO_600/4},
	{f, TEMPO_600/4},
	{f, TEMPO_600/3},
	{e, TEMPO_600/3},
	{d,TEMPO_600/3},
	{c, TEMPO_600/4},
	{eL, TEMPO_600/4},
	{0, TEMPO_600/4},
	{eL, TEMPO_600/4},
	{cL, TEMPO_600/4},
	{0, TEMPO_600/4},
	{0, TEMPO_600/2}
};

/*List of songs*/
PGM_P const playlist[] = {
	ImperialMarch,
	AngelesAzules,
	DragonBallGT,
	Clocks,
	Mario
};

/*Quantity of notes of every song in the playlist*/
const uint16_t songs_size[] ={
	ARRAY_SIZE(ImperialMarch),
	ARRAY_SIZE(AngelesAzules),
	ARRAY_SIZE(DragonBallGT),
	ARRAY_SIZE(Clocks),
	ARRAY_SIZE(Mario),
};

const uint8_t songs_counter = ARRAY_SIZE(songs_size);
uint8_t song_idx = 0;
song_t current_song ;
