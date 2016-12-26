#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <shellapi.h>
#include <time.h>
#include<conio.h>
#pragma comment(lib, "glut32.lib")
#pragma comment(lib, "glaux.lib")
#include <math.h>
#include <windows.h>
#include <gl\glaux.h>


int tempx,tempy;
int tempi,tempj;
int newct=0;
int scoreopen=0;
//**************************sound*************************************
int midx,midy;
int mfx,mfy;
int lmoux,lmouy,rmoux,rmouy;
int ci,cj;
int var;

int aax,aay;
int mposx,mposy;
void save(void);
void newgame(void);
void load(void);
void filemenu();
int box,boy;
void gamewin(void);
int gameoverr=0;
char winarr[26][26];

char strarr[26][26];
int varry[250];
int arr[26][26];
char strar[26][26];
int rightside[26][26];

char tempshowtext[30];
char showtext[30];
int text;
int textvarr;

int timearr[3];
int timestop=1;

int inx[]={-1,-1,-1,0,0,1,1,1};
int iny[]={-1,0,1,-1,1,-1,0,1};

int incorx[]={-16,0,16,-16,16,-16,0,16};
int incory[]={-16,-16,-16,0,0,16,16,16};

int menuopen=0;
int i,j;
int rmd;
int vag;
int level=1;
int cori,corj;
int mineno;
int varnum;
int fileopen=0;
int count,ctr,counttt,countt;
int m,n;
int timenext;

int x,y;
int gameopen=0;
void leftclick(int aa,int aaa,int co,int coo);
int mmm,nnn,z;
int corx,cory,sid,sidd,corxx,coryy;
int flag=0,flagno;

void recursion(int h,int k);
void right(int corxx,int coryy,int mati,int matj);
void gameover();
void drawing(void);
void mineflag(void);
void timenextt(void);
void helpmenu(void);
int helpopen=0;
int high;
int hightime;
int blink=0;
int blin=0;
void blinkk(void);
void filemouse(int mx,int my);

FILE   *hs;FILE *hs1;
void hssave(void);

void hsload(void);

char highscore[3][30]={"siddharth","siddhartha","shidwartha"};
char highscore1[3][4]={"999","999","999"};
int inix;int iniy;



#ifndef __glut_h__
#define __glut_h__

/* Copyright (c) Mark J. Kilgard, 1994, 1995, 1996, 1998. */

/* This program is freely distributable without licensing fees  and is
   provided without guarantee or warrantee expressed or  implied. This
   program is -not- in the public domain. */

#if defined(_WIN32)

/* GLUT 3.7 now tries to avoid including <windows.h>
   to avoid name space pollution, but Win32's <GL/gl.h> 
   needs APIENTRY and WINGDIAPI defined properly. */
# if 0
   /* This would put tons of macros and crap in our clean name space. */
#  define  WIN32_LEAN_AND_MEAN
#  include <windows.h>
# else
   /* XXX This is from Win32's <windef.h> */
#  ifndef APIENTRY
#   define GLUT_APIENTRY_DEFINED
#   if (_MSC_VER >= 800) || defined(_STDCALL_SUPPORTED) || defined(__BORLANDC__)
#    define APIENTRY    __stdcall
#   else
#    define APIENTRY
#   endif
#  endif
   /* XXX This is from Win32's <winnt.h> */
#  ifndef CALLBACK
#   if (defined(_M_MRX000) || defined(_M_IX86) || defined(_M_ALPHA) || defined(_M_PPC)) && !defined(MIDL_PASS)
#    define CALLBACK __stdcall
#   else
#    define CALLBACK
#   endif
#  endif
   /* XXX This is from Win32's <wingdi.h> and <winnt.h> */
#  ifndef WINGDIAPI
#   define GLUT_WINGDIAPI_DEFINED
#   define WINGDIAPI __declspec(dllimport)
#  endif
   /* XXX This is from Win32's <ctype.h> */
#  ifndef _WCHAR_T_DEFINED
typedef unsigned short wchar_t;
#   define _WCHAR_T_DEFINED
#  endif
# endif

/* To disable automatic library usage for GLUT, define GLUT_NO_LIB_PRAGMA
   in your compile preprocessor options. */
# if !defined(GLUT_BUILDING_LIB) && !defined(GLUT_NO_LIB_PRAGMA)
#  pragma comment (lib, "winmm.lib")      /* link with Windows MultiMedia lib */
/* To enable automatic SGI OpenGL for Windows library usage for GLUT,
   define GLUT_USE_SGI_OPENGL in your compile preprocessor options.  */
#  ifdef GLUT_USE_SGI_OPENGL
#   pragma comment (lib, "opengl.lib")    /* link with SGI OpenGL for Windows lib */
#   pragma comment (lib, "glu.lib")       /* link with SGI OpenGL Utility lib */
#   pragma comment (lib, "glut.lib")      /* link with Win32 GLUT for SGI OpenGL lib */
#  else
#   pragma comment (lib, "opengl32.lib")  /* link with Microsoft OpenGL lib */
#   pragma comment (lib, "glu32.lib")     /* link with Microsoft OpenGL Utility lib */
#   pragma comment (lib, "glut32.lib")    /* link with Win32 GLUT lib */
#  endif
# endif

/* To disable supression of annoying warnings about floats being promoted
   to doubles, define GLUT_NO_WARNING_DISABLE in your compile preprocessor
   options. */
# ifndef GLUT_NO_WARNING_DISABLE
#  pragma warning (disable:4244)  /* Disable bogus VC++ 4.2 conversion warnings. */
#  pragma warning (disable:4305)  /* VC++ 5.0 version of above warning. */
# endif

/* Win32 has an annoying issue where there are multiple C run-time
   libraries (CRTs).  If the executable is linked with a different CRT
   from the GLUT DLL, the GLUT DLL will not share the same CRT static
   data seen by the executable.  In particular, atexit callbacks registered
   in the executable will not be called if GLUT calls its (different)
   exit routine).  GLUT is typically built with the
   "/MD" option (the CRT with multithreading DLL support), but the Visual
   C++ linker default is "/ML" (the single threaded CRT).

   One workaround to this issue is requiring users to always link with
   the same CRT as GLUT is compiled with.  That requires users supply a
   non-standard option.  GLUT 3.7 has its own built-in workaround where
   the executable's "exit" function pointer is covertly passed to GLUT.
   GLUT then calls the executable's exit function pointer to ensure that
   any "atexit" calls registered by the application are called if GLUT
   needs to exit.

   Note that the __glut*WithExit routines should NEVER be called directly.
   To avoid the atexit workaround, #define GLUT_DISABLE_ATEXIT_HACK. */

/* XXX This is from Win32's <process.h> */
# if !defined(_MSC_VER) && !defined(__cdecl)
   /* Define __cdecl for non-Microsoft compilers. */
#  define __cdecl
#  define GLUT_DEFINED___CDECL
# endif
# ifndef _CRTIMP
#  ifdef _NTSDK
    /* Definition compatible with NT SDK */
#   define _CRTIMP
#  else
    /* Current definition */
#   ifdef _DLL
#    define _CRTIMP __declspec(dllimport)
#   else
#    define _CRTIMP
#   endif
#  endif
#  define GLUT_DEFINED__CRTIMP
# endif

/* GLUT API entry point declarations for Win32. */
# ifdef GLUT_BUILDING_LIB
#  define GLUTAPI __declspec(dllexport)
# else
#  ifdef _DLL
#   define GLUTAPI __declspec(dllimport)
#  else
#   define GLUTAPI extern
#  endif
# endif

/* GLUT callback calling convention for Win32. */
# define GLUTCALLBACK __cdecl

#endif  /* _WIN32 */

#include <GL/gl.h>
#include <GL/glu.h>

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32)
# ifndef GLUT_BUILDING_LIB
extern _CRTIMP void __cdecl exit(int);
# endif
#else
/* non-Win32 case. */
/* Define APIENTRY and CALLBACK to nothing if we aren't on Win32. */
# define APIENTRY
# define GLUT_APIENTRY_DEFINED
# define CALLBACK
/* Define GLUTAPI and GLUTCALLBACK as below if we aren't on Win32. */
# define GLUTAPI extern
# define GLUTCALLBACK
/* Prototype exit for the non-Win32 case (see above). */
extern void exit(int);
#endif

/**
 GLUT API revision history:
 
 GLUT_API_VERSION is updated to reflect incompatible GLUT
 API changes (interface changes, semantic changes, deletions,
 or additions).
 
 GLUT_API_VERSION=1  First public release of GLUT.  11/29/94

 GLUT_API_VERSION=2  Added support for OpenGL/GLX multisampling,
 extension.  Supports new input devices like tablet, dial and button
 box, and Spaceball.  Easy to query OpenGL extensions.

 GLUT_API_VERSION=3  glutMenuStatus added.

 GLUT_API_VERSION=4  glutInitDisplayString, glutWarpPointer,
 glutBitmapLength, glutStrokeLength, glutWindowStatusFunc, dynamic
 video resize subAPI, glutPostWindowRedisplay, glutKeyboardUpFunc,
 glutSpecialUpFunc, glutIgnoreKeyRepeat, glutSetKeyRepeat,
 glutJoystickFunc, glutForceJoystickFunc (NOT FINALIZED!).
**/
#ifndef GLUT_API_VERSION  /* allow this to be overriden */
#define GLUT_API_VERSION		3
#endif

/**
 GLUT implementation revision history:
 
 GLUT_XLIB_IMPLEMENTATION is updated to reflect both GLUT
 API revisions and implementation revisions (ie, bug fixes).

 GLUT_XLIB_IMPLEMENTATION=1  mjk's first public release of
 GLUT Xlib-based implementation.  11/29/94

 GLUT_XLIB_IMPLEMENTATION=2  mjk's second public release of
 GLUT Xlib-based implementation providing GLUT version 2 
 interfaces.

 GLUT_XLIB_IMPLEMENTATION=3  mjk's GLUT 2.2 images. 4/17/95

 GLUT_XLIB_IMPLEMENTATION=4  mjk's GLUT 2.3 images. 6/?/95

 GLUT_XLIB_IMPLEMENTATION=5  mjk's GLUT 3.0 images. 10/?/95

 GLUT_XLIB_IMPLEMENTATION=7  mjk's GLUT 3.1+ with glutWarpPoitner.  7/24/96

 GLUT_XLIB_IMPLEMENTATION=8  mjk's GLUT 3.1+ with glutWarpPoitner
 and video resize.  1/3/97

 GLUT_XLIB_IMPLEMENTATION=9 mjk's GLUT 3.4 release with early GLUT 4 routines.

 GLUT_XLIB_IMPLEMENTATION=11 Mesa 2.5's GLUT 3.6 release.

 GLUT_XLIB_IMPLEMENTATION=12 mjk's GLUT 3.6 release with early GLUT 4 routines + signal handling.

 GLUT_XLIB_IMPLEMENTATION=13 mjk's GLUT 3.7 beta with GameGLUT support.

 GLUT_XLIB_IMPLEMENTATION=14 mjk's GLUT 3.7 beta with f90gl friend interface.

 GLUT_XLIB_IMPLEMENTATION=15 mjk's GLUT 3.7 beta sync'ed with Mesa <GL/glut.h>
**/
#ifndef GLUT_XLIB_IMPLEMENTATION  /* Allow this to be overriden. */
#define GLUT_XLIB_IMPLEMENTATION	15
#endif

