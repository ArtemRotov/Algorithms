#include <iostream>

void generate(int n, int pos = 0,  int open = 0, int close = 0)
{
    static char str[256];
    static int cnt;
    if (close == n)
    {
        std::cout <<  str << std::endl;
        return;
    }
    else
    {
        if (open > close)
        {
            str[pos] = ')';
            generate(n, pos + 1, open, close + 1);
        }
        if (open < n)
        {
            str[pos] = '(';
            generate(n, pos + 1, open + 1, close);
        }
    }
}


int main()
{
    generate(1);	// ()
	generate(2);	// ()()	(())
    generate(3);	// ()()() ()(()) (())() (()()) ((()))
	
    return 0;
}

