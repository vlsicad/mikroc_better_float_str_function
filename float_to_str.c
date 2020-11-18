
// use link this
  // char txt[15];
  //float  a1;
  
 //          nFloatToStr(a1, 2, txt);
 //          Lcd_chr(1,9,' ');
 //          for ( cnt = 0; cnt < 4; cnt++)
 //          {
 //           Lcd_Chr_cp(txt[cnt]);
//           };


void nFloatToStr(float f, short p, char *txt) {
   unsigned long result;
   char sign = ((char *)&f)[2].B7;
   unsigned long factor = 10;
   short i = p, j = 0;

   while (i--)
      factor *= 10;

   ((char *)&f)[2].B7 = 0;

   result = ((unsigned long)(f * factor) + 5) / 10;

   do {
      txt[j++] = result % 10 + '0';
      if (--p == 0)
         txt[j++] = '.';
   } while (((result /= 10) > 0) || (p > 0));

   if (txt[j - 1] == '.')
      txt[j++] = '0';

   if (sign)
      txt[j++] = '-';

   txt[j] = '\0';

   for (i = 0, j--; i < j; i++, j--)
      p = txt[i], txt[i] = txt[j], txt[j] = p;
}