/* Display mode bit masks. */
#define GLUT_RGB			0
#define GLUT_RGBA			GLUT_RGB
#define GLUT_INDEX			1
#define GLUT_SINGLE			0
#define GLUT_DOUBLE			2
#define GLUT_ACCUM			4
#define GLUT_ALPHA			8
#define GLUT_DEPTH			16
#define GLUT_STENCIL			32
#if (GLUT_API_VERSION >= 2)
#define GLUT_MULTISAMPLE		128
#define GLUT_STEREO			256
#endif
#if (GLUT_API_VERSION >= 3)
#define GLUT_LUMINANCE			512
#endif

/* Mouse buttons. */
#define GLUT_LEFT_BUTTON		0
#define GLUT_MIDDLE_BUTTON		1
#define GLUT_RIGHT_BUTTON		2

/* Mouse button  state. */
#define GLUT_DOWN			0
#define GLUT_UP				1

#if (GLUT_API_VERSION >= 2)
/* function keys */
#define GLUT_KEY_F1			1
#define GLUT_KEY_F2			2
#define GLUT_KEY_F3			3
#define GLUT_KEY_F4			4
#define GLUT_KEY_F5			5
#define GLUT_KEY_F6			6
#define GLUT_KEY_F7			7
#define GLUT_KEY_F8			8
#define GLUT_KEY_F9			9
#define GLUT_KEY_F10			10
#define GLUT_KEY_F11			11
#define GLUT_KEY_F12			12
/* directional keys */
#define GLUT_KEY_LEFT			100
#define GLUT_KEY_UP			101
#define GLUT_KEY_RIGHT			102
#define GLUT_KEY_DOWN			103
#define GLUT_KEY_PAGE_UP		104
#define GLUT_KEY_PAGE_DOWN		105
#define GLUT_KEY_HOME			106
#define GLUT_KEY_END			107
#define GLUT_KEY_INSERT			108
#endif

/* Entry/exit  state. */
#define GLUT_LEFT			0
#define GLUT_ENTERED			1

/* Menu usage  state. */
#define GLUT_MENU_NOT_IN_USE		0
#define GLUT_MENU_IN_USE		1

/* Visibility  state. */
#define GLUT_NOT_VISIBLE		0
#define GLUT_VISIBLE			1

/* Window status  state. */
#define GLUT_HIDDEN			0
#define GLUT_FULLY_RETAINED		1
#define GLUT_PARTIALLY_RETAINED		2
#define GLUT_FULLY_COVERED		3

/* Color index component selection values. */
#define GLUT_RED			0
#define GLUT_GREEN			1
#define GLUT_BLUE			2

#if defined(_WIN32)
/* Stroke font constants (use these in GLUT program). */
#define GLUT_STROKE_ROMAN		((void*)0)
#define GLUT_STROKE_MONO_ROMAN		((void*)1)

/* Bitmap font constants (use these in GLUT program). */
#define GLUT_BITMAP_9_BY_15		((void*)2)
#define GLUT_BITMAP_8_BY_13		((void*)3)
#define GLUT_BITMAP_TIMES_ROMAN_10	((void*)4)
#define GLUT_BITMAP_TIMES_ROMAN_24	((void*)5)
#if (GLUT_API_VERSION >= 3)
#define GLUT_BITMAP_HELVETICA_10	((void*)6)
#define GLUT_BITMAP_HELVETICA_12	((void*)7)
#define GLUT_BITMAP_HELVETICA_18	((void*)8)
#endif
#else
/* Stroke font opaque addresses (use constants instead in source code). */
GLUTAPI void *glutStrokeRoman;
GLUTAPI void *glutStrokeMonoRoman;

/* Stroke font constants (use these in GLUT program). */
#define GLUT_STROKE_ROMAN		(&glutStrokeRoman)
#define GLUT_STROKE_MONO_ROMAN		(&glutStrokeMonoRoman)

/* Bitmap font opaque addresses (use constants instead in source code). */
GLUTAPI void *glutBitmap9By15;
GLUTAPI void *glutBitmap8By13;
GLUTAPI void *glutBitmapTimesRoman10;
GLUTAPI void *glutBitmapTimesRoman24;
GLUTAPI void *glutBitmapHelvetica10;
GLUTAPI void *glutBitmapHelvetica12;
GLUTAPI void *glutBitmapHelvetica18;

/* Bitmap font constants (use these in GLUT program). */
#define GLUT_BITMAP_9_BY_15		(&glutBitmap9By15)
#define GLUT_BITMAP_8_BY_13		(&glutBitmap8By13)
#define GLUT_BITMAP_TIMES_ROMAN_10	(&glutBitmapTimesRoman10)
#define GLUT_BITMAP_TIMES_ROMAN_24	(&glutBitmapTimesRoman24)
#if (GLUT_API_VERSION >= 3)
#define GLUT_BITMAP_HELVETICA_10	(&glutBitmapHelvetica10)
#define GLUT_BITMAP_HELVETICA_12	(&glutBitmapHelvetica12)
#define GLUT_BITMAP_HELVETICA_18	(&glutBitmapHelvetica18)
#endif
#endif

/* glutGet parameters. */
#define GLUT_WINDOW_X			((GLenum) 100)
#define GLUT_WINDOW_Y			((GLenum) 101)
#define GLUT_WINDOW_WIDTH		((GLenum) 102)
#define GLUT_WINDOW_HEIGHT		((GLenum) 103)
#define GLUT_WINDOW_BUFFER_SIZE		((GLenum) 104)
#define GLUT_WINDOW_STENCIL_SIZE	((GLenum) 105)
#define GLUT_WINDOW_DEPTH_SIZE		((GLenum) 106)
#define GLUT_WINDOW_RED_SIZE		((GLenum) 107)
#define GLUT_WINDOW_GREEN_SIZE		((GLenum) 108)
#define GLUT_WINDOW_BLUE_SIZE		((GLenum) 109)
#define GLUT_WINDOW_ALPHA_SIZE		((GLenum) 110)
#define GLUT_WINDOW_ACCUM_RED_SIZE	((GLenum) 111)
#define GLUT_WINDOW_ACCUM_GREEN_SIZE	((GLenum) 112)
#define GLUT_WINDOW_ACCUM_BLUE_SIZE	((GLenum) 113)
#define GLUT_WINDOW_ACCUM_ALPHA_SIZE	((GLenum) 114)
#define GLUT_WINDOW_DOUBLEBUFFER	((GLenum) 115)
#define GLUT_WINDOW_RGBA		((GLenum) 116)
#define GLUT_WINDOW_PARENT		((GLenum) 117)
#define GLUT_WINDOW_NUM_CHILDREN	((GLenum) 118)
#define GLUT_WINDOW_COLORMAP_SIZE	((GLenum) 119)
#if (GLUT_API_VERSION >= 2)
#define GLUT_WINDOW_NUM_SAMPLES		((GLenum) 120)
#define GLUT_WINDOW_STEREO		((GLenum) 121)
#endif
#if (GLUT_API_VERSION >= 3)
#define GLUT_WINDOW_CURSOR		((GLenum) 122)
#endif
#define GLUT_SCREEN_WIDTH		((GLenum) 200)
#define GLUT_SCREEN_HEIGHT		((GLenum) 201)
#define GLUT_SCREEN_WIDTH_MM		((GLenum) 202)
#define GLUT_SCREEN_HEIGHT_MM		((GLenum) 203)
#define GLUT_MENU_NUM_ITEMS		((GLenum) 300)
#define GLUT_DISPLAY_MODE_POSSIBLE	((GLenum) 400)
#define GLUT_INIT_WINDOW_X		((GLenum) 500)
#define GLUT_INIT_WINDOW_Y		((GLenum) 501)
#define GLUT_INIT_WINDOW_WIDTH		((GLenum) 502)
#define GLUT_INIT_WINDOW_HEIGHT		((GLenum) 503)
#define GLUT_INIT_DISPLAY_MODE		((GLenum) 504)
#if (GLUT_API_VERSION >= 2)
#define GLUT_ELAPSED_TIME		((GLenum) 700)
#endif
#if (GLUT_API_VERSION >= 4 || GLUT_XLIB_IMPLEMENTATION >= 13)
#define GLUT_WINDOW_FORMAT_ID		((GLenum) 123)
#endif

#if (GLUT_API_VERSION >= 2)
/* glutDeviceGet parameters. */
#define GLUT_HAS_KEYBOARD		((GLenum) 600)
#define GLUT_HAS_MOUSE			((GLenum) 601)
#define GLUT_HAS_SPACEBALL		((GLenum) 602)
#define GLUT_HAS_DIAL_AND_BUTTON_BOX	((GLenum) 603)
#define GLUT_HAS_TABLET			((GLenum) 604)
#define GLUT_NUM_MOUSE_BUTTONS		((GLenum) 605)
#define GLUT_NUM_SPACEBALL_BUTTONS	((GLenum) 606)
#define GLUT_NUM_BUTTON_BOX_BUTTONS	((GLenum) 607)
#define GLUT_NUM_DIALS			((GLenum) 608)
#define GLUT_NUM_TABLET_BUTTONS		((GLenum) 609)
#endif
#if (GLUT_API_VERSION >= 4 || GLUT_XLIB_IMPLEMENTATION >= 13)
#define GLUT_DEVICE_IGNORE_KEY_REPEAT   ((GLenum) 610)
#define GLUT_DEVICE_KEY_REPEAT          ((GLenum) 611)
#define GLUT_HAS_JOYSTICK		((GLenum) 612)
#define GLUT_OWNS_JOYSTICK		((GLenum) 613)
#define GLUT_JOYSTICK_BUTTONS		((GLenum) 614)
#define GLUT_JOYSTICK_AXES		((GLenum) 615)
#define GLUT_JOYSTICK_POLL_RATE		((GLenum) 616)
#endif

#if (GLUT_API_VERSION >= 3)
/* glutLayerGet parameters. */
#define GLUT_OVERLAY_POSSIBLE           ((GLenum) 800)
#define GLUT_LAYER_IN_USE		((GLenum) 801)
#define GLUT_HAS_OVERLAY		((GLenum) 802)
#define GLUT_TRANSPARENT_INDEX		((GLenum) 803)
#define GLUT_NORMAL_DAMAGED		((GLenum) 804)
#define GLUT_OVERLAY_DAMAGED		((GLenum) 805)

#if (GLUT_API_VERSION >= 4 || GLUT_XLIB_IMPLEMENTATION >= 9)
/* glutVideoResizeGet parameters. */
#define GLUT_VIDEO_RESIZE_POSSIBLE	((GLenum) 900)
#define GLUT_VIDEO_RESIZE_IN_USE	((GLenum) 901)
#define GLUT_VIDEO_RESIZE_X_DELTA	((GLenum) 902)
#define GLUT_VIDEO_RESIZE_Y_DELTA	((GLenum) 903)
#define GLUT_VIDEO_RESIZE_WIDTH_DELTA	((GLenum) 904)
#define GLUT_VIDEO_RESIZE_HEIGHT_DELTA	((GLenum) 905)
#define GLUT_VIDEO_RESIZE_X		((GLenum) 906)
#define GLUT_VIDEO_RESIZE_Y		((GLenum) 907)
#define GLUT_VIDEO_RESIZE_WIDTH		((GLenum) 908)
#define GLUT_VIDEO_RESIZE_HEIGHT	((GLenum) 909)
#endif

/* glutUseLayer parameters. */
#define GLUT_NORMAL			((GLenum) 0)
#define GLUT_OVERLAY			((GLenum) 1)

/* glutGetModifiers return mask. */
#define GLUT_ACTIVE_SHIFT               1
#define GLUT_ACTIVE_CTRL                2
#define GLUT_ACTIVE_ALT                 4

