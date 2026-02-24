#include "main.h"
int main(void)
{
    int r;
    r = _islower('H');  _putchar(r + '0');  /* uppercase → 0 */
    r = _islower('o');  _putchar(r + '0');  /* lowercase → 1 */
    r = _islower(108); _putchar(r + '0');  /* 108='l'  → 1 */
    _putchar('\n');
    return (0);
}