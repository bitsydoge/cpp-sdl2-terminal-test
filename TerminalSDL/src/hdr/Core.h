#pragma once
#include "Font.h"

typedef struct {

	bool quit;

	////////////////////////////////////
	// Window

	bool focus;
	int sizew;
	int sizeh;

	// Clavier

	bool key[1024];
	std::string command;

	////////////////////////////////////
	// Souris

	int mousex;
	int mousey;

	// Clic

	bool leftclic;
	int leftclic_position_x;
	int leftclic_position_y;

	bool rightclic;
	int rightclic_position_x;
	int rightclic_position_y;

	// Mouse Wheel

	int wheelup;
	int wheeldown;

	////////////////////////////////////
	// Fichier

	char *filedrop;

} Input;

class Core
{
	private:
		SDL_Window *window;
		SDL_Renderer *render;
		Input input;
		Font font;

	public:
		Core(std::string title, int x, int y);
		SDL_Renderer *GetRender() const;
		SDL_Window *GetWindow() const;
		Font& GetFont();
		Input& GetInput();
		void WindowMinimize() const;
		void Quit();
	void InputReturn();
	void InputReset();
	bool InputButton(const int button);
};

enum
{
	INPUT_UNKNOWN = 0,
	INPUT_A = 4,
	INPUT_B = 5,
	INPUT_C = 6,
	INPUT_D = 7,
	INPUT_E = 8,
	INPUT_F = 9,
	INPUT_G = 10,
	INPUT_H = 11,
	INPUT_I = 12,
	INPUT_J = 13,
	INPUT_K = 14,
	INPUT_L = 15,
	INPUT_M = 16,
	INPUT_N = 17,
	INPUT_O = 18,
	INPUT_P = 19,
	INPUT_Q = 20,
	INPUT_R = 21,
	INPUT_S = 22,
	INPUT_T = 23,
	INPUT_U = 24,
	INPUT_V = 25,
	INPUT_W = 26,
	INPUT_X = 27,
	INPUT_Y = 28,
	INPUT_Z = 29,

	INPUT_1 = 30,
	INPUT_2 = 31,
	INPUT_3 = 32,
	INPUT_4 = 33,
	INPUT_5 = 34,
	INPUT_6 = 35,
	INPUT_7 = 36,
	INPUT_8 = 37,
	INPUT_9 = 38,
	INPUT_0 = 39,

	INPUT_RETURN = 40,
	INPUT_ESCAPE = 41,
	INPUT_BACKSPACE = 42,
	INPUT_TAB = 43,
	INPUT_SPACE = 44,

	INPUT_MINUS = 45,
	INPUT_EQUALS = 46,
	INPUT_LEFTBRACKET = 47,
	INPUT_RIGHTBRACKET = 48,
	INPUT_BACKSLASH = 49, /**< Located at the lower left of the return
						  *   key on ISO keyboards and at the right end
						  *   of the QWERTY row on ANSI keyboards.
						  *   Produces REVERSE SOLIDUS (backslash) and
						  *   VERTICAL LINE in a US layout, REVERSE
						  *   SOLIDUS and VERTICAL LINE in a UK Mac
						  *   layout, NUMBER SIGN and TILDE in a UK
						  *   Windows layout, DOLLAR SIGN and POUND SIGN
						  *   in a Swiss German layout, NUMBER SIGN and
						  *   APOSTROPHE in a German layout, GRAVE
						  *   ACCENT and POUND SIGN in a French Mac
						  *   layout, and ASTERISK and MICRO SIGN in a
						  *   French Windows layout.
						  */
	INPUT_NONUSHASH = 50, /**< ISO USB keyboards actually use this code
						  *   instead of 49 for the same key, but all
						  *   OSes I've seen treat the two codes
						  *   identically. So, as an implementor, unless
						  *   your keyboard generates both of those
						  *   codes and your OS treats them differently,
						  *   you should generate INPUT_BACKSLASH
						  *   instead of this code. As a user, you
						  *   should not rely on this code because SDL
						  *   will never generate it with most (all?)
						  *   keyboards.
						  */
	INPUT_SEMICOLON = 51,
	INPUT_APOSTROPHE = 52,
	INPUT_GRAVE = 53, /**< Located in the top left corner (on both ANSI
					  *   and ISO keyboards). Produces GRAVE ACCENT and
					  *   TILDE in a US Windows layout and in US and UK
					  *   Mac layouts on ANSI keyboards, GRAVE ACCENT
					  *   and NOT SIGN in a UK Windows layout, SECTION
					  *   SIGN and PLUS-MINUS SIGN in US and UK Mac
					  *   layouts on ISO keyboards, SECTION SIGN and
					  *   DEGREE SIGN in a Swiss German layout (Mac:
					  *   only on ISO keyboards), CIRCUMFLEX ACCENT and
					  *   DEGREE SIGN in a German layout (Mac: only on
					  *   ISO keyboards), SUPERSCRIPT TWO and TILDE in a
					  *   French Windows layout, COMMERCIAL AT and
					  *   NUMBER SIGN in a French Mac layout on ISO
					  *   keyboards, and LESS-THAN SIGN and GREATER-THAN
					  *   SIGN in a Swiss German, German, or French Mac
					  *   layout on ANSI keyboards.
					  */
	INPUT_COMMA = 54,
	INPUT_PERIOD = 55,
	INPUT_SLASH = 56,