/* glutSetCursor parameters. */
/* Basic arrows. */
#define GLUT_CURSOR_RIGHT_ARROW		0
#define GLUT_CURSOR_LEFT_ARROW		1
/* Symbolic cursor shapes. */
#define GLUT_CURSOR_INFO		2
#define GLUT_CURSOR_DESTROY		3
#define GLUT_CURSOR_HELP		4
#define GLUT_CURSOR_CYCLE		5
#define GLUT_CURSOR_SPRAY		6
#define GLUT_CURSOR_WAIT		7
#define GLUT_CURSOR_TEXT		8
#define GLUT_CURSOR_CROSSHAIR		9
/* Directional cursors. */
#define GLUT_CURSOR_UP_DOWN		10
#define GLUT_CURSOR_LEFT_RIGHT		11
/* Sizing cursors. */
#define GLUT_CURSOR_TOP_SIDE		12
#define GLUT_CURSOR_BOTTOM_SIDE		13
#define GLUT_CURSOR_LEFT_SIDE		14
#define GLUT_CURSOR_RIGHT_SIDE		15
#define GLUT_CURSOR_TOP_LEFT_CORNER	16
#define GLUT_CURSOR_TOP_RIGHT_CORNER	17
#define GLUT_CURSOR_BOTTOM_RIGHT_CORNER	18
#define GLUT_CURSOR_BOTTOM_LEFT_CORNER	19
/* Inherit from parent window. */
#define GLUT_CURSOR_INHERIT		100
/* Blank cursor. */
#define GLUT_CURSOR_NONE		101
/* Fullscreen crosshair (if available). */
#define GLUT_CURSOR_FULL_CROSSHAIR	102
#endif

/* GLUT initialization sub-API. */
GLUTAPI void APIENTRY glutInit(int *argcp, char **argv);
#if defined(_WIN32) && !defined(GLUT_DISABLE_ATEXIT_HACK)
GLUTAPI void APIENTRY __glutInitWithExit(int *argcp, char **argv, void (__cdecl *exitfunc)(int));
#ifndef GLUT_BUILDING_LIB
static void APIENTRY glutInit_ATEXIT_HACK(int *argcp, char **argv) { __glutInitWithExit(argcp, argv, exit); }
#define glutInit glutInit_ATEXIT_HACK
#endif
#endif
GLUTAPI void APIENTRY glutInitDisplayMode(unsigned int mode);
#if (GLUT_API_VERSION >= 4 || GLUT_XLIB_IMPLEMENTATION >= 9)
GLUTAPI void APIENTRY glutInitDisplayString(const char *string);
#endif
GLUTAPI void APIENTRY glutInitWindowPosition(int x, int y);
GLUTAPI void APIENTRY glutInitWindowSize(int width, int height);
GLUTAPI void APIENTRY glutMainLoop(void);

/* GLUT window sub-API. */
GLUTAPI int APIENTRY glutCreateWindow(const char *title);
#if defined(_WIN32) && !defined(GLUT_DISABLE_ATEXIT_HACK)
GLUTAPI int APIENTRY __glutCreateWindowWithExit(const char *title, void (__cdecl *exitfunc)(int));
#ifndef GLUT_BUILDING_LIB
static int APIENTRY glutCreateWindow_ATEXIT_HACK(const char *title) { return __glutCreateWindowWithExit(title, exit); }
#define glutCreateWindow glutCreateWindow_ATEXIT_HACK
#endif
#endif
GLUTAPI int APIENTRY glutCreateSubWindow(int win, int x, int y, int width, int height);
GLUTAPI void APIENTRY glutDestroyWindow(int win);
GLUTAPI void APIENTRY glutPostRedisplay(void);
#if (GLUT_API_VERSION >= 4 || GLUT_XLIB_IMPLEMENTATION >= 11)
GLUTAPI void APIENTRY glutPostWindowRedisplay(int win);
#endif
GLUTAPI void APIENTRY glutSwapBuffers(void);
GLUTAPI int APIENTRY glutGetWindow(void);
GLUTAPI void APIENTRY glutSetWindow(int win);
GLUTAPI void APIENTRY glutSetWindowTitle(const char *title);
GLUTAPI void APIENTRY glutSetIconTitle(const char *title);
GLUTAPI void APIENTRY glutPositionWindow(int x, int y);
GLUTAPI void APIENTRY glutReshapeWindow(int width, int height);
GLUTAPI void APIENTRY glutPopWindow(void);
GLUTAPI void APIENTRY glutPushWindow(void);
GLUTAPI void APIENTRY glutIconifyWindow(void);
GLUTAPI void APIENTRY glutShowWindow(void);
GLUTAPI void APIENTRY glutHideWindow(void);
#if (GLUT_API_VERSION >= 3)
GLUTAPI void APIENTRY glutFullScreen(void);
GLUTAPI void APIENTRY glutSetCursor(int cursor);
#if (GLUT_API_VERSION >= 4 || GLUT_XLIB_IMPLEMENTATION >= 9)
GLUTAPI void APIENTRY glutWarpPointer(int x, int y);
#endif

/* GLUT overlay sub-API. */
GLUTAPI void APIENTRY glutEstablishOverlay(void);
GLUTAPI void APIENTRY glutRemoveOverlay(void);
GLUTAPI void APIENTRY glutUseLayer(GLenum layer);
GLUTAPI void APIENTRY glutPostOverlayRedisplay(void);
#if (GLUT_API_VERSION >= 4 || GLUT_XLIB_IMPLEMENTATION >= 11)
GLUTAPI void APIENTRY glutPostWindowOverlayRedisplay(int win);
#endif
GLUTAPI void APIENTRY glutShowOverlay(void);
GLUTAPI void APIENTRY glutHideOverlay(void);
#endif

/* GLUT menu sub-API. */
GLUTAPI int APIENTRY glutCreateMenu(void (GLUTCALLBACK *func)(int));
#if defined(_WIN32) && !defined(GLUT_DISABLE_ATEXIT_HACK)
GLUTAPI int APIENTRY __glutCreateMenuWithExit(void (GLUTCALLBACK *func)(int), void (__cdecl *exitfunc)(int));
#ifndef GLUT_BUILDING_LIB
static int APIENTRY glutCreateMenu_ATEXIT_HACK(void (GLUTCALLBACK *func)(int)) { return __glutCreateMenuWithExit(func, exit); }
#define glutCreateMenu glutCreateMenu_ATEXIT_HACK
#endif
#endif
GLUTAPI void APIENTRY glutDestroyMenu(int menu);
GLUTAPI int APIENTRY glutGetMenu(void);
GLUTAPI void APIENTRY glutSetMenu(int menu);
GLUTAPI void APIENTRY glutAddMenuEntry(const char *label, int value);
GLUTAPI void APIENTRY glutAddSubMenu(const char *label, int submenu);
GLUTAPI void APIENTRY glutChangeToMenuEntry(int item, const char *label, int value);
GLUTAPI void APIENTRY glutChangeToSubMenu(int item, const char *label, int submenu);
GLUTAPI void APIENTRY glutRemoveMenuItem(int item);
GLUTAPI void APIENTRY glutAttachMenu(int button);
GLUTAPI void APIENTRY glutDetachMenu(int button);

/* GLUT window callback sub-API. */
GLUTAPI void APIENTRY glutDisplayFunc(void (GLUTCALLBACK *func)(void));
GLUTAPI void APIENTRY glutReshapeFunc(void (GLUTCALLBACK *func)(int width, int height));
GLUTAPI void APIENTRY glutKeyboardFunc(void (GLUTCALLBACK *func)(unsigned char key, int x, int y));
GLUTAPI void APIENTRY glutMouseFunc(void (GLUTCALLBACK *func)(int button, int state, int x, int y));
GLUTAPI void APIENTRY glutMotionFunc(void (GLUTCALLBACK *func)(int x, int y));
GLUTAPI void APIENTRY glutPassiveMotionFunc(void (GLUTCALLBACK *func)(int x, int y));
GLUTAPI void APIENTRY glutEntryFunc(void (GLUTCALLBACK *func)(int state));
GLUTAPI void APIENTRY glutVisibilityFunc(void (GLUTCALLBACK *func)(int state));
GLUTAPI void APIENTRY glutIdleFunc(void (GLUTCALLBACK *func)(void));
GLUTAPI void APIENTRY glutTimerFunc(unsigned int millis, void (GLUTCALLBACK *func)(int value), int value);
GLUTAPI void APIENTRY glutMenuStateFunc(void (GLUTCALLBACK *func)(int state));
#if (GLUT_API_VERSION >= 2)
GLUTAPI void APIENTRY glutSpecialFunc(void (GLUTCALLBACK *func)(int key, int x, int y));
GLUTAPI void APIENTRY glutSpaceballMotionFunc(void (GLUTCALLBACK *func)(int x, int y, int z));
GLUTAPI void APIENTRY glutSpaceballRotateFunc(void (GLUTCALLBACK *func)(int x, int y, int z));
GLUTAPI void APIENTRY glutSpaceballButtonFunc(void (GLUTCALLBACK *func)(int button, int state));
GLUTAPI void APIENTRY glutButtonBoxFunc(void (GLUTCALLBACK *func)(int button, int state));
GLUTAPI void APIENTRY glutDialsFunc(void (GLUTCALLBACK *func)(int dial, int value));
GLUTAPI void APIENTRY glutTabletMotionFunc(void (GLUTCALLBACK *func)(int x, int y));
GLUTAPI void APIENTRY glutTabletButtonFunc(void (GLUTCALLBACK *func)(int button, int state, int x, int y));
#if (GLUT_API_VERSION >= 3)
GLUTAPI void APIENTRY glutMenuStatusFunc(void (GLUTCALLBACK *func)(int status, int x, int y));
GLUTAPI void APIENTRY glutOverlayDisplayFunc(void (GLUTCALLBACK *func)(void));
#if (GLUT_API_VERSION >= 4 || GLUT_XLIB_IMPLEMENTATION >= 9)
GLUTAPI void APIENTRY glutWindowStatusFunc(void (GLUTCALLBACK *func)(int state));
#endif
#if (GLUT_API_VERSION >= 4 || GLUT_XLIB_IMPLEMENTATION >= 13)
GLUTAPI void APIENTRY glutKeyboardUpFunc(void (GLUTCALLBACK *func)(unsigned char key, int x, int y));
GLUTAPI void APIENTRY glutSpecialUpFunc(void (GLUTCALLBACK *func)(int key, int x, int y));
GLUTAPI void APIENTRY glutJoystickFunc(void (GLUTCALLBACK *func)(unsigned int buttonMask, int x, int y, int z), int pollInterval);
#endif
#endif
#endif

/* GLUT color index sub-API. */
GLUTAPI void APIENTRY glutSetColor(int, GLfloat red, GLfloat green, GLfloat blue);
GLUTAPI GLfloat APIENTRY glutGetColor(int ndx, int component);
GLUTAPI void APIENTRY glutCopyColormap(int win);

/* GLUT state retrieval sub-API. */
GLUTAPI int APIENTRY glutGet(GLenum type);
GLUTAPI int APIENTRY glutDeviceGet(GLenum type);
#if (GLUT_API_VERSION >= 2)
/* GLUT extension support sub-API */
GLUTAPI int APIENTRY glutExtensionSupported(const char *name);
#endif
#if (GLUT_API_VERSION >= 3)
GLUTAPI int APIENTRY glutGetModifiers(void);
GLUTAPI int APIENTRY glutLayerGet(GLenum type);
#endif

/* GLUT font sub-API */
GLUTAPI void APIENTRY glutBitmapCharacter(void *font, int character);
GLUTAPI int APIENTRY glutBitmapWidth(void *font, int character);
GLUTAPI void APIENTRY glutStrokeCharacter(void *font, int character);
GLUTAPI int APIENTRY glutStrokeWidth(void *font, int character);
#if (GLUT_API_VERSION >= 4 || GLUT_XLIB_IMPLEMENTATION >= 9)
GLUTAPI int APIENTRY glutBitmapLength(void *font, const unsigned char *string);
GLUTAPI int APIENTRY glutStrokeLength(void *font, const unsigned char *string);
#endif

