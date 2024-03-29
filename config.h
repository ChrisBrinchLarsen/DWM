/* See LICENSE file for copyright and license details. */
#import "masterConfig.h"

/* appearance */
static const unsigned int borderpx  = borderSize;        /* border pixel of windows */
static const unsigned int gappx     = gapSize;        /* gaps between windows */
static const unsigned int snap      = snapTicks;       /* snap pixel */
static const int showbar            = barEnabled;        /* 0 means no bar */
static const int topbar             = barAtTop;        /* 0 means bottom bar */
static const char *fonts[]          = { dwmFont };
// static const char *dmenufont         = dmenuFont; // We don't use this but represses an error
static const unsigned int baralpha  = dwmAlpha; // 90% opaque
static const unsigned int borderalpha = OPAQUE;

// static const char lightGreen[8]       = mainColorLight;
// static const char almostLightGreen[8] = mainColorLessLight;
// static const char darkGreen[8]        = mainColorDark;
// static const char almostDarkGreen[8]  = mainColorLessDark;

static const char *colors[][3]      = {
	/*               fg                       bg                  border            */
	[SchemeNorm] = { mainColorLight, mainColorDark,   mainColorDark  },
	[SchemeSel]  = { mainColorDark,  mainColorLight,  mainColorLight },
	[SchemeTitle]= { mainColorLight, mainColorDark,   mainColorDark  },
};
static const unsigned int alphas[][3] = {
	/*               fg      bg        border     */
	[SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha },
	[SchemeTitle]= { OPAQUE, baralpha, borderalpha },
};


/* tagging */
static const char *tags[] = { ws1, ws2, ws3, ws4, ws5, ws6, ws7, ws8, ws9 };

/* Lockfile */
static char lockfile[] = "/tmp/dwm.lock";

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/*      class    instance  title  tags mask  isfloating  monitor (0=main, 1=second) */
	    {  "steam" ,   NULL,   NULL,   1 << 3,       0,         0 },
	    { "Lutris" ,   NULL,   NULL,   1 << 3,       0,         0 },
	    { "heroic" ,   NULL,   NULL,   1 << 3,       0,         0 },
        {"obsidian",   NULL,   NULL,   1 << 2,       0,         0 },
        {  "Code"  ,   NULL,   NULL,   1 << 6,       0,         0 },
    	{ "discord",   NULL,   NULL,   1 << 4,       0,         1 },
	    { "Spotify",   NULL,   NULL,   1 << 8,       0,         1 },
        {"Zathura" ,   NULL,   NULL,   1 << 2,       0,         1 },

};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int attachbelow = 1;    /* 1 means attach after the currently active window */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ tiledIcon,      tile },    /* first entry is default */
	{ floatingIcon,   NULL },    /* no layout function means floating behavior */
	{ monocleIcon,    monocle },
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
// Look at these two below to understand how to make commands that spawn on a specific monitor
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dwmFont[0], "-nb", mainColorLessLight, "-nf", mainColorLessDark, "-sb", mainColorLight, "-sf", mainColorDark, NULL };



static const char *termcmd[]  = { terminal, NULL };
static const char *dmenucmdnew[]  = { "dmenu_run", NULL};
static const char *browsercmd[]   = { browser, NULL};
static const char *qalccmd[]      = { "=", NULL};

static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_F12,    spawn,          SHCMD("systemctl suspend") },
	{ MODKEY,			XK_p,      spawn,          {.v = dmenucmdnew } },
	{ MODKEY,			XK_b,      spawn,          {.v = browsercmd } },
	{ MODKEY,			XK_0,      spawn,          {.v = qalccmd } },
	//{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	//{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY|ShiftMask,             XK_f,      togglefullscr,  {0} },
	//{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

