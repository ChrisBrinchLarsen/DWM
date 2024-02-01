#ifndef masterConfig_H_   /* Include guard */
#define masterConfig_H_

// Colorscheme
static const char mainColorLight[]     = "#30FFA4";
static const char mainColorLessLight[] = "#5FBE92";
static const char mainColorLessDark[]  = "#044B4A";
static const char mainColorDark[]      = "#031624";

// Fonts
static const char dmenuFont[] = "RobotoMono Nerd Font:style=Bold:pixelsize=16:antialias=true:autohint=true";
static const char stFont[]     = "JetBrains Mono Medium:pixelsize=16:antialias=true:autohint=true";
static char *backUpFonts[] = {
    "Hack Nerd Font Propo:pixelsize=19:antialias=true:autohint=true", // Nerd Icons
    "Noto Color Emoji:pixelsize=16:antialias=true:autohint=true",     // Emojies
    //"Source Han Sans JP:pixelsize=16:antialias=true:autohint=true",   // Japanese
     //"OpenMoji Color:pixelsize=16:antialias=true:autohint=true",    // Other emoji variants
    // "Twemoji:pixelsize=16:antialias=true:autohint=true",           // Other emoji variants
    //"JoyPixels:pixelsize=16:antialias=true:autohint=true",         // Other emoji variants
};

// Opacity (Picom has to be running)
static const unsigned int dmenuAlpha  = 0xA6; // 65%
static const float stFocused   = 0.9;
static const float stUnfocused = 0.7;

// dmenu configuration
static const int topOrBottom      = 1;   // 1 for top, 0 for bottom (doesn't matter if centered enabled)
static const int dmenuCentered    = 1;   // 0 for non centered, 1 for centered
static const int dmenuMinWidth    = 250; // Minimum width of dmenu
static const int dmenuLines       = 5;   // amount of horizontal lines in menu
static const int dmenuBorderWidth = 2;   // Width of the dmenu border                               
// TODO: Add support for the partly highlighted colors, they're just yellow rn

// st configuration
static const int stborderpx = 1; // Pixels from text to edge
static const unsigned int cursorType = 2; // 2 = "█", 4 = "_", 6 = "|", 7 = "☃"


// slstatus configuration
static const unsigned int updateInterval    = 1000; // Update interval tick rate
static const char pathToHome[]       = "/home/zupreme/"; // Used to display disk-space
static const char pathToPkgCountTXT[] = "/home/zupreme/suckless/slstatus/pkgCount.txt"; // Used to display amount of currently downloaded packages
// TODO: Add support for choosing icons for the individual status elements


#endif

// Hex Alpha Percentage conversion
// 100% — FF
// 99% — FC
// 98% — FA
// 97% — F7
// 96% — F5
// 95% — F2
// 94% — F0
// 93% — ED
// 92% — EB
// 91% — E8
// 90% — E6
// 89% — E3
// 88% — E0
// 87% — DE
// 86% — DB
// 85% — D9
// 84% — D6
// 83% — D4
// 82% — D1
// 81% — CF
// 80% — CC
// 79% — C9
// 78% — C7
// 77% — C4
// 76% — C2
// 75% — BF
// 74% — BD
// 73% — BA
// 72% — B8
// 71% — B5
// 70% — B3
// 69% — B0
// 68% — AD
// 67% — AB
// 66% — A8
// 65% — A6
// 64% — A3
// 63% — A1
// 62% — 9E
// 61% — 9C
// 60% — 99
// 59% — 96
// 58% — 94
// 57% — 91
// 56% — 8F
// 55% — 8C
// 54% — 8A
// 53% — 87
// 52% — 85
// 51% — 82
// 50% — 80
// 49% — 7D
// 48% — 7A
// 47% — 78
// 46% — 75
// 45% — 73
// 44% — 70
// 43% — 6E
// 42% — 6B
// 41% — 69
// 40% — 66
// 39% — 63
// 38% — 61
// 37% — 5E
// 36% — 5C
// 35% — 59
// 34% — 57
// 33% — 54
// 32% — 52
// 31% — 4F
// 30% — 4D
// 29% — 4A
// 28% — 47
// 27% — 45
// 26% — 42
// 25% — 40
// 24% — 3D
// 23% — 3B
// 22% — 38
// 21% — 36
// 20% — 33
// 19% — 30
// 18% — 2E
// 17% — 2B
// 16% — 29
// 15% — 26
// 14% — 24
// 13% — 21
// 12% — 1F
// 11% — 1C
// 10% — 1A
// 9% — 17
// 8% — 14
// 7% — 12
// 6% — 0F
// 5% — 0D
// 4% — 0A
// 3% — 08
// 2% — 05
// 1% — 03
// 0% — 00
