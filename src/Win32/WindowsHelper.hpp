#ifndef WINDOWS_HELPER_HPP
#define WINDOWS_HELPER_HPP

#ifdef _WIN32
	#ifndef UNICODE
		#define UNICODE
	#endif

	#ifndef _UNICODE
		#define _UNICODE
	#endif

	#define WIN32_LEAN_AND_MEAN
	#include <windows.h>
#endif // _WIN32

#include "Icon.h"

class WindowsHelper {
	public:
		WindowsHelper();

		void setIcon(const HWND &inHandle);

	private:
		PBYTE getIconDirectory(const int &inResourceId);
		HICON getIconFromIconDirectory(const PBYTE &inIconDirectory, const unsigned int &inSize);

		HICON m_hIcon32;
		HICON m_hIcon16;
};

#endif // WINDOWS_HELPER_HPP