/* GLUT pre-built models sub-API */
GLUTAPI void APIENTRY glutWireSphere(GLdouble radius, GLint slices, GLint stacks);
GLUTAPI void APIENTRY glutSolidSphere(GLdouble radius, GLint slices, GLint stacks);
GLUTAPI void APIENTRY glutWireCone(GLdouble base, GLdouble height, GLint slices, GLint stacks);
GLUTAPI void APIENTRY glutSolidCone(GLdouble base, GLdouble height, GLint slices, GLint stacks);
GLUTAPI void APIENTRY glutWireCube(GLdouble size);
GLUTAPI void APIENTRY glutSolidCube(GLdouble size);
GLUTAPI void APIENTRY glutWireTorus(GLdouble innerRadius, GLdouble outerRadius, GLint sides, GLint rings);
GLUTAPI void APIENTRY glutSolidTorus(GLdouble innerRadius, GLdouble outerRadius, GLint sides, GLint rings);
GLUTAPI void APIENTRY glutWireDodecahedron(void);
GLUTAPI void APIENTRY glutSolidDodecahedron(void);
GLUTAPI void APIENTRY glutWireTeapot(GLdouble size);
GLUTAPI void APIENTRY glutSolidTeapot(GLdouble size);
GLUTAPI void APIENTRY glutWireOctahedron(void);
GLUTAPI void APIENTRY glutSolidOctahedron(void);
GLUTAPI void APIENTRY glutWireTetrahedron(void);
GLUTAPI void APIENTRY glutSolidTetrahedron(void);
GLUTAPI void APIENTRY glutWireIcosahedron(void);
GLUTAPI void APIENTRY glutSolidIcosahedron(void);

#if (GLUT_API_VERSION >= 4 || GLUT_XLIB_IMPLEMENTATION >= 9)
/* GLUT video resize sub-API. */
GLUTAPI int APIENTRY glutVideoResizeGet(GLenum param);
GLUTAPI void APIENTRY glutSetupVideoResizing(void);
GLUTAPI void APIENTRY glutStopVideoResizing(void);
GLUTAPI void APIENTRY glutVideoResize(int x, int y, int width, int height);
GLUTAPI void APIENTRY glutVideoPan(int x, int y, int width, int height);

/* GLUT debugging sub-API. */
GLUTAPI void APIENTRY glutReportErrors(void);
#endif

#if (GLUT_API_VERSION >= 4 || GLUT_XLIB_IMPLEMENTATION >= 13)
/* GLUT device control sub-API. */
/* glutSetKeyRepeat modes. */
#define GLUT_KEY_REPEAT_OFF		0
#define GLUT_KEY_REPEAT_ON		1
#define GLUT_KEY_REPEAT_DEFAULT		2

/* Joystick button masks. */
#define GLUT_JOYSTICK_BUTTON_A		1
#define GLUT_JOYSTICK_BUTTON_B		2
#define GLUT_JOYSTICK_BUTTON_C		4
#define GLUT_JOYSTICK_BUTTON_D		8

GLUTAPI void APIENTRY glutIgnoreKeyRepeat(int ignore);
GLUTAPI void APIENTRY glutSetKeyRepeat(int repeatMode);
GLUTAPI void APIENTRY glutForceJoystickFunc(void);

/* GLUT game mode sub-API. */
/* glutGameModeGet. */
#define GLUT_GAME_MODE_ACTIVE           ((GLenum) 0)
#define GLUT_GAME_MODE_POSSIBLE         ((GLenum) 1)
#define GLUT_GAME_MODE_WIDTH            ((GLenum) 2)
#define GLUT_GAME_MODE_HEIGHT           ((GLenum) 3)
#define GLUT_GAME_MODE_PIXEL_DEPTH      ((GLenum) 4)
#define GLUT_GAME_MODE_REFRESH_RATE     ((GLenum) 5)
#define GLUT_GAME_MODE_DISPLAY_CHANGED  ((GLenum) 6)

GLUTAPI void APIENTRY glutGameModeString(const char *string);
GLUTAPI int APIENTRY glutEnterGameMode(void);
GLUTAPI void APIENTRY glutLeaveGameMode(void);
GLUTAPI int APIENTRY glutGameModeGet(GLenum mode);
#endif

#ifdef __cplusplus
}

#endif

#ifdef GLUT_APIENTRY_DEFINED
# undef GLUT_APIENTRY_DEFINED
# undef APIENTRY
#endif

#ifdef GLUT_WINGDIAPI_DEFINED
# undef GLUT_WINGDIAPI_DEFINED
# undef WINGDIAPI
#endif

#ifdef GLUT_DEFINED___CDECL
# undef GLUT_DEFINED___CDECL
# undef __cdecl
#endif

#ifdef GLUT_DEFINED__CRTIMP
# undef GLUT_DEFINED__CRTIMP
# undef _CRTIMP
#endif

#endif                  /* __glut_h__ */

int iScreenHeight, iScreenWidth;
int iMouseX, iMouseY;
int ifft=0;
void (*iAnimFunction[10])(void)={0};
int iAnimCount=0;
int iAnimDelays[10];

int win = 0 ;
void closeWindowMy();
void iDraw();
void iKeyboard(unsigned char);
void iMouseMove(int, int);
void iMouse(int button, int state, int x, int y);
void iSpecialKeyboard(unsigned char);

static void  __stdcall iA0(HWND,unsigned int, unsigned int, unsigned long){iAnimFunction[0]();}
static void  __stdcall iA1(HWND,unsigned int, unsigned int, unsigned long){iAnimFunction[1]();}
static void  __stdcall iA2(HWND,unsigned int, unsigned int, unsigned long){iAnimFunction[2]();}
static void  __stdcall iA3(HWND,unsigned int, unsigned int, unsigned long){iAnimFunction[3]();}
static void  __stdcall iA4(HWND,unsigned int, unsigned int, unsigned long){iAnimFunction[4]();}
static void  __stdcall iA5(HWND,unsigned int, unsigned int, unsigned long){iAnimFunction[5]();}
static void  __stdcall iA6(HWND,unsigned int, unsigned int, unsigned long){iAnimFunction[6]();}
static void  __stdcall iA7(HWND,unsigned int, unsigned int, unsigned long){iAnimFunction[7]();}
static void  __stdcall iA8(HWND,unsigned int, unsigned int, unsigned long){iAnimFunction[8]();}
static void  __stdcall iA9(HWND,unsigned int, unsigned int, unsigned long){iAnimFunction[9]();}
void keyboardHandler2FF(int key, int x, int y)
{
	iSpecialKeyboard(key);
	glutPostRedisplay();
}

void closeWindowMy()
{
	glutDestroyWindow(win);
}

void iSettimer(int msec, void (*f)(void))
{
	int i = iAnimCount;
	
	if(iAnimCount>=10){printf("Error: Maximum number of already timer used.\n");return;}

	iAnimFunction[i] = f;
	iAnimDelays[i] = msec;
	
	if(iAnimCount == 0) SetTimer(0, 0, msec, iA0);
	if(iAnimCount == 1) SetTimer(0, 0, msec, iA1);
	if(iAnimCount == 2) SetTimer(0, 0, msec, iA2);
	if(iAnimCount == 3) SetTimer(0, 0, msec, iA3);
	if(iAnimCount == 4) SetTimer(0, 0, msec, iA4);

	if(iAnimCount == 5) SetTimer(0, 0, msec, iA5);
	if(iAnimCount == 6) SetTimer(0, 0, msec, iA6);
	if(iAnimCount == 7) SetTimer(0, 0, msec, iA7);
	if(iAnimCount == 8) SetTimer(0, 0, msec, iA8);
	if(iAnimCount == 9) SetTimer(0, 0, msec, iA9);
	iAnimCount++;
}

void iShowBMP(int x, int y, char filename[])
{
	AUX_RGBImageRec *TextureImage;

	TextureImage = auxDIBImageLoad(filename);
	
	glRasterPos2f(x, y);
	glDrawPixels(TextureImage->sizeX, TextureImage->sizeY, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	
	free(TextureImage->data);
	free(TextureImage);

}

void iText(GLdouble x, GLdouble y, char *str, void* font=GLUT_BITMAP_8_BY_13)
{ 
   glRasterPos3d(x, y, 0);
   int i;
   for (i=0; str[i]; i++) {
      glutBitmapCharacter(font, str[i]); //,GLUT_BITMAP_8_BY_13, GLUT_BITMAP_TIMES_ROMAN_24
   }
}

void iPoint(double x, double y, int size=0)
{
	int i, j;
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	for(i=x-size;i<x+size;i++)
	{
		for(j=y-size; j<y+size;j++)
		{
			glVertex2f(i, j);
		}
	}
	glEnd();
}

void iLine(double x1, double y1, double x2, double y2)
{
	glBegin(GL_LINE_STRIP);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glEnd();
}

void iFilledPolygon(double x[], double y[], int n)
{
	int i;
	if(n<3)return;
	glBegin(GL_POLYGON);
	for(i = 0; i < n; i++){
		glVertex2f(x[i], y[i]);
	}
	glEnd();		
}

void iPolygon(double x[], double y[], int n)
{
	int i;
	if(n<3)return;
	glBegin(GL_LINE_STRIP);
	for(i = 0; i < n; i++){
		glVertex2f(x[i], y[i]);
	}
	glVertex2f(x[0], y[0]);
	glEnd();		
}

void iRectangle(double left, double bottom, double dx, double dy)
{
	double x1, y1, x2, y2;
	
	x1 = left;
	y1 = bottom;
	x2=x1+dx;
	y2=y1+dy;

	iLine(x1, y1, x2, y1);
	iLine(x2, y1, x2, y2);
	iLine(x2, y2, x1, y2);
	iLine(x1, y2, x1, y1);
}

void iFilledRectangle(double left, double bottom, double dx, double dy)
{
	double xx[4], yy[4];
	double x1, y1, x2, y2;
	
	x1 = left;
	y1 = bottom;
	x2=x1+dx;
	y2=y1+dy;

	xx[0]=x1;
	yy[0]=y1;
	xx[1]=x2;
	yy[1]=y1;
	xx[2]=x2;
	yy[2]=y2;
	xx[3]=x1;
	yy[3]=y2;

	iFilledPolygon(xx, yy, 4);

}

void iFilledCircle(double x, double y, double r, int slices=100)
{
	double t, PI=acos(-1), dt, x1,y1, xp, yp;
	dt = 2*PI/slices;
	xp = x+r;
	yp = y;
	glBegin(GL_POLYGON);
	for(t = 0; t <= 2*PI; t+=dt)
	{
		x1 = x + r * cos(t);
		y1 = y + r * sin(t);

		glVertex2f(xp, yp);
		xp = x1;
		yp = y1;
	}
	glEnd();
}

void iCircle(double x, double y, double r, int slices=100)
{
	double t, PI=acos(-1), dt, x1,y1, xp, yp;
	dt = 2*PI/slices;
	xp = x+r;
	yp = y;
	for(t = 0; t <= 2*PI; t+=dt)
	{
		x1 = x + r * cos(t);
		y1 = y + r * sin(t);
		iLine(xp, yp, x1, y1);
		xp = x1;
		yp = y1;
	}
}

void iEllipse(double x, double y, double a, double b, int slices=100)
{
	double t, PI=acos(-1), dt, x1,y1, xp, yp;
	dt = 2*PI/slices;
	xp = x+a;
	yp = y;
	for(t = 0; t <= 2*PI; t+=dt)
	{
		x1 = x + a * cos(t);
		y1 = y + b * sin(t);
		iLine(xp, yp, x1, y1);
		xp = x1;
		yp = y1;
	}
}

void iFilledEllipse(double x, double y, double a, double b, int slices=100)
{
	double t, PI=acos(-1), dt, x1,y1, xp, yp;
	dt = 2*PI/slices;
	xp = x+a;
	yp = y;
	glBegin(GL_POLYGON);
	for(t = 0; t <= 2*PI; t+=dt)
	{
		x1 = x + a * cos(t);
		y1 = y + b * sin(t);
		glVertex2f(xp, yp);
		xp = x1;
		yp = y1;
	}
	glEnd();
}


void iSetcolor(double r, double g, double b)
{
	glColor3f(r, g, b);
}

void iDelay(int sec)
{
	int t1, t2;
	t1 = time(0);
	while(1){
		t2 = time(0);
		if(t2-t1>=sec)
			break;
	}
}	


void iClear()
{
	glClear( GL_COLOR_BUFFER_BIT) ;
	glMatrixMode(GL_MODELVIEW) ;
	glClearColor(0,0,0,0);
		glFlush();
}

void displayFF(void){

	//iClear();
	iDraw();
	glutSwapBuffers() ;
}



void animFF(void)
{
	//iAnimation();
	if(ifft == 0){
		ifft = 1;
		iClear();
	}
	glutPostRedisplay();
}

void keyboardHandlerFF(unsigned char key, int x, int y)
{
	iKeyboard(key);
	glutPostRedisplay();
}

void mouseMoveHandlerFF(int mx, int my)
{
	iMouseX = mx;
	iMouseY = iScreenHeight - my;
	iMouseMove(iMouseX, iMouseY);

	glFlush();
}

void mouseHandlerFF(int button, int state, int x, int y)
{
	iMouseX = x;
	iMouseY = iScreenHeight - y;

	iMouse(button, state, iMouseX, iMouseY);

	glFlush();
}

void iInitialize(int width=500, int height=500, char *title="iGraphics")
{
	iScreenHeight = height;
	iScreenWidth = width;

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB) ;
	glutInitWindowSize(width , height ) ;
	glutInitWindowPosition( 600 , 100 ) ;
	win = glutCreateWindow(title) ;
	glClearColor( 0.0 , 0.0 , 0.0 , 0.0 ) ;
	glMatrixMode( GL_PROJECTION) ;
	glLoadIdentity() ;
	glOrtho(0.0 , width , 0.0 , height , -1.0 , 1.0) ;
	//glOrtho(-100.0 , 100.0 , -100.0 , 100.0 , -1.0 , 1.0) ;
	//SetTimer(0, 0, 10, timer_proc);
		
	iClear();

	glutDisplayFunc(displayFF) ;
	glutKeyboardFunc(keyboardHandlerFF);
	glutMouseFunc(mouseHandlerFF);
	glutMotionFunc(mouseMoveHandlerFF);	
	glutIdleFunc(animFF) ;

	glutMainLoop() ;
}