	INPUT_CAPSLOCK = 57,

	INPUT_F1 = 58,
	INPUT_F2 = 59,
	INPUT_F3 = 60,
	INPUT_F4 = 61,
	INPUT_F5 = 62,
	INPUT_F6 = 63,
	INPUT_F7 = 64,
	INPUT_F8 = 65,
	INPUT_F9 = 66,
	INPUT_F10 = 67,
	INPUT_F11 = 68,
	INPUT_F12 = 69,

	INPUT_PRINTSCREEN = 70,
	INPUT_SCROLLLOCK = 71,
	INPUT_PAUSE = 72,
	INPUT_INSERT = 73, /**< insert on PC, help on some Mac keyboards (but
					   does send code 73, not 117) */
	INPUT_HOME = 74,
	INPUT_PAGEUP = 75,
	INPUT_DELETE = 76,
	INPUT_END = 77,
	INPUT_PAGEDOWN = 78,
	INPUT_RIGHT = 79,
	INPUT_LEFT = 80,
	INPUT_DOWN = 81,
	INPUT_UP = 82,

	INPUT_NUMLOCKCLEAR = 83, /**< num lock on PC, clear on Mac keyboards
							 */
	INPUT_KP_DIVIDE = 84,
	INPUT_KP_MULTIPLY = 85,
	INPUT_KP_MINUS = 86,
	INPUT_KP_PLUS = 87,
	INPUT_KP_ENTER = 88,
	INPUT_KP_1 = 89,
	INPUT_KP_2 = 90,
	INPUT_KP_3 = 91,
	INPUT_KP_4 = 92,
	INPUT_KP_5 = 93,
	INPUT_KP_6 = 94,
	INPUT_KP_7 = 95,
	INPUT_KP_8 = 96,
	INPUT_KP_9 = 97,
	INPUT_KP_0 = 98,
	INPUT_KP_PERIOD = 99,

