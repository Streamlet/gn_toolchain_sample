#include <Windows.h>

LRESULT CALLBACK WndProc(HWND hWnd,
                         UINT message,
                         WPARAM wParam,
                         LPARAM lParam) {
  switch (message) {
    case WM_PAINT: {
      PAINTSTRUCT ps;
      RECT rc = {0};
      GetClientRect(hWnd, &rc);
      HDC hdc = BeginPaint(hWnd, &ps);
      HBRUSH hBrush = CreateSolidBrush(RGB(255, 255, 0));
      FillRect(hdc, &rc, hBrush);
      DeleteObject(hBrush);
      EndPaint(hWnd, &ps);
    } break;
    case WM_DESTROY: {
      PostQuitMessage(0);
    } break;
    default:
      return DefWindowProc(hWnd, message, wParam, lParam);
  }
  return 0;
}

int APIENTRY wWinMain(HINSTANCE hInstance,
                      HINSTANCE hPrevInstance,
                      LPWSTR lpCmdLine,
                      int nCmdShow) {
  const WCHAR szClassName[] = L"WindowClass";
  const WCHAR szWindowCaption[] = L"WindowCaption";

  WNDCLASSEXW wcex = {sizeof(WNDCLASSEX)};
  wcex.style = CS_HREDRAW | CS_VREDRAW;
  wcex.lpfnWndProc = WndProc;
  wcex.cbClsExtra = 0;
  wcex.cbWndExtra = 0;
  wcex.hInstance = hInstance;
  wcex.hIcon = NULL;
  wcex.hCursor = NULL;
  wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
  wcex.lpszMenuName = NULL;
  wcex.lpszClassName = szClassName;
  wcex.hIconSm = NULL;

  RegisterClassEx(&wcex);

  HWND hWnd =
      CreateWindowW(szClassName, szWindowCaption, WS_OVERLAPPEDWINDOW,
                    CW_USEDEFAULT, 0, 480, 300, NULL, NULL, hInstance, NULL);

  if (hWnd == NULL) {
    return FALSE;
  }

  ShowWindow(hWnd, nCmdShow);
  UpdateWindow(hWnd);

  MSG msg = {0};
  while (GetMessage(&msg, NULL, 0, 0)) {
    if (!TranslateAccelerator(msg.hwnd, NULL, &msg)) {
      TranslateMessage(&msg);
      DispatchMessage(&msg);
    }
  }

  return (int)msg.wParam;
}
