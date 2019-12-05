#include "pch.h"
#include "Parallelogram.h"
//#include"B_tree.h"
#include<conio.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	try
	{
		ifstream myfile("Text.txt");
		POINT ppt[4], pptin[4];
		Parallelogram *P=NULL;
		Parallelogram_empty PE, *PI=NULL;
		Parallelogram_comb PComb;
		Parallelogram_colored PC;
		int mode;
		int linestyle;
		int linethick;
		int linecolor;
		int fillstyle;
		int fillcolor;
		if (!myfile.is_open()) throw exception("\tФайл не открыт");
		if (myfile.peek() == EOF) throw exception("\tПустой файл");
		while (myfile.peek() != EOF)
		{
			myfile >> mode;
			
			for (int i = 0; i < 4; i++)
			{
				myfile >> ppt[i].x;
				myfile >> ppt[i].y;
			}
			if (mode = 3)
			{
				for (int i = 0; i < 4; i++)
				{
					myfile >> pptin[i].x;
					myfile >> pptin[i].y;
				}
			}
			myfile >> linestyle;
			myfile >> linethick;
			myfile >> linecolor;
			if (mode > 1) {
				myfile >> fillstyle;
				myfile >> fillcolor;
			}
			switch (mode)
			{
			case 1:
			{
				P = &PE;
				PE.set_coord(ppt);
			}
			case 2:
			{
				P = &PC;
				PC.set_fillstyle(fillstyle);
				PC.set_fillcolor(fillcolor);
				PC.set_coord(ppt);
			}
			case 3:
			{

				P = &PComb;
				PComb.set_fillstyle(fillstyle);
				PComb.set_fillcolor(fillcolor);
				PI = PComb.inner;
				PComb.set_coord_inner(pptin);
				PComb.set_coord(ppt);
				P->check_nesting(PI->get_coord());
			}
			}
			
			P->set_linestyle(linestyle);
			P->set_linecolor(linecolor);
			P->set_linethick(linethick);
		}
		myfile.close();

	//	b_tree<Parallelogram> bt;
		//bt.read_tree("Text8");

		//bt.delete_node(-42);
		//bt.delete_node(0);

		//bt.delete_node(21443);
		//bt.delete_node(213);
		//bt.delete_node(4);
		//bt.delete_node(32);
		//bt.delete_node(0);
		//bt.delete_node(8);
		//bt.delete_node(-42);
		//bt.delete_node(421);

		
		/*		if (!bt.find_node(-42, found))
		{*/
			HWND hwnd = FindWindowA("Notepad", NULL);
			HDC hdc = GetDC(hwnd);
			RECT rt;
			GetClientRect(hwnd, &rt);

			POINT scr[4];

			scr[0].y = (rt.bottom - 1);
			scr[0].x = 1;
			scr[1].y = 1; //создаётся параллелограмм размером с окно
			scr[1].x = 1;//и поле рисования закрывается им
			scr[2].y = 1;
			scr[2].x = (rt.right - 1);
			scr[3].y = (rt.bottom - 1);
			scr[3].x = (rt.right - 1);

			Parallelogram_empty screen;
			screen.set_coord(scr);
			screen.set_linecolor(4);

			cout << "\tНажимайте на клавиши wasd, чтобы двигать фигуру. Нажмите любую другую клавишу, чтобы выйти" << endl;
			char reply = '0';
			while (reply == '0' || reply == 'w' || reply == 's' || reply == 'a' || reply == 'd')
			{
				if (screen.print() == 1) throw exception("\tЗаданная фигура вне окна");

				P->move(reply);
				P->print();
				reply = _getch();
			}
			ReleaseDC(hwnd, hdc);
		//}
		//else cout << "\tЗаданного id нет в контейнере" << endl;


	}
	catch (exception & ex)
	{
		cout << ex.what() << endl;
	}


	return 0;

}

