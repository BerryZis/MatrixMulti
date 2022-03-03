#include <cvirte.h>		
#include <userint.h>
#include "Matrix.h"

static int panelHandle;
double sum,num1,num2;

int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panelHandle = LoadPanel (0, "Matrix.uir", PANEL)) < 0)
		return -1;
	DisplayPanel (panelHandle);
	RunUserInterface ();
	DiscardPanel (panelHandle);
	return 0;
}

int CVICALLBACK Exitq (int panel, int event, void *callbackData,
					   int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_GOT_FOCUS:

			break;
		case EVENT_LOST_FOCUS:

			break;
		case EVENT_CLOSE:
			QuitUserInterface (0);
			break;
	}
	return 0;
}

int CVICALLBACK Multiply (int panel, int control, int event,
						  void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			SetCtrlAttribute (panelHandle, PANEL_TABLE_3, ATTR_DIMMED, 0);
		
			
			//This way is much better then using the MatrixMul function that demand you to create arrays for saving unnecesary data.
				for(int i=1;i<=3;i++)
			{
				for(int j=1;j<=3;j++)
				{
					sum=0;
					for(int k=1;k<=3;k++)
					{
					GetTableCellVal (panelHandle, PANEL_TABLE,MakePoint(k,j) ,&num1 );
					GetTableCellVal (panelHandle, PANEL_TABLE_2,MakePoint(i,k) ,&num2 );
					
					sum = sum + num1*num2 ;
					SetTableCellVal(panelHandle, PANEL_TABLE_3,MakePoint(i,j) ,sum );
					}
				}
			}
			break;
	}
	return 0;
}

void CVICALLBACK About (int menuBar, int menuItem, void *callbackData,
						int panel)
{
	MessagePopup ("About", "Features:\n- Reset button\n- Dimmed answer\n- About button\n\n\n\nMade by: Berry Ziskind\n308183037");	
}

void CVICALLBACK Reset (int menuBar, int menuItem, void *callbackData,
						int panel)
{
	SetCtrlAttribute (panelHandle, PANEL_TABLE_3, ATTR_DIMMED, 1);
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			SetTableCellVal (panelHandle, PANEL_TABLE,MakePoint(i,j) ,0.0 );
			SetTableCellVal (panelHandle, PANEL_TABLE_2,MakePoint(i,j) ,0.0 );	
			SetTableCellVal (panelHandle, PANEL_TABLE_3,MakePoint(i,j) ,0.0 );
		}
	}
}