/*int main()
{
	iInitialize(600, 600);

	return 0 ;
}*/
void hssave(void)
{

	hs=fopen("highscore.txt","wb");
	fwrite(highscore,sizeof highscore,1,hs);

	hs1=fopen("highscore1.txt","wb");

	fwrite(highscore1,sizeof highscore1,1,hs1);

	fclose(hs);
	fclose(hs1);
}

void hsload(void)
{

	hs=fopen("highscore.txt","rb");
	fread(highscore,sizeof highscore,1,hs);

	hs1=fopen("highscore1.txt","rb");
	fread(highscore1,sizeof highscore1,1,hs1);

	fclose(hs1);

	fclose(hs);
}

/*Left click.........*/

void leftclick(int aa,int aaa,int co,int coo)
{	
	if((lmoux>aa&&lmoux<(aa+16)&&lmouy>aaa&&lmouy<(aaa+16))&&(arr[co][coo]<=8)&&(arr[co][coo]>=0))
	{

		counttt=0;
		for(z=0;z<8;z++)
		{
			mmm=co+inx[z];nnn=coo+iny[z];
			if(mmm>=0&&mmm<cori&&nnn>=0&&nnn<cori)
			{
				if(strar[mmm][nnn]=='*')
					counttt++;
			}

		}
		countt=0;
		for(z=0;z<8;z++)
		{
			mmm=co+inx[z];nnn=coo+iny[z];
			if(mmm>=0&&mmm<cori&&nnn>=0&&nnn<cori)
			{
				if(arr[mmm][nnn]==11)
					countt++;
			}

		}
		if(countt==counttt)
		{

			for(z=0;z<8;z++)
			{
				mmm=co+inx[z];nnn=coo+iny[z];
				if(mmm>=0&&mmm<cori&&nnn>=0&&nnn<cori)
				{	
					if(arr[mmm][nnn]==11)arr[mmm][nnn]=11;
					else if(strar[mmm][nnn]=='*')
						arr[mmm][nnn]=-1;
					else
						arr[mmm][nnn]=strar[mmm][nnn]-48;
				}

			}
		}
	}


	else if(lmoux>aa&&lmoux<(aa+16)&&lmouy>aaa&&lmouy<(aaa+16)&&strar[co][coo]=='*')
	{
		arr[co][coo]=-1;

	}
	else if(lmoux>aa&&lmoux<(aa+16)&&lmouy>aaa&&lmouy<(aaa+16))
	{	
		arr[co][coo]=strar[co][coo]-48;
	}

}
void middleclick(int aa,int aaa,int co,int coo)
{
	if((midx>aa&&midx<(aa+16)&&midy>aaa&&midy<(aaa+16))&&(arr[co][coo]<=8)&&(arr[co][coo]>=0))
	{

		counttt=0;
		for(z=0;z<8;z++)
		{
			mmm=co+inx[z];nnn=coo+iny[z];
			if(mmm>=0&&mmm<cori&&nnn>=0&&nnn<cori)
			{
				if(strar[mmm][nnn]=='*')
					counttt++;
			}

		}
		countt=0;
		for(z=0;z<8;z++)
		{
			mmm=co+inx[z];nnn=coo+iny[z];
			if(mmm>=0&&mmm<cori&&nnn>=0&&nnn<cori)
			{
				if(arr[mmm][nnn]==11)
					countt++;
			}

		}
		if(countt==counttt)
		{

			for(z=0;z<8;z++)
			{
				mmm=co+inx[z];nnn=coo+iny[z];
				if(mmm>=0&&mmm<cori&&nnn>=0&&nnn<cori)
				{	
					if(arr[mmm][nnn]==11)arr[mmm][nnn]=11;
					else if(strar[mmm][nnn]=='*')
						arr[mmm][nnn]=-1;
					else
						arr[mmm][nnn]=strar[mmm][nnn]-48;
				}

			}
		}
		else
		{
			newct++;
			for(z=0;z<8;z++)
			{
				mmm=co+inx[z];nnn=coo+iny[z];
				if(mmm>=0&&mmm<cori&&nnn>=0&&nnn<cori)
					if(arr[mmm][nnn]==10)
						arr[mmm][nnn]=15;
			}
		}

	}
	else if((midx>aa&&midx<(aa+16)&&midy>aaa&&midy<(aaa+16))&&arr[co][coo]==10)
	{
			newct++;
			for(z=0;z<8;z++)
			{
				mmm=co+inx[z];nnn=coo+iny[z];
				if(mmm>=0&&mmm<cori&&nnn>=0&&nnn<cori)	
					if(arr[mmm][nnn]==10)
						arr[mmm][nnn]=15;
			}

	}
	
}


void rightclick(int bb,int bbb,int doo,int dooo)
{	
	if(rmoux>bb&&rmoux<(bb+16)&&rmouy>bbb&&rmouy<(bbb+16))
	{	
		if(arr[doo][dooo]>=10)
		{
		if(rightside[doo][dooo]==2)
			arr[doo][dooo]=11;
		else if(rightside[doo][dooo]==3)
			arr[doo][dooo]=12;
		else if(rightside[doo][dooo]==1)
			arr[doo][dooo]=10;
		}
	}
}
/*for flag and?......*/

void right(int corxx,int coryy,int mati,int matj)
{	
	if(rmoux>corxx&&rmoux<(corxx+16)&&rmouy>coryy&&rmouy<(coryy+16))
	{	
		rightside[mati][matj]++;
		if(rightside[mati][matj]>3)
			rightside[mati][matj]=rightside[mati][matj]-3;

	}
}


