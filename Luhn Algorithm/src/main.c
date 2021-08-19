#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Calistir.h"
int main()
{
	calistir basla;
	basla = CalistirKurucu();
	basla->run();
	return 0;
}