	INPUT_NONUSBACKSLASH = 100, /**< This is the additional key that ISO
								*   keyboards have over ANSI ones,
								*   located between left shift and Y.
								*   Produces GRAVE ACCENT and TILDE in a
								*   US or UK Mac layout, REVERSE SOLIDUS
								*   (backslash) and VERTICAL LINE in a
								*   US or UK Windows layout, and
								*   LESS-THAN SIGN and GREATER-THAN SIGN
								*   in a Swiss German, German, or French
								*   layout. */
	INPUT_APPLICATION = 101, /**< windows contextual menu, compose */
	INPUT_POWER = 102, /**< The USB document says this is a status flag,
					   *   not a physical key - but some Mac keyboards
					   *   do have a power key. */
	INPUT_KP_EQUALS = 103,
	INPUT_F13 = 104,
	INPUT_F14 = 105,
	INPUT_F15 = 106,
	INPUT_F16 = 107,
	INPUT_F17 = 108,
	INPUT_F18 = 109,
	INPUT_F19 = 110,
	INPUT_F20 = 111,
	INPUT_F21 = 112,
	INPUT_F22 = 113,
	INPUT_F23 = 114,
	INPUT_F24 = 115,
	INPUT_EXECUTE = 116,
	INPUT_HELP = 117,
	INPUT_MENU = 118,
	INPUT_SELECT = 119,
	INPUT_STOP = 120,
	INPUT_AGAIN = 121,   /**< redo */
	INPUT_UNDO = 122,
	INPUT_CUT = 123,
	INPUT_COPY = 124,
	INPUT_PASTE = 125,
	INPUT_FIND = 126,
	INPUT_MUTE = 127,
	INPUT_VOLUMEUP = 128,
	INPUT_VOLUMEDOWN = 129,
	/* not sure whether there's a reason to enable these */
	/*     INPUT_LOCKINGCAPSLOCK = 130,  */
	/*     INPUT_LOCKINGNUMLOCK = 131, */
	/*     INPUT_LOCKINGSCROLLLOCK = 132, */
	INPUT_KP_COMMA = 133,
	INPUT_KP_EQUALSAS400 = 134,

	INPUT_INTERNATIONAL1 = 135, /**< used on Asian keyboards, see
								footnotes in USB doc */
	INPUT_INTERNATIONAL2 = 136,
	INPUT_INTERNATIONAL3 = 137, /**< Yen */
	INPUT_INTERNATIONAL4 = 138,
	INPUT_INTERNATIONAL5 = 139,
	INPUT_INTERNATIONAL6 = 140,
	INPUT_INTERNATIONAL7 = 141,
	INPUT_INTERNATIONAL8 = 142,
	INPUT_INTERNATIONAL9 = 143,
	INPUT_LANG1 = 144, /**< Hangul/English toggle */
	INPUT_LANG2 = 145, /**< Hanja conversion */
	INPUT_LANG3 = 146, /**< Katakana */
	INPUT_LANG4 = 147, /**< Hiragana */
	INPUT_LANG5 = 148, /**< Zenkaku/Hankaku */
	INPUT_LANG6 = 149, /**< reserved */
	INPUT_LANG7 = 150, /**< reserved */
	INPUT_LANG8 = 151, /**< reserved */
	INPUT_LANG9 = 152, /**< reserved */

	INPUT_ALTERASE = 153, /**< Erase-Eaze */
	INPUT_SYSREQ = 154,
	INPUT_CANCEL = 155,
	INPUT_CLEAR = 156,
	INPUT_PRIOR = 157,
	INPUT_RETURN2 = 158,
	INPUT_SEPARATOR = 159,
	INPUT_OUT = 160,
	INPUT_OPER = 161,
	INPUT_CLEARAGAIN = 162,
	INPUT_CRSEL = 163,
	INPUT_EXSEL = 164,

	INPUT_KP_00 = 176,
	INPUT_KP_000 = 177,
	INPUT_THOUSANDSSEPARATOR = 178,
	INPUT_DECIMALSEPARATOR = 179,
	INPUT_CURRENCYUNIT = 180,
	INPUT_CURRENCYSUBUNIT = 181,
	INPUT_KP_LEFTPAREN = 182,
	INPUT_KP_RIGHTPAREN = 183,
	INPUT_KP_LEFTBRACE = 184,
	INPUT_KP_RIGHTBRACE = 185,
	INPUT_KP_TAB = 186,
	INPUT_KP_BACKSPACE = 187,
	INPUT_KP_A = 188,
	INPUT_KP_B = 189,
	INPUT_KP_C = 190,
	INPUT_KP_D = 191,
	INPUT_KP_E = 192,
	INPUT_KP_F = 193,
	INPUT_KP_XOR = 194,
	INPUT_KP_POWER = 195,
	INPUT_KP_PERCENT = 196,
	INPUT_KP_LESS = 197,
	INPUT_KP_GREATER = 198,
	INPUT_KP_AMPERSAND = 199,
	INPUT_KP_DBLAMPERSAND = 200,
	INPUT_KP_VERTICALBAR = 201,
	INPUT_KP_DBLVERTICALBAR = 202,
	INPUT_KP_COLON = 203,
	INPUT_KP_HASH = 204,
	INPUT_KP_SPACE = 205,
	INPUT_KP_AT = 206,
	INPUT_KP_EXCLAM = 207,
	INPUT_KP_MEMSTORE = 208,
	INPUT_KP_MEMRECALL = 209,
	INPUT_KP_MEMCLEAR = 210,
	INPUT_KP_MEMADD = 211,
	INPUT_KP_MEMSUBTRACT = 212,
	INPUT_KP_MEMMULTIPLY = 213,
	INPUT_KP_MEMDIVIDE = 214,
	INPUT_KP_PLUSMINUS = 215,
	INPUT_KP_CLEAR = 216,
	INPUT_KP_CLEARENTRY = 217,
	INPUT_KP_BINARY = 218,
	INPUT_KP_OCTAL = 219,
	INPUT_KP_DECIMAL = 220,
	INPUT_KP_HEXADECIMAL = 221,