void filemenu()
{
	inix=box-10;iniy=boy+cori*16+120;

	iShowBMP(0,iniy-32,"bkg.bmp");
	iShowBMP(600,iniy-32,"bkg.bmp");


	iText(10,iniy-32+10,"File",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(60,iniy-32+10,"Help",GLUT_BITMAP_TIMES_ROMAN_24);
	

	if(lmoux>10&&lmoux<50&&lmouy>(iniy-32)&&lmouy<iniy)
	{
		fileopen=1;
		scoreopen=0;
		menuopen=0;
			
		iShowBMP(10,iniy-32-32,"button.bmp");
		iShowBMP(10,iniy-32-32-32,"button.bmp");
		iShowBMP(10,iniy-32-32-32-32,"button.bmp");
		iShowBMP(10,iniy-32-32-32-32-32,"button.bmp");
		iShowBMP(10,iniy-32-32-32-32-32-32,"button.bmp");
		iShowBMP(10,iniy-32-32-32-32-32-32-32,"button.bmp");


		iText(15,iniy-32-32+10,"New",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(15,iniy-32-32-32+10,"Beginner",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(12,iniy-32-32-32-32+10,"Medium",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(15,iniy-32-32-32-32-32+10,"Expert",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(15,iniy-32-32-32-32-32-32+10,"Best times",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(15,iniy-32-32-32-32-32-32-32+10,"Exit",GLUT_BITMAP_TIMES_ROMAN_24);	
	}
	else if(fileopen==1&&lmoux>10&&lmoux<150&&lmouy>(iniy-32-32-32-32-32-32)&&lmouy<((iniy-32-32-32-32)))
	{
			hsload();
			scoreopen=1;
			iShowBMP(0,0+16+16+16,"congi.bmp");
			iShowBMP(0,0+16+16,"congi.bmp");
			iShowBMP(0,0+16,"congi.bmp");
			iShowBMP(0,0,"congi.bmp");

			iText(70+90,0+16+16+16+3,highscore1[0],GLUT_BITMAP_8_BY_13);
			iText(70,0+16+16+16+3,highscore[0],GLUT_BITMAP_8_BY_13);
			iText(3,0+16+16+16+3,"Begineer",GLUT_BITMAP_8_BY_13);

			iText(70+90,0+16+16+3,highscore1[1],GLUT_BITMAP_8_BY_13);
			iText(70,0+16+16+3,highscore[1],GLUT_BITMAP_8_BY_13);
			iText(3,0+16+16+3,"Medium",GLUT_BITMAP_8_BY_13);

			iText(70+90,0+16+3,highscore1[2],GLUT_BITMAP_8_BY_13);
			iText(70,0+16+3,highscore[2],GLUT_BITMAP_8_BY_13);
			iText(3,0+16+3,"Expert",GLUT_BITMAP_8_BY_13);

		iText(0,3,"Reset all records......",GLUT_BITMAP_8_BY_13);

		
	}
	if(scoreopen==1&&(lmoux<10||lmoux>150||lmouy<(iniy-32-32-32-32-32-32)||lmouy>(iniy-32-32-32-32)))
	{
		fileopen=0;
		if(lmoux>0&&lmoux<128&&lmouy>3&&lmouy<64)
		{
			strcpy(highscore1[0],"999");
			strcpy(highscore[0],"Siddharth");
			
			strcpy(highscore1[1],"999");
			strcpy(highscore[1],"Siddhartha");
			
			strcpy(highscore1[2],"999");
			strcpy(highscore[2],"Shidwartha");
			hssave();
		}
	}

	else if(fileopen==1&&scoreopen==0&&lmoux>10&&lmoux<150&&lmouy>(iniy-32-32-32-32-32-32-32)&&lmouy<(iniy-32-32-32-32-32-32)) 
	{
		FILE *fp;
		fp=fopen("gamelevel.txt","w");
		fprintf(fp,"%d",level);
		fclose(fp);
		exit(0);
	}
}

void helpmenu(void)
{
//	if(lmoux<60||lmoux||(60+140)||lmouy<(iniy-32-32-32-32)||lmouy>iniy)menuopen=0;

	if(lmoux>60&&lmoux<(60+60)&&lmouy>(iniy-32)&&lmouy<iniy)
	{
		menuopen=1;
		fileopen=0;

		iShowBMP(60,iniy-32-32,"button.bmp");
		iShowBMP(60,iniy-32-32-32,"button.bmp");
		iShowBMP(60,iniy-32-32-32-32,"button.bmp");
		iShowBMP(60,iniy-32-32-32-32-32,"button.bmp");

		iText(65,iniy-32-32+10,"Load game",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(65,iniy-32-32-32+10,"Save game",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(65,iniy-32-32-32-32+10,"Rule",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(65,iniy-32-32-32-32-32+10,"About",GLUT_BITMAP_TIMES_ROMAN_24);
	}

	if(menuopen==1&&lmoux>60&&lmoux<(60+140)&&lmouy>(iniy-32-32-32)&&lmouy<iniy-32-32)
	{
		fileopen=0;
		text=1;
		iShowBMP(10,10,"savegame.bmp");
		iSetcolor(0,0,0);
		
		strcpy(tempshowtext,showtext);
		strcat(tempshowtext,"|");
		if(var%2==0)
			iText(22,18,tempshowtext,GLUT_BITMAP_TIMES_ROMAN_24);
		else
			iText(22,18,showtext,GLUT_BITMAP_TIMES_ROMAN_24);
		
		iSetcolor(255,255,255);
	}
}

void icursor()
{
	var++;
	if(var>20)
		var=1;

}
void gameapperance(void)
{

			 if(timearr[0]==0)iShowBMP(box+cori*16-2*16-20,boy+cori*16+20+18,"00.bmp");
		else if(timearr[0]==1)iShowBMP(box+cori*16-2*16-20,boy+cori*16+20+18,"11.bmp");
		else if(timearr[0]==2)iShowBMP(box+cori*16-2*16-20,boy+cori*16+20+18,"22.bmp");
		else if(timearr[0]==3)iShowBMP(box+cori*16-2*16-20,boy+cori*16+20+18,"33.bmp");
		else if(timearr[0]==4)iShowBMP(box+cori*16-2*16-20,boy+cori*16+20+18,"44.bmp");
		else if(timearr[0]==5)iShowBMP(box+cori*16-2*16-20,boy+cori*16+20+18,"55.bmp");
		else if(timearr[0]==6)iShowBMP(box+cori*16-2*16-20,boy+cori*16+20+18,"66.bmp");
		else if(timearr[0]==7)iShowBMP(box+cori*16-2*16-20,boy+cori*16+20+18,"77.bmp");
		else if(timearr[0]==8)iShowBMP(box+cori*16-2*16-20,boy+cori*16+20+18,"88.bmp");
		else if(timearr[0]==9)iShowBMP(box+cori*16-2*16-20,boy+cori*16+20+18,"99.bmp");

		   	 if(timearr[1]==0)iShowBMP(box+cori*16-16-20,boy+cori*16+20+18,"00.bmp");
		else if(timearr[1]==1)iShowBMP(box+cori*16-16-20,boy+cori*16+20+18,"11.bmp");
		else if(timearr[1]==2)iShowBMP(box+cori*16-16-20,boy+cori*16+20+18,"22.bmp");
		else if(timearr[1]==3)iShowBMP(box+cori*16-16-20,boy+cori*16+20+18,"33.bmp");
		else if(timearr[1]==4)iShowBMP(box+cori*16-16-20,boy+cori*16+20+18,"44.bmp");
		else if(timearr[1]==5)iShowBMP(box+cori*16-16-20,boy+cori*16+20+18,"55.bmp");
		else if(timearr[1]==6)iShowBMP(box+cori*16-16-20,boy+cori*16+20+18,"66.bmp");
		else if(timearr[1]==7)iShowBMP(box+cori*16-16-20,boy+cori*16+20+18,"77.bmp");
		else if(timearr[1]==8)iShowBMP(box+cori*16-16-20,boy+cori*16+20+18,"88.bmp");
		else if(timearr[1]==9)iShowBMP(box+cori*16-16-20,boy+cori*16+20+18,"99.bmp");

			 if(timearr[2]==0)iShowBMP(box+cori*16-20,boy+cori*16+20+18,"00.bmp");
		else if(timearr[2]==1)iShowBMP(box+cori*16-20,boy+cori*16+20+18,"11.bmp");
		else if(timearr[2]==2)iShowBMP(box+cori*16-20,boy+cori*16+20+18,"22.bmp");
		else if(timearr[2]==3)iShowBMP(box+cori*16-20,boy+cori*16+20+18,"33.bmp");
		else if(timearr[2]==4)iShowBMP(box+cori*16-20,boy+cori*16+20+18,"44.bmp");
		else if(timearr[2]==5)iShowBMP(box+cori*16-20,boy+cori*16+20+18,"55.bmp");
		else if(timearr[2]==6)iShowBMP(box+cori*16-20,boy+cori*16+20+18,"66.bmp");
		else if(timearr[2]==7)iShowBMP(box+cori*16-20,boy+cori*16+20+18,"77.bmp");
		else if(timearr[2]==8)iShowBMP(box+cori*16-20,boy+cori*16+20+18,"88.bmp");
		else if(timearr[2]==9)iShowBMP(box+cori*16-20,boy+cori*16+20+18,"99.bmp");

		iSetcolor(0,0,0);
		iShowBMP(box+(cori*16)/2-16,boy+cori*16+20+16,"duck.bmp");

		iRectangle(box-2,boy-2,cori*16+4,corj*16+4);
		iRectangle(box-10,boy-10,cori*16+20,corj*16+20);

		iRectangle(box-10+10,boy+cori*16+20+10,cori*16+20-20,64-20);
		iRectangle(box-10,boy+cori*16+20,cori*16+20,64);
		iSetcolor(255,255,255);

		y=20;
		boy=y;
		for(i=0;i<cori;i++)
		{
			x=20;
			box=x;
			
			for(j=0;j<cori;j++)
			{	
				if(timestop!=1&&fileopen==0)
				{
					leftclick(x,y,i,j);
					rightclick(x,y,i,j);
					middleclick(x,y,i,j);
				}
				
				if(arr[i][j]==14)
				{
					if(blin%2==0)iShowBMP(x,y,"flag.bmp");
					else
						iShowBMP(x,y,"mine2.bmp");
				}

				else
				{
					if(arr[i][j]==13)
					{
						if(blin%2==0)iShowBMP(x,y,"flag.bmp");
						else
							iShowBMP(x,y,"mine2.bmp");
					}
					if(arr[i][j]==0)
					{	
						iShowBMP(x,y,"0.bmp");
						arr[i][j]=-3;
						recursion(i,j);
					}
					else if(arr[i][j]==-1)
						gameover();

					else if(arr[i][j]==-3||arr[i][j]==9)
						iShowBMP(x,y,"0.bmp");	
					
					else if(arr[i][j]==1)
						iShowBMP(x,y,"1.bmp");

					else if(arr[i][j]==2)
						iShowBMP(x,y,"2.bmp");

					else if(arr[i][j]==3)
						iShowBMP(x,y,"3.bmp");

					else if(arr[i][j]==4)
						iShowBMP(x,y,"4.bmp");

					else if(arr[i][j]==12)
						iShowBMP(x,y,"q.bmp");

					else if(arr[i][j]==5)
						iShowBMP(x,y,"5.bmp");

					else if(arr[i][j]==6)
						iShowBMP(x,y,"6.bmp");

					else if(arr[i][j]==7)
						iShowBMP(x,y,"7.bmp");

					else if(arr[i][j]==8)
						iShowBMP(x,y,"8.bmp");

					else if(arr[i][j]==10)
						iShowBMP(x,y,"board.bmp");

					else if(arr[i][j]==11)
						iShowBMP(x,y,"flag.bmp");
					else if(arr[i][j]==15)
						iShowBMP(x,y,"0.bmp");


				}
				x=x+16;

			}
			y=y+16;
		}
		if(newct>3)
		{
		midx=0;midy=0;
		for(i=0;i<cori;i++)
			for(j=0;j<corj;j++)
				if(arr[i][j]==15)
					arr[i][j]=10;
				newct=0;
		}

	gamewin();

}
void gamewin(void)
{

		flagno=0;
		for(i=0;i<cori;i++)
		{
			for(j=0;j<cori;j++)
			{
				if(arr[i][j]==11||arr[i][j]==14)
					flagno++;
			}
		}
		mineflag();

		flag=0;
		if(flagno==mineno)
		{
			for(i=0;i<cori;i++)
			{
				for(j=0;j<corj;j++)
				{
					if(strarr[i][j]=='*')
					{
						if(arr[i][j]==11||arr[i][j]==14)
						{
							flag=1;
							continue;
						}
						else
						{
							flag=0;
							break;
						}
					}

				}
			}

		}

		if(flag==1)
		{
			iShowBMP(box+(cori*16/2)-60,boy+(cori*16/2)-10,"button.bmp");

			iText(box+(cori*16/2)-50,boy+(cori*16/2),"You win",GLUT_BITMAP_TIMES_ROMAN_24);
			timestop=1;
			blink=1;
			for(i=0;i<cori;i++)
				for(j=0;j<corj;j++)
				{
					if(strarr[i][j]=='*')
					{
						arr[i][j]=14;
					}
				}

			helpopen=2;
			hsload();
			
			if(timestop==1&&gameopen==1)
			{
				high=(highscore1[0][0]-48)*100+(highscore1[0][1]-48)*10+(highscore1[0][2]-48);
				hightime=timearr[0]*100+timearr[1]*10+timearr[2];
				if(hightime<=high)
				{
					highscore1[0][0]=timearr[0]+48;
					highscore1[0][1]=timearr[1]+48;
					highscore1[0][2]=timearr[2]+48;
					
					iShowBMP(598,16,"button.bmp");
					//iText(20,300,"Congratulations ",GLUT_BITMAP_TIMES_ROMAN_24);
				}	
				strcpy(highscore[0],"player");
			}
			else if(timestop==1&&gameopen==2)
			{
				high=(highscore1[1][0]-48)*100+(highscore1[1][1]-48)*10+(highscore1[1][2]-48);
				hightime=timearr[0]*100+timearr[1]*10+timearr[2];
				
				if(hightime<=high)
				{
				
					highscore1[1][0]=timearr[0]+48;
					highscore1[1][1]=timearr[1]+48;
					highscore1[1][2]=timearr[2]+48;

					iShowBMP(598,16,"button.bmp");
				//	iText(20,300,"Congratulations you",GLUT_BITMAP_TIMES_ROMAN_24);
				
				}
				strcpy(highscore[1],"player");
			} 
			else if(timestop==1&&gameopen==3)
			{
				high=(highscore1[2][0]-48)*100+(highscore1[2][1]-48)*10+(highscore1[2][2]-48);
				hightime=timearr[0]*100+timearr[1]*10+timearr[2];
				
				if(hightime<=high)
				{
				
					highscore1[2][0]=timearr[0]+48;
					highscore1[2][1]=timearr[1]+48;
					highscore1[2][2]=timearr[2]+48;

					iShowBMP(598,16,"button.bmp");
				//	iText(20,300,"Congratulations you",GLUT_BITMAP_TIMES_ROMAN_24);
				
				}
				strcpy(highscore[2],"player");
			}
			
			if(hightime>high)
			{
				iShowBMP(0,0,"congi.bmp");
				iText(3,3,"Fail to make highscore",GLUT_BITMAP_8_BY_13);
			}
			else
			{
				iShowBMP(0,0+16+16+16,"congi.bmp");
				iShowBMP(0,0+16+16,"congi.bmp");
				iShowBMP(0,0+16,"congi.bmp");
				iShowBMP(0,0,"congi.bmp");

				iText(70+90,0+16+16+16+3,highscore1[0],GLUT_BITMAP_8_BY_13);
				iText(70,0+16+16+16+3,highscore[0],GLUT_BITMAP_8_BY_13);
				iText(3,0+16+16+16+3,"Begineer",GLUT_BITMAP_8_BY_13);

				iText(70+90,0+16+16+3,highscore1[1],GLUT_BITMAP_8_BY_13);
				iText(70,0+16+16+3,highscore[1],GLUT_BITMAP_8_BY_13);
				iText(3,0+16+16+3,"Medium",GLUT_BITMAP_8_BY_13);

				iText(70+90,0+16+3,highscore1[2],GLUT_BITMAP_8_BY_13);
				iText(70,0+16+3,highscore[2],GLUT_BITMAP_8_BY_13);
				iText(3,0+16+3,"Expert",GLUT_BITMAP_8_BY_13);

				iText(0,3,"Reset all records......",GLUT_BITMAP_8_BY_13);

				if(lmoux>0&&lmoux<128&&lmouy>3&&lmouy<64)
				{
					strcpy(highscore1[0],"999");
					strcpy(highscore[0],"Siddharth");
					
					strcpy(highscore1[1],"999");
					strcpy(highscore[1],"Siddhartha");
					
					strcpy(highscore1[2],"999");
					strcpy(highscore[2],"Shidwartha");
				}

			hssave();
			}
		}


}


void drawing(void)
{
	if(gameopen==1)
	{	
		gameapperance();
	}
	else if(gameopen==2)
	{
		gameapperance();
	}
	else if(gameopen==3)
	{
		gameapperance();	
	}
}

void mineflag(void)
{
	int mineflag;
	int firstdigit;
	int seconddigit;
	
	mfx=box-16+20;mfy=boy+cori*16+20+18;
	mineflag=mineno-flagno;
	
	if(timestop==1)
	{
		iShowBMP(mfx,mfy,"00.bmp");
		iShowBMP(mfx+16,mfy,"00.bmp");
	}
	else
	{
		if(mineflag<1)
		{
			iShowBMP(mfx,mfy,"00.bmp");
			iShowBMP(mfx+16,mfy,"00.bmp");
		}
		else
		{
		firstdigit=mineflag/10;
		seconddigit=mineflag%10;
		
			 if(firstdigit==0)iShowBMP(mfx,mfy,"00.bmp");
		else if(firstdigit==1)iShowBMP(mfx,mfy,"11.bmp");
		else if(firstdigit==2)iShowBMP(mfx,mfy,"22.bmp");
		else if(firstdigit==3)iShowBMP(mfx,mfy,"33.bmp");
		else if(firstdigit==4)iShowBMP(mfx,mfy,"44.bmp");
		else if(firstdigit==5)iShowBMP(mfx,mfy,"55.bmp");
		else if(firstdigit==6)iShowBMP(mfx,mfy,"66.bmp");
		else if(firstdigit==7)iShowBMP(mfx,mfy,"77.bmp");
		else if(firstdigit==8)iShowBMP(mfx,mfy,"88.bmp");
		else if(firstdigit==9)iShowBMP(mfx,mfy,"99.bmp");
		
		
			 if(seconddigit==0)iShowBMP(mfx+16,mfy,"00.bmp");
		else if(seconddigit==1)iShowBMP(mfx+16,mfy,"11.bmp");
		else if(seconddigit==2)iShowBMP(mfx+16,mfy,"22.bmp");
		else if(seconddigit==3)iShowBMP(mfx+16,mfy,"33.bmp");
		else if(seconddigit==4)iShowBMP(mfx+16,mfy,"44.bmp");
		else if(seconddigit==5)iShowBMP(mfx+16,mfy,"55.bmp");
		else if(seconddigit==6)iShowBMP(mfx+16,mfy,"66.bmp");
		else if(seconddigit==7)iShowBMP(mfx+16,mfy,"77.bmp");
		else if(seconddigit==8)iShowBMP(mfx+16,mfy,"88.bmp");
		else if(seconddigit==9)iShowBMP(mfx+16,mfy,"99.bmp");
		}
	}	
}




void gameover()
{
	int w,s;
	iShowBMP(box+(cori*16)/2-16,boy+cori*16+20+16,"loser.bmp");

	if(gameoverr==0)PlaySound("bomb_x.wav",NULL,SND_ASYNC);
	iShowBMP(x,y,"mine2.bmp");
	
	iShowBMP(box+(cori*16/2)-60,boy+(cori*16/2)-10,"button.bmp");

	iText(box+(cori*16/2)-50,boy+(cori*16/2),"You lose",GLUT_BITMAP_TIMES_ROMAN_24);

	for(w=0;w<cori;w++)
	for(s=0;s<corj;s++)
	{
		if(strarr[w][s]=='*')
		{
			if(arr[w][s]==11)
				arr[w][s]=13;
			else if(arr[w][s]!=13)
				arr[w][s]=-1;
		}
	}
	timestop=1;
	blink=1;
	gameoverr=1;

}

void iDraw()
{
	iClear();
	iShowBMP(0,0,"back.bmp");
	drawing();
	filemenu();
	helpmenu();

}


void iMouseMove(int mx, int my)
{

}
void iPassiveMouseMove(int mx, int my)
{
	//place your codes here
	mposx=mx;
	mposy = my;

}

void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		filemouse(mx,my);
		if(flag==1)PlaySound("applause3.wav",NULL,SND_ASYNC);

		/*iShowBMP(60,iniy-32-32,"button.bmp");
		iShowBMP(60,iniy-32-32-32,"button.bmp");
		iShowBMP(60,iniy-32-32-32-32,"button.bmp");
		iShowBMP(60,iniy-32-32-32-32-32,"button.bmp");*/

		if(menuopen==1&&lmoux>60&&lmoux<(60+140)&&lmouy>(iniy-32-32)&&lmouy<iniy-32)
		{
			//exit(0);
		}
		/*if(menuopen==1&&lmoux>60&&lmoux<(60+140)&&lmouy>(iniy-32-32-32)&&lmouy<iniy-32-32)
		{
			FILE *save;
			iShowBMP()
		}*/
		if(menuopen==1&&lmoux>60&&lmoux<(60+140)&&lmouy>(iniy-32-32-32-32)&&lmouy<iniy-32-32-32)
		{
		//	exit(0);
		}
		if(menuopen==1&&lmoux>60&&lmoux<(60+140)&&lmouy>(iniy-32-32-32-32-32)&&lmouy<iniy-32-32-32-32)
		{
		//	exit(0);
		}
		printf("(%d %d)",mx,my);
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
		PlaySound("typewriter_click.wav",NULL,SND_ASYNC);

		rmoux=mx;rmouy=my;
		lmoux=0;lmouy=0;
		midx=0;midy=0;
		cory=boy;
		for(sid=0;sid<cori;sid++)
		{
			corx=box;
			for(sidd=0;sidd<cori;sidd++)
			{	
				if(arr[sid][sidd]>=10)
					right(corx,cory,sid,sidd);

				corx=corx+16;
			}
			cory=cory+16;
		}
		
	}

	if(button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
	{
			PlaySound("typewriter_click.wav",NULL,SND_ASYNC);
			midx=mx;midy=my;
			lmoux=0;lmouy=0;
			rmoux=0;rmouy=0;
	}
	
}

void filemouse(int mx,int my)
{
		lmoux=mx;lmouy=my;
		rmoux=0;rmouy=0;
		midx=0;midy=0;
		PlaySound("typewriter_click.wav",NULL,SND_ASYNC);

		if((fileopen==1&&menuopen==0&&scoreopen==0&&lmoux>10&&lmoux<80&&lmouy>(iniy-32-32)&&lmouy<(iniy-32))||(menuopen==0&&lmoux>(box+(cori*16)/2-16)&&lmoux<(box+(cori*16)/2-16+32)&&lmouy>(boy+cori*16+20+16)&&lmouy<(boy+cori*16+20+16+32)))
		{
			flag=0;
			closeWindowMy();
			lmoux=0;lmouy=0;
			FILE *fp;
			fp=fopen("gamelevel.txt","w");
			fprintf(fp,"%d",level);
			fclose(fp);

			FILE *fpp;

			fpp=fopen("gamelevel.txt","r");
			fscanf(fpp,"%d",&level);

			fclose(fpp);
		//	printf("%d",level);

			fileopen=0;

			if(level==1)
			{
				cori=9;
				corj=9;
				
				varnum=10;
			}
			else if(level==2)
			{
				cori=16;
				corj=16;
				
				varnum=40;
			}
			
			else if(level==3)
			{
				cori=25;
				corj=25;
				varnum=99;
			}
			memset(strarr,0,sizeof(strarr));
			memset(arr,0,sizeof(arr));
			memset(rightside,0,sizeof(rightside));
			memset(timearr,0,sizeof(timearr));
			for(i=0;i<cori;i++)for(j=0;j<corj;j++)
			{
				strarr[i][j]='.';
				arr[i][j]=10;
				rightside[i][j]=1;
			}
			load();
			newgame();
			gameopen=level;
			timenext=0;
			timestop=0;
			blink=0;
			save();
			gameoverr=0;
	
			if(level==1)
			iInitialize(184,282, "Minesweeper");
			if(level==2)
			iInitialize(296,396, "Minesweeper");
			if(level==3)
			iInitialize(440,536, "Minesweeper");

			fp=fopen("gamelevel.txt","w");
			fprintf(fp,"%d",level);
			fclose(fp);
		
		}

		else if(fileopen==1&&menuopen==0&&scoreopen==0&&lmoux>10&&lmoux<80&&lmouy>(iniy-32-32-32)&&lmouy<(iniy-32-32))
		{
			
			flag=0;
			lmoux=0;lmouy=0;
			level=1;
			fileopen=0;
			
			cori=9;
			corj=9;
			varnum=10;
			
			memset(strarr,0,sizeof(strarr));
			memset(arr,0,sizeof(arr));
			memset(rightside,0,sizeof(rightside));
			memset(timearr,0,sizeof(timearr));
			for(i=0;i<cori;i++)for(j=0;j<corj;j++)
			{
				strarr[i][j]='.';
				arr[i][j]=10;
				rightside[i][j]=1;
			}
			load();
			newgame();
			gameopen=1;
			save();
			timestop=0;
			timenext=0;
			blink=0;
			gameoverr=0;
			closeWindowMy();
			iInitialize(184,282, "Minesweeper");
			

			FILE *fp;
			fp=fopen("gamelevel.txt","w");
			fprintf(fp,"%d",level);
			fclose(fp);

		}

		else if(fileopen==1&&menuopen==0&&scoreopen==0&&lmoux>10&&lmoux<80&&lmouy>(iniy-32-32-32-32)&&lmouy<(iniy-32-32-32))
		{
			
			flag=0;
			lmoux=0;lmouy=0;
			level=2;
			fileopen=0;
			cori=16;
			corj=16;
			
			memset(strarr,0,sizeof(strarr));
			memset(arr,0,sizeof(arr));
			memset(rightside,0,sizeof(rightside));
			memset(timearr,0,sizeof(timearr));
			for(i=0;i<cori;i++)for(j=0;j<corj;j++)
			{
				strarr[i][j]='.';
				arr[i][j]=10;
				rightside[i][j]=1;
			}
			varnum=40;
			load();
			newgame();
			gameopen=2;
			timenext=0;
			timestop=0;
			blink=0;
			save();
			gameoverr=0;
			closeWindowMy();
			iInitialize(296,396, "Minesweeper");
			
			FILE *fp;
			fp=fopen("gamelevel.txt","w");
			fprintf(fp,"%d",level);
			fclose(fp);
		}
		
		else if(fileopen==1&&menuopen==0&&scoreopen==0&&lmoux>10&&lmoux<80&&lmouy>(iniy-32-32-32-32-32)&&lmouy<((iniy-32-32-32-32)))
		{
			
			flag=0;
			lmoux=0;lmouy=0;
			level=3;
			fileopen=0;
			cori=25;
			corj=25;
			
			memset(rightside,0,sizeof(rightside));
			memset(strarr,0,sizeof(strarr));
			memset(arr,0,sizeof(arr));
			memset(timearr,0,sizeof(timearr));
			for(i=0;i<cori;i++)for(j=0;j<corj;j++)
			{
				strarr[i][j]='.';
				arr[i][j]=10;
				rightside[i][j]=1;
			}
			varnum=99;

			load();
			gameopen=3;
			timenext=0;
			newgame();
			save();
			timestop=0;
			blink=0;
			gameoverr=0;
			closeWindowMy();
			iInitialize(440,536, "Minesweeper");

			
			FILE *fp;
			fp=fopen("gamelevel.txt","w");
			fprintf(fp,"%d",level);
			fclose(fp);
		}

}
/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.	
*/
void iKeyboard(unsigned char key)
{
	if(text==1)
	{
		if(key==8&&textvarr>0)
		{
			textvarr=textvarr-1;
			showtext[textvarr]='\0';
		}
		else
		{
			showtext[textvarr]=key;	
			textvarr++;
		}
	}

}
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_F2)
	{
		exit(0);
	}
}

int main()
{	
	iSettimer(500,icursor);
	iSettimer(1000,timenextt);
	iSettimer(500,blinkk);

	FILE *fpp;

	fpp=fopen("gamelevel.txt","r");
	fscanf(fpp,"%d",&level);

	fclose(fpp);
//	printf("%d",level);

			fileopen=0;
			if(level==1)
			{
			cori=9;
			corj=9;
			
			varnum=10;
			}
			else if(level==2)
			{
			cori=16;
			corj=16;
			
			varnum=40;
			}
			
			else if(level==3)
			{
			cori=25;
			corj=25;
			varnum=99;
			}
			memset(strarr,0,sizeof(strarr));
			memset(arr,0,sizeof(arr));
			memset(rightside,0,sizeof(rightside));
			memset(timearr,0,sizeof(timearr));
			for(i=0;i<cori;i++)for(j=0;j<corj;j++)
			{
				strarr[i][j]='.';
				arr[i][j]=10;
				rightside[i][j]=1;
			}
			load();
			newgame();
			gameopen=level;
			timenext=0;
			timestop=0;
			blink=0;
			save();
			gameoverr=0;
	
	if(level==1)
	iInitialize(184,282, "Minesweeper");
	if(level==2)
	iInitialize(296,396, "Minesweeper");
	if(level==3)
	iInitialize(440,536, "Minesweeper");
	return 0;
}

void blinkk(void)
{

	if(blink==1)
		blin++;
	if(blin>50)
		blin=0;
}


void timenextt(void)
{

	mfx=box+corj*16;mfy=boy+cori*16+20,corj*16+30;

	if(gameopen!=0&&timestop==0)
	{
		timenext++;
		
		if(timenext>999)memset(timearr,0,sizeof(timearr));
		else
		{	
			timearr[0]=timenext/100;
			timearr[2]=timenext%10;
			timearr[1]=(timenext-(timearr[0]*100+timearr[2]))/10;
		}
	}

}

/***************************************** save varry *************************************/
void save(void)
{
	FILE *va;

	va=fopen("varry.txt","wb");
	fwrite(varry,sizeof varry,1,va);

	fclose(va);
}

/***************************************** save varry *************************************/
void load(void)
{
	FILE *va;

	va=fopen("varry.txt","rb");
	fread(varry,sizeof varry,1,va);

	fclose(va);
}

/***************************************** save varry *************************************/

void newgame(void)
{	
	mineno=0;
	if(level==1)
	{
		varry[0]=(varry[0]+rand())%81;

		for(i=1;i<10;i++)
		{	
			varry[i]=(varry[i]+rand())%81;
			for(j=0;j<i;)
			{
				if(varry[j]==varry[i])
				{
					varry[i]=(varry[i]+rand())%81;
					j=0;
				}
				else
					j++;
			}

		}

		for(i=0;i<10;i++)
		{
			rmd=varry[i]%9;
			vag=varry[i]/9;
			strarr[vag][rmd]='*';
			mineno++;
		}

		for(i=0;i<cori;i++)
		{
			for(j=0;j<corj;j++)
			{
				if(strarr[i][j]=='*')
				{
					strar[i][j]=strarr[i][j];
				}
				else
				{	
					count=0;
					for(z=0;z<8;z++)
					{
						m=i+inx[z];n=j+iny[z];
						if(m>=0&&m<cori&&n>=0&&n<corj&&strarr[m][n]=='*')count=count+1;
					}
					strar[i][j]=count+48;
				}
			
			}

		}

	}
	else if(level==2)
	{
		varry[0]=(varry[0]+rand())%256;

		for(i=1;i<40;i++)
		{	
			varry[i]=(varry[i]+rand())%256;
			for(j=0;j<i;)
			{
				if(varry[j]==varry[i])
				{
					varry[i]=(varry[i]+rand())%81;
					j=0;
				}
				else
					j++;
			}

		}

		for(i=0;i<40;i++)
		{
			rmd=varry[i]%16;
			vag=varry[i]/16;
			strarr[vag][rmd]='*';
			mineno++;
		}
		for(i=0;i<cori;i++)
		{
			for(j=0;j<corj;j++)
			{
				if(strarr[i][j]=='*')
				{
					strar[i][j]=strarr[i][j];
				}
				else
				{	
					count=0;
					for(z=0;z<8;z++)
					{
						m=i+inx[z];n=j+iny[z];
						if(m>=0&&m<cori&&n>=0&&n<corj&&strarr[m][n]=='*')count=count+1;
					}
					strar[i][j]=count+48;
				}
			
			}

		}

	}
	else if(level==3)
	{
		varry[0]=(varry[0]+rand())%625;

		for(i=1;i<99;i++)
		{	
			varry[i]=(varry[i]+rand())%625;
			for(j=0;j<i;)
			{
				if(varry[j]==varry[i])
				{
					varry[i]=(varry[i]+rand())%81;
					j=0;
				}
				else
					j++;
			}

		}
	
		for(i=0;i<varnum;i++)
		{
			rmd=varry[i]%25;
			vag=varry[i]/25;
			strarr[vag][rmd]='*';
			mineno++;
			varry[i]=(varry[i]+rmd+vag+rand())%625;
		}
		for(i=0;i<cori;i++)
		{
			for(j=0;j<corj;j++)
			{
				if(strarr[i][j]=='*')
				{
					strar[i][j]=strarr[i][j];
				}
				else
				{	
					count=0;
					for(z=0;z<8;z++)
					{
						m=i+inx[z];n=j+iny[z];
						if(m>=0&&m<cori&&n>=0&&n<corj&&strarr[m][n]=='*')count=count+1;
					}
					strar[i][j]=count+48;
				}
			
			}

		}

	}

/*	printf("\n%d\n",mineno);
	
	if(level==1)
	for(i=0;i<cori;i++)
	{
		for(j=0;j<corj;j++)
			printf("%c",strarr[i][j]);
			printf("\n");
	}
	
	if(level==2)
	for(i=0;i<cori;i++)
	{
		for(j=0;j<corj;j++)
			printf("%c",strarr[i][j]);
			printf("\n");
	}

	if(level==3)
	for(i=0;i<cori;i++)
	{
		for(j=0;j<corj;j++)
			printf("%c",strarr[i][j]);
			printf("\n");
	}

	printf("\n");
	
		for(j=0;j<varnum;j++)
			printf("%d  ",varry[j]);
			printf("\n");

	printf("\n%d\n",mineno);*/

}



/******************************  To Show 0 adjacent  ******************************************8*/

void recursion(int h,int k)
{		

		if((h-1)>=0&&(h-1)<cori&&(k-1)>=0&&(k-1)<cori)
		{	
			arr[h-1][k-1]=strar[h-1][k-1]-48;
			if(strar[h-1][k-1]=='0')
			{
			strar[h-1][k-1]=9+48;
		    arr[h-1][k-1]=-3;
			recursion(h-1,k-1);
			}
		}
	

		if((h-1)>=0&&(h-1)<cori&&(k)>=0&&(k)<cori)
		{
			arr[h-1][k]=strar[h-1][k]-48;
			if(strar[h-1][k]=='0')
			{
			strar[h-1][k]=9+48;
			arr[h-1][k]=-3;
            recursion(h-1,k);
			}

		}

		if((h-1)>=0&&(h-1)<cori&&(k+1)>=0&&(k+1)<cori)
		{
			arr[h-1][k+1]=strar[h-1][k+1]-48;
			if(strar[h-1][k+1]=='0')
			{
			strar[h-1][k+1]=9+48;
			arr[h-1][k+1]=-3;
			recursion(h-1,k+1);
			}

		}


		if((h)>=0&&(h)<cori&&(k-1)>=0&&(k-1)<cori)
		{
			arr[h][k-1]=strar[h][k-1]-48;
			if(strar[h][k-1]=='0')
			{
			strar[h][k-1]=9+48;
			arr[h][k-1]=-3;
			recursion(h,k-1);
			}

		}

		if((h)>=0&&(h)<cori&&(k+1)>=0&&(k+1)<cori)
		{
			arr[h][k+1]=strar[h][k+1]-48;
			if(strar[h][k+1]=='0')
			{
			strar[h][k+1]=9+48;
			arr[h][k+1]=-3;
			recursion(h,k+1);
			}

		}

		if((h+1)>=0&&(h+1)<cori&&(k-1)>=0&&(k-1)<cori)
		{
			arr[h+1][k-1]=strar[h+1][k-1]-48;
			if(strar[h+1][k-1]=='0')
			{
			strar[h+1][k-1]=9+48;
			arr[h+1][k-1]=-3;
			recursion(h+1,k-1);
			}

		}

		if((h+1)>=0&&(h+1)<cori&&(k)>=0&&(k)<cori)
		{
			arr[h+1][k]=strar[h+1][k]-48;
			if(strar[h+1][k]=='0')
			{
			strar[h+1][k]=9+48;
			arr[h+1][k]=-3;
			recursion(h+1,k);
			}

		}

		if((h+1)>=0&&(h+1)<cori&&(k+1)>=0&&(k+1)<cori)
		{
			arr[h+1][k+1]=strar[h+1][k+1]-48;
			if(strar[h+1][k+1]=='0')
			{
			strar[h+1][k+1]=9+48;
			arr[h+1][k+1]=-3;
			recursion(h+1,k+1);
			}
		}	

}


















