#include <iostream>
#include "App.h"
#include <time.h>
#include <locale.h>

int main()
{	
	setlocale(LC_ALL, "Portuguese");
	// rand is for tests and presentation only 
	srand(time(0));

	App app;
	app.run();
}
