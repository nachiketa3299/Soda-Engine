#include "Soda/SodaApp.h"

#include <cstdio>

#include "Soda/WinGdiCommon.h"

#include "Soda/SceneManager.h"
#include "Soda/Scene.h"
#include "Soda/GEntity.h"
#include "Soda/Input.h"
#include "Soda/Time.h"

void soda::SodaApp::initialize(HWND hwnd, UINT width, UINT height) {
	Gdiplus::GdiplusStartup(&gdi_token_, &gdi_sinput, NULL);


	hwnd_ = hwnd;
	dc_ = GetDC(hwnd_);

	// 윈도우 설정 및 생성
	RECT rect = { 0, 0, (LONG)width, (LONG)height };

	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

	width_ = rect.right - rect.left;
	height_ = rect.bottom - rect.top;

	SetWindowPos(hwnd, nullptr, 0, 0, width_, height_, 0);
	ShowWindow(hwnd, true);

	// 윈도우 해상도에 맞는 백버퍼(도화지) 생성
	buffer_ = CreateCompatibleBitmap(dc_, width, height);

	bdc_ = CreateCompatibleDC(dc_);

	HBITMAP prev_bitmap = (HBITMAP)SelectObject(bdc_, buffer_);
	DeleteObject(prev_bitmap);

	Input::initialize();
	Time::initialize();
	SceneManager::initialize();
}

void soda::SodaApp::clear_render_target() const {
	Rectangle(bdc_, 0, 0, width_, height_);
}

void soda::SodaApp::copy_render_target(HDC src, HDC dest) const {
	// Back Buffer에 있는 것을 워본 버퍼에 복사
	BitBlt(dest, 0, 0, width_, height_, src, 0, 0, SRCCOPY);
}

void soda::SodaApp::run() {
	update();
	render();
}

void soda::SodaApp::update() {
	Input::update();
	Time::update();
	SceneManager::update();
}

constexpr auto SODA_TIME_DEBUG_BUFF_LEN = 128;
constexpr auto SODA_DEBUG_FMT_STR = L"> fps: %.3f\n> scene: %s";

void soda::SodaApp::render() {
	clear_render_target();

	Time::render(bdc_);
	SceneManager::render(bdc_);

	// Draw Debug Infos

  wchar_t d_str_buff[SODA_TIME_DEBUG_BUFF_LEN] = L"";

  swprintf_s(d_str_buff, 
		SODA_TIME_DEBUG_BUFF_LEN, 
		SODA_DEBUG_FMT_STR, 
		1.f / Time::get_dt(), SceneManager::get_a_scene()->get_name().c_str()
	);

  // size_t const len = wcsnlen_s(d_str_buff, SODA_TIME_DEBUG_BUFF_LEN);
  RECT rect{10, 10, 300, 300};
  DrawText(bdc_, d_str_buff, -1, &rect, DT_LEFT);

	copy_render_target(bdc_, dc_);
}
