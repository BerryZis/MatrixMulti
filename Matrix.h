/**************************************************************************/
/* LabWindows/CVI User Interface Resource (UIR) Include File              */
/*                                                                        */
/* WARNING: Do not add to, delete from, or otherwise modify the contents  */
/*          of this include file.                                         */
/**************************************************************************/

#include <userint.h>

#ifdef __cplusplus
    extern "C" {
#endif

     /* Panels and Controls: */

#define  PANEL                            1       /* callback function: Exitq */
#define  PANEL_TABLE_3                    2       /* control type: table, callback function: (none) */
#define  PANEL_TABLE_2                    3       /* control type: table, callback function: (none) */
#define  PANEL_TABLE                      4       /* control type: table, callback function: (none) */
#define  PANEL_TEXTMSG                    5       /* control type: textMsg, callback function: (none) */
#define  PANEL_TEXTMSG_2                  6       /* control type: textMsg, callback function: (none) */
#define  PANEL_COMMANDBUTTON              7       /* control type: command, callback function: Multiply */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

#define  MENUBAR                          1
#define  MENUBAR_MENU1_2                  2       /* callback function: Reset */
#define  MENUBAR_MENU1                    3       /* callback function: About */


     /* Callback Prototypes: */

void CVICALLBACK About(int menubar, int menuItem, void *callbackData, int panel);
int  CVICALLBACK Exitq(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Multiply(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
void CVICALLBACK Reset(int menubar, int menuItem, void *callbackData, int panel);


#ifdef __cplusplus
    }
#endif