	INPUT_LCTRL = 224,
	INPUT_LSHIFT = 225,
	INPUT_LALT = 226, /**< alt, option */
	INPUT_LGUI = 227, /**< windows, command (apple), meta */
	INPUT_RCTRL = 228,
	INPUT_RSHIFT = 229,
	INPUT_RALT = 230, /**< alt gr, option */
	INPUT_RGUI = 231, /**< windows, command (apple), meta */

	INPUT_MODE = 257,    /**< I'm not sure if this is really not covered
						 *   by any of the above, but since there's a
						 *   special KMOD_MODE for it I'm adding it here
						 */

						 /* @} *//* Usage page 0x07 */

								 /**
								 *  \name Usage page 0x0C
								 *
								 *  These values are mapped from usage page 0x0C (USB consumer page).
								 */
								 /* @{ */

								 INPUT_AUDIONEXT = 258,
								 INPUT_AUDIOPREV = 259,
								 INPUT_AUDIOSTOP = 260,
								 INPUT_AUDIOPLAY = 261,
								 INPUT_AUDIOMUTE = 262,
								 INPUT_MEDIASELECT = 263,
								 INPUT_WWW = 264,
								 INPUT_MAIL = 265,
								 INPUT_CALCULATOR = 266,
								 INPUT_COMPUTER = 267,
								 INPUT_AC_SEARCH = 268,
								 INPUT_AC_HOME = 269,
								 INPUT_AC_BACK = 270,
								 INPUT_AC_FORWARD = 271,
								 INPUT_AC_STOP = 272,
								 INPUT_AC_REFRESH = 273,
								 INPUT_AC_BOOKMARKS = 274,

								 /* @} *//* Usage page 0x0C */

										 /**
										 *  \name Walther keys
										 *
										 *  These are values that Christian Walther added (for mac keyboard?).
										 */
										 /* @{ */

										 INPUT_BRIGHTNESSDOWN = 275,
										 INPUT_BRIGHTNESSUP = 276,
										 INPUT_DISPLAYSWITCH = 277, /**< display mirroring/dual display
																	switch, video mode switch */
	INPUT_KBDILLUMTOGGLE = 278,
	INPUT_KBDILLUMDOWN = 279,
	INPUT_KBDILLUMUP = 280,
	INPUT_EJECT = 281,
	INPUT_SLEEP = 282,

	INPUT_APP1 = 283,
	INPUT_APP2 = 284,

	/* @} *//* Walther keys */

			/**
			*  \name Usage page 0x0C (additional media keys)
			*
			*  These values are mapped from usage page 0x0C (USB consumer page).
			*/
			/* @{ */

			INPUT_AUDIOREWIND = 285,
			INPUT_AUDIOFASTFORWARD = 286,

			/* @} *//* Usage page 0x0C (additional media keys) */

					/* Add any other keys here. */

					INPUT_SCANCODES = 512, /**< not a key, just marks the number of scancodes
										   for array bounds */
	INPUT_OTHER = 600,

	//  Mouse
	INPUT_LEFTCLICK = 601,
	INPUT_RIGHTCLICK = 602,
	INPUT_WHEELUP = 603,
	INPUT_WHEELDOWN = 604
};