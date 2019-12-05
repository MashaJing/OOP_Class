#pragma once
#ifndef __PARALLELOGRAM_H
#define __PARALLELOGRAM_H
#define red RGB(255, 0, 0)
#define green RGB(0, 255, 0)
#define blue RGB(0, 0, 255)
#define black RGB(0, 0, 0)
#define white RGB(255, 255, 255)

class Parallelogram {


protected:

	int linestyle;
	int linethick;
	int linecolor;

	int check_window_location(const RECT &rt);
	float len_between(const POINT a, const POINT b);
	

public:
	POINT *ppt;
	Parallelogram();
	Parallelogram(const POINT *ppt);
	~Parallelogram();

	virtual	void move(char reply);
	int set_coord(const POINT *ppt);
	void set_linethick(int linethick);
	void set_linestyle(int linestyle);
	void set_linecolor(int linecolor);
	int check_nesting(POINT *inner);

	POINT* get_coord();
	int get_linethick();
	int get_linestyle();
	int get_linecolor();

	int check_parall(const POINT *ppt);
	
	virtual int print() = 0;

};

class Parallelogram_empty : public Parallelogram
{
public:
	int print() override;

};
class Colored
{
protected:
	int fillstyle{ 0 };
	int fillcolor{ 4 };

public:
	void set_fillcolor(int fillcolor);
	void set_fillstyle(int fillstyle);
	int get_fillcolor();
	int get_fillstyle();
};

class Parallelogram_colored : public Parallelogram_empty, public Colored
{

public:
	int print() override;
};

class Parallelogram_comb : public Parallelogram_colored
{
public:
	Parallelogram_empty *inner;
	void move(char reply) override;
	void set_coord_inner(POINT *ppt);
};

// TODO: add headers that you want to pre-compile here

#endif