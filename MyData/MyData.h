// MyData.h : main header file for the MyData DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#ifdef MYDATA_EXPORTS
#define MYDATA_API __declspec(dllexport)
#else
#define MYDATA_API __declspec(dllimport)
#endif

#include "resource.h"		// main symbols


// CMyDataApp
// See MyData.cpp for the implementation of this class
//

class MYDATA_API MY_COORD
{
public:
	double x;
	double y;

	MY_COORD() : x(0), y(0) {}
	MY_COORD(double xx, double yy) : x(xx), y(yy) {}
	~MY_COORD() {}

	void set(double xx, double yy) { x = xx; y = yy; }
	MY_COORD get() { return *this; }
};

class CMyDataApp : public CWinApp
{
public:
	CMyDataApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};


#pragma pack(push, 1)
class CExcept1App;

class MYDATA_API MY_POINT : public MY_COORD
{
public:
	char* name;
	int numb;
	COLORREF color;

	MY_POINT() : MY_COORD(), name(nullptr), numb(0), color(RGB(0, 0, 0)) {}
	MY_POINT(double xx, double yy, const char* pname, int n, COLORREF c)
		: MY_COORD(xx, yy), numb(n), color(c)
	{
		name = new char[strlen(pname) + 1];
		strcpy_s(name, strlen(pname) + 1, pname);
	}
	~MY_POINT() { delete[] name; }

	void set(double xx, double yy, const char* pname, int n, COLORREF c)
	{
		x = xx;
		y = yy;
		numb = n;
		color = c;
		delete[] name;
		name = new char[strlen(pname) + 1];
		strcpy_s(name, strlen(pname) + 1, pname);
	}
	MY_POINT& operator=(const MY_POINT& other) {
		if (this != &other) {
			x = other.x;
			y = other.y;
		}
		return *this;
	}
	bool operator==(const MY_POINT& other) const {
		return (x == other.x && y == other.y);
	}

	bool operator!=(const MY_POINT& other) const {
		return !(*this == other);
	}
};

class MYDATA_API MY_DATA : public MY_POINT
{
protected:
	MY_POINT* pTab;
	int capacity;
	int last;
public:
	CExcept1App* pExcept;
public:
	MY_DATA(int no_it);
	MY_DATA(const MY_DATA& ob);
	~MY_DATA() { Free(); }
	void Free() { if (pTab) delete[] pTab; pTab = NULL; }
	void Init(int no_it);
	void Push(const MY_POINT& tmp);
	int size() { return last; }
	void clear() { last = 0; }
	void clear_all();
	void SaveToFile(const char* filename);
	void LoadFromFile(const char* filename);

	MY_POINT& operator [] (const int i);

	void GetMaxMinCoords(double& max_x, double& min_x, double& max_y, double& min_y);

private:
	MY_POINT* allocTab(MY_POINT* pTab, int i);
};

#pragma pack(pop)
