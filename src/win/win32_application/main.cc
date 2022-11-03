#include <Windows.h>

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        RECT rc = {};
        GetClientRect(hWnd, &rc);
        HDC hdc = BeginPaint(hWnd, &ps);
        HBRUSH hBrush = CreateSolidBrush(RGB(255, 255, 0));
        FillRect(hdc, &rc, hBrush);
        DeleteObject(hBrush);
        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:
    {
        PostQuitMessage(0);
    }
    break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                      _In_opt_ HINSTANCE hPrevInstance,
                      _In_ LPWSTR lpCmdLine,
                      _In_ int nCmdShow)
{

    const WCHAR szClassName[] = L"WindowClass";
    const WCHAR szWindowCaption[] = L"WindowCaption";

    WNDCLASSEXW wcex = {sizeof(WNDCLASSEX)};
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = nullptr;
    wcex.hCursor = nullptr;
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = nullptr;
    wcex.lpszClassName = szClassName;
    wcex.hIconSm = nullptr;

    RegisterClassEx(&wcex);

    HWND hWnd = CreateWindowW(szClassName, szWindowCaption, WS_OVERLAPPEDWINDOW,
                              CW_USEDEFAULT, 0, 480, 300, nullptr, nullptr, hInstance, nullptr);

    if (hWnd == nullptr)
    {
        return FALSE;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    MSG msg = {};
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, nullptr, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int)msg.wParam;
}
