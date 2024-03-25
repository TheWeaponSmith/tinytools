#include <stdio.h>
#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nShowCmd) {
  // Declare variables to store the parameters
  char label[256], message[256];
  int intParam1;

  // Initialize icon with default value
  int icon = MB_ICONINFORMATION;

  // Parse command line
  int argsParsed =
      sscanf(lpCmdLine, "%d %255s %255[^\n]", &intParam1, label, message);
  if (argsParsed < 3) {
    return 1;
  }

  // Update icon based on intParam1
  switch (intParam1) {
  case 0:
    icon = MB_ICONINFORMATION;
    break;
  case 1:
    icon = MB_ICONWARNING;
    break;
  case 2:
    icon = MB_ICONERROR;
    break;
  default:
    icon = MB_ICONINFORMATION;
    break;
  }

  // Display message box
  MessageBox(NULL, message, label, MB_OK | icon);

  return 0;
}
