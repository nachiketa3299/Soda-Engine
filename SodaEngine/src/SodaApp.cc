#include "Soda/SodaApp.h"

#include "Soda/Input.h"
#include "Soda/Time.h"

void soda::SodaApp::initialize(HWND hwnd, UINT width, UINT height) {
	hwnd_ = hwnd;
	dc_ = GetDC(hwnd_);

	// 윈도우 설정 및 생성
	RECT rect = { 0, 0, (LONG)width, (LONG)height };

	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

	width_ = rect.right - rect.left;
	height_ = rect.bottom - rect.top;

	SetWindowPos(hwnd, nullptr, 
	  0, 0, 
		width_, height_, 
		0
	);
	ShowWindow(hwnd, true);

	// 윈도우 해상도에 맞는 백버퍼(도화지) 생성
	buffer_ = CreateCompatibleBitmap(dc_, width, height);

	bdc_ = CreateCompatibleDC(dc_);

	HBITMAP prev_bitmap = (HBITMAP)SelectObject(bdc_, buffer_);
	DeleteObject(prev_bitmap);

	Input::initialize();
	Time::initialize();
}

void soda::SodaApp::run() {
	update();
	render();
}

void soda::SodaApp::update() {
	Input::update();
	Time::update();
}

void soda::SodaApp::render() {

	// 도화지에 그리고
	// Rectangle(bdc_, 0, 0, 10, 20);
	Time::render(bdc_);

	// Back Buffer에 있는 것을 워본 버퍼에 복사
	BitBlt(dc_, 0, 0, width_, height_, bdc_, 0, 0, SRCCOPY);
}
